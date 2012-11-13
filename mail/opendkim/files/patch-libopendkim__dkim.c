--- ./libopendkim/dkim.c.orig	2012-10-19 05:22:16.000000000 +0900
+++ ./libopendkim/dkim.c	2012-10-20 15:52:54.000000000 +0900
@@ -938,7 +938,7 @@
 			dkim_dstring_cat(dkim->dkim_sslerrbuf, "; ");
 
 		dkim_dstring_cat(dkim->dkim_sslerrbuf,
-		                 gnutls_strerror(status));
+		                 (u_char *) gnutls_strerror(status));
 	}
 
 #else /* USE_GNUTLS */
@@ -1004,7 +1004,7 @@
 			dkim_dstring_cat(sig->sig_sslerrbuf, "; ");
 
 		dkim_dstring_cat(sig->sig_sslerrbuf,
-		                 gnutls_strerror(status));
+		                 (u_char *) gnutls_strerror(status));
 	}
 
 #else /* USE_GNUTLS */
