--- setup.py.orig	2021-03-22 15:58:33 UTC
+++ setup.py
@@ -36,6 +36,9 @@ OS = platform.system()
 if OS not in ['Windows', 'Darwin']:
     if OS == 'Linux':
         DIST, DIST_VERSION, DIST_NAME = get_distro()
+    # platform.dist() returns "('', '', '')" on FreeBSD
+    elif OS == 'FreeBSD':
+        DIST, DIST_VERSION, DIST_NAME = ('', '', '')
     else:
         DIST, DIST_VERSION, DIST_NAME = platform.dist()
     NAME = NAME.lower()
