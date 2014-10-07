--- tools/infodump.py.orig	2014-10-06 16:48:04 UTC
+++ tools/infodump.py
@@ -41,7 +41,7 @@
 	print "Nevow Version: Unknown or Not Installed"
 
 try:
-	from Image import VERSION
+	from PIL.Image import VERSION
 	print "Python Imaging Library (PIL) Version: " + VERSION
 except:
 	print "Python Imaging Library (PIL) Version: Unknown or Not Installed"
