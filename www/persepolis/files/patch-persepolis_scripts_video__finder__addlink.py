--- persepolis/scripts/video_finder_addlink.py.orig	2019-09-16 20:45:38 UTC
+++ persepolis/scripts/video_finder_addlink.py
@@ -24,9 +24,11 @@ from time import time, sleep
 from functools import partial
 from random import random
 from copy import deepcopy
-import youtube_dl
 import re
 import os
+import sys
+sys.path.append('/usr/local/bin/yt-dlp')
+import yt_dlp as youtube_dl
 
 # write youtube_dl version in log
 logger.sendToLog('youtube_dl version: '
