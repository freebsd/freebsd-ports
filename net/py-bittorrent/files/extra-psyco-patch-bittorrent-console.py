--- bittorrent-console.py	Wed Oct 12 01:08:15 2005
+++ bittorrent-console.py	Wed Oct 12 07:57:46 2005
@@ -14,6 +14,13 @@
 
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
 
