--- BitTorrent/defaultargs.py.orig	Thu Dec  8 14:52:02 2005
+++ BitTorrent/defaultargs.py	Thu Dec  8 14:52:22 2005
@@ -33,6 +33,8 @@
 if os.name == 'posix':
     if os.uname()[0] in ['Darwin']:
         BAD_LIBC_WORKAROUND_DEFAULT = MYTRUE
+    if os.uname()[0] in ['FreeBSD']:
+        BAD_LIBC_WORKAROUND_DEFAULT = MYTRUE
     
 from BitTorrent import languages
 
