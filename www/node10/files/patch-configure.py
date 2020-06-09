--- configure.py.orig	2020-06-08 21:39:42 UTC
+++ configure.py
@@ -705,7 +705,7 @@ def get_nasm_version(asm):
 
 def get_llvm_version(cc):
   return get_version_helper(
-    cc, r"(^(?:FreeBSD )?clang version|based on LLVM) ([3-9]\.[0-9]+)")
+    cc, r"(^(?:FreeBSD )?clang version|based on LLVM) ([0-9]+\.[0-9]+)")
 
 def get_xcode_version(cc):
   return get_version_helper(
