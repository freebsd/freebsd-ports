--- subsystem/startstop/startstop.py.orig	Sat Nov 20 14:56:54 2004
+++ subsystem/startstop/startstop.py	Sat Nov 20 14:58:56 2004
@@ -253,6 +253,7 @@
 
         initBlock.append('BINDIR=' + BINDIR)
         initBlock.append('LOCALSTATEDIR=' + LOCALSTATEDIR)
+        initBlock.append('PATH=/usr/bin:/bin:/usr/local/bin')
 
         # Set up a default MAILTO directive
         mailto='root@localhost'
