--- Library/src/HTMIMImp.c.orig	1999-02-22 22:10:11 UTC
+++ Library/src/HTMIMImp.c
@@ -226,7 +226,7 @@ PRIVATE int HTFindInt(char * haystack, c
     int value = deflt;
     if (start != NULL) {
 	start += strlen(needle);
-	while isspace(*start) start++;
+	while (isspace(*start)) start++;
 	if (isdigit(*start)) {
 	    char * end = start + 1;
 	    char save;
