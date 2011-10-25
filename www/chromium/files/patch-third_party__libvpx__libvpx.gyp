--- third_party/libvpx/libvpx.gyp.orig	2011-10-09 00:08:25.368469771 +0300
+++ third_party/libvpx/libvpx.gyp	2011-10-10 21:41:31.622025374 +0300
@@ -77,7 +77,7 @@
       'source/libvpx/vpx_scale/generic/yv12extend.c',
     ],
     'conditions': [
-      ['OS=="mac" or OS=="linux"', {
+      ['OS=="mac" or OS=="linux" or OS=="freebsd"', {
         'asm_obj_extension': 'o',
       }],
       ['OS=="win"', {
@@ -86,7 +86,7 @@
     ],
   },
   'conditions': [
-    [ '(OS=="linux" or OS=="mac" or OS=="win") and target_arch!="arm"', {
+    [ '(OS=="linux" or OS=="freebsd" or OS=="mac" or OS=="win") and target_arch!="arm"', {
       'targets': [
         {
           # This libvpx target contains both encoder and decoder.
@@ -98,7 +98,7 @@
               '<(SHARED_INTERMEDIATE_DIR)/third_party/libvpx',
             'yasm_path': '<(PRODUCT_DIR)/yasm',
             'conditions': [
-              [ 'OS=="linux" and target_arch=="ia32"', {
+              [ '(OS=="linux" or OS=="freebsd") and target_arch=="ia32"', {
                 'yasm_flags': [
                   '-felf32',
                   '-m', 'x86',
@@ -106,7 +106,7 @@
                   '-I', 'source/libvpx',
                 ],
               }],
-              [ 'OS=="linux" and target_arch=="x64"', {
+              [ '(OS=="linux" or OS=="freebsd") and target_arch=="x64"', {
                 'yasm_flags': [
                   '-felf64',
                   '-m', 'amd64',
@@ -482,6 +482,11 @@
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
