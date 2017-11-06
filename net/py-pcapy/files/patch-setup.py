--- setup.py.orig	2017-02-09 00:45:41 UTC
+++ setup.py
@@ -77,10 +77,6 @@ setup(name=PACKAGE_NAME,
           define_macros=macros,
           include_dirs=include_dirs,
           library_dirs=library_dirs,
-          libraries=libraries)],
+          libraries=libraries)]
       # scripts=['tests/pcapytests.py', 'tests/96pings.pcap'],
-      data_files=[
-          (os.path.join('share', 'doc', PACKAGE_NAME),
-              ['README', 'LICENSE', 'pcapy.html']),
-          ('tests', ['tests/pcapytests.py', 'tests/96pings.pcap'])]
       )
