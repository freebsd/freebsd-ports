--- third_party/grpc/grpc.gyp.orig	2017-10-06 10:33:51 UTC
+++ third_party/grpc/grpc.gyp
@@ -22,8 +22,10 @@
       'cflags_cc': [
         '-Wall',
         '-pthread',
-        '-zdefs',
-        '-Wno-error=deprecated-declarations'
+        '-Wl,-z,defs',
+        '-Wno-error=deprecated-declarations',
+        '-frtti',
+        '-I/usr/local/include'
       ],
       'sources': [
         "src/src/cpp/client/secure_credentials.cc",
@@ -71,9 +73,12 @@
       'cflags': [
         '-std=c99',
         '-Wall',
+        '-frtti',
+        '-I/usr/local/include',
       ],
       'ldflags': [
         '-Wl,-wrap,memcpy',
+        '-Wl,-z,defs',
       ],
       'sources': [
         'src/src/core/lib/surface/init.c',
@@ -270,6 +276,8 @@
       'cflags': [
         '-std=c99',
         '-Wall',
+        '-frtti',
+        '-I/usr/local/include',
       ],
       'sources': [
         'src/src/core/lib/profiling/basic_timers.c',
@@ -326,8 +334,10 @@
       'cflags_cc': [
         '-Wall',
         '-pthread',
-        '-zdefs',
-        '-Wno-error=deprecated-declarations'
+        '-Wl,-z,defs',
+        '-Wno-error=deprecated-declarations',
+        '-frtti',
+        '-I/usr/local/include'
       ],
       'sources': [
         'src/src/compiler/cpp_generator.cc',
