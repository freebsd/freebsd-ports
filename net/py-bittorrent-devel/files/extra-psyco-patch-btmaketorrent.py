--- btmaketorrent.py.orig	Fri Mar 11 23:15:38 2005
+++ btmaketorrent.py	Fri Mar 11 23:15:43 2005
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
 import sys
 from BitTorrent.makemetafile import make_meta_files
 from BitTorrent.parseargs import parseargs, printHelp
