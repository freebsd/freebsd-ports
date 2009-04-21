--- setup.py.orig	2009-04-19 02:22:16.549958526 +0800
+++ setup.py	2009-04-19 02:24:10.837075743 +0800
@@ -60,7 +60,5 @@
           include_dirs = include_dirs,
           library_dirs = library_dirs,
           libraries = libraries)],
-      data_files = [(os.path.join('share', 'doc', PACKAGE_NAME),
-                     ['README', 'LICENSE', 'pcapy.html'])],
       )
 
