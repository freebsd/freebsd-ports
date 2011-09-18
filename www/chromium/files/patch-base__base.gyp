--- base/base.gyp.orig	2011-09-11 11:01:29.000000000 +0300
+++ base/base.gyp	2011-09-14 00:13:24.000000000 +0300
@@ -320,6 +320,11 @@
             'test/scoped_locale.h',
           ],
         }],
+        ['OS=="freebsd"', {
+          'sources!': [
+            'test/test_file_util_linux.cc',
+          ],
+        }],
       ],
       'sources': [
         'perftimer.cc',
