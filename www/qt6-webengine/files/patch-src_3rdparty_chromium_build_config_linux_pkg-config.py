--- src/3rdparty/chromium/build/config/linux/pkg-config.py.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/build/config/linux/pkg-config.py
@@ -113,7 +113,7 @@ def main():
   # If this is run on non-Linux platforms, just return nothing and indicate
   # success. This allows us to "kind of emulate" a Linux build from other
   # platforms.
-  if 'linux' not in sys.platform and 'darwin' not in sys.platform:
+  if not sys.platform.startswith(tuple(['linux', 'darwin', 'freebsd', 'openbsd'])):
     print("[[],[],[],[],[]]")
     return 0
 
