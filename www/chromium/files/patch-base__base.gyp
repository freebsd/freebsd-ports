--- base/base.gyp.orig	2014-10-02 21:05:31 UTC
+++ base/base.gyp
@@ -129,7 +129,7 @@
           ],
           'link_settings': {
             'libraries': [
-              '-L/usr/local/lib -lexecinfo',
+              '-L/usr/local/lib -lexecinfo -lkvm',
             ],
           },
         }],
@@ -784,6 +784,11 @@
             ['include', '^debug/proc_maps_linux_unittest\\.cc$'],
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
