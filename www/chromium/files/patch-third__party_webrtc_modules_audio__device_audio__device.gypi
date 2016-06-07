--- third_party/webrtc/modules/audio_device/audio_device.gypi.orig	2016-05-11 19:04:03 UTC
+++ third_party/webrtc/modules/audio_device/audio_device.gypi
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
