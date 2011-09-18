--- third_party/libvpx/libvpx.gyp.orig	2011-08-30 12:19:17.000000000 +0300
+++ third_party/libvpx/libvpx.gyp	2011-09-08 02:22:17.000000000 +0300
@@ -4,7 +4,7 @@
 {
   'variables': {
     'conditions': [
-      ['OS=="mac" or OS=="linux"', {
+      ['OS=="mac" or OS=="linux" or OS=="freebsd"', {
         'asm_obj_extension': 'o',
       }],
       ['OS=="win"', {
@@ -13,7 +13,7 @@
     ],
   },
   'conditions': [
-    [ '(OS=="linux" or OS=="mac" or OS=="win") and target_arch!="arm" and target_arch!="arm-neon"', {
+    [ '(OS=="linux" or OS=="freebsd" or OS=="mac" or OS=="win") and target_arch!="arm" and target_arch!="arm-neon"', {
       'targets': [
         {
           # This libvpx target contains both encoder and decoder.
@@ -25,7 +25,7 @@
               '<(SHARED_INTERMEDIATE_DIR)/third_party/libvpx',
             'yasm_path': '<(PRODUCT_DIR)/yasm',
             'conditions': [
-              [ 'OS=="linux" and target_arch=="ia32"', {
+              [ '(OS=="linux" or OS=="freebsd") and target_arch=="ia32"', {
                 'yasm_flags': [
                   '-felf32',
                   '-m', 'x86',
@@ -33,7 +33,7 @@
                   '-I', 'source/libvpx',
                 ],
               }],
-              [ 'OS=="linux" and target_arch=="x64"', {
+              [ '(OS=="linux" or OS=="freebsd") and target_arch=="x64"', {
                 'yasm_flags': [
                   '-felf64',
                   '-m', 'amd64',
@@ -265,6 +265,11 @@
             'libvpx_path': 'lib/linux/arm',
           },
         }],
+        ['OS=="freebsd"', {
+          'variables': {
+            'libvpx_path': '/usr/local/lib',
+         },
+        }],
         ['OS=="win"', {
           'variables': {
             'libvpx_path': 'lib/win/ia32',
