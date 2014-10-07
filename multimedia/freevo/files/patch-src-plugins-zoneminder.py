--- src/plugins/zoneminder.py.orig	2014-10-06 12:02:58 UTC
+++ src/plugins/zoneminder.py
@@ -50,7 +50,7 @@
 import pygame
 import MySQLdb
 import threading
-import ImageFile
+from PIL import ImageFile
 
 # Freevo
 import config
