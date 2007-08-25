--- mls_text.h.orig	2007-08-26 03:29:23.000000000 +0800
+++ mls_text.h	2007-08-26 03:30:12.000000000 +0800
@@ -30,7 +30,7 @@
 void PrintTopQ(nTptr, int);
 void PrintTopHtml(nTptr, int);
 void PrintGraph(long[], int, int);
-void PrintGraphHtml(long[], long[][], int, char *);
+void PrintGraphHtml(long[], long[][SNUMB_LEN], int, char *);
 
 void PrintStatText(int, char *);
 void PrintStatHtml(int, char *, short);
