--- cargo-crates/rusty_v8-0.17.0/build/config/linux/pkg-config.py.orig	2020-06-26 16:27:54 UTC
+++ cargo-crates/rusty_v8-0.17.0/build/config/linux/pkg-config.py
@@ -59,8 +59,12 @@ def SetConfigPath(options):
     print("You must specify an architecture via -a if using a sysroot.")
     sys.exit(1)
 
-  libdir = sysroot + '/usr/' + options.system_libdir + '/pkgconfig'
-  libdir += ':' + sysroot + '/usr/share/pkgconfig'
+  if "linux" in sys.platform:
+    libdir = sysroot + '/libdata/' + options.system_libdir + '/pkgconfig'
+    libdir += ':' + sysroot + '/usr/share/pkgconfig'
+  elif "bsd" in sys.platform:
+    libdir = sysroot + '/libdata/pkgconfig'
+    libdir += ':' + '/usr/libdata/pkgconfig'
   os.environ['PKG_CONFIG_LIBDIR'] = libdir
   return libdir
 
@@ -109,7 +113,7 @@ def main():
   # If this is run on non-Linux platforms, just return nothing and indicate
   # success. This allows us to "kind of emulate" a Linux build from other
   # platforms.
-  if "linux" not in sys.platform:
+  if "bsd" not in sys.platform:
     print("[[],[],[],[],[]]")
     return 0
 
