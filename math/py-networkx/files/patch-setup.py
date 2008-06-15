--- setup.py.orig	2007-12-22 03:44:22.000000000 +0800
+++ setup.py	2008-06-16 05:02:58.000000000 +0800
@@ -33,11 +33,11 @@
           "networkx.tests.readwrite",
           ]
 
-docdirbase  = 'share/doc/networkx-%s' % version
+docdirbase  = '%%DOCSDIR%%'
 data = [(docdirbase, glob("doc/*.txt")),
-        (os.path.join(docdirbase, 'examples'),glob("doc/examples/*.py")),
-        (os.path.join(docdirbase, 'examples'),glob("doc/examples/*.dat")),
-        (os.path.join(docdirbase, 'examples'),glob("doc/examples/*.edges")),
+        ('%%EXAMPLESDIR%%',glob("doc/examples/*.py")),
+        ('%%EXAMPLESDIR%%',glob("doc/examples/*.dat")),
+        ('%%EXAMPLESDIR%%',glob("doc/examples/*.edges")),
         (os.path.join(docdirbase, 'data'),glob("doc/data/*ls")),
         ]
 
