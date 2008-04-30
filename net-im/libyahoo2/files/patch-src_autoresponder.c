--- src/autoresponder.c.orig	2008-04-30 05:09:22.000000000 +0000
+++ src/autoresponder.c	2008-04-30 05:09:31.000000000 +0000
@@ -58,7 +58,7 @@
 #include "yahoo_util.h"
 
 #ifndef _WIN32
-int fileno(FILE * stream);
+//int fileno(FILE * stream);
 #endif
 
 #define MAX_PREF_LEN 255
