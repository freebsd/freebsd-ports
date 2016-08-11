--- getline.c.orig	2002-12-14 09:02:26 UTC
+++ getline.c
@@ -34,7 +34,7 @@
  *	/pattern/	action[/hint/]	[arg {arg ...}]
  */
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include "rule.h"
@@ -175,7 +175,7 @@ vis(FILE *output, unsigned char *s)
  * getline() gets a rule off the input stream
  */
 struct rule *
-getline(FILE *input)
+get_line(FILE *input)
 {
     static char *bfr = 0;	/* a buffer for reading lines into */
     static int buflen = 0;	/* size of that buffer */
