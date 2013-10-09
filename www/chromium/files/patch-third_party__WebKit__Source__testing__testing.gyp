--- third_party/WebKit/Source/testing/testing.gyp.orig	2013-09-03 23:36:08.000000000 +0300
+++ third_party/WebKit/Source/testing/testing.gyp	2013-09-03 23:37:05.000000000 +0300
@@ -339,5 +339,12 @@
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
