--- launchmany-curses.py	Wed Oct 12 01:08:27 2005
+++ launchmany-curses.py	Wed Oct 12 07:58:27 2005
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
 
