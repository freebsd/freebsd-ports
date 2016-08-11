--- txdav/base/propertystore/xattr.py.orig	2016-01-07 15:18:44 UTC
+++ txdav/base/propertystore/xattr.py
@@ -47,10 +47,14 @@ from txdav.idav import PropertyStoreErro
 # expose.  Its value is 93.
 #
 
-if sys.platform in ("darwin", "freebsd8", "freebsd9"):
-    _ERRNO_NO_ATTR = getattr(errno, "ENOATTR", 93)
-else:
+_ERRNO_NO_ATTR = 0
+try:
     _ERRNO_NO_ATTR = errno.ENODATA
+except AttributeError:
+    if sys.platform[:6] == 'darwin' or sys.platform[:7] == 'freebsd':
+        _ERRNO_NO_ATTR = getattr(errno, "ENOATTR", 93)
+    else:
+        raise
 
 
 
