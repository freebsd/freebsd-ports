--- core/tesseract.py.orig	2014-10-06 16:41:31 UTC
+++ core/tesseract.py
@@ -26,9 +26,9 @@
 import subprocess
 import tempfile
 
-import ImageFile
-import Image
-import TiffImagePlugin
+from PIL import ImageFile
+from PIL import Image
+from PIL import TiffImagePlugin
 
 import cons
 
