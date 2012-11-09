--- ./deps/openssl/openssl.gyp.orig	2012-10-24 12:21:44.000000000 -0400
+++ ./deps/openssl/openssl.gyp	2012-11-08 19:57:39.000000000 -0500
@@ -3,6 +3,11 @@
 # found in the LICENSE file.
 
 {
+  'variables': {
+    'is_clang': 0,
+    'gcc_version': 0,
+  },
+
   'targets': [
     {
       'target_name': 'openssl',
@@ -674,10 +679,10 @@
             'OPENSSLDIR="/etc/ssl"',
             'TERMIOS',
           ],
-          'cflags': [
-            '-Wno-missing-field-initializers',
-            '-Wno-old-style-declaration',
-          ],
+          'cflags': ['-Wno-missing-field-initializers'],
+        }],
+        ['is_clang==1 or gcc_version>=43', {
+          'cflags': ['-Wno-old-style-declaration'],
         }],
         ['OS=="solaris"', {
           'defines': ['__EXTENSIONS__'],
