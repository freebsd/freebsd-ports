--- third_party/sfntly/sfntly.gyp.orig	2015-10-14 03:01:24.000000000 -0400
+++ third_party/sfntly/sfntly.gyp	2015-10-23 14:16:34.022090000 -0400
@@ -126,7 +126,7 @@
         'src/cpp/src/sample/chromium/subsetter_impl.h',
       ],
       'include_dirs': [
-        'src/cpp/src',
+        'src/cpp/src', '<(prefix_dir)/include',
       ],
       # This macro must be define to suppress the use of exception
       'defines': [
