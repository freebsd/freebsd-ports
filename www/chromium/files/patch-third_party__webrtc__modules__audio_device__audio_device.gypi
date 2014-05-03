--- ./third_party/webrtc/modules/audio_device/audio_device.gypi.orig	2014-04-24 22:37:00.000000000 +0200
+++ ./third_party/webrtc/modules/audio_device/audio_device.gypi	2014-04-24 23:23:48.000000000 +0200
@@ -47,7 +47,7 @@
         'dummy/audio_device_utility_dummy.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'include_dirs': [
             'linux',
           ],
@@ -141,7 +141,7 @@
                 ],
               },
             }],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'defines': [
                 'LINUX_ALSA',
               ],
