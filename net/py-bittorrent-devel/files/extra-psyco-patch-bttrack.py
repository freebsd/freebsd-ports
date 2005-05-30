--- bttrack.py.orig	Fri Mar 11 23:17:26 2005
+++ bttrack.py	Fri Mar 11 23:17:31 2005
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
 from sys import argv
 from BitTorrent.track import track
 
