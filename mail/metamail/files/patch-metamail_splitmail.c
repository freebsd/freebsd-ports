--- metamail/splitmail.c.orig	1994-01-31 22:23:14 UTC
+++ metamail/splitmail.c
@@ -21,6 +21,8 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
  ******************************************************* */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <config.h>
@@ -28,7 +30,7 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 #include <time.h>
 
 #define MINCHUNKSIZE 20000 /* Better be enough to hold the headers, or we die! */
-extern char *malloc(), *index(), *getmyname();
+extern char *getmyname();
 
 #ifdef AMIGA
 #define Prototype   extern
@@ -41,8 +43,8 @@ extern char *malloc(), *index(), *getmyn
 #define VERBOSEDELIVERYCMD VerboseDeliveryCmd
 #else
 extern char *getenv();
-#define NORMALDELIVERYCMD "/usr/lib/sendmail -t -oi"
-#define VERBOSEDELIVERYCMD "/usr/lib/sendmail -t -v -oi"
+#define NORMALDELIVERYCMD "/usr/sbin/sendmail -t -oi"
+#define VERBOSEDELIVERYCMD "/usr/sbin/sendmail -t -v -oi"
 #endif
 
 usageexit() {
@@ -194,7 +196,7 @@ char **argv;
 	s = endofheader(from);  /* would be index(from, '\n'),
 				 but need to check for continuation lines */
         *s = '\0';
-	if (ShareThisHeader(from, SubjectBuf, &OrigID)) {
+	if (ShareThisHeader(from, SubjectBuf, sizeof(SubjectBuf), &OrigID)) {
 	    strcat(SharedHeaders, from);
 	    strcat(SharedHeaders, "\n");
 	}
@@ -339,9 +341,10 @@ static char *SharedHeads[] = {
     NULL
 };
 
-ShareThisHeader(s, SubjectBuf, OrigID)
+ShareThisHeader(s, SubjectBuf, size, OrigID)
 char *s;
 char *SubjectBuf;
+size_t size;
 char **OrigID;
 {
     int i;
@@ -361,7 +364,8 @@ char **OrigID;
     }
     if (!ULstrcmp(s, "subject")) {
         *colon = ':';
-        strcpy(SubjectBuf, ++colon);
+        strncpy(SubjectBuf, ++colon, size);
+        SubjectBuf[size - 1] = '\0';
         return(0);
     }
     if (!ULstrcmp(s, "content-type")) {
