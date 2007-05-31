--- ./changetracker-console.py.orig	Thu Mar  1 22:12:53 2007
+++ ./changetracker-console.py	Mon May  7 06:06:21 2007
@@ -12,6 +12,13 @@
 
 # Written by Henry 'Pi' James and Bram Cohen
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 app_name = "BitTorrent"
 from BitTorrent.translation import _
 
