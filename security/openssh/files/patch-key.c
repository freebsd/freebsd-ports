--- key.c	Mon Jun 24 20:46:53 2002
+++ key.c.orig	Fri May 31 15:16:48 2002
@@ -368,7 +368,7 @@
 		return 0;
 	}
 	fprintf(f, " %s", buf);
-	free(buf);
+	OPENSSL_free(buf);
 	return 1;
 }
 
