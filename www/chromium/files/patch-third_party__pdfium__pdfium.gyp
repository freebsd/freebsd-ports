--- ./third_party/pdfium/pdfium.gyp.orig	2014-08-20 21:04:00.000000000 +0200
+++ ./third_party/pdfium/pdfium.gyp	2014-08-22 16:59:52.000000000 +0200
@@ -14,7 +14,7 @@
       ['pdf_use_skia==1', {
         'defines': ['_SKIA_SUPPORT_'],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'cflags!': [
           '-fno-exceptions',
         ],
