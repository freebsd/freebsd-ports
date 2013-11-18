--- media/media.gyp.orig	2013-11-08 07:41:32.000000000 +0100
+++ media/media.gyp	2013-11-15 16:39:58.000000000 +0100
@@ -563,7 +563,7 @@
             'audio/openbsd/audio_manager_openbsd.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'variables': {
             'conditions': [
               ['sysroot!=""', {
@@ -836,7 +836,7 @@
             'ENABLE_EAC3_PLAYBACK',
           ],
         }],
-        ['OS!="linux" and OS!="win"', {
+        ['OS!="linux" and OS!="win" and OS!="freebsd"', {
           'sources!': [
             'base/keyboard_event_counter.cc',
             'base/keyboard_event_counter.h',
