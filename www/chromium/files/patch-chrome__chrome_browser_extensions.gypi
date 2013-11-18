--- chrome/chrome_browser_extensions.gypi.orig	2013-11-16 01:17:16.000000000 +0100
+++ chrome/chrome_browser_extensions.gypi	2013-11-17 17:09:41.000000000 +0100
@@ -854,6 +854,11 @@
         'browser/extensions/window_controller_list_observer.h',
       ],
       'conditions': [
+        ['os_bsd==1', {
+         'sources/': [
+            ['exclude', '^browser/extensions/api/image_writer_private/removable_storage_provider_linux.cc'],
+         ],
+        }],
         ['chromeos==1', {
           'dependencies': [
             '../build/linux/system.gyp:dbus',
