--- ./base/base.gyp.orig	2014-04-30 22:41:43.000000000 +0200
+++ ./base/base.gyp	2014-05-04 14:38:46.000000000 +0200
@@ -803,6 +803,11 @@
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
