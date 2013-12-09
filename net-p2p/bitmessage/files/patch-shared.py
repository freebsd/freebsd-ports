--- src/shared.py.orig
+++ src/shared.py
@@ -347,6 +347,11 @@ def checkSensitiveFilePermissions(filename):
         # TODO: This might deserve extra checks by someone familiar with
         # Windows systems.
         return True
+    elif sys.platform[:7] == 'freebsd':
+        # FreeBSD file systems are the same as major Linux file systems
+        present_permissions = os.stat(filename)[0]
+        disallowed_permissions = stat.S_IRWXG | stat.S_IRWXO
+        return present_permissions & disallowed_permissions == 0
     else:
         try:
             # Skip known problems for non-Win32 filesystems without POSIX permissions.
