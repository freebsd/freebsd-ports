--- base/common/python/pki/nssdb.py.orig	2026-07-28 16:37:15 UTC
+++ base/common/python/pki/nssdb.py
@@ -312,13 +312,20 @@ class NSSDatabase:
 
         logger.debug('Command: %s', ' '.join(cmd))
 
+        subprocess_kwargs = {}
+
         if runas and self.user is not None:
 
             current_user = pwd.getpwuid(os.getuid()).pw_name
 
             # switch to NSS database owner if different from current user
+            # (FreeBSD has no runuser, use subprocess privilege switching)
             if current_user != self.user:
-                cmd = ['runuser', '-u', self.user, '--'] + cmd
+                subprocess_kwargs.update({
+                    'user': self.uid,
+                    'group': self.gid,
+                    'extra_groups': os.getgrouplist(self.user, self.gid)
+                })
 
         if capture_output:
             stdout = subprocess.PIPE
@@ -334,7 +341,8 @@ class NSSDatabase:
             stdout=stdout,
             stderr=stderr,
             check=check,
-            universal_newlines=text)
+            universal_newlines=text,
+            **subprocess_kwargs)
 
         return result
 
