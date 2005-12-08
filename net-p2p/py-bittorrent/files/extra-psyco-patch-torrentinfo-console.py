--- torrentinfo-console.py	Wed Oct 12 01:08:50 2005
+++ torrentinfo-console.py	Wed Oct 12 07:58:48 2005
@@ -12,6 +12,13 @@
 
 # Written by Henry 'Pi' James, Loring Holden and Matt Chisholm
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 from BitTorrent.platform import install_translation
 install_translation()
 
