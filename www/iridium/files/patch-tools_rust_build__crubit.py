--- tools/rust/build_crubit.py.orig	2026-11-17 21:17:00 UTC
+++ tools/rust/build_crubit.py
@@ -128,7 +128,7 @@ CMAKE_STAMP_FILENAME = 'build_crubit_stamp'
 
 IS_WIN = sys.platform == 'win32'
 IS_MAC = sys.platform == 'darwin'
-IS_LINUX = sys.platform.startswith('linux')
+IS_LINUX = sys.platform.startswith(("linux","openbsd","freebsd")):
 
 
 def GetCrubitCxxFlags():
