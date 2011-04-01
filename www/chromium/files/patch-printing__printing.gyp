--- ./printing/printing.gyp.orig	2010-12-16 02:11:23.000000000 +0100
+++ ./printing/printing.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -165,7 +165,7 @@
         'units_unittest.cc',
       ],
       'conditions': [
-        ['OS!="linux"', {'sources/': [['exclude', '_cairo_unittest\\.cc$']]}],
+        ['OS!="linux" and OS!="freebsd"', {'sources/': [['exclude', '_cairo_unittest\\.cc$']]}],
         ['OS!="mac"', {'sources/': [['exclude', '_mac_unittest\\.(cc|mm?)$']]}],
         ['OS!="win"', {'sources/': [['exclude', '_win_unittest\\.cc$']]
           }, {  # else: OS=="win"
@@ -176,14 +176,12 @@
             'dependencies': [
               '../build/linux/system.gyp:gtk',
            ],
-        }],
-        ['OS=="linux"', {
-          'conditions': [
-            ['linux_use_tcmalloc==1', {
+            'conditions': [
+              ['linux_use_tcmalloc==1', {
               'dependencies': [
                 '../base/allocator/allocator.gyp:allocator',
-              ],
-            }],
+                ],
+              }],
           ],
         }],
       ],
