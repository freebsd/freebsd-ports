--- setup.py.orig	2015-05-19 20:23:13 UTC
+++ setup.py
@@ -61,8 +61,5 @@ setup(name = PACKAGE_NAME,
           include_dirs = include_dirs,
           library_dirs = library_dirs,
           libraries = libraries)],
-      scripts = ['tests/pcapytests.py', 'tests/96pings.pcap'],
-      data_files = [(os.path.join('share', 'doc', PACKAGE_NAME),
-                     ['README', 'LICENSE', 'pcapy.html'])],
       )
 
