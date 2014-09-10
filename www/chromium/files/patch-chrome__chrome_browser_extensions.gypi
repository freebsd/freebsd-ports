--- ./chrome/chrome_browser_extensions.gypi.orig	2014-08-20 21:02:14.000000000 +0200
+++ ./chrome/chrome_browser_extensions.gypi	2014-08-22 15:06:25.000000000 +0200
@@ -958,6 +958,11 @@
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
