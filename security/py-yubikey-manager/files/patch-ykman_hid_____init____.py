See https://github.com/Yubico/yubikey-manager/commit/ecd7897b3f02054
--- ykman/hid/__init__.py.orig	2022-05-27 13:02:44 UTC
+++ ykman/hid/__init__.py
@@ -41,6 +41,8 @@ elif sys.platform.startswith("win32"):
     from . import windows as backend
 elif sys.platform.startswith("darwin"):
     from . import macos as backend
+elif sys.platform.startswith("freebsd"):
+    from . import freebsd as backend
 else:
 
     class backend:
