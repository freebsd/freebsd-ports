--- maketorrent-console.py.orig	Tue Aug 23 22:49:16 2005
+++ maketorrent-console.py	Tue Aug 23 22:50:41 2005
@@ -12,6 +12,15 @@
 
 # Written by Bram Cohen
 
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
