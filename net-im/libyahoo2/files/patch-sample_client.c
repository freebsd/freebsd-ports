--- src/sample_client.c.orig	Sun Sep 28 10:40:03 2003
+++ src/sample_client.c	Tue Sep 30 21:35:55 2003
@@ -52,7 +52,6 @@
 #include <yahoo2_callbacks.h>
 #include "yahoo_util.h"
 
-int fileno(FILE * stream);
 
 
 #define MAX_PREF_LEN 255
@@ -177,7 +176,6 @@
 
 FILE *popen(const char *command, const char *type);
 int pclose(FILE *stream);
-int gethostname(char *name, size_t len);
 
 static char * get_local_addresses()
 {
