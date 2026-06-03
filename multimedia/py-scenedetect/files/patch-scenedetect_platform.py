--- scenedetect/platform.py.orig	2022-11-29 01:37:13 UTC
+++ scenedetect/platform.py
@@ -25,6 +25,7 @@ import subprocess
 import sys
 from typing import AnyStr, Dict, List, Optional, Union
 
+import numpy
 import cv2
 
 ##
