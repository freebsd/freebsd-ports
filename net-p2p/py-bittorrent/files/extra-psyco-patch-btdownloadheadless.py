--- btdownloadheadless.py.orig	Fri Mar 11 23:14:21 2005
+++ btdownloadheadless.py	Fri Mar 11 23:14:28 2005
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
 import os
 import threading
