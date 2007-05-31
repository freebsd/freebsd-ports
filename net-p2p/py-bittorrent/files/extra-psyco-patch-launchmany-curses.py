--- ./launchmany-curses.py.orig	Thu Mar  1 22:12:55 2007
+++ ./launchmany-curses.py	Mon May  7 06:06:21 2007
@@ -14,8 +14,16 @@
 # License.
 
 # Written by John Hoffman

 from __future__ import division
+
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 app_name = "BitTorrent"
 from BTL.translation import _
 
