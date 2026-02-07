--- textps.c.orig	1993-02-22 21:46:10.000000000 +0900
+++ textps.c	2013-04-27 23:04:41.000000000 +0900
@@ -41,10 +41,12 @@
 #endif /* not BOLD_FONT */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 
-extern char *malloc();
+#include <paper.h>
+
 extern char *optarg;
 extern int optind;
 
@@ -86,10 +88,24 @@
   exit(1);
 }
 
+const struct paper *findpaper(char *name)
+{
+	const struct paper *pp;
+
+	paperinit();
+	for (pp = paperfirst(); pp; pp = papernext(pp)) {
+		if (strcmp(name, papername(pp)) == 0)
+			return (pp);
+	}
+	return (NULL);
+}
+
 main(argc, argv)
 int argc;
 char **argv;
 {
+  const struct paper *pp;
+  char *name;
   int bad_files = 0;
   double cpi = 12.0;			/* characters per inch */
   int opt;
@@ -124,6 +140,12 @@
       abort();
     }
 
+  name = (char *)systempapername();
+  if (name == NULL)
+    name = (char *)defaultpapername();
+  if ((pp = findpaper(name)) != NULL)
+	page_length = paperpsheight(pp);
+
   char_width = 72.0/cpi;
   prologue();
   if (optind >= argc)
