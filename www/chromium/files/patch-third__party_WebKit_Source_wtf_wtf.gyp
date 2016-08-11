--- third_party/WebKit/Source/wtf/wtf.gyp.orig	2016-03-25 13:05:01 UTC
+++ third_party/WebKit/Source/wtf/wtf.gyp
@@ -57,7 +57,7 @@
       'target_name': 'wtf',
       'type': '<(component)',
       'include_dirs': [
-        '..',
+        '..', '<(prefix_dir)/include',
       ],
       'dependencies': [
           'wtf_config',
