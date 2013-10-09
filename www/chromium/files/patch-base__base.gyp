--- base/base.gyp.orig	2013-09-26 02:17:34.000000000 +0300
+++ base/base.gyp	2013-09-26 03:00:53.000000000 +0300
@@ -823,6 +823,11 @@
             ['include', '^debug/proc_maps_linux_unittest\\.cc$'],
           ],
         }],
+        ['<(os_bsd) == 1', {
+          'sources/': [
+            ['exclude', '^debug/proc_maps_linux_unittest\\.cc$'],
+          ],
+        }],
       ],  # target_conditions
     },
     {
