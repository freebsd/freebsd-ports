--- base/server/python/pki/server/deployment/pkihelper.py.orig	2026-07-04 19:39:15 UTC
+++ base/server/python/pki/server/deployment/pkihelper.py
@@ -44,9 +44,12 @@ import pki.util
 import pki.util

 # special care for SELinux
-import selinux
+try:
+    import selinux
+except ImportError:
+    selinux = None
 seobject = None
-if selinux.is_selinux_enabled():
+if selinux is not None and selinux.is_selinux_enabled():
     try:
         import seobject
     except ImportError:
