--- gpu/gpu.gyp.orig	2011-09-14 00:37:31.000000000 +0300
+++ gpu/gpu.gyp	2011-09-14 00:36:48.000000000 +0300
@@ -328,6 +328,7 @@
       ],
       'include_dirs': [
         '..',
+        '<(prefix_dir)/include',
       ],
       'sources': [
         'command_buffer/common/gl_mock.h',
