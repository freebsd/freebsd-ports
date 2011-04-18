--- build/linux/system.gyp.orig	2011-04-17 22:18:20.000000000 +0200
+++ build/linux/system.gyp	2011-04-17 22:18:57.000000000 +0200
@@ -309,12 +309,6 @@
                   '<!@(<(pkg-config) --libs-only-l gnome-keyring-1)',
                 ],
               },
-            }, {
-              'link_settings': {
-                'libraries': [
-                  '-ldl',
-                ],
-              },
             }],
           ],
         }],
