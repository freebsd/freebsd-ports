--- ./media/media.gyp.orig	2014-04-24 22:35:20.000000000 +0200
+++ ./media/media.gyp	2014-04-24 23:23:46.000000000 +0200
@@ -625,7 +625,7 @@
             'audio/openbsd/audio_manager_openbsd.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'variables': {
             'conditions': [
               ['sysroot!=""', {
@@ -885,7 +885,7 @@
             'base/simd/convert_yuv_to_rgb_x86.cc',
           ],
         }],
-        ['OS!="linux" and OS!="win"', {
+        ['OS!="linux" and OS!="win" and OS!="freebsd"', {
           'sources!': [
             'base/keyboard_event_counter.cc',
             'base/keyboard_event_counter.h',
