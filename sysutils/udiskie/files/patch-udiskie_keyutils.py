--- udiskie/keyutils.py.orig	2026-09-29 16:06:47 UTC
+++ udiskie/keyutils.py
@@ -52,11 +52,17 @@ class KeyRejected(KeyutilsError):
     pass
 
 
+# The key error codes are Linux-specific; skip the ones the platform lacks
+# so that a missing keyutils library surfaces as ImportError below.
 _errno_map = {
-    errno.ENOKEY: KeyNotAvailable,
-    errno.EKEYEXPIRED: KeyExpired,
-    errno.EKEYREVOKED: KeyRevoked,
-    errno.EKEYREJECTED: KeyRejected,
+    getattr(errno, name): exc_type
+    for name, exc_type in (
+        ('ENOKEY', KeyNotAvailable),
+        ('EKEYEXPIRED', KeyExpired),
+        ('EKEYREVOKED', KeyRevoked),
+        ('EKEYREJECTED', KeyRejected),
+    )
+    if hasattr(errno, name)
 }
 
 
