--- twms/fetchers.py.orig	2014-10-07 11:58:04 UTC
+++ twms/fetchers.py
@@ -21,7 +21,7 @@
 import math
 import sys
 import StringIO
-import Image
+from PIL import Image
 
 import config
 import projections
@@ -115,4 +115,4 @@
         tne.close()
         os.remove(local+ this_layer["ext"])
       return False
-   return im
\ No newline at end of file
+   return im
