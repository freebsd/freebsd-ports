--- third_party/pdfium/build/standalone.gypi.orig	2014-10-02 17:40:24 UTC
+++ third_party/pdfium/build/standalone.gypi
@@ -13,7 +13,7 @@
       'variables': {
         'variables': {
           'conditions': [
-            ['OS=="linux" or OS=="mac"', {
+            ['OS=="linux" or OS=="mac" or OS=="freebsd"', {
               # This handles the Unix platforms we generally deal with.
               # Anything else gets passed through, which probably won't work
               # very well; such hosts should pass an explicit target_arch
@@ -26,7 +26,7 @@
                                        s/aarch64/arm64/;\
                                        s/mips.*/mipsel/")',
             }, {
-              # OS!="linux" and OS!="mac"
+              # OS!="linux" and OS!="mac" and OS!="freebsd"
               'host_arch%': 'ia32',
             }],
           ],
@@ -259,4 +259,4 @@
     # See comment in Chromium's common.gypi for why this is needed.
     'SYMROOT': '<(DEPTH)/xcodebuild',
   }
-}
\ No newline at end of file
+}
