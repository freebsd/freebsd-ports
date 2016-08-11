--- global.c.orig	2005-04-19 22:26:50 UTC
+++ global.c
@@ -1307,12 +1307,12 @@ fgetstr(FILE * f)
 }
 
 /*
- *	getline - gets a line from stdin
+ *	get_line - gets a line from stdin
  *			returns the length of the line
  */
 
 int
-getline(char *line, int max)
+get_line(char *line, int max)
 {
     if (fgets(line, max, stdin) == NULL)
 	return 0;
