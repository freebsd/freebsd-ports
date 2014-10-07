--- src/imgmanip.py.orig	2014-10-06 16:49:20 UTC
+++ src/imgmanip.py
@@ -5,7 +5,7 @@
 
 if not config.disableAvatars:
 	try:
-		import Image
+		from PIL import Image
 		import StringIO
 
 		def convertToPNG(imageData):
