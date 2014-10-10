--- third_party/khronos/khronos.gyp.orig	2014-10-02 17:19:02 UTC
+++ third_party/khronos/khronos.gyp
@@ -11,6 +11,7 @@
         'include_dirs': [
           '.',
           '../../gpu',  # Contains GLES2/gl2chromium.h
+          '<(prefix_dir)/include',
         ],
       },
     },
