--- ./printing/printing.gyp.orig	2014-04-30 22:43:20.000000000 +0200
+++ ./printing/printing.gyp	2014-05-04 14:38:48.000000000 +0200
@@ -215,7 +215,7 @@
             'backend/print_backend_chromeos.cc',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" and chromeos==0) or OS=="freebsd"', { #XXX (rene) temp!
           'sources': [
             'printing_context_linux.cc',
             'printing_context_linux.h',
