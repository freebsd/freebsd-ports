--- ssl/srtp.h.orig	2015-03-19 13:37:10 UTC
+++ ssl/srtp.h
@@ -137,7 +137,6 @@ int SSL_set_tlsext_use_srtp(SSL *ctx, co
 SRTP_PROTECTION_PROFILE *SSL_get_selected_srtp_profile(SSL *s);
 
 STACK_OF(SRTP_PROTECTION_PROFILE) *SSL_get_srtp_profiles(SSL *ssl);
-SRTP_PROTECTION_PROFILE *SSL_get_selected_srtp_profile(SSL *s);
 
 # endif
 
