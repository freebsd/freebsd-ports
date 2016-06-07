--- chrome/chrome_browser_extensions.gypi.orig	2016-05-25 15:00:58.000000000 -0400
+++ chrome/chrome_browser_extensions.gypi	2016-05-27 09:56:46.969693000 -0400
@@ -1019,6 +1019,11 @@
             '<@(chrome_browser_extensions_task_manager_enabled_sources)',
           ],
         }],
+        ['os_bsd==1', {
+          'sources/': [
+            ['exclude', '^browser/extensions/api/image_writer_private/removable_storage_provider_linux.cc'],
+          ],
+        }],
         ['chromeos==1', {
           'dependencies': [
             '../build/linux/system.gyp:dbus',
@@ -1061,7 +1066,7 @@
             '../ui/views/views.gyp:views',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['use_aura==1', {
               'dependencies': [
