--- persepolis/scripts/play.py.orig	2019-09-16 20:45:38 UTC
+++ persepolis/scripts/play.py
@@ -16,6 +16,8 @@ from persepolis.scripts import logger
 from PyQt5.QtCore import QSettings
 import subprocess
 import platform
+from pyogg import VorbisFile
+from ossaudiodev import open as ossOpen, AFMT_S16_NE
 
 os_type = platform.system()
 
@@ -36,18 +38,11 @@ def playNotification(file):
     if enable_notification == 'yes':
         if os_type == 'Linux' or os_type == 'FreeBSD' or os_type == 'OpenBSD':
 
-            pipe = subprocess.Popen(['paplay', '--volume=' + str(volume),
-                                     str(file)],
-                                    stderr=subprocess.PIPE,
-                                    stdout=subprocess.PIPE,
-                                    stdin=subprocess.PIPE,
-                                    shell=False)
-
-            answer = pipe.wait()
-
-            if answer != 0:
-                logger.sendToLog(
-                    "paplay not installed!Install it for playing sound notification", "WARNING")
+            sound = VorbisFile(file)
+            dsp = ossOpen('/dev/dsp', 'w')
+            dsp.setparameters(AFMT_S16_NE, sound.channels, sound.frequency)
+            dsp.write(sound.buffer)
+            dsp.close()
 
         elif os_type == 'Darwin':
 
