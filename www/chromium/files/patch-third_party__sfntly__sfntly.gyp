--- third_party/sfntly/sfntly.gyp.orig	2014-10-10 08:54:18 UTC
+++ third_party/sfntly/sfntly.gyp
@@ -126,7 +126,7 @@
         'cpp/src/sample/chromium/subsetter_impl.h',
       ],
       'include_dirs': [
-        'cpp/src', '../..',
+        'cpp/src', '../..', '<(prefix_dir)/include',
       ],
       # This macro must be define to suppress the use of exception
       'defines': [
