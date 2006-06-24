--- BitTorrent/defaultargs.py.orig	Sat Jun 24 15:17:24 2006
+++ BitTorrent/defaultargs.py	Sat Jun 24 15:17:33 2006
@@ -20,6 +20,8 @@
 if os.name == 'posix':
     if os.uname()[0] in ['Darwin']:
         BAD_LIBC_WORKAROUND_DEFAULT = True
+    if os.uname()[0] in ['FreeBSD']:
+        BAD_LIBC_WORKAROUND_DEFAULT = True
 
 MAX_INCOMPLETE = 100
 MAX_FILES_OPEN = 50
