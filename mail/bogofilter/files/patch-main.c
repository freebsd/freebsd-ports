--- bogofilter-0.8.0/main.c	Wed Nov  6 01:07:59 2002
+++ bogofilter-0.8.0.1/main.c	Mon Nov 11 02:28:08 2002
@@ -26,6 +26,9 @@
 #include "version.h"
 #include "common.h"
 #include "bogofilter.h"
+#include "find_home.h"
+#include "xmalloc.h"
+#include "xstrdup.h"
 
 #define BOGODIR ".bogofilter"
 
@@ -254,6 +257,16 @@
 {
     int   exitcode;
 
+    if (NULL == getenv("HOME")) {
+	const char *t;
+	if ((t = find_home(FALSE)) != NULL) {
+	    char *t2 = xmalloc(strlen(t) + 6);
+	    strcpy(t2, "HOME=");
+	    strcat(t2, t);
+	    putenv(xstrdup(t2)); /* putenv may leak memory by copying again */
+	    free(t2);
+	}
+    }
     set_dir_from_env(directory, "HOME", BOGODIR);
     set_dir_from_env(directory, "BOGOFILTER_DIR", NULL);
 
