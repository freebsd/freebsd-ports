--- src/agent/Core/SecurityUpdateChecker.h.orig	2018-11-03 10:06:51 UTC
+++ src/agent/Core/SecurityUpdateChecker.h
@@ -256,9 +256,11 @@ private:
 				error.append(" for proxy address " + sessionState.config["proxy_url"].asString());
 				break;
 
+#if LIBCURL_VERSION_NUM < 0x073e00
 			case CURLE_SSL_CACERT:
 				// Peer certificate cannot be authenticated with given / known CA certificates. This would happen
 				// for MITM but could also be a truststore issue.
+#endif
 			case CURLE_PEER_FAILED_VERIFICATION:
 				// The remote server's SSL certificate or SSH md5 fingerprint was deemed not OK.
 				error.append(" while connecting to " + sessionState.configRlz.url
