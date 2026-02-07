--- psutil.c.orig	2012-03-03 03:13:21.000000000 +0900
+++ psutil.c	2012-03-03 03:20:46.000000000 +0900
@@ -21,6 +21,11 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#if defined(LIBPAPER)
+#include <math.h>
+#include <paper.h>
+#endif
+
 #define iscomment(x,y) (strncmp(x,y,strlen(y)) == 0)
 
 extern char *program ;
@@ -42,6 +47,7 @@
 static int maxpages = 100;
 static long *pageptr;
 
+#if !defined(LIBPAPER)
 /* list of paper sizes supported */
 static Paper papersizes[] = {
    { "a3", 842, 1191 },		/* 29.7cm * 42cm */
@@ -70,6 +76,7 @@
 Paper* findpaper(char *name)
 {
    Paper *pp;
+
    for (pp = papersizes; PaperName(pp); pp++) {
       if (strcmp(PaperName(pp), name) == 0) {
 	 return pp;
@@ -77,6 +84,27 @@
    }
    return (Paper *)NULL;
 }
+#else
+static Paper pspec;
+
+Paper *findpaper(char *name)
+{
+	const struct paper *pp;
+
+	paperinit();
+	for (pp = paperfirst(); pp; pp = papernext(pp)) {
+		if (strcmp(name, papername(pp)) == 0) {
+			pspec.name = strdup(name);
+			pspec.width = round(paperpswidth(pp));
+			pspec.height = round(paperpsheight(pp));
+			return (&pspec);
+		}
+	}
+	return (NULL);
+}
+#endif
+
+
 
 /* Make a file seekable, using temporary files if necessary */
 FILE *seekable(FILE *fp)
