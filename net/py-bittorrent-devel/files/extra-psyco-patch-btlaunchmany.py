--- btlaunchmany.py.orig	Fri Mar 11 23:14:47 2005
+++ btlaunchmany.py	Fri Mar 11 23:14:54 2005
@@ -12,6 +12,15 @@
 
 # Written by John Hoffman
 
+from BitTorrent import PSYCO
+if PSYCO.psyco:
+    try:
+       import psyco
+       assert psyco.__version__ >= 0x010300f0
+       psyco.full()
+    except:
+       pass
+
 import sys
 import os
 
