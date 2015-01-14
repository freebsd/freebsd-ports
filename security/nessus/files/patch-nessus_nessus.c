--- nessus/nessus.c.orig	2006-09-22 20:28:30 UTC
+++ nessus/nessus.c
@@ -438,11 +438,17 @@ Please launch nessus-mkrand(1) first !")
 	}
       if (ssl_mt == NULL)
 	{
+#ifndef OPENSSL_NO_SSL2
 	  if (strcasecmp(ssl_ver, "SSLv2") == 0)
 	    ssl_mt = SSLv2_client_method();
-	  else if (strcasecmp(ssl_ver, "SSLv3") == 0)
+	  else
+#endif
+#ifndef OPENSSL_NO_SSL3_METHOD
+	  if (strcasecmp(ssl_ver, "SSLv3") == 0)
 	    ssl_mt = SSLv3_client_method();
-	  else if (strcasecmp(ssl_ver, "SSLv23") == 0)
+	  else
+#endif
+	  if (strcasecmp(ssl_ver, "SSLv23") == 0)
 	    ssl_mt = SSLv23_client_method();
 	  else if (strcasecmp(ssl_ver, "TLSv1") == 0)
 	    ssl_mt = TLSv1_client_method();
