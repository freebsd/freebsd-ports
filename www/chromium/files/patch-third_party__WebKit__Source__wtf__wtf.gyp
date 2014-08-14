--- ./third_party/WebKit/Source/wtf/wtf.gyp.orig	2014-08-12 21:07:13.000000000 +0200
+++ ./third_party/WebKit/Source/wtf/wtf.gyp	2014-08-13 09:56:58.000000000 +0200
@@ -70,7 +70,7 @@
       'target_name': 'wtf',
       'type': '<(component)',
       'include_dirs': [
-        '..',
+        '..', '<(prefix_dir)/include',
       ],
       'dependencies': [
           'wtf_config',
