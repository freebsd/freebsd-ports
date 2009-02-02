--- src/www/configlib.py.orig	2008-02-21 15:49:20.000000000 -0500
+++ src/www/configlib.py	2009-01-13 21:39:28.000000000 -0500
@@ -53,7 +53,7 @@
     """
     get pid of running 'name'
     """
-    for fname in ('/var/run/' + name  + '-%s.pid' % os.getuid(),
+    for fname in ('/var/run/freevo/' + name  + '-%s.pid' % os.getuid(),
                   '/tmp/' + name + '-%s.pid' % os.getuid()):
         if os.path.isfile(fname):
             f = open(fname)
