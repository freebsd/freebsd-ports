--- chrome/chrome_browser.gypi.orig	2011-03-20 22:02:04.255736830 +0200
+++ chrome/chrome_browser.gypi	2011-03-20 22:02:04.431736294 +0200
@@ -1237,7 +1237,7 @@
         'browser/favicon_service.h',
         'browser/file_path_watcher/file_path_watcher.cc',
         'browser/file_path_watcher/file_path_watcher.h',
-        'browser/file_path_watcher/file_path_watcher_inotify.cc',
+        #'browser/file_path_watcher/file_path_watcher_inotify.cc',
         'browser/file_path_watcher/file_path_watcher_mac.cc',
         'browser/file_path_watcher/file_path_watcher_win.cc',
         'browser/file_select_helper.cc',
@@ -1266,8 +1266,8 @@
         'browser/geolocation/empty_device_data_provider.h',
         'browser/geolocation/gateway_data_provider_common.cc',
         'browser/geolocation/gateway_data_provider_common.h',
-        'browser/geolocation/gateway_data_provider_linux.cc',
-        'browser/geolocation/gateway_data_provider_linux.h',
+        #'browser/geolocation/gateway_data_provider_linux.cc',
+        #'browser/geolocation/gateway_data_provider_linux.h',
         'browser/geolocation/gateway_data_provider_win.cc',
         'browser/geolocation/gateway_data_provider_win.h',
         'browser/geolocation/geolocation_content_settings_map.cc',
@@ -1307,7 +1307,7 @@
         'browser/geolocation/wifi_data_provider_corewlan_mac.mm',
         'browser/geolocation/wifi_data_provider_common_win.cc',
         'browser/geolocation/wifi_data_provider_common_win.h',
-        'browser/geolocation/wifi_data_provider_linux.cc',
+        #'browser/geolocation/wifi_data_provider_linux.cc',
         'browser/geolocation/wifi_data_provider_linux.h',
         'browser/geolocation/wifi_data_provider_mac.cc',
         'browser/geolocation/wifi_data_provider_mac.h',
@@ -3621,7 +3621,7 @@
             ['include', '^browser/chromeos/dom_ui/login/'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:dbus-glib',
             '../build/linux/system.gyp:gconf',
@@ -4294,7 +4294,7 @@
               ],
             }],
             # GTK build only
-            ['OS=="linux" and toolkit_views==0', {
+            ['(OS=="linux" or OS=="freebsd") and toolkit_views==0', {
               'sources/': [
                 ['include', '^browser/printing/print_dialog_gtk.cc'],
                 ['include', '^browser/printing/print_dialog_gtk.h'],
