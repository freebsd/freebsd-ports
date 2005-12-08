--- bittorrent.py	Wed Oct 12 01:08:18 2005
+++ bittorrent.py	Wed Oct 12 07:58:12 2005
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
 
