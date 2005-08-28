--- bittorrent.py.orig	Tue Aug 23 22:49:16 2005
+++ bittorrent.py	Tue Aug 23 22:50:20 2005
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
 from BitTorrent.platform import locale_root
 
 import gettext
