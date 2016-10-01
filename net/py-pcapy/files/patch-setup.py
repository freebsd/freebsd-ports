--- setup.py.orig	2016-09-29 12:25:59 UTC
+++ setup.py
@@ -71,8 +71,4 @@ setup(name=PACKAGE_NAME,
           library_dirs=library_dirs,
           libraries=libraries)],
       # scripts=['tests/pcapytests.py', 'tests/96pings.pcap'],
-      data_files=[
-          (os.path.join('share', 'doc', PACKAGE_NAME),
-              ['README', 'LICENSE', 'pcapy.html']),
-          ('tests', ['tests/pcapytests.py', 'tests/96pings.pcap'])]
       )
