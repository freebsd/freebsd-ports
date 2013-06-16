--- domain.c.orig	1993-03-03 22:10:02.000000000 +0100
+++ domain.c	2013-06-16 15:38:40.000000000 +0200
@@ -1,9 +1,14 @@
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)domain.c	9.5 92/08/25";
+static const char	*sccsid = "@(#)domain.c	9.5 92/08/25";
 #endif /* lint */
 
 #include "def.h"
+#include <string.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
+#include <resolv.h>
 
 /* imports */
 extern dom *newdom();
@@ -12,12 +17,14 @@
 
 /* exports */
 
+
 /* privates */
 static dom *good, *bad;
 
 /*
  * good and bad are passed by reference for move-to-front
  */
+int
 isadomain(domain)
 	char *domain;
 {
@@ -43,6 +50,7 @@
 	}
 }
 
+int
 ondomlist(headp, domain)
 	dom **headp;
 	char *domain;
@@ -60,6 +68,7 @@
 
 
 			
+void
 adddom(headp, domain)
 	dom **headp;
 	char *domain;
@@ -73,6 +82,7 @@
 	*headp = d;
 }
 
+void
 movetofront(headp, d)
 	dom **headp, *d;
 {	dom *head = *headp;
@@ -91,11 +101,12 @@
 #include <sys/types.h>
 #include <arpa/nameser.h>
 
+int
 nslookup(domain)
 	char *domain;
 {	register HEADER *hp;
 	register int n;
-	char q[PACKETSZ], a[PACKETSZ];	/* query, answer */
+	unsigned char q[PACKETSZ], a[PACKETSZ];	/* query, answer */
 	char buf[PACKETSZ+1];
 
 	if ((n = strlen(domain)) >= PACKETSZ)
@@ -105,7 +116,7 @@
 		buf[n++] = '.';
 		buf[n] = 0;
 	}
-	if ((n = res_mkquery(QUERY, buf, C_IN, T_ANY, (char *) 0, 0, (struct rrec *) 0, q, sizeof(q))) < 0)
+	if ((n = res_mkquery(QUERY, buf, C_IN, T_ANY, (const unsigned char *) 0, 0, (const unsigned char *) 0, q, sizeof(q))) < 0)
 		die("impossible res_mkquery error");
 	errno = 0;
 	if ((n = res_send(q, n, a, sizeof(a))) < 0)
@@ -117,6 +128,7 @@
 }
 #else /*!RESOLVER*/
 /*ARGSUSED*/
+int
 nslookup(domain)
 	char *domain;
 {
