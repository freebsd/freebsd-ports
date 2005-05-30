--- btdownloadgui.py.orig	Mon May 30 00:19:57 2005
+++ btdownloadgui.py	Mon May 30 00:20:19 2005
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
 import sys
 
 assert sys.version_info >= (2, 3), "Install Python 2.3 or greater"
