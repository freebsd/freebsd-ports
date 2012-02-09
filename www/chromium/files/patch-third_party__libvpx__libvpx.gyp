--- third_party/libvpx/libvpx.gyp.orig	2012-01-29 21:54:54.000000000 +0200
+++ third_party/libvpx/libvpx.gyp	2012-01-29 21:55:14.000000000 +0200
@@ -13,7 +13,7 @@
     ],
   },
   'conditions': [
-    [ '(OS=="linux" or OS=="mac" or OS=="win") and target_arch!="arm"', {
+    [ '(OS=="linux" or OS=="freebsd" or OS=="mac" or OS=="win") and target_arch!="arm"', {
       'targets': [
         {
           # This libvpx target contains both encoder and decoder.
