Disable USE_SYMBOLIZE, it assumes Linux is being used and does things such as
reading from /proc.
--- src/3rdparty/chromium/base/base.gyp.orig	2017-04-19 16:31:45 UTC
+++ src/3rdparty/chromium/base/base.gyp
@@ -46,7 +46,7 @@
             'xdg_mime',
           ],
           'defines': [
-            'USE_SYMBOLIZE',
+            # 'USE_SYMBOLIZE',
           ],
         }, {  # desktop_linux == 0 and chromeos == 0
             'sources/': [
