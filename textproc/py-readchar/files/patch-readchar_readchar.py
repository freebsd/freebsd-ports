--- readchar/readchar.py.orig	2021-04-15 14:19:54 UTC
+++ readchar/readchar.py
@@ -6,6 +6,8 @@ import sys
 
 if sys.platform.startswith("linux"):
     from .readchar_linux import readchar
+elif sys.platform.startswith("freebsd"):
+    from .readchar_linux import readchar
 elif sys.platform == "darwin":
     from .readchar_linux import readchar
 elif sys.platform in ("win32", "cygwin"):
