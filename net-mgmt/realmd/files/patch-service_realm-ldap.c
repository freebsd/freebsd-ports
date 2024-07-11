--- service/realm-ldap.c.orig	2022-09-29 11:05:56 UTC
+++ service/realm-ldap.c
@@ -259,7 +259,7 @@ realm_ldap_connect_anonymous (GSocketAddress *address,
 		if (rc != 0) {
 			g_warning ("couldn't set SO_SNDTIMEO");
 		}
-		rc = setsockopt (ls->sock, IPPROTO_TCP, TCP_USER_TIMEOUT,
+		rc = setsockopt (ls->sock, IPPROTO_TCP, TCP_KEEPINIT*1000,
 		                 &milli, sizeof (milli));
 		if (rc != 0) {
 			g_warning ("couldn't set TCP_USER_TIMEOUT");
