--- btmakemetafile.py	Thu Dec 16 11:03:11 2004
+++ btmakemetafile.py	Thu Dec 16 11:15:10 2004
@@ -3,6 +3,15 @@
 # Written by Bram Cohen
 # see LICENSE.txt for license information
 
+from BitTorrent import PSYCO
+if PSYCO.psyco:
+    try:
+	import psyco
+	assert psyco.__version__ >= 0x010300f0
+	psyco.full()
+    except:
+	pass
+
 from sys import argv
 from os.path import getsize, split, join, abspath, isdir
 from os import listdir
