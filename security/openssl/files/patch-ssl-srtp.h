--- ssl/srtp.h.orig	2012-04-26 22:40:38.000000000 -0500
+++ ssl/srtp.h	2012-04-26 22:40:51.000000000 -0500
@@ -135,7 +135,6 @@
 SRTP_PROTECTION_PROFILE *SSL_get_selected_srtp_profile(SSL *s);
 
 STACK_OF(SRTP_PROTECTION_PROFILE) *SSL_get_srtp_profiles(SSL *ssl);
-SRTP_PROTECTION_PROFILE *SSL_get_selected_srtp_profile(SSL *s);
 
 #ifdef  __cplusplus
 }
