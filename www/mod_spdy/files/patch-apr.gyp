--- third_party/apache/apr/apr.gyp.old	2012-05-14 20:42:31.000000000 +0900
+++ third_party/apache/apr/apr.gyp	2012-05-14 21:46:57.000000000 +0900
@@ -201,7 +201,7 @@
         },
         {
           'target_name': 'apr',
-          'type': 'settings',
+          'type': '<(library)',
           'dependencies': [
             'include',
           ],
