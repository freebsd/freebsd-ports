--- chrome/chrome_browser.gypi.orig	2015-07-21 22:00:15.902799000 -0400
+++ chrome/chrome_browser.gypi	2015-07-21 22:08:53.180707000 -0400
@@ -3277,6 +3277,13 @@
             'browser/download/download_dir_policy_handler.h',
           ],
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
             'app_shim',
@@ -3416,7 +3423,7 @@
             '../device/media_transfer_protocol/media_transfer_protocol.gyp:device_media_transfer_protocol',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" and chromeos==0) or os_bsd==1', {
           'dependencies': [
             '../build/linux/system.gyp:libspeechd',
           ],
@@ -3472,7 +3479,7 @@
         ['use_x11==1', {
           'sources': [ '<@(chrome_browser_x11_sources)' ],
         }],
-        ['os_posix == 1 and OS != "mac" and OS != "ios"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and os_bsd != 1', {
           'sources': [
             'app/chrome_crash_reporter_client.cc',
             'app/chrome_crash_reporter_client.h',
@@ -3667,7 +3674,7 @@
             }],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'sources': [ '<@(chrome_browser_linux_sources)' ],
           'conditions': [
             ['use_aura==1', {
