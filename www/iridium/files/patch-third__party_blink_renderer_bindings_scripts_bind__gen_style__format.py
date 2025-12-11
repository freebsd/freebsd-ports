--- third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py.orig	2025-12-10 15:04:57 UTC
+++ third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py
@@ -30,7 +30,7 @@ def init(root_src_dir, enable_style_format=True):
 
     # Determine //buildtools/<platform>/ directory
     new_path_platform_suffix = ""
-    if sys.platform.startswith("linux"):
+    if sys.platform.startswith(("linux","openbsd","freebsd")):
         platform = "linux64"
         exe_suffix = ""
     elif sys.platform.startswith("darwin"):
