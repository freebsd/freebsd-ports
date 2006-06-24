--- maketorrent.py.orig	Tue Jun  6 20:43:43 2006
+++ maketorrent.py	Thu Jun 15 14:46:45 2006
@@ -14,6 +14,13 @@
 
 from __future__ import division
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 from BitTorrent.translation import _
 
 import os
