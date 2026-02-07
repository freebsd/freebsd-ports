--- sphinxclient.c.orig	2010-07-15 15:05:40.000000000 +0400
+++ sphinxclient.c	2011-06-03 17:56:23.000000000 +0400
@@ -17,9 +17,6 @@
 // VS 2005 and above
 #define _CRT_SECURE_NO_DEPRECATE 1
 #define _CRT_NONSTDC_NO_DEPRECATE 1
-#else
-// VS 2003 and below
-#define vsnprintf _vsnprintf
 #endif
 
 #include <stdlib.h>
