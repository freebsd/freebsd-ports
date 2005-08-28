--- torrentinfo-console.py.orig	Tue Aug 23 22:49:16 2005
+++ torrentinfo-console.py	Tue Aug 23 22:50:55 2005
@@ -12,6 +12,15 @@
 
 # Written by Henry 'Pi' James, Loring Holden and Matt Chisholm
 
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
 
