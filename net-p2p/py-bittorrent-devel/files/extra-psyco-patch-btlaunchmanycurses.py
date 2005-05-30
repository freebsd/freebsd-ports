--- btlaunchmanycurses.py.orig	Fri Mar 11 23:15:15 2005
+++ btlaunchmanycurses.py	Fri Mar 11 23:15:22 2005
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
 DOWNLOAD_SCROLL_RATE = 1
 
 import sys, os
