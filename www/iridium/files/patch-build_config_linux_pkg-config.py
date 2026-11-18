--- build/config/linux/pkg-config.py.orig	2026-11-17 21:17:00 UTC
+++ build/config/linux/pkg-config.py
@@ -143,7 +143,7 @@ def main():
     )
     (options, args) = parser.parse_args()
 
-    if "linux" not in sys.platform:
+    if not sys.platform.startswith(tuple(['linux', 'openbsd', 'freebsd'])):
         if (
             sys.platform == 'darwin'
             and options.sysroot
