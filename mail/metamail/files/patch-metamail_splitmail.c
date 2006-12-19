--- metamail/splitmail.c.orig	Mon Jan 31 23:23:14 1994
+++ metamail/splitmail.c	Mon Dec 18 11:46:22 2006
@@ -41,8 +43,8 @@
 #define VERBOSEDELIVERYCMD VerboseDeliveryCmd
 #else
 extern char *getenv();
-#define NORMALDELIVERYCMD "/usr/lib/sendmail -t -oi"
-#define VERBOSEDELIVERYCMD "/usr/lib/sendmail -t -v -oi"
+#define NORMALDELIVERYCMD "/usr/sbin/sendmail -t -oi"
+#define VERBOSEDELIVERYCMD "/usr/sbin/sendmail -t -v -oi"
 #endif
 
 usageexit() {
@@ -194,7 +196,7 @@
 	s = endofheader(from);  /* would be index(from, '\n'),
 				 but need to check for continuation lines */
         *s = '\0';
-	if (ShareThisHeader(from, SubjectBuf, &OrigID)) {
+	if (ShareThisHeader(from, SubjectBuf, sizeof(SubjectBuf), &OrigID)) {
 	    strcat(SharedHeaders, from);
 	    strcat(SharedHeaders, "\n");
 	}
@@ -339,9 +341,10 @@
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
@@ -361,7 +364,8 @@
     }
     if (!ULstrcmp(s, "subject")) {
         *colon = ':';
-        strcpy(SubjectBuf, ++colon);
+        strncpy(SubjectBuf, ++colon, size);
+        SubjectBuf[size - 1] = '\0';
         return(0);
     }
     if (!ULstrcmp(s, "content-type")) {
