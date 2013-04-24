--- psresize.c.orig	1997-03-12 07:53:03.000000000 +0900
+++ psresize.c	2012-03-03 03:02:24.000000000 +0900
@@ -20,6 +20,10 @@
 #include "pserror.h"
 #include "patchlev.h"
 
+#if defined(LIBPAPER)
+#include <paper.h>
+#endif
+
 char *program ;
 int pages ;
 int verbose ;
@@ -46,7 +50,7 @@
 #define MIN(x,y) ((x) > (y) ? (y) : (x))
 #define MAX(x,y) ((x) > (y) ? (x) : (y))
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    double scale, rscale;			/* page scale */
    double waste, rwaste;			/* amount wasted */
@@ -56,13 +60,21 @@
    double inheight = -1;
    Paper *paper;
    PageSpec *specs;
+   char *name = NULL;
 
+#if defined(LIBPAPER)
+	name = (char *)systempapername();
+	if (name == NULL)
+		name = (char *)defaultpapername();
+#else
 #ifdef PAPER
-   if ( (paper = findpaper(PAPER)) != (Paper *)0 ) {
-      inwidth = width = (double)PaperWidth(paper);
-      inheight = height = (double)PaperHeight(paper);
-   }
+	name = PAPER;
+#endif
 #endif
+	if ((paper = findpaper(name)) != NULL) {
+		inwidth = width = (double)PaperWidth(paper);
+		inheight = height = (double)PaperHeight(paper);
+	}
 
    vshift = hshift = 0;
    rotate = 0;
@@ -175,6 +187,6 @@
       
    pstops(1, 1, 0, specs, 0.0);		/* do page rearrangement */
 
-   exit(0);
+   return (0);
 }
 
