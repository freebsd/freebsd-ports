--- Library/src/HTMIMImp.c.orig	Sun Jun 30 22:51:48 2002
+++ Library/src/HTMIMImp.c	Sun Jun 30 22:52:01 2002
@@ -226,7 +226,7 @@
     int value = deflt;
     if (start != NULL) {
 	start += strlen(needle);
-	while isspace(*start) start++;
+	while (isspace(*start)) start++;
 	if (isdigit(*start)) {
 	    char * end = start + 1;
 	    char save;
