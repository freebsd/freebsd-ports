--- nessus/nessus.c.orig	2006-09-22 22:28:30.000000000 +0200
+++ nessus/nessus.c	2015-02-28 12:01:15.344694473 +0100
@@ -438,11 +438,12 @@
 	}
       if (ssl_mt == NULL)
 	{
-	  if (strcasecmp(ssl_ver, "SSLv2") == 0)
-	    ssl_mt = SSLv2_client_method();
-	  else if (strcasecmp(ssl_ver, "SSLv3") == 0)
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
