--- src/charset.c.orig	Wed Jun 11 23:25:17 2003
+++ src/charset.c	Thu Jan 22 10:18:01 2004
@@ -165,12 +165,12 @@
 
 
 char* replacement_table(char* string) {
-return NULL;
 	char**a,b;
 	char*position;
 	char*tempstring,tempstring2;
 	//int replacementlength;
 	int current;
+return NULL;
 	tempstring = g_strdup(string);
 	for (current=0;_latinchars[current];current++) {
 		g_print("To replace: %s         Replacement: %s\n",_latinchars[current],_replacements[current]);
