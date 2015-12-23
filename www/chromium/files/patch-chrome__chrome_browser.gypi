--- chrome/chrome_browser.gypi.orig	2015-12-04 22:23:49.106516000 +0100
+++ chrome/chrome_browser.gypi	2015-12-04 22:27:43.886261000 +0100
@@ -3369,6 +3369,13 @@
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
@@ -3522,7 +3529,7 @@
             '../device/media_transfer_protocol/media_transfer_protocol.gyp:device_media_transfer_protocol',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" and chromeos==0) or os_bsd==1', {
           'dependencies': [
             '../build/linux/system.gyp:libspeechd',
           ],
@@ -3576,7 +3583,7 @@
         ['use_x11==1', {
           'sources': [ '<@(chrome_browser_x11_sources)' ],
         }],
-        ['os_posix == 1 and OS != "mac" and OS != "ios"', {
+        ['os_posix == 1 and os_bsd != 1 and OS != "mac" and OS != "ios"', {
           'sources': [
             'app/chrome_crash_reporter_client.cc',
             'app/chrome_crash_reporter_client.h',
@@ -3817,7 +3824,7 @@
             }],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['use_aura==1', {
               'dependencies': [
