--- kcgiregress.c.orig	2015-07-17 06:16:43 UTC
+++ kcgiregress.c
@@ -197,9 +197,6 @@ dochild_cgi(kcgi_regress_server child, v
 		setenv(headbuf, val, 1);
 	}
 
-	if (NULL == head)
-		goto out;
-
 	if (-1 != in)
 		close(in);
 	if (-1 != s)
