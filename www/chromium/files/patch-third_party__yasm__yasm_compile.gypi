--- third_party/yasm/yasm_compile.gypi.orig	2011-11-22 00:07:26.000000000 +0200
+++ third_party/yasm/yasm_compile.gypi	2011-11-22 00:08:10.000000000 +0200
@@ -36,13 +36,13 @@
       }],
 
       # Define yasm_flags that pass into YASM.
-      [ 'OS=="linux" and target_arch=="ia32"', {
+      [ '(OS=="linux" or OS=="freebsd") and target_arch=="ia32"', {
         'yasm_flags': [
           '-felf32',
           '-m', 'x86',
         ],
       }],
-      [ 'OS=="linux" and target_arch=="x64"', {
+      [ '(OS=="linux" or OS=="freebsd") and target_arch=="x64"', {
         'yasm_flags': [
           '-DPIC',
           '-felf64',
