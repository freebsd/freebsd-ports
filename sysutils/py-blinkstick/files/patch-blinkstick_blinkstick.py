--- blinkstick/blinkstick.py.orig	2023-05-04 08:45:38 UTC
+++ blinkstick/blinkstick.py
@@ -1,4 +1,5 @@ from ._version import  __version__
 from ._version import  __version__
+import os
 import time
 import sys
 import re
@@ -820,7 +821,7 @@ class BlinkStick(object):
         if self.device is None:
             raise BlinkStickException("Could not find BlinkStick...")
 
-        if self.device.is_kernel_driver_active(0):
+        if os.geteuid() == 0 and self.device.is_kernel_driver_active(0):
             try:
                 self.device.detach_kernel_driver(0)
             except usb.core.USBError as e:
