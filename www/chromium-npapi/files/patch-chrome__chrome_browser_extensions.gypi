--- ./chrome/chrome_browser_extensions.gypi.orig	2014-04-30 22:42:53.000000000 +0200
+++ ./chrome/chrome_browser_extensions.gypi	2014-05-04 14:38:46.000000000 +0200
@@ -885,6 +885,11 @@
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
