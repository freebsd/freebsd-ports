--- btreannounce.py.orig	Wed Aug 17 15:24:19 2005
+++ btreannounce.py	Mon Aug 22 23:06:19 2005
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
 from os.path import basename
 from sys import argv, exit
 from BitTorrent.bencode import bencode, bdecode
