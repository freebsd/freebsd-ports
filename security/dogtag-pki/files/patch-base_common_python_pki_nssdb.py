--- base/common/python/pki/nssdb.py.orig	2025-08-05 19:20:05 UTC
+++ base/common/python/pki/nssdb.py
@@ -312,14 +312,14 @@ class NSSDatabase(object):
 
         logger.debug('Command: %s', ' '.join(cmd))
 
+        subprocess_kwargs = {}
+
         if runas and self.user is not None:
-            runuser = [
-                'runuser',
-                '-u',
-                self.user,
-                '--',
-            ]
-            cmd = runuser + cmd
+            subprocess_kwargs.update({
+                'user': self.uid,
+                'group': self.gid,
+                'extra_groups': os.getgrouplist(self.user, self.gid)
+            })
 
         if capture_output:
             stdout = subprocess.PIPE
@@ -335,7 +335,8 @@ class NSSDatabase(object):
             stdout=stdout,
             stderr=stderr,
             check=check,
-            universal_newlines=text)
+            universal_newlines=text,
+            **subprocess_kwargs)
 
         if capture_output:
             logger.debug('stdout:\n%s', result.stdout.decode('utf-8'))
