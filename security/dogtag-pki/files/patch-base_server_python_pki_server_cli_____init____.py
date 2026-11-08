--- base/server/python/pki/server/cli/__init__.py.orig	2026-08-19 19:54:22 UTC
+++ base/server/python/pki/server/cli/__init__.py
@@ -226,6 +226,7 @@ class PKIServerCLI(pki.cli.CLI):
         instance.load()
 
         cmd = []
+        subprocess_kwargs = {}
 
         # by default run the command as PKI user (e.g. pkiuser)
         # unless the current user wants to run it as itself (e.g. root)
@@ -234,8 +235,15 @@ class PKIServerCLI(pki.cli.CLI):
             current_user = pwd.getpwuid(os.getuid()).pw_name
 
             # switch to PKI user if it's different from the current user
+            # (FreeBSD has no runuser, use subprocess privilege switching)
             if current_user != instance.user:
-                cmd.extend(['runuser', '-u', instance.user, '--'])
+                subprocess_kwargs.update({
+                    'user': instance.user,
+                    'group': instance.group,
+                    'extra_groups': os.getgrouplist(
+                        instance.user,
+                        instance.gid)
+                })
 
         java_home = os.getenv('JAVA_HOME')
         cmd.extend([java_home + '/bin/java'])
@@ -306,7 +314,7 @@ class PKIServerCLI(pki.cli.CLI):
         cmd.extend(args)
 
         logger.debug('Java Command: %s', ' '.join(cmd))
-        subprocess.check_call(cmd)
+        subprocess.check_call(cmd, **subprocess_kwargs)
 
     def execute(self, argv, args=None):
 
