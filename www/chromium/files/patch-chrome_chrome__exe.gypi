--- chrome/chrome_exe.gypi.orig	2016-05-11 19:02:17 UTC
+++ chrome/chrome_exe.gypi
@@ -182,7 +182,7 @@
                 '../build/linux/system.gyp:xext',
               ],
             }],
-            ['OS=="linux" and enable_plugins==1', {
+            ['(OS=="linux" or os_bsd==1) and enable_plugins==1', {
               'dependencies': [
                 '../pdf/pdf.gyp:pdf',
               ],
