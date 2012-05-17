--- third_party/apache/aprutil/aprutil.gyp.old	2012-05-14 20:42:31.000000000 +0900
+++ third_party/apache/aprutil/aprutil.gyp	2012-05-14 21:47:36.000000000 +0900
@@ -142,7 +142,7 @@
         },
         {
           'target_name': 'aprutil',
-          'type': 'settings',
+          'type': '<(library)',
           'dependencies': [
             'include',
           ],
