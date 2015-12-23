--- third_party/sfntly/sfntly.gyp.orig	2015-12-04 23:48:12.085644000 +0100
+++ third_party/sfntly/sfntly.gyp	2015-12-04 23:48:36.966732000 +0100
@@ -127,6 +127,7 @@
       ],
       'include_dirs': [
         'src/cpp/src',
+        '<(prefix_dir)/include',
       ],
       # This macro must be define to suppress the use of exception
       'defines': [
