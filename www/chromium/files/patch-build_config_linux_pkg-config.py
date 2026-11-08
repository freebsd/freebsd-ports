--- build/config/linux/pkg-config.py.orig	2026-09-25 15:26:43 UTC
+++ build/config/linux/pkg-config.py
@@ -145,7 +145,7 @@ def main():
     # If this is run on non-Linux platforms, just return nothing and indicate
     # success. This allows us to "kind of emulate" a Linux build from other
     # platforms.
-    if "linux" not in sys.platform:
+    if not sys.platform.startswith(tuple(['linux', 'openbsd', 'freebsd'])):
         if options.dridriverdir or options.libdir:
             sys.stdout.write("")
             return 0
