--- ipaserver/install/krbinstance.py.orig	2026-01-16 09:23:37 UTC
+++ ipaserver/install/krbinstance.py
@@ -273,6 +273,9 @@ class KrbInstance(service.Service):
     def __setup_sub_dict(self):
         if not os.path.exists(paths.COMMON_KRB5_CONF_DIR):
             os.mkdir(paths.COMMON_KRB5_CONF_DIR, 0o755)
+        # mkdir() honors umask; force world-readable so the krb5
+        # profile includedir stays readable for ns-slapd (dirsrv) et al.
+        os.chmod(paths.COMMON_KRB5_CONF_DIR, 0o755)
         includes = 'includedir {}'.format(paths.COMMON_KRB5_CONF_DIR)
 
         fips_enabled = tasks.is_fips_enabled()
@@ -363,7 +366,7 @@ class KrbInstance(service.Service):
         installutils.check_entropy()
 
         #populate the directory with the realm structure
-        args = ["kdb5_util", "create", "-s",
+        args = [paths.KDB5_UTIL, "create", "-s",
                                        "-r", self.realm,
                                        "-x", "ipa-setup-override-restrictions"]
         dialogue = (
@@ -402,9 +405,10 @@ class KrbInstance(service.Service):
         appendvars = {}
         if workers and cpus > 1:
             appendvars = {'KRB5KDC_ARGS': "'-w %s'" % str(cpus)}
-        ipautil.backup_config_and_replace_variables(self.fstore, paths.SYSCONFIG_KRB5KDC_DIR,
-                                                    replacevars=replacevars,
-                                                    appendvars=appendvars)
+        if os.path.exists(paths.SYSCONFIG_KRB5KDC_DIR):
+            ipautil.backup_config_and_replace_variables(self.fstore, paths.SYSCONFIG_KRB5KDC_DIR,
+                                                        replacevars=replacevars,
+                                                        appendvars=appendvars)
         tasks.restore_context(paths.SYSCONFIG_KRB5KDC_DIR)
 
     #add the password extop module
