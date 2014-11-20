--- chrome/chrome_tests_unit.gypi.orig	2014-10-23 01:54:54.000000000 +0200
+++ chrome/chrome_tests_unit.gypi	2014-10-26 14:01:43.000000000 +0100
@@ -1878,6 +1878,12 @@
             'test/ppapi/ppapi_test.h',
           ],
         }],
+        ['OS=="freebsd"', {
+          'sources!': [
+            'browser/media_galleries/linux/mtp_device_object_enumerator_unittest.cc',
+            'browser/media_galleries/linux/mtp_device_object_enumerator.h',
+          ],
+        }],
       ],
     },
     {
