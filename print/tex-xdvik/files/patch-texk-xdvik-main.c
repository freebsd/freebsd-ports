--- main.c.orig	2014-04-03 10:17:12.000000000 +0900
+++ main.c	2014-08-22 23:24:13.000000000 +0900
@@ -39,6 +39,9 @@
 #include "filehist.h"
 #include "mag.h"
 #include "message-window.h"
+#ifdef HAVE_LIBPAPER
+#include <paper.h>
+#endif
 
 #if FREETYPE
 # include <ft2build.h>
@@ -651,8 +654,16 @@
 
     /* paper type */
     if (!set_paper_type(resource.paper)) {
-	const char **p;
 	char *helpmsg = xstrdup("Possible paper types are:\n    ");
+#ifdef HAVE_LIBPAPER
+	const struct paper *pp;
+
+	for (pp = paperfirst(); pp; pp = papernext(pp)) {
+		helpmsg = xstrcat(helpmsg, papername(pp));
+		helpmsg = xstrcat(helpmsg, " ");
+	}
+#else
+	const char **p;
 	const char **paper_types = get_paper_types();
 	for (p = paper_types; p < paper_types + get_paper_types_size(); p += 2) {
 	    if (**p == '\0') { /* next line of list */
@@ -663,6 +674,7 @@
 		helpmsg = xstrcat(helpmsg, " ");
 	    }
 	}
+#endif
 	helpmsg = xstrcat(helpmsg,
 			  "\n(the names ending with `r' are `rotated' or `landscape' variants).\n"
 			  "Alternatively, you can specify the dimensions as `WIDTHxHEIGHT', followed "
