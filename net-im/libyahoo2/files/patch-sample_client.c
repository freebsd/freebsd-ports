--- src/sample_client.c.orig	Sat May 17 03:33:06 2003
+++ src/sample_client.c	Wed May 21 08:38:45 2003
@@ -52,7 +52,6 @@
 #include <yahoo2_callbacks.h>
 #include "yahoo_util.h"
 
-int fileno(FILE * stream);
 
 
 #define MAX_PREF_LEN 255
@@ -186,7 +185,6 @@
 
 FILE *popen(const char *command, const char *type);
 int pclose(FILE *stream);
-int gethostname(char *name, size_t len);
 
 static char * get_local_addresses()
 {
