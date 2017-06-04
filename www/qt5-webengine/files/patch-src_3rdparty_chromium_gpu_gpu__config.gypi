--- src/3rdparty/chromium/gpu/gpu_config.gypi.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/gpu/gpu_config.gypi
@@ -66,12 +66,12 @@
         '../third_party/amd/amd_videocard_info_win.cc',
       ],
     }],
-    ['OS=="linux" and use_libpci==1 and (use_x11==1 or use_ozone==1)', {
+    ['(OS=="linux" or os_bsd==1) and use_libpci==1 and (use_x11==1 or use_ozone==1)', {
       'dependencies': [
         '../build/linux/system.gyp:libpci',
       ],
     }],
-    ['OS=="linux" and use_x11==1', {
+    ['(OS=="linux" or os_bsd==1) and use_x11==1', {
       'dependencies': [
         '../build/linux/system.gyp:x11',
         '../build/linux/system.gyp:xext',
