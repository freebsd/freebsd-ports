--- remoting/remoting.gyp.orig	2011-09-07 02:04:45.000000000 +0300
+++ remoting/remoting.gyp	2011-09-07 02:08:27.000000000 +0300
@@ -53,6 +53,20 @@
           'resources/linux/chromoting16.png',
         ],
       }],
+      ['OS=="freebsd" and target_arch=="x64"', {
+        'name_suffix': '- FreeBSD - amd64',
+        'remoting_it2me_os_files': [
+          'resources/linux/chromoting128.png',
+          'resources/linux/chromoting16.png',
+        ],
+      }],
+      ['OS=="freebsd" and target_arch!="x64"', {
+        'name_suffix': '- FreeBSD',
+        'remoting_it2me_os_files': [
+          'resources/linux/chromoting128.png',
+          'resources/linux/chromoting16.png',
+        ],
+      }],
       ['OS=="win"', {
         'plugin_extension': 'dll',
         'plugin_prefix': '',
