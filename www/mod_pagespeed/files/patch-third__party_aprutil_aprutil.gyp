--- third_party/aprutil/aprutil.gyp.orig	2017-10-04 20:48:05 UTC
+++ third_party/aprutil/aprutil.gyp
@@ -22,7 +22,7 @@
     'aprutil_src_root': '<(aprutil_root)/src',
     'aprutil_gen_os_root': '<(aprutil_root)/gen/arch/<(OS)',
     'aprutil_gen_arch_root': '<(aprutil_gen_os_root)/<(target_arch)',
-    'system_include_path_aprutil%': '/usr/include/apr-1.0',
+    'system_include_path_aprutil%': '/usr/local/include/apr-1',
   },
   'conditions': [
     ['use_system_apache_dev==0', {
@@ -142,6 +142,14 @@
               '_GNU_SOURCE',
             ],
           },
+          'link_settings': {
+            'ldflags': [
+              '<!@(pkg-config --libs apr-util-1)',
+            ],
+            'libraries': [
+              '<!@(pkg-config --libs apr-util-1)',
+            ],
+          },
         },
         {
           'target_name': 'aprutil',
@@ -153,8 +161,11 @@
             'include',
           ],
           'link_settings': {
+            'ldflags': [
+              '<!@(pkg-config --libs apr-util-1)',
+            ],
             'libraries': [
-              '-laprutil-1',
+              '<!@(pkg-config --libs apr-util-1)',
             ],
           },
         },
