--- base/server/python/pki/server/__init__.py.orig	2026-07-28 16:37:15 UTC
+++ base/server/python/pki/server/__init__.py
@@ -33,7 +33,10 @@ import requests
 import pwd
 import re
 import requests
-import selinux
+try:
+    import selinux
+except ImportError:
+    selinux = None
 import shutil
 import socket
 import subprocess
@@ -55,7 +58,7 @@ seobject = None
 import pki.server.subsystem
 
 seobject = None
-if selinux.is_selinux_enabled():
+if selinux is not None and selinux.is_selinux_enabled():
     try:
         import seobject
     except ImportError:
@@ -64,9 +67,9 @@ if selinux.is_selinux_enabled():
         if sys.version_info.major == 2:
             raise
 
-SYSCONFIG_DIR = '/etc/sysconfig'
-ETC_SYSTEMD_DIR = '/etc/systemd'
-LIB_SYSTEMD_DIR = '/lib/systemd'
+SYSCONFIG_DIR = '/usr/local/etc'
+RC_CONF_DIR = '/etc/rc.conf.d'
+RC_DIR = '/usr/local/etc/rc.d'
 FAPOLICY_RULES_PATH = '/etc/fapolicyd/rules.d'
 
 
@@ -77,7 +80,7 @@ SCHEMA_FILES = [
 DEFAULT_LINK_MODE = 0o0777
 
 SCHEMA_FILES = [
-    '/usr/share/pki/server/database/ds/schema.ldif'
+    '/usr/local/share/pki/server/database/ds/schema.ldif'
 ]
 
 DEFAULT_INSTANCE_NAME = 'pki-tomcat'
@@ -100,15 +103,15 @@ class Tomcat(object):
 
 class Tomcat(object):
 
-    BASE_DIR = '/var/lib/tomcats'
-    CONF_DIR = '/etc/tomcat'
-    LIB_DIR = '/usr/share/java/tomcat'
-    SHARE_DIR = '/usr/share/tomcat'
+    BASE_DIR = '/var/db/tomcats'
+    CONF_DIR = '/usr/local/apache-tomcat-9.0/conf'
+    LIB_DIR = '/usr/local/apache-tomcat-9.0/lib'
+    SHARE_DIR = '/usr/local/apache-tomcat-9.0'
     OLD_EXECUTABLE = '/usr/sbin/tomcat'
-    EXECUTABLE = '/usr/share/tomcat/bin/catalina.sh'
-    UNIT_FILE = '/lib/systemd/system/tomcat@.service'
+    EXECUTABLE = '/usr/local/apache-tomcat-9.0/bin/catalina.sh'
+    UNIT_FILE = '/usr/local/etc/rc.d/tomcat9'
     SERVER_XML = CONF_DIR + '/server.xml'
-    TOMCAT_CONF = CONF_DIR + '/tomcat.conf'
+    TOMCAT_CONF = '/usr/local/share/pki/etc/tomcat.conf'
 
     @classmethod
     def get_version(cls):
@@ -140,10 +143,10 @@ class PKIServer(object):
 @functools.total_ordering
 class PKIServer(object):
 
-    BASE_DIR = '/var/lib/pki'
-    CONFIG_DIR = '/etc/pki'
+    BASE_DIR = '/var/db/pki'
+    CONFIG_DIR = '/usr/local/etc/pki'
     LOG_DIR = '/var/log/pki'
-    SHARE_DIR = '/usr/share/pki'
+    SHARE_DIR = '/usr/local/share/pki'
     REGISTRY_DIR = SYSCONFIG_DIR + '/pki'
     TOMCAT_CONF = SHARE_DIR + '/etc/tomcat.conf'
 
@@ -158,11 +161,11 @@ class PKIServer(object):
         self.user = user
         self.group = group
 
-        # The standard conf dir at /var/lib/pki/<instance>/conf
+        # The standard conf dir at /var/db/pki/<instance>/conf
         # will be an actual folder (i.e. not a link).
         self._conf_dir = None
 
-        # The standard logs dir at /var/lib/pki/<instance>/logs
+        # The standard logs dir at /var/db/pki/<instance>/logs
         # will be an actual folder (i.e. not a link).
         self._logs_dir = None
 
@@ -279,9 +282,100 @@ class PKIServer(object):
         return '%s@%s' % (self.type, self.name)
 
     @property
+    def rc_service_name(self):
+        return ''.join(
+            char if char.isalnum() or char == '_' else '_'
+            for char in self.service_name)
+
+    @property
+    def rc_script(self):
+        return os.path.join(RC_DIR, self.rc_service_name)
+
+    @property
     def service_conf(self):
-        return os.path.join(SYSCONFIG_DIR, self.service_name)
+        return os.path.join(RC_CONF_DIR, self.rc_service_name)
 
+    def create_rc_service(self, exist_ok=False):
+        os.makedirs(RC_CONF_DIR, mode=0o755, exist_ok=True)
+
+        if not os.path.exists(self.service_conf) or not exist_ok:
+            prefix = self.rc_service_name
+            java_home = os.environ["JAVA_HOME"]
+
+            with open(self.service_conf, "w", encoding="utf-8") as f:
+                print("%s_enable=\"YES\"" % prefix, file=f)
+                print("%s_catalina_home=\"%s\"" % (prefix, Tomcat.SHARE_DIR), file=f)
+                print("%s_catalina_base=\"%s\"" % (prefix, self.base_dir), file=f)
+                print("%s_catalina_user=\"%s\"" % (prefix, self.user), file=f)
+                print("%s_java_home=\"%s\"" % (prefix, java_home), file=f)
+                tomcat_config = {}
+                pki.util.load_properties(self.tomcat_conf, tomcat_config)
+                java_opts = tomcat_config.get("JAVA_OPTS", "").strip(chr(34))
+                pki_version = tomcat_config.get("PKI_VERSION", "").strip(chr(34))
+                print('%s_java_opts="%s"' % (prefix, java_opts), file=f)
+                print('%s_env="PKI_VERSION=%s"' % (prefix, pki_version), file=f)
+
+                # rc(8) waits forever for the pid from the pidfile, and
+                # jsvc records the pid of its *child* there while the
+                # parent is the process that reacts to SIGTERM.  Tomcat
+                # can also deadlock inside JSS while closing the LDAP
+                # connections of the ACME realm.  Either way the system
+                # shutdown would stall indefinitely, so signal both
+                # processes and fall back to SIGKILL after a grace period.
+                print('%s_stop_timeout="60"' % prefix, file=f)
+                print('%s_stop()' % prefix, file=f)
+                print('{', file=f)
+                print('\t_pidfile="/var/run/%s.pid"' % prefix, file=f)
+                print('\t_pid=$(cat "${_pidfile}" 2>/dev/null)', file=f)
+                print('\tif [ -z "${_pid}" ]; then', file=f)
+                print('\t\techo "%s not running?"' % prefix, file=f)
+                print('\t\treturn 0', file=f)
+                print('\tfi', file=f)
+                print('\t_ppid=$(ps -o ppid= -p "${_pid}" 2>/dev/null | '
+                      'tr -d " ")', file=f)
+                print('\techo "Stopping %s."' % prefix, file=f)
+                print('\tkill -TERM ${_ppid} ${_pid} 2>/dev/null', file=f)
+                print('\t_waited=0', file=f)
+                print('\twhile kill -0 "${_pid}" 2>/dev/null; do', file=f)
+                print('\t\t[ ${_waited} -ge ${%s_stop_timeout} ] && break'
+                      % prefix, file=f)
+                print('\t\tsleep 1', file=f)
+                print('\t\t_waited=$((_waited + 1))', file=f)
+                print('\tdone', file=f)
+                print('\tif kill -0 "${_pid}" 2>/dev/null; then', file=f)
+                print('\t\techo "%s did not stop, killing it."' % prefix,
+                      file=f)
+                print('\t\tkill -KILL ${_ppid} ${_pid} 2>/dev/null', file=f)
+                print('\t\tsleep 1', file=f)
+                print('\tfi', file=f)
+                print('\trm -f "${_pidfile}"', file=f)
+                print('}', file=f)
+                print('stop_cmd="%s_stop"' % prefix, file=f)
+
+            os.chmod(self.service_conf, 0o644)
+
+        if os.path.lexists(self.rc_script):
+            if exist_ok:
+                return
+            raise FileExistsError(self.rc_script)
+
+        os.symlink(os.path.join(RC_DIR, "tomcat9"), self.rc_script)
+
+    def remove_rc_service(self, force=False):
+        logger.info("Removing %s", self.rc_script)
+        pki.util.unlink(self.rc_script, force=force)
+
+        logger.info("Removing %s", self.service_conf)
+        pki.util.remove(self.service_conf, force=force)
+
+        rcvar = "%s_enable" % self.rc_service_name
+        logger.info("Removing %s from rc.conf", rcvar)
+        subprocess.run(
+            ["/usr/sbin/sysrc", "-x", rcvar],
+            stdout=subprocess.DEVNULL,
+            stderr=subprocess.DEVNULL,
+            check=False)
+
     @property
     def uid(self):
         return pwd.getpwnam(self.user).pw_uid
@@ -335,7 +429,7 @@ class PKIServer(object):
             raise pki.PKIException('Invalid instance: ' + self.name, None)
 
     def is_active(self):
-        cmd = ['systemctl', '--quiet', 'is-active', '%s.service' % self.service_name]
+        cmd = ['/usr/sbin/service', self.rc_service_name, 'onestatus']
         logger.debug('Command: %s', ' '.join(cmd))
         rc = subprocess.call(cmd)
         return rc == 0
@@ -415,14 +509,14 @@ class PKIServer(object):
         logger.info('Creating catalina.policy')
 
         # add "do not edit" warning
-        filename = '/usr/share/pki/server/conf/catalina.policy'
+        filename = '/usr/local/share/pki/server/conf/catalina.policy'
         logger.info('Appending %s', filename)
         with open(filename, 'r', encoding='utf-8') as f:
             content = f.read()
 
         # add Tomcat's default policy
-        filename = '/usr/share/tomcat/conf/catalina.policy'
-        new_filename = '/etc/tomcat/catalina.policy'
+        filename = Tomcat.SHARE_DIR + '/conf/catalina.policy'
+        new_filename = Tomcat.CONF_DIR + '/catalina.policy'
 
         if os.path.exists(filename):
             logger.debug('Using original filename')
@@ -438,7 +532,7 @@ class PKIServer(object):
         content += '\n\n'
 
         # add PKI's default policy
-        filename = '/usr/share/pki/server/conf/pki.policy'
+        filename = '/usr/local/share/pki/server/conf/pki.policy'
         logger.info('Appending %s', filename)
         with open(filename, 'r', encoding='utf-8') as f:
             content += f.read()
@@ -512,7 +606,7 @@ grant codeBase "file:%s" {
 
     def start(self, wait=False, max_wait=60, timeout=None):
 
-        cmd = ['systemctl', 'start', '%s.service' % self.service_name]
+        cmd = ['/usr/sbin/service', self.rc_service_name, 'onestart']
         logger.debug('Command: %s', ' '.join(cmd))
         subprocess.check_call(cmd)
 
@@ -552,9 +646,24 @@ grant codeBase "file:%s" {
 
     def stop(self, wait=False, max_wait=60, timeout=None):
 
-        cmd = ['systemctl', 'stop', '%s.service' % self.service_name]
+        if not self.is_active():
+            logger.info("PKI server already stopped")
+            return
+
+        cmd = ['/usr/sbin/service', self.rc_service_name, 'onestop']
         logger.debug('Command: %s', ' '.join(cmd))
-        subprocess.check_call(cmd)
+        # rc onestop relies on rc.subr wait_for_pids(), which blocks
+        # forever when the jsvc/JVM does not exit (e.g. a wedged webapp
+        # during pkidestroy). Bound it and fall back to SIGKILL so the
+        # caller never hangs indefinitely.
+        stop_timeout = timeout or max_wait
+        try:
+            subprocess.check_call(cmd, timeout=stop_timeout)
+        except subprocess.TimeoutExpired:
+            logger.warning(
+                '%s did not stop within %ss; sending SIGKILL',
+                self.rc_service_name, stop_timeout)
+            subprocess.call(['/bin/pkill', '-KILL', '-f', self.rc_service_name])
 
         if not wait:
             return
@@ -598,12 +707,17 @@ grant codeBase "file:%s" {
         self.start(wait=wait, max_wait=max_wait, timeout=timeout)
 
     def enable(self):
-        cmd = ['systemctl', 'enable', '%s.service' % self.service_name]
+        cmd = ['/usr/sbin/service', self.rc_service_name, 'enable']
         logger.debug('Command: %s', ' '.join(cmd))
         subprocess.check_call(cmd)
 
     def disable(self):
-        cmd = ['systemctl', 'disable', '%s.service' % self.service_name]
+
+        if not os.path.exists(self.rc_script):
+            logger.info("PKI server already disabled")
+            return
+
+        cmd = ['/usr/sbin/service', self.rc_service_name, 'disable']
         logger.debug('Command: %s', ' '.join(cmd))
         subprocess.check_call(cmd)
 
@@ -643,7 +757,7 @@ grant codeBase "file:%s" {
         for name in self.config:
             logger.debug('- %s: %s', name, self.config[name])
 
-        prefix = []
+        subprocess_kwargs = {}
 
         # by default run PKI server as systemd user
         if not as_current_user:
@@ -652,7 +766,11 @@ grant codeBase "file:%s" {
 
             # switch to systemd user if different from current user
             if current_user != self.user:
-                prefix.extend(['runuser', '-u', self.user, '--'])
+                subprocess_kwargs.update({
+                    'user': self.user,
+                    'group': self.group,
+                    'extra_groups': os.getgrouplist(self.user, self.gid)
+                })
 
         java_home = self.config.get('JAVA_HOME')
         java_opts = self.config.get('JAVA_OPTS')
@@ -661,12 +779,12 @@ grant codeBase "file:%s" {
         classpath = [
             Tomcat.SHARE_DIR + '/bin/bootstrap.jar',
             Tomcat.SHARE_DIR + '/bin/tomcat-juli.jar',
-            '/usr/share/java/ant.jar',
-            '/usr/share/java/ant-launcher.jar',
+            '/usr/local/share/java/apache-ant/lib/ant.jar',
+            '/usr/local/share/java/apache-ant/lib/ant-launcher.jar',
             '/usr/lib/jvm/java/lib/tools.jar'
         ]
 
-        cmd = prefix
+        cmd = []
 
         if with_valgrind:
             cmd.extend(['valgrind', '--trace-children=yes', '--tool=massif'])
@@ -680,7 +798,7 @@ grant codeBase "file:%s" {
         else:
             cmd.extend([java_home + '/bin/java'])
 
-            # add JVM options as in /etc/tomcat/conf.d/java-9-start-up-parameters.conf
+            # add JVM options as in /usr/local/apache-tomcat-9.0/conf/conf.d/java-9-start-up-parameters.conf
             cmd.extend([
                 '--add-opens', 'java.base/java.lang=ALL-UNNAMED',
                 '--add-opens', 'java.base/java.io=ALL-UNNAMED',
@@ -723,7 +841,7 @@ grant codeBase "file:%s" {
 
         logger.debug('Command: %s', ' '.join(cmd))
 
-        return subprocess.Popen(cmd, env=self.config)
+        return subprocess.Popen(cmd, env=self.config, **subprocess_kwargs)
 
     def chown(self, path):
 
@@ -850,8 +968,8 @@ grant codeBase "file:%s" {
         self.create_logging_properties(exist_ok=True)
         self.create_web_xml(exist_ok=True)
 
-        # copy /etc/tomcat/tomcat.conf
-        # to /var/lib/pki/<instance>/conf/tomcat.conf
+        # copy /usr/local/apache-tomcat-9.0/conf/tomcat.conf
+        # to /var/db/pki/<instance>/conf/tomcat.conf
         self.copy(
             Tomcat.TOMCAT_CONF,
             self.tomcat_conf,
@@ -861,7 +979,7 @@ grant codeBase "file:%s" {
         tomcat_conf = pki.PropertyFile(self.tomcat_conf, quote='"')
         tomcat_conf.read()
 
-        # store JAVA_HOME from /usr/share/pki/etc/pki.conf
+        # store JAVA_HOME from /usr/local/share/pki/etc/pki.conf
         java_home = os.getenv('JAVA_HOME')
         tomcat_conf.set('JAVA_HOME', java_home)
 
@@ -873,27 +991,21 @@ grant codeBase "file:%s" {
 
         tomcat_conf.write()
 
-        # copy /var/lib/pki/<instance>/conf/tomcat.conf
-        # to /etc/sysconfig/<type>@<instance>
-        self.copy(
-            self.tomcat_conf,
-            self.service_conf,
-            exist_ok=True,
-            force=force)
+        self.create_rc_service(exist_ok=True)
 
     def create_conf_dir(self, exist_ok=False):
 
         if self._conf_dir:
 
-            # Create /etc/pki/<instance>
+            # Create /usr/local/etc/pki/<instance>
             self.makedirs(self._conf_dir, exist_ok=exist_ok)
 
-            # Link /var/lib/pki/<instance>/conf to /etc/pki/<instance>
+            # Link /var/db/pki/<instance>/conf to /usr/local/etc/pki/<instance>
             self.symlink(self._conf_dir, self.conf_dir, exist_ok=exist_ok)
 
             return
 
-        # Create /var/lib/pki/<instance>/conf
+        # Create /var/db/pki/<instance>/conf
         self.makedirs(self.conf_dir, exist_ok=exist_ok)
 
     def create_logs_dir(self, exist_ok=False):
@@ -907,15 +1019,15 @@ grant codeBase "file:%s" {
             backup_dir = os.path.join(self._logs_dir, 'backup')
             self.makedirs(backup_dir, exist_ok=exist_ok)
 
-            # Link /var/lib/pki/<instance>/logs to /var/log/pki/<instance>
+            # Link /var/db/pki/<instance>/logs to /var/log/pki/<instance>
             self.symlink(self._logs_dir, self.logs_dir, exist_ok=exist_ok)
 
             return
 
-        # Create /var/lib/pki/<instance>/logs
+        # Create /var/db/pki/<instance>/logs
         self.makedirs(self.logs_dir, exist_ok=exist_ok)
 
-        # Create /var/lib/pki/<instance>/logs/backup
+        # Create /var/db/pki/<instance>/logs/backup
         backup_dir = os.path.join(self.logs_dir, 'backup')
         self.makedirs(backup_dir, exist_ok=exist_ok)
 
@@ -931,8 +1043,8 @@ grant codeBase "file:%s" {
 
     def create_catalina_properties(self, exist_ok=False):
 
-        # Link /var/lib/pki/<instance>/conf/catalina.properties
-        # to /usr/share/pki/server/conf/catalina.properties.
+        # Link /var/db/pki/<instance>/conf/catalina.properties
+        # to /usr/local/share/pki/server/conf/catalina.properties.
 
         catalina_properties = os.path.join(
             PKIServer.SHARE_DIR, 'server', 'conf', 'catalina.properties')
@@ -940,16 +1052,16 @@ grant codeBase "file:%s" {
 
     def create_context_xml(self, exist_ok=False):
 
-        # Link /var/lib/pki/<instance>/conf/context.xml
-        # to /etc/tomcat/context.xml.
+        # Link /var/db/pki/<instance>/conf/context.xml
+        # to /usr/local/apache-tomcat-9.0/conf/context.xml.
 
         context_xml = os.path.join(Tomcat.CONF_DIR, 'context.xml')
         self.symlink(context_xml, self.context_xml, exist_ok=exist_ok)
 
     def create_logging_properties(self, exist_ok=False):
 
-        # Copy /etc/tomcat/logging.properties
-        # to /var/lib/pki/<instance>/conf/logging.properties.
+        # Copy /usr/local/apache-tomcat-9.0/conf/logging.properties
+        # to /var/db/pki/<instance>/conf/logging.properties.
 
         logging_properties = os.path.join(Tomcat.CONF_DIR, 'logging.properties')
         self.copy(
@@ -959,7 +1071,7 @@ grant codeBase "file:%s" {
 
     def create_server_xml(self, exist_ok=False):
 
-        # Copy /etc/tomcat/server.xml to <instance>/conf/server.xml
+        # Copy /usr/local/apache-tomcat-9.0/conf/server.xml to <instance>/conf/server.xml
 
         self.copy(
             pki.server.Tomcat.SERVER_XML,
@@ -1036,7 +1148,7 @@ grant codeBase "file:%s" {
                 self.makedirs(host_dir, exist_ok=exist_ok)
 
                 # Link <instance>/conf/<engine>/<host>/rewrite.config
-                # to /usr/share/pki/server/conf/Catalina/localhost/rewrite.config
+                # to /usr/local/share/pki/server/conf/Catalina/localhost/rewrite.config
 
                 link = os.path.join(host_dir, 'rewrite.config')
                 self.symlink(target, link, exist_ok=exist_ok)
@@ -1045,8 +1157,8 @@ grant codeBase "file:%s" {
 
     def create_web_xml(self, exist_ok=False):
 
-        # Link /var/lib/pki/<instance>/conf/web.xml
-        # to /etc/tomcat/web.xml.
+        # Link /var/db/pki/<instance>/conf/web.xml
+        # to /usr/local/apache-tomcat-9.0/conf/web.xml.
 
         self.symlink(
             os.path.join(Tomcat.CONF_DIR, 'web.xml'),
@@ -1367,8 +1479,7 @@ grant codeBase "file:%s" {
 
     def remove(self, remove_conf=False, remove_logs=False, force=False):
 
-        logger.info('Removing %s', self.service_conf)
-        pki.util.remove(self.service_conf, force=force)
+        self.remove_rc_service(force=force)
 
         logger.info('Removing %s', self.work_dir)
         pki.util.rmtree(self.work_dir, force=force)
@@ -1419,7 +1530,7 @@ grant codeBase "file:%s" {
             # Get the actual folder in case it has changed
             _logs_dir = os.readlink(self.logs_dir)
 
-            # Remove /var/lib/pki/<instance>/logs
+            # Remove /var/db/pki/<instance>/logs
             logger.info('Removing %s', self.logs_dir)
             pki.util.unlink(self.logs_dir, force=force)
 
@@ -1429,7 +1540,7 @@ grant codeBase "file:%s" {
 
             return
 
-        # Remove /var/lib/pki/<instance>/logs
+        # Remove /var/db/pki/<instance>/logs
         logger.info('Removing %s', self.logs_dir)
         pki.util.rmtree(self.logs_dir, force=force)
 
@@ -1440,17 +1551,17 @@ grant codeBase "file:%s" {
             # Get the actual folder in case it has changed
             _conf_dir = os.readlink(self.conf_dir)
 
-            # Remove /var/lib/pki/<instance>/conf
+            # Remove /var/db/pki/<instance>/conf
             logger.info('Removing %s', self.conf_dir)
             pki.util.unlink(self.conf_dir, force=force)
 
-            # Remove /etc/pki/<instance>
+            # Remove /usr/local/etc/pki/<instance>
             logger.info('Removing %s', _conf_dir)
             pki.util.rmtree(_conf_dir, force=force)
 
             return
 
-        # Remove /var/lib/pki/<instance>/conf
+        # Remove /var/db/pki/<instance>/conf
         logger.info('Removing %s', self.conf_dir)
         pki.util.rmtree(self.conf_dir, force=force)
 
@@ -1531,11 +1642,11 @@ grant codeBase "file:%s" {
 
             subsystem_dir = os.path.join(self.base_dir, subsystem_name)
 
-            # ensure /var/lib/pki/<instance>/<subsystem> exists
+            # ensure /var/db/pki/<instance>/<subsystem> exists
             if not os.path.exists(subsystem_dir):
                 continue
 
-            # ensure /var/lib/pki/<instance>/<subsystem> is not empty
+            # ensure /var/db/pki/<instance>/<subsystem> is not empty
             # https://issues.redhat.com/browse/RHEL-21568
             if not os.listdir(subsystem_dir):
                 # Directory exists but it is empty
@@ -1783,6 +1894,8 @@ grant codeBase "file:%s" {
         The restocon API is not working in RHEL
         (see https://issues.redhat.com/browse/RHEL-73348).
 
+        if selinux is None:
+            return
         selinux.restorecon(self.base_dir, True)
         selinux.restorecon(PKIServer.LOG_DIR, True)
         selinux.restorecon(self.actual_logs_dir, True)
@@ -2658,7 +2771,11 @@ class PKIServerFactory(object):
             instance_type = parts[0]
             instance_name = parts[1]
 
-        sysconfig_file = os.path.join('/etc/sysconfig', instance_name)
+        rc_service_name = "".join(
+            char if char.isalnum() or char == "_" else "_"
+            for char in "%s@%s" % (instance_type, instance_name))
+
+        sysconfig_file = os.path.join(RC_CONF_DIR, rc_service_name)
 
         if os.path.isfile(sysconfig_file):
 
