--- changetracker-console.py.orig	Tue Jun  6 20:43:34 2006
+++ changetracker-console.py	Thu Jun 15 14:45:47 2006
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
 
