--- ui/gl/gl.gyp.orig	2013-07-04 06:47:11.000000000 +0300
+++ ui/gl/gl.gyp	2013-07-15 19:31:47.000000000 +0300
@@ -188,7 +188,7 @@
         },
       ],
       'conditions': [
-        ['OS in ("win", "android") or (OS == "linux" and use_x11 == 1)', {
+        ['OS in ("win", "android") or ((OS == "linux" or os_bsd == 1) and use_x11 == 1)', {
           'sources': [
             'async_pixel_transfer_delegate_egl.cc',
             'async_pixel_transfer_delegate_egl.h',
