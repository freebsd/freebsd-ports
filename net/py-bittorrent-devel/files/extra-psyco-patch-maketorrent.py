--- maketorrent.py.orig	Tue Aug 23 22:49:16 2005
+++ maketorrent.py	Tue Aug 23 22:50:45 2005
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
 import gettext
 gettext.install('bittorrent', 'locale')
 
