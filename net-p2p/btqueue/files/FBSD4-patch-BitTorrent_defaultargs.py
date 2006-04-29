--- BitTorrent/defaultargs.py.orig	Mon Apr  3 14:57:11 2006
+++ BitTorrent/defaultargs.py	Mon Apr  3 15:11:49 2006
@@ -29,10 +29,7 @@
 
 import os
 ### add your favorite here
-BAD_LIBC_WORKAROUND_DEFAULT = MYFALSE
-if os.name == 'posix':
-    if os.uname()[0] in ['Darwin']:
-        BAD_LIBC_WORKAROUND_DEFAULT = MYTRUE
+BAD_LIBC_WORKAROUND_DEFAULT = MYTRUE
 
 MIN_INCOMPLETE = 100
 if os.name == 'nt':
