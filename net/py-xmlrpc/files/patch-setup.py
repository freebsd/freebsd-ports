--- setup.py.orig	Sun Apr 22 23:37:47 2001
+++ setup.py	Sun Apr 22 23:37:55 2001
@@ -4,7 +4,7 @@
 
 import sys
 
-if sys.platform[:5] == 'linux':
+if sys.platform[:7] == 'freebsd':
 	MACROS	= {'define' : []}
 	LIBS	= []
 else:
