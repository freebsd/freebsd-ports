--- bittorrent-curses.py	Wed Oct 12 01:08:15 2005
+++ bittorrent-curses.py	Wed Oct 12 07:57:28 2005
@@ -15,6 +15,13 @@
 
 from __future__ import division
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 from BitTorrent.platform import install_translation
 install_translation()
 
