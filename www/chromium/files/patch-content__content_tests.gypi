--- content/content_tests.gypi.orig	2016-01-21 16:12:12.019069967 +0100
+++ content/content_tests.gypi	2016-01-21 16:32:14.310986945 +0100
@@ -1264,6 +1264,15 @@
                 '../third_party/libvpx_new/libvpx.gyp:libvpx_new',
               ],
             }],
+            ['OS == "freebsd"', {
+              'sources!': [
+                'browser/download/file_metadata_unittest_linux.cc',
+                'browser/geolocation/wifi_data_provider_linux_unittest.cc',
+                'browser/renderer_host/media/media_stream_dispatcher_host_unittest.cc',
+                'browser/renderer_host/media/media_stream_manager_unittest.cc',
+                'browser/renderer_host/media/media_stream_ui_controller_unittest.cc'
+              ]
+            }],
             # Avoid windows due to non-availability of cursor resources in test.
             ['OS != "linux"', {
               'sources!': [
