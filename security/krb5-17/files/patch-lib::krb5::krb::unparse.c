--- lib/krb5/krb/unparse.c.orig	Tue Jan 18 09:57:32 2005
+++ lib/krb5/krb/unparse.c	Tue Jul 12 14:04:38 2005
@@ -91,6 +91,8 @@
 				totalsize++;
 		totalsize++;	/* This is for the separator */
 	}
+	if (nelem == 0)
+		totalsize++;
 
 	/*
 	 * Allocate space for the ascii string; if space has been
