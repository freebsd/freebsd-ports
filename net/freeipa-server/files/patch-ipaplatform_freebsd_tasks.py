--- ipaplatform/freebsd/tasks.py.orig	2026-08-17 20:38:02 UTC
+++ ipaplatform/freebsd/tasks.py
@@ -0,0 +1,251 @@
+#
+# Copyright (C) 2026  FreeIPA Contributors see COPYING for license
+#
+
+import os
+
+from ipaplatform.base.tasks import BaseTaskNamespace
+from ipaplatform.constants import constants
+from ipaplatform.paths import paths
+from ipapython import ipautil
+
+
+class FreeBSDTaskNamespace(BaseTaskNamespace):
+    def restore_context(self, filepath, force=False):
+        return None
+
+    def backup_hostname(self, fstore, statestore):
+        return None
+
+    def restore_hostname(self, fstore, statestore):
+        return None
+
+    def set_hostname(self, hostname):
+        return None
+
+    def reload_systemwide_ca_store(self):
+        return False
+
+    def platform_insert_ca_certs(self, ca_certs):
+        return False
+
+    def platform_remove_ca_certs(self):
+        return False
+
+    def check_selinux_status(self):
+        return False
+
+    def check_ipv6_stack_enabled(self):
+        return None
+
+    def detect_container(self):
+        return None
+
+    def restore_pre_ipa_client_configuration(self, fstore, statestore,
+                                             was_sssd_installed,
+                                             was_sssd_configured):
+        return None
+
+    def set_nisdomain(self, nisdomain):
+        # FreeBSD: persist the NIS domain in rc.conf; the base-system
+        # nisdomain(8) rc service applies it via domainname(1). The IPA
+        # "domainname" service maps to the FreeBSD "nisdomain" rc script.
+        ipautil.run([paths.SBIN_SYSRC, "nisdomainname=%s" % nisdomain])
+
+    def modify_nsswitch_pam_stack(self, sssd, mkhomedir, statestore,
+                                  sudo=True, subid=False):
+        # FreeBSD: the base implementation relies on authselect/authconfig,
+        # which do not exist here.  Enable the SSSD NSS module in
+        # nsswitch.conf so getent/id resolve IPA users and groups (the
+        # nss_sss module is provided by security/sssd2).
+        if not sssd:
+            return None
+        conf = paths.NSSWITCH_CONF
+        try:
+            with open(conf) as fd:
+                lines = fd.readlines()
+        except OSError:
+            return None
+        changed = False
+        out = []
+        for line in lines:
+            stripped = line.strip()
+            for db in ("passwd", "group"):
+                if stripped.startswith(db + ":") and "sss" not in stripped:
+                    line = "%s: files sss\n" % db
+                    changed = True
+                    break
+            out.append(line)
+        if changed:
+            with open(conf, "w") as fd:
+                fd.writelines(out)
+            self.restore_context(conf)
+
+    def modify_pam_to_use_krb5(self, statestore):
+        return None
+
+    def backup_auth_configuration(self, path):
+        return None
+
+    def restore_auth_configuration(self, path):
+        return None
+
+    def set_selinux_booleans(self, required_settings, backup_func=None):
+        return False
+
+    def configure_httpd_service_ipa_conf(self):
+        env_conf = paths.HTTPD_IPA_ENVVARS_CONF
+        os.makedirs(os.path.dirname(env_conf), mode=0o755, exist_ok=True)
+        # FreeBSD: gssproxy's S4U2 delegation is unreliable in the
+        # long-running httpd worker, so the framework does the constrained
+        # delegation via direct MIT krb5 instead (GSS_USE_PROXY=no).  It
+        # needs the HTTP keytab as its client keytab for S4U2Proxy, and the
+        # ipapython.ipaldap gss_krb5_ccache_name fix to pick up the
+        # per-request ccache.  gssproxy itself stays installed and available.
+        env_text = """# Do not edit. Created by IPA installer.
+KRB5CCNAME={}
+GSS_USE_PROXY=no
+KDCPROXY_CONFIG={}
+LC_ALL=C.UTF-8
+KRB5_CLIENT_KTNAME={}
+export KRB5CCNAME KRB5_CLIENT_KTNAME GSS_USE_PROXY KDCPROXY_CONFIG LC_ALL
+""".format(paths.KRB5CC_HTTPD, paths.KDCPROXY_CONFIG, paths.HTTP_KEYTAB)
+        with open(env_conf, "w") as fd:
+            fd.write(env_text)
+        os.chmod(env_conf, 0o644)
+        self.restore_context(env_conf)
+
+        rc_conf = paths.HTTPD_IPA_RC_CONF
+        os.makedirs(os.path.dirname(rc_conf), mode=0o755, exist_ok=True)
+        rc_text = """# Do not edit. Created by IPA installer.
+ipa_httpd_start_precmd="${start_precmd}"
+ipa_httpd_restart_precmd="${restart_precmd}"
+start_precmd="ipa_httpd_kdcproxy_prestart"
+restart_precmd="ipa_httpd_kdcproxy_prerestart"
+
+ipa_httpd_kdcproxy_environment()
+{
+    if test -f "${apache24_envvars}"
+    then
+        . "${apache24_envvars}"
+    fi
+}
+
+ipa_httpd_kdcproxy_prestart()
+{
+    ipa_httpd_kdcproxy_environment
+    @IPA_HTTPD_KDCPROXY@ || return $?
+    if test -n "${ipa_httpd_start_precmd}"
+    then
+        ${ipa_httpd_start_precmd}
+    fi
+}
+
+ipa_httpd_kdcproxy_prerestart()
+{
+    ipa_httpd_kdcproxy_environment
+    @IPA_HTTPD_KDCPROXY@ || return $?
+    if test -n "${ipa_httpd_restart_precmd}"
+    then
+        ${ipa_httpd_restart_precmd}
+    fi
+}
+""".replace("@IPA_HTTPD_KDCPROXY@", paths.IPA_HTTPD_KDCPROXY)
+        with open(rc_conf, "w") as fd:
+            fd.write(rc_text)
+        os.chmod(rc_conf, 0o644)
+        self.restore_context(rc_conf)
+
+    def add_user_to_group(self, user, group):
+        # FreeBSD has no usermod(8); use pw(8).  Used to make the httpd
+        # worker user (www) a member of the ipaapi group so it can write
+        # delegated GSSAPI ccaches into the ipaapi-group-owned
+        # /var/run/ipa/ccaches directory.
+        try:
+            ipautil.run(
+                ["/usr/sbin/pw", "group", "mod", str(group),
+                 "-m", str(user)]
+            )
+        except ipautil.CalledProcessError:
+            pass
+
+    def configure_http_gssproxy_conf(self, ipauser):
+        confdir = os.path.dirname(paths.GSSPROXY_CONF)
+        os.makedirs(confdir, mode=0o755, exist_ok=True)
+        ipautil.copy_template_file(
+            os.path.join(paths.USR_SHARE_IPA_DIR, "gssproxy.conf.template"),
+            paths.GSSPROXY_CONF,
+            dict(
+                HTTP_KEYTAB=paths.HTTP_KEYTAB,
+                HTTPD_USER=constants.HTTPD_USER,
+                IPAAPI_USER=ipauser,
+                SWEEPER_SOCKET=paths.IPA_CCACHE_SWEEPER_GSSPROXY_SOCK,
+            ),
+        )
+        os.chmod(paths.GSSPROXY_CONF, 0o600)
+        self.restore_context(paths.GSSPROXY_CONF)
+
+    def remove_httpd_service_ipa_conf(self):
+        for conf in (
+            paths.HTTPD_IPA_ENVVARS_CONF,
+            paths.HTTPD_IPA_RC_CONF,
+        ):
+            try:
+                os.unlink(conf)
+            except FileNotFoundError:
+                pass
+
+    def configure_httpd_wsgi_conf(self):
+        conf = paths.HTTPD_IPA_WSGI_MODULES_CONF
+        confdir = os.path.dirname(conf)
+        os.makedirs(confdir, mode=0o755, exist_ok=True)
+        modules = (
+            ("proxy_module", "mod_proxy.so"),
+            ("proxy_ajp_module", "mod_proxy_ajp.so"),
+            ("proxy_http_module", "mod_proxy_http.so"),
+            ("ssl_module", "mod_ssl.so"),
+            ("socache_shmcb_module", "mod_socache_shmcb.so"),
+            ("rewrite_module", "mod_rewrite.so"),
+            ("deflate_module", "mod_deflate.so"),
+            ("wsgi_module", "mod_wsgi.so"),
+            ("auth_gssapi_module", "mod_auth_gssapi.so"),
+            ("session_module", "mod_session.so"),
+            ("session_cookie_module", "mod_session_cookie.so"),
+            ("expires_module", "mod_expires.so"),
+        )
+        with open(conf, "w") as fd:
+            fd.write("## vim: set filetype=apache:\n")
+            fd.write("##\n")
+            fd.write("## FreeIPA required Apache modules\n")
+            fd.write("##\n")
+            for module, filename in modules:
+                fd.write("<IfModule {negation}{module}>\n".format(
+                    negation=chr(33), module=module
+                ))
+                fd.write(
+                    "    LoadModule {module} "
+                    "libexec/apache24/{filename}\n".format(
+                        module=module, filename=filename
+                    )
+                )
+                fd.write("</IfModule>\n")
+        os.chmod(conf, 0o644)
+        self.restore_context(conf)
+
+    def configure_httpd_protocol(self):
+        return None
+
+    def setup_httpd_logging(self):
+        return None
+
+    def systemd_daemon_reload(self):
+        return None
+
+    def configure_pkcs11_modules(self, fstore):
+        return False
+
+    def restore_pkcs11_modules(self, fstore):
+        return False
+
+
+tasks = FreeBSDTaskNamespace()
