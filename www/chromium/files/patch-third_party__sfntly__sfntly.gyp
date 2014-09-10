--- ./third_party/sfntly/sfntly.gyp.orig	2014-08-20 21:03:05.000000000 +0200
+++ ./third_party/sfntly/sfntly.gyp	2014-08-22 15:06:27.000000000 +0200
@@ -126,7 +126,7 @@
         'cpp/src/sample/chromium/subsetter_impl.h',
       ],
       'include_dirs': [
-        'cpp/src', '../..',
+        'cpp/src', '../..', '<(prefix_dir)/include',
       ],
       # This macro must be define to suppress the use of exception
       'defines': [
