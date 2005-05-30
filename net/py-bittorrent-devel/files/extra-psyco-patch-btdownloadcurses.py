--- btdownloadcurses.py.orig	Sun May 29 23:28:15 2005
+++ btdownloadcurses.py	Sun May 29 23:30:23 2005
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
 
