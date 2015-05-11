--- chrome/chrome_exe.gypi.orig	2015-04-20 20:19:42.000000000 +0200
+++ chrome/chrome_exe.gypi	2015-04-20 20:21:17.000000000 +0200
@@ -190,7 +190,7 @@
                 '../build/linux/system.gyp:xext',
               ],
             }],
-            ['OS=="linux" and enable_plugins==1', {
+            ['(OS=="linux" or os_bsd==1) and enable_plugins==1', {
               'dependencies': [
                 '../pdf/pdf.gyp:pdf',
               ],
