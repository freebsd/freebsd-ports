--- changetracker-console.py.orig	Tue Aug 23 22:49:16 2005
+++ changetracker-console.py	Tue Aug 23 22:50:25 2005
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
 import gettext
 gettext.install('bittorrent', 'locale')
 
