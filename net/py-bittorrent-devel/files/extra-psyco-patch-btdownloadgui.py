--- btdownloadgui.py.orig	Sun May 29 23:28:15 2005
+++ btdownloadgui.py	Sun May 29 23:31:03 2005
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
 
