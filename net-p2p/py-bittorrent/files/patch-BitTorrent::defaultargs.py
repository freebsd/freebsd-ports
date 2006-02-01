--- BitTorrent/defaultargs.py.orig	Wed Jan 11 19:16:54 2006
+++ BitTorrent/defaultargs.py	Wed Jan 11 19:17:16 2006
@@ -33,6 +33,8 @@
 if os.name == 'posix':
     if os.uname()[0] in ['Darwin']:
         BAD_LIBC_WORKAROUND_DEFAULT = MYTRUE
+    if os.uname()[0] in ['FreeBSD']:
+        BAD_LIBC_WORKAROUND_DEFAULT = MYTRUE
 
 MIN_INCOMPLETE = 100
 if os.name == 'nt':
