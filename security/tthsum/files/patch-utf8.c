--- utf8.c.orig	Sun Sep 25 14:23:55 2005
+++ utf8.c	Sun Sep 25 14:24:06 2005
@@ -24,7 +24,7 @@
 #	define WINDOWS_LEAN_AND_MEAN
 #	include <windows.h>
 #endif /* _WIN32 */
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 /*
