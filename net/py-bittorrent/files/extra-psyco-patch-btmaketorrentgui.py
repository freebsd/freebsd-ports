--- btmaketorrentgui.py.orig	Mon May 30 00:20:48 2005
+++ btmaketorrentgui.py	Mon May 30 00:21:00 2005
@@ -14,6 +14,15 @@
 
 from __future__ import division
 
+from BitTorrent import PSYCO
+if PSYCO.psyco:
+    try:
+       import psyco
+       assert psyco.__version__ >= 0x010300f0
+       psyco.full()
+    except:
+       pass
+
 import os
 import sys
 
