--- utils.c.orig	Mon Oct 13 13:14:12 2003
+++ utils.c	Mon Oct 13 13:14:58 2003
@@ -17,14 +17,9 @@
 #else
 #include <strings.h>
 #endif
-#include <varargs.h>
+#include <stdarg.h>
 #include "utils.h"
 
-#ifdef lint
-#undef va_arg
-#define va_arg(x,y) (y)NULL
-#endif
-
 #ifndef u_long
 #define u_long unsigned long
 #endif /* u_long */
@@ -42,14 +37,11 @@
  *	    follows it.
  */
 /*VARARGS*/
-void Error(va_alist)
-va_dcl
+void Error(char *format, ...)
 {
 	va_list args;
-	char *format;
 
-	va_start(args);
-	format = va_arg(args, char *);
+	va_start(args, format);
 	(void)fprintf(stderr, "%s: ", progname);
 	(void)vfprintf(stderr, format, args);
 	(void)fprintf(stderr, "\n");
@@ -63,18 +55,11 @@
  *            is equal to or greater than the debugging level.
  */
 /*VARARGS*/
-void dfprintf(va_alist)
-va_dcl
+void dfprintf(int debugLevel, FILE *stream, char *format, ...)
 {
 	va_list args;
-	int debugLevel;
-	FILE *stream;
-	char *format;
 	
-	va_start(args);
-	debugLevel = va_arg(args, int);
-	stream = va_arg(args, FILE *);
-	format = va_arg(args, char *);
+	va_start(args, format); 
 	if(d >= debugLevel){
 		(void)vfprintf(stream, format, args);
 	}
@@ -85,18 +70,15 @@
  * Warning(): behaves like Error, except returns rather than exits.
  */
 /*VARARGS*/
-void Warning(va_alist)
-va_dcl
+void Warning(char *format, ...)
 {
 	va_list args;
-	char *format;
 
-	va_start(args);
-	format = va_arg(args, char *);
-    (void)fprintf(stderr, "%s: ", progname);
-    (void)vfprintf(stderr, format, args);
-    (void)fprintf(stderr, "\n");
-    va_end(args);
+	va_start(args, format);
+	(void)fprintf(stderr, "%s: ", progname);
+	(void)vfprintf(stderr, format, args);
+	(void)fprintf(stderr, "\n");
+	va_end(args);
 }
 
 FILE *efopen(file, mode)
@@ -186,15 +168,14 @@
  *        in malloc'ed space.
  */
 /*VARARGS*/
-char *cat(va_alist)
-va_dcl
+char *cat(char *str0, ...)
 {
 	va_list args;
-	unsigned length=1;
+	unsigned length=1+strlen(str0);
 	char *str, *newstr;
 
 	/* get length */
-	va_start(args);
+	va_start(args, str0);
 	loop{
 		str = va_arg(args, char *);
 		if(NULL!=str){
@@ -209,9 +190,10 @@
 	if(NULL==newstr) Error("Out of memory in cat()");
 	
 	newstr[0]=(char)0;
+	strcat(newstr, str0);
 
 	/* create string */
-	va_start(args);
+	va_start(args, str0);
 	loop{
 		str = va_arg(args, char *);
 		if(NULL!=str) {
@@ -220,7 +202,7 @@
 			break;
 		}
 	}
- va_end(args);
+	va_end(args);
 #ifdef lint
 	args=args; /* make lint shut up about "args set but not used" */
 #endif
@@ -259,6 +241,7 @@
 				lastfail++;
 			}
 		}
+		iaddr=ntohl(iaddr);
 		sprintf(iaddrbuff, "%u.%u.%u.%u", (iaddr>>24)&0xff,
 		(iaddr>>16)&0xff, (iaddr>>8)&0xff,
 		iaddr&0xff);
