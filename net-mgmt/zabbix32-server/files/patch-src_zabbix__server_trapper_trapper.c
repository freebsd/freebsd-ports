--- src/zabbix_server/trapper/trapper.c.orig	2016-12-21 08:08:40 UTC
+++ src/zabbix_server/trapper/trapper.c
@@ -37,6 +37,7 @@
 
 #include "daemon.h"
 #include "../../libs/zbxcrypto/tls.h"
+#include <openssl/opensslconf.h>
 
 extern unsigned char	process_type, program_type;
 extern int		server_num, process_num;
@@ -677,8 +678,10 @@ ZBX_THREAD_ENTRY(trapper_thread, args)
 
 #if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
 	zbx_tls_init_child();
+#ifndef OPENSSL_NO_PSK
 	find_psk_in_cache = DCget_psk_by_identity;
 #endif
+#endif
 	zbx_setproctitle("%s #%d [connecting to the database]", get_process_type_string(process_type), process_num);
 
 	DBconnect(ZBX_DB_CONNECT_NORMAL);
