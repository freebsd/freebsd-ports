--- btdownloadcurses.py.orig	Fri Mar 11 23:12:10 2005
+++ btdownloadcurses.py	Fri Mar 11 23:13:08 2005
@@ -15,6 +15,15 @@
 
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
 SPEW_SCROLL_RATE = 1
 
 import sys
