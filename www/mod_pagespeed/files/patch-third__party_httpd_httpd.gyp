--- third_party/httpd/httpd.gyp.orig	2017-10-06 09:52:26 UTC
+++ third_party/httpd/httpd.gyp
@@ -18,7 +18,7 @@
     'apache_src_root': '<(apache_root)/src',
     'apache_gen_os_root': '<(apache_root)/gen/arch/<(OS)',
     'apache_gen_arch_root': '<(apache_gen_os_root)/<(target_arch)',
-    'system_include_path_httpd%': '/usr/include/apache2',
+    'system_include_path_httpd%': '/usr/local/include/apache22',
     'conditions': [
       ['OS!="win"', {
         'apache_os_include': '<(apache_src_root)/os/unix',
@@ -58,6 +58,10 @@
          'direct_dependent_settings': {
            'include_dirs': [
              '<(system_include_path_httpd)',
+             '/usr/local/libexec/apache22',
+           ],
+           'ldflags+': [
+             '-L/usr/local/libexec/apache22',
            ],
          },
          'dependencies': [
