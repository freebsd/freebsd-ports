--- tivo-parse.c.orig	Tue Jan  2 02:30:58 2007
+++ tivo-parse.c	Tue Jan  2 02:31:12 2007
@@ -8,6 +8,7 @@
 #ifdef WIN32
 #	include <windows.h>
 #else
+#	include <sys/types.h>
 #	include <netinet/in.h>
 #endif
 #include "sha1.h"
