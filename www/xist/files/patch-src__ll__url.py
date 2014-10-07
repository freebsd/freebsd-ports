--- src/ll/url.py.orig	2014-10-07 12:02:25 UTC
+++ src/ll/url.py
@@ -57,7 +57,7 @@
 	execnet = None
 
 try:
-	import Image
+	from PIL import Image
 except ImportError:
 	pass
 
