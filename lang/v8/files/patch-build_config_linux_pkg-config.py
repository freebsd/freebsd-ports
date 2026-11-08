--- build/config/linux/pkg-config.py.orig	2026-10-12 03:47:41 UTC
+++ build/config/linux/pkg-config.py
@@ -59,8 +59,12 @@ def SetConfigPath(options):
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
 
@@ -143,7 +147,7 @@ def main():
     )
     (options, args) = parser.parse_args()
 
-    if "linux" not in sys.platform:
+    if "linux" not in sys.platform and "bsd" not in sys.platform:
         if (
             sys.platform == 'darwin'
             and options.sysroot
