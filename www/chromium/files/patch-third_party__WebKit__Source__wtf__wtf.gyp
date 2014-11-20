--- third_party/WebKit/Source/wtf/wtf.gyp.orig	2014-10-10 09:34:38 UTC
+++ third_party/WebKit/Source/wtf/wtf.gyp
@@ -67,7 +67,7 @@
       'target_name': 'wtf',
       'type': '<(component)',
       'include_dirs': [
-        '..',
+        '..', '<(prefix_dir)/include',
       ],
       'dependencies': [
           'wtf_config',
