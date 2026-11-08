# FreeIPA server on FreeBSD (net/freeipa-server)

FreeIPA integrated identity management (LDAP, Kerberos, PKI) on FreeBSD.
This port ships FreeIPA 4.13.x together with the FreeBSD glue that upstream,
which targets Linux and systemd, does not provide.

Read the prerequisites first. If they are not met, `ipa-server-install` runs
for several minutes and then fails at the very last step.

---

## Prerequisites

### The two ports that must not use the base Kerberos

FreeIPA uses the MIT Kerberos from ports (`security/krb5`) with its own
`/usr/local/etc/krb5.conf`. Two dependencies default to `GSSAPI_BASE`, which
links the base-system Kerberos under `/usr/lib` instead:

* `security/cyrus-sasl2-gssapi`, used by the client enrolment step
* `security/py-gssapi`, used by `ipalib` for the kinit during self-enrolment

With either of them built that way the install runs all the way through and
then fails with `SPNEGO cannot find mechanisms to negotiate` or
`Cannot find KDC for realm`.

The official packages are built with default options, so these two have to
be built locally. Set the options in the `make.conf` of the poudriere set you
build in, or in `/etc/make.conf` if you build without poudriere:

```conf
security_cyrus-sasl2-gssapi_SET=GSSAPI_MIT
security_cyrus-sasl2-gssapi_UNSET=GSSAPI_BASE
security_py-gssapi_SET=GSSAPI_MIT
security_py-gssapi_UNSET=GSSAPI_BASE
```

Build and install both from that set before `freeipa-server`.

Verify once installed. Both must point into `/usr/local`, never `/usr/lib`:

```sh
ldd /usr/local/lib/sasl2/libgssapiv2.so | grep libgssapi_krb5
ldd /usr/local/lib/python3*/site-packages/gssapi/raw/misc*.so | grep libgssapi_krb5
```

This is a system-wide choice: every SASL/GSSAPI consumer on the host (SSSD,
OpenLDAP, Postfix) then uses the ports Kerberos, which is the consistent
setup on a machine dedicated to FreeIPA. The plugin is loaded through
`dlopen`, so those consumers do not need rebuilding.

### Host name

The hostname must be a fully qualified domain name, it must resolve to the
host's real address rather than loopback, and it must be the canonical name
in `/etc/hosts`:

```sh
sysrc hostname="ipa.example.com"
hostname ipa.example.com
```

```
::1         localhost
127.0.0.1   localhost
10.0.0.10   ipa.example.com ipa
```

Without that line FreeIPA cannot resolve its own name and `ipactl` aborts
with `socket.gaierror: [Errno 8] Name does not resolve`. Both of these must
print the FQDN:

```sh
hostname
python3 -c 'import socket; print(socket.gethostname(), socket.getfqdn())'
```

The rc script warns at start time if the hostname is not an FQDN, but it
does not fix it for you.

### Time

Kerberos rejects tickets once clocks drift apart by more than five minutes,
and FreeBSD ships `ntpd_enable="NO"` in `/etc/defaults/rc.conf`. Make sure a
time source runs before you install:

```sh
service ntpd status
sysrc ntpd_enable=YES && service ntpd start   # if it does not
```

The install below then passes `--no-ntp` and keeps that source. The port
also depends on `net/chrony`, which `ipa-server-install` can configure
instead, but that path is untested here.

---

## Installation

```sh
pkg install freeipa-server
ipa-server-install \
    --hostname=ipa.example.com \
    --domain=example.com \
    --realm=EXAMPLE.COM \
    --no-host-dns \
    --no-ntp
```

`--no-host-dns` skips the DNS pre-checks when you manage names in
`/etc/hosts`, and `--no-ntp` keeps the time source from the previous section.
Do not use `--setup-dns`: `bind-dyndb-ldap` is not in the ports tree, so
IPA-managed DNS cannot work.

The installer asks for a Directory Manager password and an `admin` password,
then creates the 389-ds instance, the KDC, the Dogtag CA and the httpd
stack. It runs for several minutes, Dogtag and its Tomcat take the longest.

---

## Running the server

A single rc service wraps IPA's own orchestrator `ipactl`, which starts and
stops the components in dependency order. The script name carries a hyphen,
the rc variable an underscore:

```sh
sysrc freeipa_server_enable=YES
service freeipa-server start      # start | stop | status
```

Apart from `gssproxy_enable` below you do not set the back-end services in
`rc.conf` yourself:

* `ipa-server-install` sets `kdc_enable`, `kadmind_enable`,
  `certmonger_enable`, `oddjobd_enable`, `sssd_enable`, `dbus_enable` and
  `nisdomain_enable`.
* It leaves `dirsrv_enable`, `pki_tomcatd_pki_tomcat_enable`,
  `apache24_enable` and `ipa_custodia_enable` at `NO`, because `ipactl`
  brings those four up itself: the Directory Server through `dsctl`
  (389-ds installs no rc script at all, so `dirsrv_enable` is inert) and
  the other three with `service <name> onestart`.
* It also writes `ipa_enable=YES`, a leftover from the Linux `ipa.service`.
  FreeBSD has no `ipa` rc script, so it does nothing.

pki-tomcatd above all must not start at boot: it would race the Directory
Server and come up with a dead `/ca` endpoint while `ipactl status` still
reports RUNNING.

### Surviving a reboot

`freeipa_server_enable=YES` is not the whole story. Three things decide
whether the stack comes back.

1. **D-Bus, handled for you.** `certmonger` and `oddjobd` connect to the
   system bus at start and their rc scripts `REQUIRE: dbus`. Without it the
   boot hangs in `oddjobd`'s endless
   `Error connecting to bus for "com.redhat.oddjob"` retry loop, which also
   delays `sshd`. The installer runs `sysrc dbus_enable=YES` itself. If a
   boot ever hangs there, check with `sysrc -n dbus_enable` and set it
   again.

2. **gssproxy, yours to enable.** `ipa-server-install` writes
   `/usr/local/etc/gssproxy/10-ipa.conf` but leaves the rc switch alone:

   ```sh
   sysrc gssproxy_enable=YES
   ```

   Installing `security/gssproxy` also puts
   `/usr/local/etc/gss/mech.d/proxymech.conf` on the host, which registers
   `proxymech.so` as an `<interposer>` for the krb5 GSSAPI mechanism. httpd
   is kept out of it: the installer sets `GSS_USE_PROXY=no` in
   `/usr/local/etc/apache24/envvars.d/ipa.env`, and `mod_auth_gssapi` reads
   `/var/db/ipa/gssproxy/http.keytab` directly, with
   `GssapiUseS4U2Proxy on` in `/usr/local/etc/apache24/Includes/ipa.conf`.

3. **cloud-init, yours to disable.** On cloud-init images `/etc/hosts` is
   regenerated from a template on every boot, which drops the line mapping
   the FQDN to the real address. FreeIPA can then no longer resolve its own
   name and `ipactl` aborts with
   `socket.gaierror: [Errno 8] Name does not resolve`. Once the host is
   provisioned cloud-init has no further job on an IPA server:

   ```sh
   touch /usr/local/etc/cloud/cloud-init.disabled
   ```

   Where cloud-init has to stay, a drop-in is the alternative, but it loses
   against the image's own user-data, which Proxmox for one generates with
   `manage_etc_hosts: true`:

   ```sh
   printf 'preserve_hostname: true\nmanage_etc_hosts: false\n' \
       > /usr/local/etc/cloud/cloud.cfg.d/99-freeipa.cfg
   ```

### Checking that it works

`ipactl status` only reports whether the processes are alive. The CA web
application and the API have to be checked separately:

```sh
ipactl status
curl -sk https://localhost:8443/ca/admin/ca/getStatus
ipa user-show admin
```

`ipactl status` lists seven services and `getStatus` returns
`"Status" : "running"` for the CA. `ipa user-show admin` answers as root
without any `kinit`, because `ipa-client-install` left the host ticket in
`/tmp/krb5cc_0`; `klist` shows it as `host/<fqdn>@<REALM>`.

To work as `admin` instead, mind which `kinit` you get. The base system and
`security/krb5` both ship one, and the default `PATH` puts `/usr/bin` ahead
of `/usr/local/bin`, so a plain `kinit` picks the base binary, which has no
`/etc/krb5.conf` and fails with
`Configuration file does not specify default realm`. Use the ports one, and
as an unprivileged user, so that it does not overwrite the host ticket:

```sh
/usr/local/bin/kinit admin
```

The Web UI is at `https://ipa.example.com/ipa/ui/`.

Reboot once and run all of it again. That is what covers the rc
configuration.

### Logs

| What | Where |
|---|---|
| Server install | `/var/log/ipaserver-install.log` |
| Client enrolment | `/var/log/ipaclient-install.log` |
| Web UI and API | `/var/log/httpd-error.log` |
| Kerberos KDC | `/var/log/krb5kdc.log` |
| Directory server | `/var/log/dirsrv/slapd-<REALM>/errors` |
| Dogtag CA | `/var/log/pki/pki-tomcat/` |
| OTP daemon | `/var/log/ipa-otpd.log` |
| Secret sharing | `/var/log/ipa-custodia.log` |

Put `KRB5_TRACE=/dev/stderr` in front of a failing command for Kerberos
problems. The port ships its log rotation as
`/usr/local/etc/newsyslog.conf.d/freeipa-server.conf.sample`; copy it
without the suffix, otherwise `ipa-otpd.log` is never rotated.

---

## Components

| Component | Program | Runs as | Notes |
|---|---|---|---|
| Directory server | `ns-slapd` (389-ds) | `dirsrv` | instance `slapd-<REALM>` with dots as dashes, LDAP 389/636 |
| Kerberos KDC | `krb5kdc` | `root` | 88 tcp/udp, data in `/usr/local/var/krb5kdc` |
| Kerberos admin | `kadmind` | `root` | 464, `kadmin` on 749 |
| Dogtag PKI (CA) | `pki-tomcatd` (jsvc) | `pkiuser` | Tomcat 8080/8443, `security/dogtag-pki` |
| Web UI and API | `httpd` (apache24) | `www` | 80/443, mod_wsgi as `ipaapi` |
| KDC proxy (MS-KKDCP) | mod_wsgi `/KdcProxy` | `kdcproxy` | 443, `security/py-kdcproxy` |
| Secret sharing | `ipa-custodia` | `root` | rc script `ipa-custodia`, rcvar `ipa_custodia_enable` |
| OTP daemon | `ipa-otpd` | `root` | own `inetd` instance, socket in `/var/run/krb5kdc` |

Alongside these the installer enables the shared helpers `dbus`,
`certmonger`, `oddjobd` and `sssd`, plus `gssproxy` above. The service users
`ipaapi` and `kdcproxy` are created by the port.

---

## Uninstalling

`ipa-server-install --uninstall` removes the IPA instance, its configuration
and its data. As on upstream FreeIPA it does not remove packages. It sets the
rc variables it owns to `NO` and drops `kdc_program` and `kadmind_program`,
but it neither stops nor disables the shared helper services.

### Full decommission

```sh
ipa-server-install --uninstall -U

service certmonger stop
service oddjobd stop
service gssproxy stop
service sssd stop

sysrc -x freeipa_server_enable gssproxy_enable certmonger_enable \
    oddjobd_enable sssd_enable kdc_enable kadmind_enable \
    nisdomain_enable nisdomainname ipa_enable \
    dirsrv_enable pki_tomcatd_pki_tomcat_enable apache24_enable \
    ipa_custodia_enable

pkg delete -y freeipa-server
```

`dbus_enable` is left in place on purpose, other software on the host is
likely to want it. The same goes for the system-wide `GSSAPI_MIT` choice
from the prerequisites: revert it only if nothing else relies on it.
