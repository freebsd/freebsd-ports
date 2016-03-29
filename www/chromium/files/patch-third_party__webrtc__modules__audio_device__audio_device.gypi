--- third_party/webrtc/modules/audio_device/audio_device.gypi.orig	2016-03-05 14:34:43.377223299 +0100
+++ third_party/webrtc/modules/audio_device/audio_device.gypi	2016-03-05 14:36:01.230217200 +0100
@@ -47,7 +47,7 @@
         'fine_audio_buffer.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'include_dirs': [
             'linux',
           ],
@@ -113,7 +113,7 @@
                 ],
               },
             }],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'sources': [
                 'linux/alsasymboltable_linux.cc',
                 'linux/alsasymboltable_linux.h',
