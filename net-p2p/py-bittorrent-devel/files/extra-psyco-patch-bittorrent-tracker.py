--- bittorrent-tracker.py	Wed Oct 12 01:08:15 2005
+++ bittorrent-tracker.py	Wed Oct 12 07:57:55 2005
@@ -12,6 +12,13 @@
 
 # Written by Bram Cohen
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 if __name__ == '__main__':
     from BitTorrent.platform import install_translation
     install_translation()
