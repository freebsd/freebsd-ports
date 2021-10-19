--- third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py.orig	2021-09-14 01:52:02 UTC
+++ third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py
@@ -37,6 +37,9 @@ def init(root_src_dir, enable_style_format=True):
     elif sys.platform.startswith(("cygwin", "win")):
         platform = "win"
         exe_suffix = ".exe"
+    elif sys.platform.startswith("freebsd"):
+        platform = "freebsd"
+        exe_suffix = ""
     else:
         assert False, "Unknown platform: {}".format(sys.platform)
     buildtools_platform_dir = os.path.join(root_src_dir, "buildtools",
