--- lib389/instance/setup.py.orig	2026-04-30 12:45:04 UTC
+++ lib389/instance/setup.py
@@ -826,10 +826,10 @@ class SetupDs(object):
         # which subsequently breaks containers starting as instance.start then believes
         # it COULD check the ds status. The times we need to check for systemd are mainly
         # in other environments that use systemd natively in their containers.
-        container_result = 1
-        if not self.containerised:
+        container_result = None
+        if not self.containerised and shutil.which("systemd-detect-virt"):
             container_result = subprocess.run(["systemd-detect-virt", "-c"], stdout=subprocess.PIPE)
-        if self.containerised or container_result.returncode == 0:
+        if self.containerised or (container_result is not None and container_result.returncode == 0):
             # In a container, set the db_home_dir to the db path
             self.log.debug("Container detected setting db home directory to db directory.")
             slapd['db_home_dir'] = slapd['db_dir']
@@ -962,14 +962,10 @@ class SetupDs(object):
         if self.containerised:
             ds_instance.systemd_override = general['systemd']
 
-        # By default SUSE does something extremely silly - it creates a hostname
-        # that CANT be resolved by DNS. As a result this causes all installs to
-        # fail. We need to guarantee that we only connect to localhost here, as
-        # it's the only stable and guaranteed way to connect to the instance
-        # at this point.
-        #
-        # Use ldapi which would prevent the need
-        # to configure a temp root pw in the setup phase.
+        # Use a local LDAP connection for the temporary authenticated setup session.
+        # FreeBSD's OpenLDAP client stack rejects SASL EXTERNAL over LDAPI here,
+        # while the generated temporary Directory Manager password provides the
+        # required authenticated connection over localhost LDAP.
         args = {
             SER_HOST: "localhost",
             SER_PORT: slapd['port'],
@@ -977,9 +973,9 @@ class SetupDs(object):
             SER_ROOT_DN: slapd['root_dn'],
             SER_ROOT_PW: self._raw_secure_password,
             SER_DEPLOYED_DIR: slapd['prefix'],
-            SER_LDAPI_ENABLED: 'on',
+            SER_LDAPI_ENABLED: 'off',
             SER_LDAPI_SOCKET: slapd['ldapi'],
-            SER_LDAPI_AUTOBIND: 'on'
+            SER_LDAPI_AUTOBIND: 'off'
         }
 
         ds_instance.allocate(args)
