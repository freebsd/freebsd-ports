Index: imap/fetchnews.c
diff -u -p imap/fetchnews.c.orig imap/fetchnews.c
--- imap/fetchnews.c.orig	Wed Mar 23 09:40:11 2005
+++ imap/fetchnews.c	Fri Apr 14 23:36:14 2006
@@ -60,6 +60,7 @@
 #include "cyrusdb.h"
 #include "exitcodes.h"
 #include "global.h"
+#include "gmtoff.h"
 #include "lock.h"
 #include "prot.h"
 #include "xmalloc.h"
@@ -388,6 +389,7 @@ int main(int argc, char *argv[])
 	       &ctime.tm_hour, &ctime.tm_min, &ctime.tm_sec);
 	ctime.tm_year -= 1900;
 	ctime.tm_mon--;
+	ctime.tm_isdst = -1;
 
 	/* read the previous timestamp */
 	if (!sfile[0]) {
@@ -417,6 +419,7 @@ int main(int argc, char *argv[])
 	/* ask for new articles */
 	if (stamp) stamp -= 180; /* adjust back 3 minutes */
 	ptime = gmtime(&stamp);
+	ptime->tm_isdst = -1;
 	strftime(buf, sizeof(buf), datefmt, ptime);
 	prot_printf(pout, "NEWNEWS %s %s GMT\r\n", wildmat, buf);
 	
@@ -433,7 +436,7 @@ int main(int argc, char *argv[])
 	   We can't change this, otherwise we'd be incompatible
 	   with an old localtime timestamp.
 	*/
-	stamp -= timezone;
+	stamp += gmtoff_of(&ctime, stamp);
     }
 
     if (!newnews) {
