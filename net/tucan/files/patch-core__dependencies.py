--- core/dependencies.py.orig	2014-10-06 16:41:03 UTC
+++ core/dependencies.py
@@ -55,7 +55,7 @@
 		""""""
 		self.checked[cons.DEPENDENCY_TESSERACT] = None
 		try:
-			import Image
+			from PIL import Image
 		except:
 			message = "PIL not found."
 			self.checked[cons.DEPENDENCY_TESSERACT] = message
