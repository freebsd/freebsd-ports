--- src/libs/zbxdbhigh/proxy.c.orig	2016-12-21 08:08:41 UTC
+++ src/libs/zbxdbhigh/proxy.c
@@ -28,6 +28,7 @@
 #include "discovery.h"
 #include "zbxalgo.h"
 #include "../zbxcrypto/tls_tcp_active.h"
+#include <openssl/opensslconf.h>
 
 extern unsigned int	configured_tls_accept_modes;
 
@@ -2054,9 +2055,13 @@ void	process_mass_data(zbx_socket_t *soc
 #if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
 	if (0 == proxy_hostid &&
 			((ZBX_TCP_SEC_TLS_CERT == sock->connection_type &&
-				SUCCEED != zbx_tls_get_attr_cert(sock, &attr)) ||
-			(ZBX_TCP_SEC_TLS_PSK == sock->connection_type &&
-				SUCCEED != zbx_tls_get_attr_psk(sock, &attr))))
+				SUCCEED != zbx_tls_get_attr_cert(sock, &attr))
+#ifndef OPENSSL_NO_PSK
+			|| (ZBX_TCP_SEC_TLS_PSK == sock->connection_type &&
+				SUCCEED != zbx_tls_get_attr_psk(sock, &attr))
+#endif
+			)
+		)
 	{
 		THIS_SHOULD_NEVER_HAPPEN;
 		return;
