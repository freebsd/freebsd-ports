--- ./printing/printing.gyp.orig	2014-08-12 21:02:51.000000000 +0200
+++ ./printing/printing.gyp	2014-08-13 09:56:58.000000000 +0200
@@ -193,7 +193,7 @@
             'backend/print_backend_chromeos.cc',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" or os_bsd == 1) and chromeos==0', {
           'sources': [
             'printing_context_linux.cc',
             'printing_context_linux.h',
