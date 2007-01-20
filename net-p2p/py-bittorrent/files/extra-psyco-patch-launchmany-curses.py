--- launchmany-curses.py.orig	Tue Jun  6 20:43:42 2006
+++ launchmany-curses.py	Thu Jun 15 14:46:16 2006
@@ -13,6 +13,14 @@
 
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
 
