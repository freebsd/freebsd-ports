--- ./setup.py.orig	2013-04-28 16:58:49.000000000 +0000
+++ ./setup.py	2013-04-28 17:02:38.000000000 +0000
@@ -62,8 +62,5 @@
           include_dirs = include_dirs,
           library_dirs = library_dirs,
           libraries = libraries)],
-      scripts = ['tests/pcapytests.py', 'tests/96pings.pcap'],
-      data_files = [(os.path.join('share', 'doc', PACKAGE_NAME),
-                     ['README', 'LICENSE', 'pcapy.html'])],
       )
 
