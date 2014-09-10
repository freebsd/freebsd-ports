--- ./third_party/webrtc/modules/audio_device/audio_device.gypi.orig	2014-08-20 21:04:06.000000000 +0200
+++ ./third_party/webrtc/modules/audio_device/audio_device.gypi	2014-08-22 15:06:27.000000000 +0200
@@ -49,7 +49,7 @@
         'dummy/file_audio_device.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'include_dirs': [
             'linux',
           ],
@@ -150,7 +150,7 @@
                 ],
               },
             }],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'defines': [
                 'LINUX_ALSA',
               ],
