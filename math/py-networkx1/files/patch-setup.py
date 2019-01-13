--- setup.py.orig	2015-12-26 17:06:48 UTC
+++ setup.py
@@ -59,27 +59,6 @@ packages=["networkx",
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
-
 # add the tests
 package_data     = {
     'networkx': ['tests/*.py'],
@@ -131,7 +110,6 @@ if __name__ == "__main__":
         download_url     = release.download_url,
         classifiers      = release.classifiers,
         packages         = packages,
-        data_files       = data,
         package_data     = package_data,
         install_requires = install_requires,
         test_suite       = 'nose.collector',
