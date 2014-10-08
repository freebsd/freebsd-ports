--- chrome/chrome_browser.gypi.orig	2014-10-02 17:39:46 UTC
+++ chrome/chrome_browser.gypi
@@ -3173,7 +3173,7 @@
             '../device/media_transfer_protocol/media_transfer_protocol.gyp:device_media_transfer_protocol',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" and chromeos==0) or os_bsd==1', {
           'dependencies': [
             '../build/linux/system.gyp:libspeechd',
           ],
@@ -3230,7 +3230,7 @@
             }],
           ],
         }],
-        ['os_posix == 1 and OS != "mac" and OS != "ios"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and os_bsd != 1', {
           'sources': [
             'app/chrome_breakpad_client.cc',
             'app/chrome_breakpad_client.h',
@@ -3313,6 +3313,13 @@
         }, {  # Non-Android.
           'sources': [ '<@(chrome_browser_non_android_sources)' ],
         }],
+        ['os_bsd==1', {
+          'sources/': [
+            ['exclude', '^browser/chrome_browser_main_linux.cc'],
+            ['exclude', '^browser/chrome_browser_main_linux.h'],
+            ['exclude', '^browser/media_galleries/linux/'],
+          ],
+        }],  
         ['OS=="mac"', {
           'dependencies': [
             '../third_party/google_toolbox_for_mac/google_toolbox_for_mac.gyp:google_toolbox_for_mac',
@@ -3389,7 +3396,7 @@
             }],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'sources': [ '<@(chrome_browser_linux_sources)' ],
           'conditions': [
             ['use_aura==1', {
