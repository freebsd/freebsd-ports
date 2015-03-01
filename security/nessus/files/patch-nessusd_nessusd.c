--- nessusd/nessusd.c.orig	2006-10-16 19:55:54.000000000 +0200
+++ nessusd/nessusd.c	2015-02-28 12:02:32.184040116 +0100
@@ -622,11 +622,12 @@
 
       if (ssl_mt == NULL)
 	{
-	  if (strcasecmp(ssl_ver, "SSLv2") == 0)
-	    ssl_mt = SSLv2_server_method();
-	  else if (strcasecmp(ssl_ver, "SSLv3") == 0)
+#ifndef OPENSSL_NO_SSL3_METHOD
+	  if (strcasecmp(ssl_ver, "SSLv3") == 0)
 	    ssl_mt = SSLv3_server_method();
-	  else if (strcasecmp(ssl_ver, "SSLv23") == 0)
+	  else
+#endif
+	  if (strcasecmp(ssl_ver, "SSLv23") == 0)
 	    ssl_mt = SSLv23_server_method();
 	  else if (strcasecmp(ssl_ver, "TLSv1") == 0)
 	    ssl_mt = TLSv1_server_method();
