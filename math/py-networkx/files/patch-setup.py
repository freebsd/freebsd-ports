--- setup.py.orig	2010-01-09 08:30:12.000000000 +0800
+++ setup.py	2010-01-09 08:31:47.000000000 +0800
@@ -38,27 +38,6 @@
           "networkx.tests",
           ]
 
-docdirbase  = 'share/doc/networkx-%s' % release.version
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
@@ -82,7 +61,6 @@
         download_url     = release.download_url,
         classifiers      = release.classifiers,
         packages         = packages,
-        data_files       = data,
         package_data     = package_data
       )
 
