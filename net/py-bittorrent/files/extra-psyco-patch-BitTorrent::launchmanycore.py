--- BitTorrent/launchmanycore.py.orig	Sat Mar 12 10:00:19 2005
+++ BitTorrent/launchmanycore.py	Sat Mar 12 10:00:40 2005
@@ -13,6 +13,15 @@
 # Original version written by John Hoffman, heavily modified for different
 # multitorrent architecture by Uoti Urpala (over 40% shorter than original)
 
+from BitTorrent import PSYCO
+if PSYCO.psyco:
+    try:
+       import psyco
+       assert psyco.__version__ >= 0x010300f0
+       psyco.full()
+    except:
+       pass
+
 import os
 from cStringIO import StringIO
 from traceback import print_exc
