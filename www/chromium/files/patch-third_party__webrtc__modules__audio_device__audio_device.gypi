--- third_party/webrtc/modules/audio_device/audio_device.gypi.orig	2013-07-16 18:26:35.000000000 +0300
+++ third_party/webrtc/modules/audio_device/audio_device.gypi	2013-07-16 18:29:22.000000000 +0300
@@ -45,7 +45,7 @@
         'dummy/audio_device_utility_dummy.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'include_dirs': [
             'linux',
           ],
@@ -133,7 +133,7 @@
                 }],
               ],
             }],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'defines': [
                 'LINUX_ALSA',
               ],
