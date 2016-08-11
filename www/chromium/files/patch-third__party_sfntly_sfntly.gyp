--- third_party/sfntly/sfntly.gyp.orig	2016-03-25 13:05:02 UTC
+++ third_party/sfntly/sfntly.gyp
@@ -127,6 +127,7 @@
       ],
       'include_dirs': [
         'src/cpp/src',
+        '<(prefix_dir)/include',
       ],
       # This macro must be define to suppress the use of exception
       'defines': [
