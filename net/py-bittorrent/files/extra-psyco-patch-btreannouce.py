--- btreannounce.py.orig	Fri Mar 11 23:15:59 2005
+++ btreannounce.py	Fri Mar 11 23:16:05 2005
@@ -12,6 +12,15 @@
 
 # Written by Henry 'Pi' James and Bram Cohen
 
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
 from BitTorrent.bencode import bencode, bdecode
 
