--- ./libturpial/common/tools.py.orig	2014-01-18 13:59:52.000000000 +0000
+++ ./libturpial/common/tools.py	2014-02-22 11:26:39.000000000 +0000
@@ -33,6 +33,11 @@
     """ Returns a string according to the OS host """
     if sys.platform.startswith('linux'):
         return OS_LINUX
+    elif sys.platform.startswith('freebsd'):
+        return OS_FREEBSD
+    # Need test on real DragonFly system instead of guess 
+    elif 'dragonfly' in sys.platform:
+        return OS_DFLY
     elif sys.platform.startswith('win32'):
         return OS_WINDOWS
     elif sys.platform.startswith('darwin'):
