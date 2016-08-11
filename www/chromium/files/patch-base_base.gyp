--- base/base.gyp.orig	2016-05-11 19:02:11 UTC
+++ base/base.gyp
@@ -113,7 +113,7 @@
           ],
           'link_settings': {
             'libraries': [
-              '-L/usr/local/lib -lexecinfo',
+              '-L/usr/local/lib -lexecinfo -lkvm',
             ],
           },
         }],
@@ -748,6 +748,11 @@
             'sync_socket_unittest.cc',
           ],
         }],
+        ['OS == "freebsd"', {
+          'sources!': [
+            'debug/proc_maps_linux_unittest.cc',
+          ],
+        }],
       ],  # target_conditions
     },
     {
