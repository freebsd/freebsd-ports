--- rfc822/rfc822_parsedt.c.orig	Mon Jun 17 08:48:45 2002
+++ rfc822/rfc822_parsedt.c	Mon Jun 17 08:49:39 2002
@@ -199,6 +199,7 @@
 	}
 
 	if (year < 1970)	return (0);
+	if (year > 9999)	return (0);
 
 	t=0;
 	for (y=1970; y<year; y++)
