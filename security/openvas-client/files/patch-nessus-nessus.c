--- nessus/nessus.c.orig	2009-06-05 07:12:11 UTC
+++ nessus/nessus.c
@@ -481,11 +481,17 @@ Please launch openvasclient-mkrand(1) fi
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
