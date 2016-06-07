--- content/content_tests.gypi.orig	2016-05-25 15:01:01.000000000 -0400
+++ content/content_tests.gypi	2016-05-27 10:58:38.919413000 -0400
@@ -1186,6 +1186,15 @@
             'renderer/media/video_track_recorder_unittest.cc',
           ],
         }],
+        ['OS == "freebsd"', {
+          'sources!': [
+            'browser/download/file_metadata_unittest_linux.cc',
+            'browser/geolocation/wifi_data_provider_linux_unittest.cc',
+            'browser/renderer_host/media/media_stream_dispatcher_host_unittest.cc',
+            'browser/renderer_host/media/media_stream_manager_unittest.cc',
+            'browser/renderer_host/media/media_stream_ui_controller_unittest.cc'
+          ]
+        }], 
         # Avoid windows due to non-availability of cursor resources in test.
         ['OS != "linux"', {
           'sources!': [
