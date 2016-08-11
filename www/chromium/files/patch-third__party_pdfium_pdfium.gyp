--- third_party/pdfium/pdfium.gyp.orig	2016-05-11 19:03:45 UTC
+++ third_party/pdfium/pdfium.gyp
@@ -44,7 +44,7 @@
       ['pdf_enable_xfa==1', {
         'defines': ['PDF_ENABLE_XFA'],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'conditions': [
           ['target_arch=="x64"', {
             'defines' : [ '_FX_CPU_=_FX_X64_', ],
