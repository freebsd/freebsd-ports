--- ./bittorrent-curses.py.orig	Thu Mar  1 22:12:51 2007
+++ ./bittorrent-curses.py	Mon May  7 06:06:21 2007
@@ -15,6 +15,13 @@
 
 from __future__ import division
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 app_name = "BitTorrent"
 from BitTorrent.translation import _
 
