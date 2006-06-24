--- torrentinfo-console.py.orig	Tue Jun  6 20:44:39 2006
+++ torrentinfo-console.py	Thu Jun 15 14:47:13 2006
@@ -12,6 +12,13 @@
 
 # Written by Henry 'Pi' James, Loring Holden and Matt Chisholm
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 from BitTorrent.translation import _
 
 from sys import *
