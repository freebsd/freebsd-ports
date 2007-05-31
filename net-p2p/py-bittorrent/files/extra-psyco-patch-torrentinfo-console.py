--- ./torrentinfo-console.py.orig	Thu Mar  1 22:13:28 2007
+++ ./torrentinfo-console.py	Mon May  7 06:06:21 2007
@@ -12,6 +12,13 @@
 
 # Written by Henry 'Pi' James, Loring Holden and Matt Chisholm
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 app_name = "BitTorrent"
 from BTL.translation import _
 
