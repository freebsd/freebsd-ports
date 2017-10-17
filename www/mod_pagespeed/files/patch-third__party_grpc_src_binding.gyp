--- third_party/grpc/src/binding.gyp.orig	2017-10-06 10:33:51 UTC
+++ third_party/grpc/src/binding.gyp
@@ -91,11 +91,14 @@
             'cflags': [
               '-ftest-coverage',
               '-fprofile-arcs',
-              '-O0'
+              '-O0',
+              '-frtti',
+              '-I/usr/local/include'
             ],
             'ldflags': [
               '-ftest-coverage',
-              '-fprofile-arcs'
+              '-fprofile-arcs',
+              '-Wl,-z,defs'
             ]
           }
          ],
@@ -143,7 +147,9 @@
           'cflags': [
             '-std=c99',
             '-Wall',
-            '-Werror'
+            '-Werror',
+            '-frtti',
+            '-I/usr/local/include'
           ],
           'target_name': 'boringssl',
           'product_prefix': 'lib',
@@ -454,7 +460,9 @@
           'cflags': [
             '-std=c99',
             '-Wall',
-            '-Werror'
+            '-Werror',
+            '-frtti',
+            '-I/usr/local/include'
           ],
           'target_name': 'z',
           'product_prefix': 'lib',
@@ -487,7 +495,9 @@
       'cflags': [
         '-std=c99',
         '-Wall',
-        '-Werror'
+        '-Werror',
+        '-frtti',
+        '-I/usr/local/include'
       ],
       'target_name': 'gpr',
       'product_prefix': 'lib',
@@ -553,7 +563,9 @@
       'cflags': [
         '-std=c99',
         '-Wall',
-        '-Werror'
+        '-Werror',
+        '-frtti',
+        '-I/usr/local/include'
       ],
       'target_name': 'grpc',
       'product_prefix': 'lib',
@@ -766,12 +778,15 @@
         '-Wall',
         '-pthread',
         '-g',
-        '-zdefs',
+        '-Wl,-z,defs',
         '-Werror',
-        '-Wno-error=deprecated-declarations'
+        '-Wno-error=deprecated-declarations',
+        '-frtti',
+        '-I/usr/local/include'
       ],
       'ldflags': [
-        '-g'
+        '-g',
+        '-Wl,-z,defs'
       ],
       "conditions": [
         ['OS=="mac"', {
@@ -779,7 +795,9 @@
             'MACOSX_DEPLOYMENT_TARGET': '10.9',
             'OTHER_CFLAGS': [
               '-stdlib=libc++',
-              '-std=c++11'
+              '-std=c++11',
+              '-frtti',
+              '-I/usr/local/include'
             ]
           }
         }],
@@ -791,7 +809,8 @@
         }],
         ['OS=="linux"', {
           'ldflags': [
-            '-Wl,-wrap,memcpy'
+            '-Wl,-wrap,memcpy',
+            '-Wl,-z,defs'
           ]
         }]
       ],
