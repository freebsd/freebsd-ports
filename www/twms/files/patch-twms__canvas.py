--- twms/canvas.py.orig	2014-10-07 11:58:01 UTC
+++ twms/canvas.py
@@ -24,7 +24,7 @@
 
 
 import projections
-import Image, ImageFilter
+from PIL import Image, ImageFilter
 import urllib2
 import StringIO
 import datetime
@@ -132,4 +132,4 @@
       tiles = self.tiles.keys()
       for tile in tiles:
         self.tiles[tile]["im"] = self.tiles[tile]["im"].filter(ImageFilter.MedianFilter(size))
-        self.tiles[tile]["pix"] = self.tiles[tile]["im"].load()
\ No newline at end of file
+        self.tiles[tile]["pix"] = self.tiles[tile]["im"].load()
