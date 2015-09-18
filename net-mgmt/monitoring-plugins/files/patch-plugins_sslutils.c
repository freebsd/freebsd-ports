--- plugins/sslutils.c.orig	2014-11-30 11:36:26.000000000 +0100
+++ plugins/sslutils.c	2015-09-10 17:12:27.486954140 +0200
@@ -66,7 +66,12 @@ int np_net_ssl_init_with_hostname_versio
 #endif
 		break;
 	case 3: /* SSLv3 protocol */
+#if defined(OPENSSL_NO_SSL3)
+		printf(("%s\n", _("CRITICAL - SSL protocol version 3 is not supported by your SSL library.")));
+		return STATE_CRITICAL;
+#else
 		method = SSLv3_client_method();
+#endif
 		break;
 	default: /* Unsupported */
 		printf("%s\n", _("CRITICAL - Unsupported SSL protocol version."));
