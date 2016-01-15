--- plugins/sslutils.c.orig	2015-07-30 21:40:06 UTC
+++ plugins/sslutils.c
@@ -70,8 +70,13 @@ int np_net_ssl_init_with_hostname_versio
 #endif
 		break;
 	case 3: /* SSLv3 protocol */
+#if defined(OPENSSL_NO_SSL3)
+		printf(("%s\n", _("CRITICAL - SSL protocol version 3 is not supported by your SSL library.")));
+		return STATE_CRITICAL;
+#else
 		method = SSLv3_client_method();
 		ssl_options = SSL_OP_NO_SSLv2 | SSL_OP_NO_TLSv1;
+#endif
 		break;
 	default: /* Unsupported */
 		printf("%s\n", _("CRITICAL - Unsupported SSL protocol version."));
