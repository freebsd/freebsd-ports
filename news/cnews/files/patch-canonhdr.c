--- util/canonhdr.c.orig	1995-04-28 02:51:38.000000000 +0200
+++ util/canonhdr.c	2014-02-07 16:47:48.000000000 +0100
@@ -92,7 +92,7 @@
 	static char expiresnm[] = "Expires: ";
 
 	if (!washdr)
-		return;
+		return 0;
 	while ((hdr = gethdr(in, &nolimit, &ishdr)) != NULL && ishdr) {
 		register char *cp;
 		static char canonmsgid[] = "Message-Id:";
@@ -141,6 +141,7 @@
 		(void) fputs(datenm, stdout);
 		(void) fputs(canondate("now", "now"), stdout);
 	}
+	return 0;
 }
 
 int
