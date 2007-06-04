--- src/fileschanged.c.orig	Wed Apr 19 21:42:28 2006
+++ src/fileschanged.c	Mon Jun  4 21:30:49 2007
@@ -3,7 +3,6 @@
 #include <signal.h>
 #include <fam.h>
 #include <errno.h>
-#include <error.h>
 #include "config.h"
 #include "gettext.h"
 #include "fileschanged.h"
@@ -15,6 +14,10 @@
 #include "handlers.h"
 extern struct arguments_t arguments;
 struct fileschanged_appstate_t app;
+
+static void error (int status, int errnum, const char *format) {
+	fprintf(stderr, "%s\n", format);
+}
 
 static void 
 show_changed_file (char *filename, struct stat *statbuf)
