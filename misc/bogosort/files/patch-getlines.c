--- getlines.c.orig	2002-05-04 20:22:22 UTC
+++ getlines.c
@@ -49,7 +49,7 @@ getlines(FILE *stream)
     char **ss = NULL;
 
     /* read all lines available */
-    while ((s = getline(stream)) != NULL) {
+    while ((s = get_line(stream)) != NULL) {
 	if (numlines == allocated)		/* make more room if needed */
 	    ss = (char **)xrealloc(ss,
 		    (allocated += LINESTEP) * sizeof (char *));
@@ -81,7 +81,7 @@ getmorelines(FILE *stream, char **lines)
     allocated = numlines + 1;	/* this is a lie, but it's close enough */
 
     /* read all lines available */
-    while ((s = getline(stream)) != NULL) {
+    while ((s = get_line(stream)) != NULL) {
 	if (numlines == allocated)		/* make more room if needed */
 	    ss = (char **)xrealloc(ss,
 		    (allocated += LINESTEP) * sizeof (char *));
@@ -100,7 +100,7 @@ getmorelines(FILE *stream, char **lines)
  * line in stream, return NULL on EOF
  */
 char *
-getline(FILE *stream)
+get_line(FILE *stream)
 {
     int c, numchars = 0, allocated = 0;
     char *s = NULL;
