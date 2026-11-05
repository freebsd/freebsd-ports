--- ASTK_SERV/asrun/common/sysutils.py.orig	2026-10-24 14:49:35 UTC
+++ ASTK_SERV/asrun/common/sysutils.py
@@ -88,6 +88,10 @@ def on_mac():
     """Tell if it's running on a mac platform"""
     return sys.platform in ("darwin",)
 
+def on_freebsd():
+    """Tell if it's running on a FreeBSD platform"""
+    return sys.platform.startswith("freebsd")
+
 def on_linux():
     """Tell if it's running on a linux platform"""
     return not on_windows()
