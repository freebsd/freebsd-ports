--- tools/rust/build_crubit.py.orig	2026-11-19 12:25:27 UTC
+++ tools/rust/build_crubit.py
@@ -127,7 +127,7 @@ CMAKE_STAMP_FILENAME = 'build_crubit_stamp'
 
 IS_WIN = sys.platform == 'win32'
 IS_MAC = sys.platform == 'darwin'
-IS_LINUX = sys.platform.startswith('linux')
+IS_LINUX = sys.platform.startswith(("linux","openbsd","freebsd")):
 
 
 def GetCrubitCxxFlags():
