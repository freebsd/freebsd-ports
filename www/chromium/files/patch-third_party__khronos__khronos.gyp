--- ./third_party/khronos/khronos.gyp.orig	2014-08-20 21:03:05.000000000 +0200
+++ ./third_party/khronos/khronos.gyp	2014-08-22 15:06:26.000000000 +0200
@@ -11,6 +11,7 @@
         'include_dirs': [
           '.',
           '../../gpu',  # Contains GLES2/gl2chromium.h
+          '<(prefix_dir)/include',
         ],
       },
     },
