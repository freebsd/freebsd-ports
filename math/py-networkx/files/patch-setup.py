--- setup.py.orig	2015-06-06 09:03:01 UTC
+++ setup.py
@@ -58,26 +58,7 @@ packages=["networkx",
           "networkx.testing",
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
-    dd = os.path.join(docdirbase,'examples', d)
-    pp = os.path.join('examples', d)
-    data.append((dd, glob(os.path.join(pp ,"*.py"))))
-    data.append((dd, glob(os.path.join(pp ,"*.bz2"))))
-    data.append((dd, glob(os.path.join(pp ,"*.gz"))))
-    data.append((dd, glob(os.path.join(pp ,"*.mbox"))))
-    data.append((dd, glob(os.path.join(pp ,"*.edgelist"))))
+data = [ ]
 
 # add the tests
 package_data     = {
