--- launchmany-console.py	Wed Oct 12 01:08:27 2005
+++ launchmany-console.py	Wed Oct 12 07:58:23 2005
@@ -12,6 +12,13 @@
 
 # Written by John Hoffman
 
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
