--- readchar/readchar.py.orig	2020-11-18 17:42:51 UTC
+++ readchar/readchar.py
@@ -9,6 +9,8 @@ if sys.platform.startswith('linux'):
     from .readchar_linux import readchar
 elif sys.platform == 'darwin':
     from .readchar_linux import readchar
+elif sys.platform.startswith('freebsd'):
+    from .readchar_linux import readchar
 elif sys.platform in ('win32', 'cygwin'):
     import msvcrt
     from .readchar_windows import readchar
