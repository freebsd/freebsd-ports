--- third_party/apr/apr.gyp.orig	2017-10-04 20:42:02 UTC
+++ third_party/apr/apr.gyp
@@ -19,7 +19,7 @@
     'apr_src_root': '<(apr_root)/src',
     'apr_gen_os_root': '<(apr_root)/gen/arch/<(OS)',
     'apr_gen_arch_root': '<(apr_gen_os_root)/<(target_arch)',
-    'system_include_path_apr%': '/usr/include/apr-1.0',
+    'system_include_path_apr%': '/usr/local/include/apr-1',
     'conditions': [
       ['OS!="win"', {
         'apr_os_include': '<(apr_src_root)/include/arch/unix',
@@ -187,6 +187,14 @@
               '_GNU_SOURCE',
             ],
           },
+          'link_settings': {
+            'ldflags': [
+              '<!@(pkg-config --libs apr-1)',
+            ],
+            'libraries': [
+              '<!@(pkg-config --libs apr-1)',
+            ],
+          },
         },
         {
           'target_name': 'apr',
@@ -198,8 +206,11 @@
             'include',
           ],
           'link_settings': {
+            'ldflags': [
+              '<!@(pkg-config --libs apr-1)',
+            ],
             'libraries': [
-              '-lapr-1',
+              '<!@(pkg-config --libs apr-1)',
             ],
           },
         },
