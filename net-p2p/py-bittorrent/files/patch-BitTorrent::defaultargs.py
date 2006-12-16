--- BitTorrent/defaultargs.py.orig	Sat Dec 16 08:28:42 2006
+++ BitTorrent/defaultargs.py	Sat Dec 16 08:29:08 2006
@@ -19,6 +19,8 @@
 if os.name == 'posix':
     if os.uname()[0] in ['Darwin']:
         BAD_LIBC_WORKAROUND_DEFAULT = True
+    if os.uname()[0] in ['FreeBSD']:
+        BAD_LIBC_WORKAROUND_DEFAULT = True
 
 MAX_INCOMPLETE = 100
 MAX_FILES_OPEN = 50
