--- mls_text.h.orig	2003-02-15 10:16:07 UTC
+++ mls_text.h
@@ -30,7 +30,7 @@ void PrintTop(nTptr, int);
 void PrintTopQ(nTptr, int);
 void PrintTopHtml(nTptr, int);
 void PrintGraph(long[], int, int);
-void PrintGraphHtml(long[], long[][], int, char *);
+void PrintGraphHtml(long[], long[][SNUMB_LEN], int, char *);
 
 void PrintStatText(int, char *);
 void PrintStatHtml(int, char *, short);
