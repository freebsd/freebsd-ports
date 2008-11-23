--- setup.py.orig	2008-11-19 21:40:27.000000000 +0800
+++ setup.py	2008-11-19 21:41:15.000000000 +0800
@@ -37,27 +37,6 @@
           "networkx.tests",
           ]
 
-docdirbase  = 'share/doc/networkx-%s' % version
-# add basic documentation 
-data = [(docdirbase, glob("*.txt"))]
-# add examples
-for d in ['advanced',
-          'algorithms',
-          'basic',
-          'drawing',
-          'graph',
-          'multigraph',
-          'pygraphviz',
-          'readwrite',
-          'ubigraph']:
-    dd=os.path.join(docdirbase,'examples',d)
-    pp=os.path.join('examples',d)
-    data.append((dd,glob(os.path.join(pp,"*.py"))))
-    data.append((dd,glob(os.path.join(pp,"*.bz2"))))
-    data.append((dd,glob(os.path.join(pp,"*.gz"))))
-    data.append((dd,glob(os.path.join(pp,"*.mbox"))))
-    data.append((dd,glob(os.path.join(pp,"*.edgelist"))))
-
 # add the tests
 package_data     = {'': ['tests/*.py'],
                     '': ['tests/*.txt'],
@@ -77,7 +56,6 @@
       url              = url,      
       download_url     = download_url,
       packages         = packages,
-      data_files       = data,
       package_data     = package_data, 
       classifiers      = classifiers,
       )
