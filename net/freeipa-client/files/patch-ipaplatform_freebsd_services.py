--- ipaplatform/freebsd/services.py.orig	2026-08-11 14:55:32 UTC
+++ ipaplatform/freebsd/services.py
@@ -0,0 +1,522 @@
+#
+# Copyright (C) 2026  FreeIPA Contributors see COPYING for license
+#
+
+import errno
+import json
+import logging
+import os
+import signal
+import stat
+import time
+from configparser import RawConfigParser
+
+from ipaplatform.base import services as base_services
+from ipaplatform.paths import paths
+from ipapython import ipautil
+
+logger = logging.getLogger(__name__)
+
+freebsd_rc_services = dict((name, name) for name in base_services.wellknownservices)
+freebsd_rc_services.update({
+    "httpd": "apache24",
+    "kadmin": "kadmind",
+    "krb5kdc": "kdc",
+    "pki_tomcatd": "pki_tomcatd_pki_tomcat",
+    "pki-tomcatd": "pki_tomcatd_pki_tomcat",
+    "domainname": "nisdomain",
+})
+
+freebsd_rc_enable_names = {
+    "ipa-custodia": "ipa_custodia",
+}
+
+freebsd_kerberos_rcvars = {
+    "kdc": {
+        "kdc_program": "/usr/local/sbin/krb5kdc",
+        "kdc_enable": "YES",
+    },
+    "kadmind": {
+        "kdc_program": "/usr/local/sbin/krb5kdc",
+        "kdc_enable": "YES",
+        "kadmind_program": "/usr/local/sbin/kadmind",
+        "kadmind_enable": "YES",
+    },
+}
+
+
+class FreeBSDService(base_services.PlatformService):
+    def __init__(self, service_name, api=None):
+        super(FreeBSDService, self).__init__(service_name, api=api)
+        self.rc_name = freebsd_rc_services.get(service_name, service_name)
+        self.rc_enable_name = freebsd_rc_enable_names.get(
+            self.rc_name, self.rc_name.replace("-", "_")
+        )
+
+    def _set_rcvars(self, rcvars):
+        for key, value in rcvars.items():
+            try:
+                ipautil.run([paths.SBIN_SYSRC, "%s=%s" % (key, value)])
+            except ipautil.CalledProcessError:
+                pass
+
+    def _prepare_rc_service(self, action):
+        if action not in ("onestart", "onerestart", "start", "restart"):
+            return
+        self._set_rcvars(freebsd_kerberos_rcvars.get(self.rc_name, {}))
+
+    def _run_service(self, action, capture_output=True):
+        self._prepare_rc_service(action)
+        daemonizing = action in ("onestart", "onerestart", "start", "restart")
+        # rc.d daemons may inherit stdout and stderr. Redirect daemonizing
+        # actions to /dev/null to avoid waiting on inherited output pipes.
+        return ipautil.run(
+            [paths.SBIN_SERVICE, self.rc_name, action],
+            skip_output=daemonizing or not capture_output
+        )
+
+    def start(self, instance_name="", capture_output=True, wait=True):
+        os.makedirs(os.path.dirname(paths.SVC_LIST_FILE), mode=0o711, exist_ok=True)
+        if not self.is_running(instance_name, wait=wait):
+            try:
+                self._run_service("onestart", capture_output=capture_output)
+            except ipautil.CalledProcessError:
+                # FreeBSD base rc scripts for the Kerberos daemons (kdc,
+                # kadmind) can fail to (re)start while the environment is
+                # being torn down -- e.g. SimpleServiceInstance.uninstall()
+                # restores a previously-running kadmind after krb5kdc/DS
+                # were already unconfigured. Aborting the whole uninstall
+                # over a best-effort restore is worse than continuing; a
+                # genuine install-time failure still surfaces at the first
+                # real use of the service.
+                if self.rc_name not in ("kdc", "kadmind"):
+                    raise
+                logger.warning(
+                    "Ignoring failed '%s onestart' (service could not be "
+                    "started; likely mid-teardown restore)", self.rc_name)
+        super(FreeBSDService, self).start(
+            instance_name, capture_output=capture_output, wait=wait
+        )
+
+    def stop(self, instance_name="", capture_output=True):
+        if self.is_running(instance_name):
+            self._run_service("onestop", capture_output=capture_output)
+        super(FreeBSDService, self).stop(
+            instance_name, capture_output=capture_output
+        )
+
+    def restart(self, instance_name="", capture_output=True, wait=True):
+        self._run_service("onerestart", capture_output=capture_output)
+
+    def try_restart(self, instance_name="", capture_output=True, wait=True):
+        if self.is_running(instance_name, wait=wait):
+            self.restart(instance_name, capture_output=capture_output, wait=wait)
+
+    def reload_or_restart(self, instance_name="", capture_output=True, wait=True):
+        self.restart(instance_name, capture_output=capture_output, wait=wait)
+
+    def is_running(self, instance_name="", wait=True):
+        try:
+            self._run_service("onestatus", capture_output=True)
+        except ipautil.CalledProcessError:
+            return False
+        return True
+
+    def is_installed(self):
+        return (
+            os.path.exists("/etc/rc.d/%s" % self.rc_name) or
+            os.path.exists("/usr/local/etc/rc.d/%s" % self.rc_name)
+        )
+
+    def enable(self, instance_name=""):
+        try:
+            self._set_rcvars(freebsd_kerberos_rcvars.get(self.rc_name, {}))
+            ipautil.run([paths.SBIN_SYSRC, "%s_enable=YES" % self.rc_enable_name])
+        except ipautil.CalledProcessError:
+            pass
+
+    def disable(self, instance_name=""):
+        try:
+            ipautil.run([paths.SBIN_SYSRC, "%s_enable=NO" % self.rc_enable_name])
+            # Undo the extra rc.conf variables that enable() set for the
+            # Kerberos services (kdc_program/kadmind_program and their
+            # *_enable flags) so an uninstall leaves no stale rc.conf
+            # entries behind.
+            for key in freebsd_kerberos_rcvars.get(self.rc_name, {}):
+                if key.endswith("_enable"):
+                    ipautil.run([paths.SBIN_SYSRC, "%s=NO" % key])
+                else:
+                    ipautil.run([paths.SBIN_SYSRC, "-x", key])
+        except ipautil.CalledProcessError:
+            pass
+
+    def is_enabled(self, instance_name=""):
+        try:
+            result = ipautil.run(
+                [paths.SBIN_SYSRC, "-n", "%s_enable" % self.rc_enable_name],
+                capture_output=True
+            )
+        except ipautil.CalledProcessError:
+            return False
+        return result.output.strip().upper() == "YES"
+
+    def install(self, instance_name=""):
+        self.enable(instance_name)
+
+    def remove(self, instance_name=""):
+        self.disable(instance_name)
+
+
+class FreeBSDOtpdService(base_services.PlatformService):
+    _START_TIMEOUT = 10.0
+    _STOP_TIMEOUT = 10.0
+
+    @staticmethod
+    def _ensure_directory(directory):
+        try:
+            os.makedirs(directory, 0o755)
+        except OSError as error:
+            if error.errno not in (errno.EEXIST,):
+                raise
+        if not os.path.isdir(directory):
+            raise RuntimeError("%s is not a directory" % directory)
+
+    @staticmethod
+    def _unlink(path):
+        try:
+            os.unlink(path)
+        except OSError as error:
+            if error.errno not in (errno.ENOENT,):
+                raise
+
+    def _read_ldap_uri(self):
+        parser = RawConfigParser()
+        if not parser.read(paths.IPA_DEFAULT_CONF):
+            raise RuntimeError("Unable to read %s" % paths.IPA_DEFAULT_CONF)
+        if not parser.has_section("global"):
+            raise RuntimeError(
+                "Missing global section in %s" % paths.IPA_DEFAULT_CONF
+            )
+        if not parser.has_option("global", "ldap_uri"):
+            raise RuntimeError(
+                "Missing ldap_uri in %s" % paths.IPA_DEFAULT_CONF
+            )
+        ldap_uri = parser.get("global", "ldap_uri").strip()
+        if not ldap_uri or any(char.isspace() for char in ldap_uri):
+            raise RuntimeError(
+                "Invalid ldap_uri in %s" % paths.IPA_DEFAULT_CONF
+            )
+        return ldap_uri
+
+    def _write_inetd_config(self):
+        self._ensure_directory(os.path.dirname(paths.IPA_OTPD_INETD_CONF))
+        self._ensure_directory(paths.IPA_OTPD_SOCKET_DIR)
+        ldap_uri = self._read_ldap_uri()
+        socket_spec = ":root:wheel:600:%s" % paths.IPA_OTPD_SOCKET
+        config_line = (
+            "%s\tstream\tunix\tnowait\troot\t%s\tipa-otpd-wrapper %s\n"
+            % (socket_spec, paths.IPA_OTPD_WRAPPER, ldap_uri)
+        )
+        temporary = paths.IPA_OTPD_INETD_CONF + ".tmp"
+        with open(temporary, "w") as config:
+            config.write(config_line)
+            config.flush()
+            os.fsync(config.fileno())
+        os.chmod(temporary, 0o600)
+        os.rename(temporary, paths.IPA_OTPD_INETD_CONF)
+
+    @staticmethod
+    def _read_pid_file():
+        try:
+            with open(paths.IPA_OTPD_INETD_PID, "r") as pid_file:
+                pid = int(pid_file.read().strip())
+        except (OSError, ValueError):
+            return None
+        if pid <= 1:
+            return None
+        return pid
+
+    @staticmethod
+    def _command_matches(command):
+        required = (
+            paths.SBIN_INETD,
+            paths.IPA_OTPD_INETD_PID,
+            paths.IPA_OTPD_INETD_CONF,
+        )
+        return all(value in command for value in required)
+
+    def _pid_command(self, pid):
+        result = ipautil.run(
+            [paths.BIN_PS, "-ww", "-p", str(pid), "-o", "command="],
+            capture_output=True,
+            raiseonerr=False
+        )
+        if result.returncode:
+            return ""
+        return result.output.strip()
+
+    def _find_pid(self):
+        pid = self._read_pid_file()
+        if pid is not None and self._command_matches(self._pid_command(pid)):
+            return pid
+
+        result = ipautil.run(
+            [paths.BIN_PS, "-axww", "-o", "pid=", "-o", "command="],
+            capture_output=True,
+            raiseonerr=False
+        )
+        if result.returncode:
+            return None
+
+        for line in result.output.splitlines():
+            fields = line.strip().split(None, 1)
+            if len(fields) < 2:
+                continue
+            try:
+                candidate = int(fields[0])
+            except ValueError:
+                continue
+            if self._command_matches(fields[1]):
+                return candidate
+        return None
+
+    @staticmethod
+    def _wait_until(predicate, timeout):
+        deadline = time.monotonic() + timeout
+        while time.monotonic() < deadline:
+            if predicate():
+                return True
+            time.sleep(0.1)
+        return predicate()
+
+    def _cleanup_runtime(self):
+        self._unlink(paths.IPA_OTPD_SOCKET)
+        self._unlink(paths.IPA_OTPD_INETD_PID)
+        self._unlink(paths.IPA_OTPD_INETD_CONF)
+
+    def _stop_private(self):
+        pid = self._find_pid()
+        if pid is not None:
+            try:
+                os.kill(pid, signal.SIGTERM)
+            except OSError as error:
+                if error.errno not in (errno.ESRCH,):
+                    raise
+            stopped = self._wait_until(
+                lambda: self._find_pid() is None,
+                self._STOP_TIMEOUT
+            )
+            if not stopped:
+                raise RuntimeError("Unable to stop private ipa-otpd inetd")
+        self._cleanup_runtime()
+
+    def _start_private(self, capture_output=True):
+        if self.is_running(wait=False):
+            return
+        if self._find_pid() is not None:
+            self._stop_private()
+        else:
+            self._cleanup_runtime()
+        self._write_inetd_config()
+        ipautil.run(
+            [
+                paths.SBIN_INETD,
+                "-p",
+                paths.IPA_OTPD_INETD_PID,
+                paths.IPA_OTPD_INETD_CONF,
+            ],
+            skip_output=not capture_output
+        )
+        started = self._wait_until(
+            lambda: self.is_running(wait=False),
+            self._START_TIMEOUT
+        )
+        if not started:
+            self._stop_private()
+            raise RuntimeError("Unable to start private ipa-otpd inetd")
+
+    def start(self, instance_name="", capture_output=True, wait=True):
+        self._start_private(capture_output=capture_output)
+        base_services.PlatformService.start(
+            self, instance_name, capture_output=capture_output, wait=wait
+        )
+
+    def stop(self, instance_name="", capture_output=True):
+        self._stop_private()
+        base_services.PlatformService.stop(
+            self, instance_name, capture_output=capture_output
+        )
+
+    def restart(self, instance_name="", capture_output=True, wait=True):
+        self._stop_private()
+        self._start_private(capture_output=capture_output)
+
+    def try_restart(self, instance_name="", capture_output=True, wait=True):
+        if self._find_pid() is not None:
+            self.restart(
+                instance_name, capture_output=capture_output, wait=wait
+            )
+
+    def reload_or_restart(self, instance_name="", capture_output=True,
+                          wait=True):
+        self.restart(
+            instance_name, capture_output=capture_output, wait=wait
+        )
+
+    def is_running(self, instance_name="", wait=True):
+        if self._find_pid() is None:
+            return False
+        try:
+            socket_status = os.stat(paths.IPA_OTPD_SOCKET)
+        except OSError:
+            return False
+        return stat.S_ISSOCK(socket_status.st_mode)
+
+    def is_installed(self):
+        return all(os.path.isfile(path) for path in (
+            paths.SBIN_INETD,
+            paths.IPA_OTPD,
+            paths.IPA_OTPD_WRAPPER,
+        ))
+
+    def enable(self, instance_name=""):
+        pass
+
+    def disable(self, instance_name=""):
+        pass
+
+    def is_enabled(self, instance_name=""):
+        return False
+
+    def install(self, instance_name=""):
+        pass
+
+    def remove(self, instance_name=""):
+        pass
+
+
+class FreeBSDDirectoryService(FreeBSDService):
+    def _instance_name(self, instance_name):
+        if instance_name:
+            return instance_name
+        realm = getattr(self.api.env, "realm", "")
+        if realm:
+            return realm.replace(".", "-")
+        return ""
+
+    def _run_dsctl(self, instance_name, action, capture_output=True):
+        instance_name = self._instance_name(instance_name)
+        if not instance_name:
+            raise ValueError("Directory Server instance name is required")
+        # ns-slapd drops privileges in-process (root -> dirsrv), which makes
+        # MIT krb5 ignore KRB5_KTNAME from the environment (secure mode).
+        # Pass the DS keytab explicitly so ns-slapd's GSSAPI acceptor uses
+        # it (389-ds registers it via krb5_gss_register_acceptor_identity)
+        # instead of the unreadable default keytab.
+        env = dict(os.environ)
+        env["KRB5_KTNAME"] = paths.DS_KEYTAB
+        ipautil.run(
+            [paths.DSCTL, instance_name, action],
+            skip_output=not capture_output,
+            env=env
+        )
+        return instance_name
+
+    def _wait_until_running(self, instance_name, wait, ldapi):
+        if not wait:
+            return
+        if ldapi:
+            socket_name = paths.SLAPD_INSTANCE_SOCKET_TEMPLATE % instance_name
+            ipautil.wait_for_open_socket(
+                socket_name, self.api.env.startup_timeout
+            )
+        elif not self.is_running(instance_name, wait=False):
+            raise RuntimeError(
+                "Directory Server instance %s is not running" % instance_name
+            )
+
+    def start(self, instance_name="", capture_output=True, wait=True,
+              ldapi=False):
+        instance_name = self._instance_name(instance_name)
+        if not self.is_running(instance_name, wait=False):
+            self._run_dsctl(instance_name, "start", capture_output)
+        self._wait_until_running(instance_name, wait, ldapi)
+        base_services.PlatformService.start(
+            self, instance_name, capture_output=capture_output, wait=wait
+        )
+
+    def stop(self, instance_name="", capture_output=True):
+        instance_name = self._instance_name(instance_name)
+        if self.is_running(instance_name, wait=False):
+            self._run_dsctl(instance_name, "stop", capture_output)
+        base_services.PlatformService.stop(
+            self, instance_name, capture_output=capture_output
+        )
+
+    def restart(self, instance_name="", capture_output=True, wait=True,
+                ldapi=False):
+        instance_name = self._run_dsctl(
+            instance_name, "restart", capture_output
+        )
+        self._wait_until_running(instance_name, wait, ldapi)
+
+    def try_restart(self, instance_name="", capture_output=True, wait=True):
+        instance_name = self._instance_name(instance_name)
+        if self.is_running(instance_name, wait=False):
+            self.restart(
+                instance_name, capture_output=capture_output, wait=wait
+            )
+
+    def is_running(self, instance_name="", wait=True):
+        instance_name = self._instance_name(instance_name)
+        if not instance_name:
+            return False
+        result = ipautil.run(
+            [paths.DSCTL, "--json", instance_name, "status"],
+            capture_output=True,
+            raiseonerr=False
+        )
+        if result.returncode != 0:
+            return False
+        try:
+            status = json.loads(result.output)
+        except (TypeError, ValueError):
+            return False
+        return isinstance(status, dict) and status.get("running") is True
+
+    def is_installed(self, instance_name=""):
+        instance_name = self._instance_name(instance_name)
+        if not instance_name:
+            return False
+        instance_path = paths.ETC_DIRSRV_SLAPD_INSTANCE_TEMPLATE % instance_name
+        return os.path.isdir(instance_path)
+
+
+def freebsd_service_class_factory(name, api=None):
+    if name == "dirsrv":
+        return FreeBSDDirectoryService(name, api)
+    if name == "ipa-otpd":
+        return FreeBSDOtpdService(name, api)
+    return FreeBSDService(name, api)
+
+
+class FreeBSDServices(base_services.KnownServices):
+    def __init__(self):
+        import ipalib
+
+        services = dict()
+        for service_name in base_services.wellknownservices:
+            services[service_name] = self.service_class_factory(
+                service_name, ipalib.api
+            )
+
+        super(FreeBSDServices, self).__init__(services)
+
+    def service_class_factory(self, name, api=None):
+        return freebsd_service_class_factory(name, api)
+
+
+timedate_services = base_services.timedate_services
+
+service = freebsd_service_class_factory
+knownservices = FreeBSDServices()
