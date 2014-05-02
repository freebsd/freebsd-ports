--- ./printing/printing.gyp.orig	2014-04-24 22:35:32.000000000 +0200
+++ ./printing/printing.gyp	2014-04-24 23:23:46.000000000 +0200
@@ -215,7 +215,7 @@
             'backend/print_backend_chromeos.cc',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" and chromeos==0) or OS=="freebsd"', { #XXX (rene) temp!
           'sources': [
             'printing_context_linux.cc',
             'printing_context_linux.h',
