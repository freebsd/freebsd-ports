--- ./base/base.gyp.orig	2014-04-24 22:36:11.000000000 +0200
+++ ./base/base.gyp	2014-04-24 23:23:41.000000000 +0200
@@ -820,6 +820,11 @@
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
