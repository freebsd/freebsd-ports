--- ./third_party/khronos/khronos.gyp.orig	2014-08-12 21:02:46.000000000 +0200
+++ ./third_party/khronos/khronos.gyp	2014-08-13 09:56:58.000000000 +0200
@@ -11,6 +11,7 @@
         'include_dirs': [
           '.',
           '../../gpu',  # Contains GLES2/gl2chromium.h
+          '<(prefix_dir)/include',
         ],
       },
     },
