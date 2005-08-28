--- launchmany-console.py.orig	Tue Aug 23 22:49:16 2005
+++ launchmany-console.py	Tue Aug 23 22:50:30 2005
@@ -12,6 +12,15 @@
 
 # Written by John Hoffman
 
+from BitTorrent import PSYCO
+if PSYCO.psyco:
+    try:
+       import psyco
+       assert psyco.__version__ >= 0x010300f0
+       psyco.full()
+    except:
+       pass
+
 if __name__ == '__main__':
     import gettext
     gettext.install('bittorrent', 'locale')
