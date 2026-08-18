# FreeIPA server on FreeBSD (net/freeipa-server)

FreeIPA integrated identity management (LDAP + Kerberos + PKI) on FreeBSD.
This port ships FreeIPA 4.13.x together with the FreeBSD-specific glue that
upstream (Linux/systemd oriented) does not provide.

This document has two audiences:

* **Operators** — how to install, configure and run an IPA server
  (sections *Prerequisites* … *Uninstalling*).
* **Port maintainers / reviewers** — why the FreeBSD patches exist
  (section *FreeBSD integration notes*).

---

## Prerequisites (read this first)

### Kerberos / SASL — **do this or the install fails at the very end**

FreeIPA on FreeBSD uses the **MIT Kerberos from ports** (`security/krb5`).
The SASL/GSSAPI plugin used by the final *client enrolment* step of
`ipa-server-install` must use the **same** Kerberos. By default
`security/cyrus-sasl2-gssapi` is built with `GSSAPI_BASE`, which links the
**base-system** Kerberos (`/usr/lib/libgssapi_krb5`) and reads
`/etc/krb5.conf` — the wrong Kerberos for FreeIPA. The install then runs
all the way through and fails at the end with either:

```
Insufficient access: SASL(-1): ... (SPNEGO cannot find mechanisms to negotiate)
```

or `Cannot find KDC for realm "..."`.

**Fix:** build `security/cyrus-sasl2-gssapi` with the **`GSSAPI_MIT`** option
(instead of the default `GSSAPI_BASE`) so the plugin links the ports
Kerberos (`/usr/local/lib/libgssapi_krb5`) and reads
`/usr/local/etc/krb5.conf`:

```sh
# make.conf (ports / poudriere):
security_cyrus-sasl2-gssapi_SET=GSSAPI_MIT
security_cyrus-sasl2-gssapi_UNSET=GSSAPI_BASE

# or interactively, then rebuild + reinstall the plugin:
make -C /usr/ports/security/cyrus-sasl2-gssapi config   # select GSSAPI_MIT
```

Verify (must show the ports Kerberos, **not** `/usr/lib/...`):

```sh
ldd /usr/local/lib/sasl2/libgssapiv2.so | grep libgssapi_krb5
# -> /usr/local/lib/libgssapi_krb5.so
```

This is a system-wide choice: all SASL/GSSAPI consumers (SSSD, OpenLDAP,
Postfix, ...) then use the ports MIT Kerberos — the correct, consistent
setup on a host dedicated to FreeIPA. The plugin is loaded at runtime via
`dlopen`, so those consumers do **not** need rebuilding.

### Python GSSAPI bindings — same Kerberos, same reason

`security/py-gssapi` (the `pyXX-gssapi` package) has the **same** default
pitfall and must be fixed the same way. It defaults to `GSSAPI_BASE`, building
against the base-system Kerberos. FreeIPA's own tooling uses these Python
bindings for the Kerberos step of the self-enrolment (`ipalib` calls `kinit`);
with the base Kerberos it cannot find the KDC and the install fails at the very
end with `Cannot find KDC for realm "..."`.

**Fix:** build `security/py-gssapi` with **`GSSAPI_MIT`** too:

```sh
# make.conf (ports / poudriere):
security_py-gssapi_SET=GSSAPI_MIT
security_py-gssapi_UNSET=GSSAPI_BASE

# or interactively:
make -C /usr/ports/security/py-gssapi config   # select GSSAPI_MIT
```

Verify (must show the ports Kerberos, **not** `/usr/lib/...`):

```sh
ldd /usr/local/lib/python3*/site-packages/gssapi/raw/misc*.so | grep libgssapi_krb5
# -> /usr/local/lib/libgssapi_krb5.so
```

---

FreeIPA is very sensitive to host naming. **Before** running
`ipa-server-install` make sure:

1. The system hostname is a **fully-qualified domain name** (FQDN):

   ```sh
   sysrc hostname="ipa.example.com"
   hostname ipa.example.com
   ```

2. The FQDN resolves to the host's **real** IP address (not `127.0.0.1`)
   and is the **canonical** name in `/etc/hosts`:

   ```
   ::1         localhost
   127.0.0.1   localhost
   10.0.0.10   ipa.example.com ipa
   ```

   Do **not** map the hostname to a loopback address and do **not** let the
   short name be canonical. A short hostname breaks Kerberos and Dogtag
   (certificate hostname mismatch, wrong TLS-key passphrase lookup).

3. Check the result — both must print the FQDN:

   ```sh
   hostname
   python3 -c 'import socket; print(socket.gethostname(), socket.getfqdn())'
   ```

The `freeipa_server` rc script warns at start time if the hostname is not a
FQDN, but it does not fix it for you.

---

## Installation

```sh
pkg install freeipa-server
```

Then configure the instance (interactive; `--no-host-dns` skips DNS
pre-checks when you manage names via `/etc/hosts`, `--no-ntp` skips the
chrony client which is not used on FreeBSD):

```sh
ipa-server-install \
    --hostname=ipa.example.com \
    --domain=example.com \
    --realm=EXAMPLE.COM \
    --no-host-dns \
    --no-ntp
```

`ipa-server-install` creates and configures the 389-ds instance, the KDC,
the Dogtag CA, Apache/httpd and the helper services.

---

## Running the server

The whole stack is driven by a single rc service that wraps IPA's own
orchestrator `ipactl` (it starts/stops the components in the correct order):

```sh
sysrc freeipa_server_enable=YES
service freeipa_server start      # start | stop | status
```

You do **not** need to enable the individual back-end services in
`rc.conf` — `ipactl` starts them with `service <name> onestart`, which does
not require a per-service `_enable=YES`. The single switch
`freeipa_server_enable=YES` is enough for boot.

`ipa-custodia` ships its own rc script (`ipa_custodia`) and is managed by
`ipactl` as part of the stack.

### Boot persistence (surviving a reboot)

Two host-level settings must be right or the server will **not** come back
up after a reboot (`freeipa_server_enable=YES` alone is not enough):

1. **Enable D-Bus.** `certmonger` and `oddjobd` (both pulled in by FreeIPA)
   connect to the system D-Bus at start and their rc scripts `REQUIRE: dbus`.
   If D-Bus is not enabled the boot **hangs** in `oddjobd`'s endless
   `Error connecting to bus for "com.redhat.oddjob"` retry loop (and
   `certmonger` fails to start), which also delays `sshd`:

   ```sh
   sysrc dbus_enable=YES
   ```

2. **Enable gssproxy.** `httpd`'s `mod_auth_gssapi` acquires the HTTP
   service credentials through gssproxy (the ports MIT Kerberos GSS
   proxy).  Without it every authenticated request to the IPA API / Web
   UI fails -- `gss_acquire_cred() ... SPNEGO cannot find mechanisms to
   negotiate` in the httpd error log, and `ipa` commands report
   `No valid Negotiate header in server response`:

   ```sh
   sysrc gssproxy_enable=YES
   ```

3. **Stop cloud-init from managing `/etc/hosts`.** On cloud-init images
   (`manage_etc_hosts: true`) `/etc/hosts` is regenerated from a template on
   every boot; that drops the `FQDN -> real-IP` line and maps the host to
   `127.0.0.1` only. FreeIPA can then no longer resolve its own FQDN and
   `ipactl` aborts at boot with `socket.gaierror: [Errno 8] Name does not
   resolve`. Disable it and keep the `/etc/hosts` entry from the
   Prerequisites section above:

   ```sh
   printf 'manage_etc_hosts: false\n' \
       > /usr/local/etc/cloud/cloud.cfg.d/99-ipa-no-manage-hosts.cfg
   ```

---

## Components / service map

| Component            | Program / rc            | Runs as   | Notes                                    |
|----------------------|-------------------------|-----------|------------------------------------------|
| Directory server     | `ns-slapd` (389-ds)     | `dirsrv`  | instance `slapd-<REALM>`, LDAP 389/636   |
| Kerberos KDC         | `krb5kdc`               | `root`    | UDP/TCP 88; data in `/usr/local/var/krb5kdc` |
| Kerberos admin       | `kadmind`               | `root`    | 464                                      |
| Dogtag PKI (CA)      | `pki-tomcatd` (jsvc)    | `pkiuser` | Tomcat 8080/8443; `security/dogtag-pki`  |
| Web UI / API         | `httpd` (apache24)      | `www`     | 80/443; mod_wsgi as `ipaapi`             |
| KDC proxy (MS-KKDCP) | mod_wsgi `/KdcProxy`    | `kdcproxy`| HTTPS 443; `security/py-kdcproxy`        |
| Secret sharing       | `ipa-custodia`          | `root`    | rc `ipa_custodia`                        |
| OTP daemon           | `ipa-otpd`              | `root`    | socket in `/var/run/krb5kdc`             |

Service users `ipaapi` and `kdcproxy` are created by the port.

---

## Uninstalling

`ipa-server-install --uninstall` removes the IPA **instance** (its
configuration and data). As on upstream FreeIPA it does **not** remove the
installed packages, and it deliberately leaves shared helper services and
their `rc.conf` toggles alone. Two cases:

### Reinstall later (keep this host as an IPA server)

```sh
ipa-server-install --uninstall -U
```

That is all you need before another `ipa-server-install`. Leftover enabled
helpers (e.g. `certmonger`) are harmless - the next install reconfigures them.
If you plan to reinstall, also drop the Kerberos config left from the previous
instance (`--uninstall` leaves it behind) so the reinstall regenerates it
cleanly:

```sh
rm -rf /usr/local/etc/krb5.conf /usr/local/etc/krb5.conf.d
```

### Full decommission (this host should no longer run IPA)

`--uninstall` intentionally does not stop/disable shared services or undo
`rc.conf` toggles it did not exclusively own, so finish by hand:

```sh
ipa-server-install --uninstall -U

# stop helper daemons that may still run from the removed instance
service certmonger stop 2>/dev/null || pkill certmonger
service gssproxy   stop 2>/dev/null || pkill gssproxy

# drop rc.conf leftovers the instance left behind
sysrc -x certmonger_enable kdc_program

# optional: remove the package(s)
pkg delete -y freeipa-server

# a reboot then guarantees nothing lingers in memory or /var/run
```

`certmonger`, `gssproxy` and the system-wide `GSSAPI_MIT` choice for
`security/cyrus-sasl2-gssapi` (see *Prerequisites*) are shared: only
disable/revert them if nothing else on the host relies on them.

---

## Building / testing

Development tree: `~/dev/ports` on the poudriere host. Test a single port:

```sh
poudriere testport -j <jail> -p ports net/freeipa-server
```

The runtime is exercised on a dedicated test VM (`ipa-server-install`),
not on the build host.
