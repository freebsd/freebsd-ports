--- cargo-crates/v8-147.4.0/build/config/linux/pkg-config.py.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-147.4.0/build/config/linux/pkg-config.py
@@ -108,7 +108,7 @@ def main():
   # If this is run on non-Linux platforms, just return nothing and indicate
   # success. This allows us to "kind of emulate" a Linux build from other
   # platforms.
-  if "linux" not in sys.platform:
+  if not sys.platform.startswith(tuple(['linux', 'openbsd', 'freebsd'])):
     print("[[],[],[],[],[]]")
     return 0
 
