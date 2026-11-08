--- cef/tools/clang_util.py.orig	2026-09-06 17:31:54 UTC
+++ cef/tools/clang_util.py
@@ -22,6 +22,8 @@ if sys.platform == 'win32':
 else:
   clang_format_exe = 'clang-format'
   clang_exe = os.path.join(llvm_bin_dir, 'clang')
+  if not os.path.exists(clang_exe):
+    clang_exe = 'clang'
 
 
 def clang_format(file_name, file_contents):
