--- build/config/linux/pkg-config.py.orig	2026-09-13 16:54:58 UTC
+++ build/config/linux/pkg-config.py
@@ -58,8 +58,12 @@ def SetConfigPath(options):
         print("You must specify an architecture via -a if using a sysroot.")
         sys.exit(1)
 
-    libdir = sysroot + '/usr/' + options.system_libdir + '/pkgconfig'
-    libdir += ':' + sysroot + '/usr/share/pkgconfig'
+    if "bsd" in sys.platform:
+        libdir = sysroot + '/libdata/pkgconfig'
+        libdir += ':' + '/usr/libdata/pkgconfig'
+    else:
+        libdir = sysroot + '/usr/' + options.system_libdir + '/pkgconfig'
+        libdir += ':' + sysroot + '/usr/share/pkgconfig'
     os.environ['PKG_CONFIG_LIBDIR'] = libdir
     return libdir
 
@@ -145,7 +149,7 @@ def main():
     # If this is run on non-Linux platforms, just return nothing and indicate
     # success. This allows us to "kind of emulate" a Linux build from other
     # platforms.
-    if "linux" not in sys.platform:
+    if "linux" not in sys.platform and "bsd" not in sys.platform:
         if options.dridriverdir or options.libdir:
             sys.stdout.write("")
             return 0
