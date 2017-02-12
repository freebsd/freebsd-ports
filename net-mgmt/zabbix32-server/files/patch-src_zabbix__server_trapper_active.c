--- src/zabbix_server/trapper/active.c.orig	2016-12-21 08:08:40 UTC
+++ src/zabbix_server/trapper/active.c
@@ -26,6 +26,7 @@
 
 #include "active.h"
 #include "../../libs/zbxcrypto/tls_tcp_active.h"
+#include <openssl/opensslconf.h>
 
 extern unsigned char	program_type;
 
@@ -131,6 +132,7 @@ static int	get_hostid_by_host(const zbx_
 					goto done;
 				}
 			}
+#ifndef OPENSSL_NO_PSK
 			else if (ZBX_TCP_SEC_TLS_PSK == sock->connection_type)
 			{
 				zbx_tls_conn_attr_t	attr;
@@ -151,6 +153,7 @@ static int	get_hostid_by_host(const zbx_
 					goto done;
 				}
 			}
+#endif /* OPENSSL_NO_PSK */
 #endif
 			ZBX_STR2UINT64(*hostid, row[0]);
 
