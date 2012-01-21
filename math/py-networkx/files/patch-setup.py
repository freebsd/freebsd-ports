--- setup.py.orig	2011-11-19 02:31:31.000000000 +0100
+++ setup.py	2012-01-21 21:04:35.000000000 +0100
@@ -53,26 +53,7 @@
           "networkx.tests",
           "networkx.utils"]
 
-docdirbase  = 'share/doc/networkx-%s' % version
-# add basic documentation 
-data = [(docdirbase, glob("*.txt"))]
-# add examples
-for d in ['advanced',
-          'algorithms',
-          'basic',
-          '3d_drawing',
-          'drawing',
-          'graph',
-          'multigraph',
-          'pygraphviz',
-          'readwrite']:
-    dd=os.path.join(docdirbase,'examples',d)
-    pp=os.path.join('examples',d)
-    data.append((dd,glob(os.path.join(pp,"*.py"))))
-    data.append((dd,glob(os.path.join(pp,"*.bz2"))))
-    data.append((dd,glob(os.path.join(pp,"*.gz"))))
-    data.append((dd,glob(os.path.join(pp,"*.mbox"))))
-    data.append((dd,glob(os.path.join(pp,"*.edgelist"))))
+data = [ ]
 
 # add the tests
 package_data     = {
