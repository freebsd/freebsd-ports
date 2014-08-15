--- ./third_party/sfntly/sfntly.gyp.orig	2014-08-12 21:02:45.000000000 +0200
+++ ./third_party/sfntly/sfntly.gyp	2014-08-13 09:56:59.000000000 +0200
@@ -126,7 +126,7 @@
         'cpp/src/sample/chromium/subsetter_impl.h',
       ],
       'include_dirs': [
-        'cpp/src', '../..',
+        'cpp/src', '../..', '<(prefix_dir)/include',
       ],
       # This macro must be define to suppress the use of exception
       'defines': [
