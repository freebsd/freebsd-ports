--- ui/gfx/surface/surface.gyp.orig	2011-06-05 21:15:55.954163307 +0300
+++ ui/gfx/surface/surface.gyp	2011-06-05 21:16:05.238163089 +0300
@@ -10,11 +10,17 @@
       ['exclude', '/(gtk|win|x11)_[^/]*\\.cc$'],
     ],
     'conditions': [
-      ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {'sources/': [
+      ['OS=="linux"', {'sources/': [
         ['include', '/gtk/'],
         ['include', '_(gtk|linux|posix|skia|x)\\.cc$'],
         ['include', '/(gtk|x11)_[^/]*\\.cc$'],
       ]}],
+      ['OS=="freebsd" or OS=="openbsd"', {'sources/': [
+        # gliaskos: Use transport_dib_mac.cc instead of duplicating the code.
+        ['include', '/gtk/'],
+        ['include', '_(gtk|dib_mac|posix|skia|x)\\.cc$'],
+        ['include', '/(gtk|x11)_[^/]*\\.cc$'],
+      ]}],
       ['OS=="mac"', {'sources/': [
         ['include', '/cocoa/'],
         ['include', '_(cocoa|mac|posix)\\.(cc|mm?)$'],
