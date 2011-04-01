--- ./base/base.gyp.orig	2010-12-16 02:11:49.000000000 +0100
+++ ./base/base.gyp	2010-12-20 20:15:07.000000000 +0100
@@ -241,6 +241,13 @@
           ],
         }],
       ],
+      'conditions': [
+        [ 'OS == "freebsd"', {
+            # fdatasync is not implemented on FreeBSD
+            'sources/': [ ['exclude', '^test/test_file_util_linux.cc$'] ],
+          },
+        ],
+      ],
     },
     {
       'target_name': 'test_support_base',
