--- btlaunchmany.py	Thu Dec 16 11:03:11 2004
+++ btlaunchmany.py	Thu Dec 16 11:14:54 2004
@@ -7,6 +7,15 @@
 # fmttime and fmtsize stolen from btdownloadcurses. 
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
 from BitTorrent.download import download
 from threading import Thread, Event, Lock
 from os import listdir
