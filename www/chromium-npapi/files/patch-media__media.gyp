--- ./media/media.gyp.orig	2014-04-30 22:41:24.000000000 +0200
+++ ./media/media.gyp	2014-05-04 14:38:48.000000000 +0200
@@ -641,7 +641,7 @@
             'audio/openbsd/audio_manager_openbsd.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'conditions': [
             ['use_x11==1', {
               'dependencies': [
@@ -892,7 +892,7 @@
             'base/simd/convert_yuv_to_rgb_x86.cc',
           ],
         }],
-        ['OS!="linux" and OS!="win"', {
+        ['OS!="linux" and OS!="win" and OS!="freebsd"', {
           'sources!': [
             'base/keyboard_event_counter.cc',
             'base/keyboard_event_counter.h',
