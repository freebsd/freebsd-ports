--- content/content_tests.gypi.orig	2014-10-02 17:39:47 UTC
+++ content/content_tests.gypi
@@ -916,6 +916,15 @@
             'browser/geolocation/wifi_data_provider_linux_unittest.cc',
           ],
         }],
+        ['OS == "freebsd"', {
+          'sources!': [
+            'browser/download/file_metadata_unittest_linux.cc',
+            'browser/geolocation/wifi_data_provider_linux_unittest.cc',
+            'browser/renderer_host/media/media_stream_dispatcher_host_unittest.cc',
+            'browser/renderer_host/media/media_stream_manager_unittest.cc',
+            'browser/renderer_host/media/media_stream_ui_controller_unittest.cc',
+          ],
+        }],
         ['OS != "android" and OS != "ios"', {
           'dependencies': [
             '../third_party/libvpx/libvpx.gyp:libvpx',
