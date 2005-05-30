--- btreannounce.py.orig	Tue May 24 03:01:08 2005
+++ btreannounce.py	Sun May 29 22:46:38 2005
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
 
