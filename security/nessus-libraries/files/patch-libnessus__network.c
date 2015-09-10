--- libnessus/network.c.orig	2006-05-22 10:14:35.000000000 -0400
+++ libnessus/network.c	2015-03-23 20:16:26.470964000 -0400
@@ -532,9 +532,11 @@
 
   switch (fp->transport)
     {
+#ifndef OPENSSL_NO_SSL2
     case NESSUS_ENCAPS_SSLv2:
       fp->ssl_mt = SSLv2_client_method();
       break;
+#endif
     case NESSUS_ENCAPS_SSLv3:
       fp->ssl_mt = SSLv3_client_method();
       break;
@@ -724,7 +726,9 @@
  {
   case NESSUS_ENCAPS_IP:
 #ifdef HAVE_SSL
+#ifndef OPENSSL_NO_SSL2
   case NESSUS_ENCAPS_SSLv2:
+#endif
   case NESSUS_ENCAPS_SSLv23:
   case NESSUS_ENCAPS_SSLv3:
   case NESSUS_ENCAPS_TLSv1:
@@ -783,8 +787,10 @@
 	  }
      }
    
+#ifndef OPENSSL_NO_SSL2
   case NESSUS_ENCAPS_SSLv2:
     /* We do not need a client certificate in this case */
+#endif
 
     if (open_SSL_connection(fp, timeout, cert, key, passwd, cert_names) <= 0)
     goto failed;
@@ -812,7 +818,9 @@
   struct timeval	tv1, tv2;
  static int encaps[] = {
 #ifdef HAVE_SSL
+#ifndef OPENSSL_NO_SSL2
    NESSUS_ENCAPS_SSLv2,
+#endif
    NESSUS_ENCAPS_TLSv1,
    NESSUS_ENCAPS_SSLv3,
 #endif
@@ -1044,7 +1052,9 @@
     {
       /* NESSUS_ENCAPS_IP was treated before with the non-Nessus fd */
 #ifdef HAVE_SSL
+#ifndef OPENSSL_NO_SSL2
     case NESSUS_ENCAPS_SSLv2:
+#endif
     case NESSUS_ENCAPS_SSLv23:
     case NESSUS_ENCAPS_SSLv3:
     case NESSUS_ENCAPS_TLSv1:
@@ -1280,7 +1290,9 @@
     break;
 
 #ifdef HAVE_SSL
+#ifndef OPENSSL_NO_SSL2
   case NESSUS_ENCAPS_SSLv2:
+#endif
   case NESSUS_ENCAPS_SSLv23:
   case NESSUS_ENCAPS_SSLv3:
   case NESSUS_ENCAPS_TLSv1:
@@ -1504,8 +1516,10 @@
  {
   case NESSUS_ENCAPS_IP:
    return "IP";
+#ifndef OPENSSL_NO_SSL2
   case NESSUS_ENCAPS_SSLv2:
     return "SSLv2";
+#endif
   case NESSUS_ENCAPS_SSLv23:
     return "SSLv23";
   case NESSUS_ENCAPS_SSLv3:
@@ -1527,7 +1541,9 @@
  {
   case NESSUS_ENCAPS_IP:
    return "";
+#ifndef OPENSSL_NO_SSL2
   case NESSUS_ENCAPS_SSLv2:
+#endif
   case NESSUS_ENCAPS_SSLv23:
   case NESSUS_ENCAPS_SSLv3:
   case NESSUS_ENCAPS_TLSv1:
