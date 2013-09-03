--- third_party/WebKit/Tools/DumpRenderTree/DumpRenderTree.gyp/DumpRenderTree.gyp.orig	2013-08-19 03:03:10.000000000 +0300
+++ third_party/WebKit/Tools/DumpRenderTree/DumpRenderTree.gyp/DumpRenderTree.gyp	2013-08-30 23:14:53.000000000 +0300
@@ -377,5 +377,12 @@
                 },
             },
         }],
+        ['OS=="freebsd"', {
+            'target_defaults': {
+                'include_dirs': [
+                    '/usr/local/include',
+                ],
+            },
+        }],
     ], # conditions
 }
