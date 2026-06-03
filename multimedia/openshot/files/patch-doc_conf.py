--- doc/conf.py.orig	2026-03-18 21:17:58 UTC
+++ doc/conf.py
@@ -20,6 +20,7 @@ import sys
 import os
 import re
 import sys
+sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath('.')), "openshot_qt"))
 sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath('.')), "src"))
 
 from classes import info
