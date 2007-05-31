--- ./launchmany-console.py.orig	Thu Mar  1 22:12:55 2007
+++ ./launchmany-console.py	Mon May  7 06:06:21 2007
@@ -13,6 +13,13 @@
 # Written by John Hoffman
 # Updated to 4.20 by David Harrison
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 app_name = "BitTorrent"
 if __name__ == '__main__':
     from BTL.translation import _
