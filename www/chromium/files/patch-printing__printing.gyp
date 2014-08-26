--- ./printing/printing.gyp.orig	2014-08-20 21:03:08.000000000 +0200
+++ ./printing/printing.gyp	2014-08-22 15:06:26.000000000 +0200
@@ -187,7 +187,7 @@
             'backend/print_backend_chromeos.cc',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" or os_bsd == 1) and chromeos==0', {
           'sources': [
             'printing_context_linux.cc',
             'printing_context_linux.h',
