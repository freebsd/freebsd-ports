--- libnessus/network.c.orig	2006-05-22 14:14:35 UTC
+++ libnessus/network.c
@@ -532,12 +532,16 @@ open_SSL_connection(fp, timeout, cert, k
 
   switch (fp->transport)
     {
+#ifndef OPENSSL_NO_SSL2
     case NESSUS_ENCAPS_SSLv2:
       fp->ssl_mt = SSLv2_client_method();
       break;
+#endif
+#ifndef OPENSSL_NO_SSL3
     case NESSUS_ENCAPS_SSLv3:
       fp->ssl_mt = SSLv3_client_method();
       break;
+#endif
     case NESSUS_ENCAPS_TLSv1:
       fp->ssl_mt = TLSv1_client_method();
       break;
@@ -724,9 +728,13 @@ open_stream_connection(args, port, trans
  {
   case NESSUS_ENCAPS_IP:
 #ifdef HAVE_SSL
+#ifndef OPENSSL_NO_SSL2
   case NESSUS_ENCAPS_SSLv2:
+#endif
   case NESSUS_ENCAPS_SSLv23:
+#ifndef OPENSSL_NO_SSL3
   case NESSUS_ENCAPS_SSLv3:
+#endif
   case NESSUS_ENCAPS_TLSv1:
 #endif 
    break;
@@ -763,7 +771,9 @@ open_stream_connection(args, port, trans
     break;
 #ifdef HAVE_SSL
   case NESSUS_ENCAPS_SSLv23:
+#ifndef OPENSSL_NO_SSL3
   case NESSUS_ENCAPS_SSLv3:
+#endif
   case NESSUS_ENCAPS_TLSv1:
     renice_myself();
     cert   = kb_item_get_str(plug_get_kb(args), "SSL/cert");
<<<<<<< HEAD:security/nessus-libraries/files/patch-libnessus_network.c
@@ -783,8 +793,10 @@ open_stream_connection(args, port, trans
=======
@@ -782,12 +792,13 @@ open_stream_connection(args, port, trans
 	    sslerror(msg);
>>>>>>> 4243c1c6373d1b338727bc0c539ec0ea6788094b:security/nessus-libraries/files/patch-libnessus_network.c
 	  }
      }
-   
+#ifndef OPENSSL_NO_SSL2   
   case NESSUS_ENCAPS_SSLv2:
     /* We do not need a client certificate in this case */
 
     if (open_SSL_connection(fp, timeout, cert, key, passwd, cert_names) <= 0)
     goto failed;
<<<<<<< HEAD:security/nessus-libraries/files/patch-libnessus_network.c
@@ -812,10 +824,14 @@ open_stream_connection_unknown_encaps5(a
=======
+#endif
   break;
 #endif
  }
@@ -812,10 +823,14 @@ open_stream_connection_unknown_encaps5(a
>>>>>>> 4243c1c6373d1b338727bc0c539ec0ea6788094b:security/nessus-libraries/files/patch-libnessus_network.c
   struct timeval	tv1, tv2;
  static int encaps[] = {
 #ifdef HAVE_SSL
+#ifndef OPENSSL_NO_SSL2
    NESSUS_ENCAPS_SSLv2,
+#endif
    NESSUS_ENCAPS_TLSv1,
+#ifndef OPENSSL_NO_SSL3
    NESSUS_ENCAPS_SSLv3,
 #endif
+#endif
     NESSUS_ENCAPS_IP
   };
  
<<<<<<< HEAD:security/nessus-libraries/files/patch-libnessus_network.c
@@ -1044,9 +1060,13 @@ read_stream_connection_unbuffered(fd, bu
=======
@@ -1044,9 +1059,13 @@ read_stream_connection_unbuffered(fd, bu
>>>>>>> 4243c1c6373d1b338727bc0c539ec0ea6788094b:security/nessus-libraries/files/patch-libnessus_network.c
     {
       /* NESSUS_ENCAPS_IP was treated before with the non-Nessus fd */
 #ifdef HAVE_SSL
+#ifndef OPENSSL_NO_SSL2
     case NESSUS_ENCAPS_SSLv2:
+#endif
     case NESSUS_ENCAPS_SSLv23:
+#ifndef OPENSSL_NO_SSL3
     case NESSUS_ENCAPS_SSLv3:
+#endif
     case NESSUS_ENCAPS_TLSv1:
 # if DEBUG_SSL > 0
       if (getpid() != fp->pid)
<<<<<<< HEAD:security/nessus-libraries/files/patch-libnessus_network.c
@@ -1280,9 +1300,13 @@ write_stream_connection4(fd, buf0, n, i_
=======
@@ -1280,9 +1299,13 @@ write_stream_connection4(fd, buf0, n, i_
>>>>>>> 4243c1c6373d1b338727bc0c539ec0ea6788094b:security/nessus-libraries/files/patch-libnessus_network.c
     break;
 
 #ifdef HAVE_SSL
+#ifndef OPENSSL_NO_SSL2
   case NESSUS_ENCAPS_SSLv2:
+#endif
   case NESSUS_ENCAPS_SSLv23:
+#ifndef OPENSSL_NO_SSL3
   case NESSUS_ENCAPS_SSLv3:
+#endif
   case NESSUS_ENCAPS_TLSv1:
       FD_ZERO(&fdr); FD_ZERO(&fdw); 
       FD_SET(fp->fd, & fdr); FD_SET(fp->fd, & fdw);
<<<<<<< HEAD:security/nessus-libraries/files/patch-libnessus_network.c
@@ -1504,12 +1528,16 @@ get_encaps_name(code)
=======
@@ -1504,12 +1527,16 @@ get_encaps_name(code)
>>>>>>> 4243c1c6373d1b338727bc0c539ec0ea6788094b:security/nessus-libraries/files/patch-libnessus_network.c
  {
   case NESSUS_ENCAPS_IP:
    return "IP";
+#ifndef OPENSSL_NO_SSL2
   case NESSUS_ENCAPS_SSLv2:
     return "SSLv2";
+#endif
   case NESSUS_ENCAPS_SSLv23:
     return "SSLv23";
+#ifndef OPENSSL_NO_SSL3
   case NESSUS_ENCAPS_SSLv3:
     return "SSLv3";
+#endif
   case NESSUS_ENCAPS_TLSv1:
     return "TLSv1";
   default:
<<<<<<< HEAD:security/nessus-libraries/files/patch-libnessus_network.c
@@ -1527,9 +1555,13 @@ get_encaps_through(code)
=======
@@ -1527,9 +1554,13 @@ get_encaps_through(code)
>>>>>>> 4243c1c6373d1b338727bc0c539ec0ea6788094b:security/nessus-libraries/files/patch-libnessus_network.c
  {
   case NESSUS_ENCAPS_IP:
    return "";
+#ifndef OPENSSL_NO_SSL2
   case NESSUS_ENCAPS_SSLv2:
+#endif
   case NESSUS_ENCAPS_SSLv23:
+#ifndef OPENSSL_NO_SSL3
   case NESSUS_ENCAPS_SSLv3:
+#endif
   case NESSUS_ENCAPS_TLSv1:
     return " through SSL";
   default:
