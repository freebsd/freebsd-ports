--- btrename.py.orig	Fri Mar 11 23:16:21 2005
+++ btrename.py	Fri Mar 11 23:16:28 2005
@@ -12,6 +12,15 @@
 
 # Written by Henry 'Pi' James
 
+from BitTorrent import PSYCO
+if PSYCO.psyco:
+    try:
+       import psyco
+       assert psyco.__version__ >= 0x010300f0
+       psyco.full()
+    except:
+       pass
+
 from sys import *
 from os.path import *
 from sha import *
