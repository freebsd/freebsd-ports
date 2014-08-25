--- ./third_party/WebKit/Source/wtf/wtf.gyp.orig	2014-08-20 21:08:05.000000000 +0200
+++ ./third_party/WebKit/Source/wtf/wtf.gyp	2014-08-22 15:06:26.000000000 +0200
@@ -70,7 +70,7 @@
       'target_name': 'wtf',
       'type': '<(component)',
       'include_dirs': [
-        '..',
+        '..', '<(prefix_dir)/include',
       ],
       'dependencies': [
           'wtf_config',
