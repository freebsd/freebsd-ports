--- cargo-crates/v8-137.2.1/build/config/linux/pkg-config.py.orig	2020-06-26 16:27:54 UTC
+++ cargo-crates/v8-137.2.1/build/config/linux/pkg-config.py
@@ -108,7 +108,7 @@ def main():
   # If this is run on non-Linux platforms, just return nothing and indicate
   # success. This allows us to "kind of emulate" a Linux build from other
   # platforms.
-  if "linux" not in sys.platform:
+  if not sys.platform.startswith(tuple(['linux', 'openbsd', 'freebsd'])):
     print("[[],[],[],[],[]]")
     return 0
 
