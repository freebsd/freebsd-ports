--- libnessus/network.c.orig	2006-05-22 16:14:35.000000000 +0200
+++ libnessus/network.c	2015-02-27 22:04:48.622142215 +0100
@@ -532,9 +532,6 @@
 
   switch (fp->transport)
     {
-    case NESSUS_ENCAPS_SSLv2:
-      fp->ssl_mt = SSLv2_client_method();
-      break;
     case NESSUS_ENCAPS_SSLv3:
       fp->ssl_mt = SSLv3_client_method();
       break;
@@ -724,7 +721,6 @@
  {
   case NESSUS_ENCAPS_IP:
 #ifdef HAVE_SSL
-  case NESSUS_ENCAPS_SSLv2:
   case NESSUS_ENCAPS_SSLv23:
   case NESSUS_ENCAPS_SSLv3:
   case NESSUS_ENCAPS_TLSv1:
@@ -786,7 +782,6 @@
   case NESSUS_ENCAPS_SSLv2:
     /* We do not need a client certificate in this case */
 
-    if (open_SSL_connection(fp, timeout, cert, key, passwd, cert_names) <= 0)
     goto failed;
   break;
 #endif
@@ -1044,7 +1039,6 @@
     {
       /* NESSUS_ENCAPS_IP was treated before with the non-Nessus fd */
 #ifdef HAVE_SSL
-    case NESSUS_ENCAPS_SSLv2:
     case NESSUS_ENCAPS_SSLv23:
     case NESSUS_ENCAPS_SSLv3:
     case NESSUS_ENCAPS_TLSv1:
@@ -1280,7 +1274,6 @@
     break;
 
 #ifdef HAVE_SSL
-  case NESSUS_ENCAPS_SSLv2:
   case NESSUS_ENCAPS_SSLv23:
   case NESSUS_ENCAPS_SSLv3:
   case NESSUS_ENCAPS_TLSv1:
@@ -1504,8 +1497,6 @@
  {
   case NESSUS_ENCAPS_IP:
    return "IP";
-  case NESSUS_ENCAPS_SSLv2:
-    return "SSLv2";
   case NESSUS_ENCAPS_SSLv23:
     return "SSLv23";
   case NESSUS_ENCAPS_SSLv3:
@@ -1527,7 +1518,6 @@
  {
   case NESSUS_ENCAPS_IP:
    return "";
-  case NESSUS_ENCAPS_SSLv2:
   case NESSUS_ENCAPS_SSLv23:
   case NESSUS_ENCAPS_SSLv3:
   case NESSUS_ENCAPS_TLSv1:
