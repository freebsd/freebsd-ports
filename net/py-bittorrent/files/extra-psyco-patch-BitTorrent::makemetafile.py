--- BitTorrent/makemetafile.py.orig	Sat Mar 12 09:58:42 2005
+++ BitTorrent/makemetafile.py	Sat Mar 12 09:59:06 2005
@@ -12,6 +12,15 @@
 
 # Written by Bram Cohen
 
+from BitTorrent import PSYCO
+if PSYCO.psyco:
+    try:
+       import psyco
+       assert psyco.__version__ >= 0x010300f0
+       psyco.full()
+    except:
+       pass
+
 from __future__ import division
 
 import os
