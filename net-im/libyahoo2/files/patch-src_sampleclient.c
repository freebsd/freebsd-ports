--- src/sample_client.c.orig	2008-04-30 05:08:50.000000000 +0000
+++ src/sample_client.c	2008-04-30 05:09:08.000000000 +0000
@@ -58,7 +58,7 @@
 #include "yahoo_util.h"
 
 #ifndef _WIN32
-int fileno(FILE * stream);
+// int fileno(FILE * stream);
 #endif
 
 #define MAX_PREF_LEN 255
