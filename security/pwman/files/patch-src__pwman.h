--- src/pwman.h.orig	2017-05-01 16:59:03 UTC
+++ src/pwman.h
@@ -26,6 +26,7 @@
 #include <string.h>
 #include <config.h>
 #include <time.h>
+#include <stdlib.h>
 #include <stdarg.h>
 
 #define CONF_FILE 	".pwmanrc" 
@@ -112,12 +113,12 @@ typedef struct {
 	int sign_db;
 } Options;
 
-Options *options;
-int write_options;
-PWList *pwlist;
-PWList *current_pw_sublist;
-PWSearchResult *search_results;
-time_t time_base;
+extern Options *options;
+extern int write_options;
+extern PWList *pwlist;
+extern PWList *current_pw_sublist;
+extern PWSearchResult *search_results;
+extern time_t time_base;
 
 char *trim_ws(char*);
 void debug(char*, ...);
