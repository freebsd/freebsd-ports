--- third_party/pdfium/build_gyp/standalone.gypi.orig	2016-08-03 16:25:54.875923000 -0400
+++ third_party/pdfium/build_gyp/standalone.gypi	2016-08-03 16:28:57.583883000 -0400
@@ -19,7 +19,7 @@
       'variables': {
         'variables': {
           'conditions': [
-            ['OS=="linux" or OS=="mac"', {
+            ['OS=="linux" or OS=="mac" or OS=="freebsd"', {
               # This handles the Unix platforms we generally deal with.
               # Anything else gets passed through, which probably won't work
               # very well; such hosts should pass an explicit target_arch
@@ -32,7 +32,7 @@
                                        s/aarch64/arm64/;\
                                        s/mips.*/mipsel/")',
             }, {
-              # OS!="linux" and OS!="mac"
+              # OS!="linux" and OS!="mac" and OS!="freebsd"
               'host_arch%': 'ia32',
             }],
           ],
@@ -59,7 +59,7 @@
       }, {
         'os_posix%': 1,
       }],
-      ['OS=="linux" or OS=="mac"', {
+      ['OS=="linux" or OS=="mac" or OS=="freebsd"', {
         'clang%': 1,
         'host_clang%': 1,
       }, {
@@ -141,7 +141,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="freebsd"', {
             'cflags': [
               '-fdata-sections',
               '-ffunction-sections',
