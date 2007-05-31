--- ./bittorrent-tracker.py.orig	Thu Mar  1 22:12:51 2007
+++ ./bittorrent-tracker.py	Mon May  7 06:06:21 2007
@@ -12,6 +12,13 @@
 
 # Written by Bram Cohen
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 app_name = "BitTorrent"
 if __name__ == '__main__':
     from BitTorrent.translation import _
