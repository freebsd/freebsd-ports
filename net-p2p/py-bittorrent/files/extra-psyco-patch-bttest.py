--- bttest.py.orig	Fri Mar 11 23:17:05 2005
+++ bttest.py	Fri Mar 11 23:17:12 2005
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
 from BitTorrent import testtest
 import bttrack
 import btmakemetafile
