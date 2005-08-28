--- bittorrent-curses.py.orig	Tue Aug 23 22:49:16 2005
+++ bittorrent-curses.py	Tue Aug 23 22:49:59 2005
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
 import gettext
 gettext.install('bittorrent', 'locale')
 
