--- third_party/pdfium/pdfium.gyp.orig	2014-10-10 09:15:55 UTC
+++ third_party/pdfium/pdfium.gyp
@@ -13,7 +13,7 @@
       ['pdf_use_skia==1', {
         'defines': ['_SKIA_SUPPORT_'],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'conditions': [
           ['target_arch=="x64"', {
             'defines' : [ '_FX_CPU_=_FX_X64_', ],
