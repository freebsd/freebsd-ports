--- src/contact.py.orig	2014-10-06 16:48:44 UTC
+++ src/contact.py
@@ -13,7 +13,7 @@
 import globals
 import base64
 if not config.disableAvatars:
-	import Image
+	from PIL import Image
 import StringIO
 
 
