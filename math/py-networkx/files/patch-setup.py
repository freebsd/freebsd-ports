--- setup.py.orig	2010-08-04 18:13:53.000000000 +0900
+++ setup.py	2010-08-04 18:14:18.000000000 +0900
@@ -45,26 +45,6 @@
           "networkx.readwrite",
           "networkx.tests"]
 
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
-          'readwrite']:
-    dd=os.path.join(docdirbase,'examples',d)
-    pp=os.path.join('examples',d)
-    data.append((dd,glob(os.path.join(pp,"*.py"))))
-    data.append((dd,glob(os.path.join(pp,"*.bz2"))))
-    data.append((dd,glob(os.path.join(pp,"*.gz"))))
-    data.append((dd,glob(os.path.join(pp,"*.mbox"))))
-    data.append((dd,glob(os.path.join(pp,"*.edgelist"))))
-
 # add the tests
 package_data     = {
     'networkx': ['tests/*.py'],
@@ -102,7 +82,6 @@
         download_url     = release.download_url,
         classifiers      = release.classifiers,
         packages         = packages,
-        data_files       = data,
         package_data     = package_data
       )
 
