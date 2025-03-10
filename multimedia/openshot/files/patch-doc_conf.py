--- doc/conf.py.orig	2024-12-22 02:37:46 UTC
+++ doc/conf.py
@@ -19,6 +19,7 @@
 #
 import os
 import sys
+sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath('.')), "openshot_qt"))
 sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath('.')), "src"))
 
 from classes import info
