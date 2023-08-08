--- vnpstext.c.orig	1992-09-02 21:01:59 UTC
+++ vnpstext.c
@@ -86,7 +86,8 @@ main(ac, av)
 dofile(input)
     FILE		*input;
 {
-    u_char		line[1024];
+#define LINESIZE 1024
+    u_char		line[LINESIZE];
     register u_char	*s;
     register int	pageno = 1;
     register short	col = 0;
@@ -95,7 +96,8 @@ dofile(input)
 
     printf("StartDoc\n");
 
-    while (gets(line)) {
+    while (fgets(line, LINESIZE, stdin)) {
+	if (line[ strlen(line) - 1 ] == '\n') line[ strlen(line) - 1 ] = '\0';
 	if (!*line) printf("B\n");
 	else {
 
@@ -180,7 +182,7 @@ doprolog(file)
 	printf("/S{Lcheck count{gsave show grestore}repeat 0 ld rmoveto}def\n");
 	printf("/L{Lcheck ld mul 0 exch rmoveto}def\n");
 	printf("/B{Lcheck 0 ld rmoveto}def\n");
-	return;
+	return 0;
     }
 
     /* filename specified, use it */
