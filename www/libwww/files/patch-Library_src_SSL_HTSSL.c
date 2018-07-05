--- Library/src/SSL/HTSSL.c.orig	2018-07-04 23:30:19 UTC
+++ Library/src/SSL/HTSSL.c
@@ -214,12 +214,16 @@ PUBLIC BOOL HTSSL_init (void)
 
 	/* select the protocol method */
 	switch (ssl_prot_method) {
+#ifndef OPENSSL_NO_SSL2
 	case HTSSL_V2:
 	  meth = SSLv2_client_method();
 	  break;
+#endif
+#ifndef OPENSSL_NO_SSL3_METHOD
 	case HTSSL_V3:
 	  meth = SSLv3_client_method();
 	  break;
+#endif
 	case HTSSL_V23:
 	  meth = SSLv23_client_method();
 	  break;
