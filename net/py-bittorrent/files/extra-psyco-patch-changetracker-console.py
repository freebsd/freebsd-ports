--- changetracker-console.py	Wed Oct 12 01:08:18 2005
+++ changetracker-console.py	Wed Oct 12 07:58:18 2005
@@ -12,6 +12,13 @@
 
 # Written by Henry 'Pi' James and Bram Cohen
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 from BitTorrent.platform import install_translation
 install_translation()
 
