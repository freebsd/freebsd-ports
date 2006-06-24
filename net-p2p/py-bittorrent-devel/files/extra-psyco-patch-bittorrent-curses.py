--- bittorrent-curses.py.orig	Tue Jun  6 20:43:25 2006
+++ bittorrent-curses.py	Thu Jun 15 14:45:05 2006
@@ -15,6 +15,13 @@
 
 from __future__ import division
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 from BitTorrent.translation import _
 
 SPEW_SCROLL_RATE = 1
