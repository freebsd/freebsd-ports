--- ./vnpstext.c.orig	1992-09-02 23:01:59.000000000 +0200
+++ ./vnpstext.c	2013-05-27 16:27:32.390245389 +0200
@@ -86,7 +86,8 @@
 dofile(input)
     FILE		*input;
 {
-    u_char		line[1024];
+#define LINESIZE 1024
+    u_char		line[LINESIZE];
     register u_char	*s;
     register int	pageno = 1;
     register short	col = 0;
@@ -95,7 +96,8 @@
 
     printf("StartDoc\n");
 
-    while (gets(line)) {
+    while (fgets(line, LINESIZE, stdin)) {
+	if (line[ strlen(line) - 1 ] == '\n') line[ strlen(line) - 1 ] = '\0';
 	if (!*line) printf("B\n");
 	else {
 
@@ -180,7 +182,7 @@
 	printf("/S{Lcheck count{gsave show grestore}repeat 0 ld rmoveto}def\n");
 	printf("/L{Lcheck ld mul 0 exch rmoveto}def\n");
 	printf("/B{Lcheck 0 ld rmoveto}def\n");
-	return;
+	return NULL;
     }
 
     /* filename specified, use it */
