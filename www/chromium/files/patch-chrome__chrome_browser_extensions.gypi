--- chrome/chrome_browser_extensions.gypi.orig	2014-10-10 09:15:30 UTC
+++ chrome/chrome_browser_extensions.gypi
@@ -950,6 +950,11 @@
         '<@(chrome_browser_extensions_enabled_sources)',
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
