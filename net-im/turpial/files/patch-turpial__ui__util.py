--- ./turpial/ui/util.py.orig	2013-12-19 01:59:58.000000000 +0000
+++ ./turpial/ui/util.py	2014-02-22 11:49:20.000000000 +0000
@@ -8,10 +8,14 @@
 
 try:
     # TODO: Implement this function for other platforms
+    import ctypes
     if detect_os() == OS_LINUX:
-        import ctypes
         libc = ctypes.CDLL('libc.so.6')
         libc.prctl(15, 'turpial', 0, 0)
+    elif detect_os() == OS_FREEBSD or detect_os() == OS_DFLY:
+        import ctypes.util
+        libc = ctypes.cdll.LoadLibrary(ctypes.util.find_library('c'))
+        libc.setproctitle('turpial')
 except ImportError, exc:
     print exc
 
