--- libfreerdp/crypto/tls.c.orig	2014-09-11 22:46:32 UTC
+++ libfreerdp/crypto/tls.c
@@ -34,6 +34,7 @@
 #include <freerdp/utils/debug.h>
 #include <freerdp/crypto/tls.h>
 #include "../core/tcp.h"
+#include "opensslcompat.h"
 
 #ifdef HAVE_POLL_H
 #include <poll.h>
@@ -55,7 +56,7 @@ static int bio_rdp_tls_write(BIO* bio, const char* buf
 {
 	int error;
 	int status;
-	BIO_RDP_TLS* tls = (BIO_RDP_TLS*) bio->ptr;
+	BIO_RDP_TLS* tls = (BIO_RDP_TLS*) BIO_get_data(bio);
 
 	if (!buf || !tls)
 		return 0;
@@ -82,12 +83,12 @@ static int bio_rdp_tls_write(BIO* bio, const char* buf
 
 			case SSL_ERROR_WANT_X509_LOOKUP:
 				BIO_set_flags(bio, BIO_FLAGS_IO_SPECIAL);
-				bio->retry_reason = BIO_RR_SSL_X509_LOOKUP;
+				BIO_set_retry_reason(bio, BIO_RR_SSL_X509_LOOKUP);
 				break;
 
 			case SSL_ERROR_WANT_CONNECT:
 				BIO_set_flags(bio, BIO_FLAGS_IO_SPECIAL);
-				bio->retry_reason = BIO_RR_CONNECT;
+				BIO_set_retry_reason(bio, BIO_RR_CONNECT);
 				break;
 
 			case SSL_ERROR_SYSCALL:
@@ -116,7 +117,7 @@ static int bio_rdp_tls_read(BIO* bio, char* buf, int s
 {
 	int error;
 	int status;
-	BIO_RDP_TLS* tls = (BIO_RDP_TLS*) bio->ptr;
+	BIO_RDP_TLS* tls = (BIO_RDP_TLS*) BIO_get_data(bio);
 
 	if (!buf || !tls)
 		return 0;
@@ -143,17 +144,17 @@ static int bio_rdp_tls_read(BIO* bio, char* buf, int s
 
 			case SSL_ERROR_WANT_X509_LOOKUP:
 				BIO_set_flags(bio, BIO_FLAGS_IO_SPECIAL);
-				bio->retry_reason = BIO_RR_SSL_X509_LOOKUP;
+				BIO_set_retry_reason(bio, BIO_RR_SSL_X509_LOOKUP);
 				break;
 
 			case SSL_ERROR_WANT_ACCEPT:
 				BIO_set_flags(bio, BIO_FLAGS_IO_SPECIAL);
-				bio->retry_reason = BIO_RR_ACCEPT;
+				BIO_set_retry_reason(bio, BIO_RR_ACCEPT);
 				break;
 
 			case SSL_ERROR_WANT_CONNECT:
 				BIO_set_flags(bio, BIO_FLAGS_IO_SPECIAL);
-				bio->retry_reason = BIO_RR_CONNECT;
+				BIO_set_retry_reason(bio, BIO_RR_CONNECT);
 				break;
 
 			case SSL_ERROR_SSL:
@@ -203,9 +204,11 @@ static int bio_rdp_tls_gets(BIO* bio, char* str, int s
 
 static long bio_rdp_tls_ctrl(BIO* bio, int cmd, long num, void* ptr)
 {
-	BIO* rbio;
+	BIO* ssl_rbio;
+	BIO* ssl_wbio;
+	BIO* next_bio;
 	int status = -1;
-	BIO_RDP_TLS* tls = (BIO_RDP_TLS*) bio->ptr;
+	BIO_RDP_TLS* tls = (BIO_RDP_TLS*) BIO_get_data(bio);
 
 	if (!tls)
 		return 0;
@@ -213,28 +216,32 @@ static long bio_rdp_tls_ctrl(BIO* bio, int cmd, long n
 	if (!tls->ssl && (cmd != BIO_C_SET_SSL))
 		return 0;
 
+	next_bio = BIO_next(bio);
+	ssl_rbio = tls->ssl ? SSL_get_rbio(tls->ssl) : NULL;
+	ssl_wbio = tls->ssl ? SSL_get_wbio(tls->ssl) : NULL;
+
 	switch (cmd)
 	{
 		case BIO_CTRL_RESET:
 			SSL_shutdown(tls->ssl);
 
-			if (tls->ssl->handshake_func == tls->ssl->method->ssl_connect)
+			if (SSL_in_connect_init(tls->ssl))
 				SSL_set_connect_state(tls->ssl);
-			else if (tls->ssl->handshake_func == tls->ssl->method->ssl_accept)
+			else if (SSL_in_accept_init(tls->ssl))
 				SSL_set_accept_state(tls->ssl);
 
 			SSL_clear(tls->ssl);
 
-			if (bio->next_bio)
-				status = BIO_ctrl(bio->next_bio, cmd, num, ptr);
-			else if (tls->ssl->rbio)
-				status = BIO_ctrl(tls->ssl->rbio, cmd, num, ptr);
+			if (next_bio)
+				status = BIO_ctrl(next_bio, cmd, num, ptr);
+			else if (ssl_rbio)
+				status = BIO_ctrl(ssl_rbio, cmd, num, ptr);
 			else
 				status = 1;
 			break;
 
 		case BIO_C_GET_FD:
-			status = BIO_ctrl(tls->ssl->rbio, cmd, num, ptr);
+			status = BIO_ctrl(ssl_rbio, cmd, num, ptr);
 			break;
 
 		case BIO_CTRL_INFO:
@@ -259,36 +266,41 @@ static long bio_rdp_tls_ctrl(BIO* bio, int cmd, long n
 			break;
 
 		case BIO_CTRL_GET_CLOSE:
-			status = bio->shutdown;
+			status = BIO_get_shutdown(bio);
 			break;
 
 		case BIO_CTRL_SET_CLOSE:
-			bio->shutdown = (int) num;
+			BIO_set_shutdown(bio, (int) num);
 			status = 1;
 			break;
 
 		case BIO_CTRL_WPENDING:
-			status = BIO_ctrl(tls->ssl->wbio, cmd, num, ptr);
+			status = BIO_ctrl(ssl_wbio, cmd, num, ptr);
 			break;
 
 		case BIO_CTRL_PENDING:
 			status = SSL_pending(tls->ssl);
 			if (status == 0)
-				status = BIO_pending(tls->ssl->rbio);
+				status = BIO_pending(ssl_rbio);
 			break;
 
 		case BIO_CTRL_FLUSH:
 			BIO_clear_retry_flags(bio);
-			status = BIO_ctrl(tls->ssl->wbio, cmd, num, ptr);
+			status = BIO_ctrl(ssl_wbio, cmd, num, ptr);
 			BIO_copy_next_retry(bio);
 			status = 1;
 			break;
 
 		case BIO_CTRL_PUSH:
-			if (bio->next_bio && (bio->next_bio != tls->ssl->rbio))
+			if (next_bio && (next_bio != ssl_rbio))
 			{
-				SSL_set_bio(tls->ssl, bio->next_bio, bio->next_bio);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+				SSL_set_bio(tls->ssl, next_bio, next_bio);
 				CRYPTO_add(&(bio->next_bio->references), 1, CRYPTO_LOCK_BIO);
+#else
+				BIO_up_ref(next_bio);
+				SSL_set_bio(tls->ssl, next_bio, next_bio);
+#endif
 			}
 			status = 1;
 			break;
@@ -296,13 +308,17 @@ static long bio_rdp_tls_ctrl(BIO* bio, int cmd, long n
 		case BIO_CTRL_POP:
 			if (bio == ptr)
 			{
-				if (tls->ssl->rbio != tls->ssl->wbio)
-					BIO_free_all(tls->ssl->wbio);
+				if (ssl_rbio != ssl_wbio)
+					BIO_free_all(ssl_wbio);
 
-				if (bio->next_bio)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+				if (next_bio)
 					CRYPTO_add(&(bio->next_bio->references), -1, CRYPTO_LOCK_BIO);
 
 				tls->ssl->wbio = tls->ssl->rbio = NULL;
+#else
+				SSL_set_bio(tls->ssl, NULL, NULL);
+#endif
 			}
 			status = 1;
 			break;
@@ -316,29 +332,34 @@ static long bio_rdp_tls_ctrl(BIO* bio, int cmd, long n
 			break;
 
 		case BIO_C_SET_SSL:
-			bio->shutdown = (int) num;
+			BIO_set_shutdown(bio, (int) num);
 
-			if (ptr)
+			if (ptr) {
 				tls->ssl = (SSL*) ptr;
+				ssl_rbio = SSL_get_rbio(tls->ssl);
+				ssl_wbio = SSL_get_wbio(tls->ssl);
+			}
 
-			rbio = SSL_get_rbio(tls->ssl);
-
-			if (rbio)
+			if (ssl_rbio)
 			{
-				if (bio->next_bio)
-					BIO_push(rbio, bio->next_bio);
+				if (next_bio)
+					BIO_push(ssl_rbio, next_bio);
 
-				bio->next_bio = rbio;
-				CRYPTO_add(&(rbio->references), 1, CRYPTO_LOCK_BIO);
+				BIO_set_next(bio, ssl_rbio);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+				CRYPTO_add(&(ssl_rbio->references), 1, CRYPTO_LOCK_BIO);
+#else
+				BIO_up_ref(ssl_rbio);
+#endif
 			}
 
-			bio->init = 1;
+			BIO_set_init(bio, 1);
 			status = 1;
 			break;
 
 		case BIO_C_DO_STATE_MACHINE:
 			BIO_clear_flags(bio, BIO_FLAGS_READ | BIO_FLAGS_WRITE | BIO_FLAGS_IO_SPECIAL);
-			bio->retry_reason = 0;
+			BIO_set_retry_reason(bio, 0);
 
 			status = SSL_do_handshake(tls->ssl);
 
@@ -356,7 +377,7 @@ static long bio_rdp_tls_ctrl(BIO* bio, int cmd, long n
 
 					case SSL_ERROR_WANT_CONNECT:
 						BIO_set_flags(bio, BIO_FLAGS_IO_SPECIAL | BIO_FLAGS_SHOULD_RETRY);
-						bio->retry_reason = bio->next_bio->retry_reason;
+						BIO_set_retry_reason(bio, BIO_get_retry_reason(next_bio));
 						break;
 
 					default:
@@ -367,7 +388,7 @@ static long bio_rdp_tls_ctrl(BIO* bio, int cmd, long n
 			break;
 
 		default:
-			status = BIO_ctrl(tls->ssl->rbio, cmd, num, ptr);
+			status = BIO_ctrl(ssl_rbio, cmd, num, ptr);
 			break;
 	}
 
@@ -378,17 +399,16 @@ static int bio_rdp_tls_new(BIO* bio)
 {
 	BIO_RDP_TLS* tls;
 
-	bio->init = 0;
-	bio->num = 0;
-	bio->flags = BIO_FLAGS_SHOULD_RETRY;
-	bio->next_bio = NULL;
+	BIO_set_init(bio, 0);
+	BIO_set_data(bio, 0);
+	BIO_set_flags(bio, BIO_FLAGS_SHOULD_RETRY);
 
 	tls = calloc(1, sizeof(BIO_RDP_TLS));
 
 	if (!tls)
 		return 0;
 
-	bio->ptr = (void*) tls;
+	BIO_set_data(bio, (void*) tls);
 
 	return 1;
 }
@@ -400,21 +420,21 @@ static int bio_rdp_tls_free(BIO* bio)
 	if (!bio)
 		return 0;
 
-	tls = (BIO_RDP_TLS*) bio->ptr;
+	tls = (BIO_RDP_TLS*) BIO_get_data(bio);
 
 	if (!tls)
 		return 0;
 
-	if (bio->shutdown)
+	if (BIO_get_shutdown(bio))
 	{
-		if (bio->init && tls->ssl)
+		if (BIO_get_init(bio) && tls->ssl)
 		{
 			SSL_shutdown(tls->ssl);
 			SSL_free(tls->ssl);
 		}
 
-		bio->init = 0;
-		bio->flags = 0;
+		BIO_set_init(bio, 0);
+		BIO_set_flags(bio, 0);
 	}
 
 	free(tls);
@@ -430,7 +450,7 @@ static long bio_rdp_tls_callback_ctrl(BIO* bio, int cm
 	if (!bio)
 		return 0;
 
-	tls = (BIO_RDP_TLS*) bio->ptr;
+	tls = (BIO_RDP_TLS*) BIO_get_data(bio);
 
 	if (!tls)
 		return 0;
@@ -443,7 +463,7 @@ static long bio_rdp_tls_callback_ctrl(BIO* bio, int cm
 			break;
 
 		default:
-			status = BIO_callback_ctrl(tls->ssl->rbio, cmd, fp);
+			status = BIO_callback_ctrl(SSL_get_rbio(tls->ssl), cmd, fp);
 			break;
 	}
 
@@ -452,23 +472,26 @@ static long bio_rdp_tls_callback_ctrl(BIO* bio, int cm
 
 #define BIO_TYPE_RDP_TLS	68
 
-static BIO_METHOD bio_rdp_tls_methods =
-{
-	BIO_TYPE_RDP_TLS,
-	"RdpTls",
-	bio_rdp_tls_write,
-	bio_rdp_tls_read,
-	bio_rdp_tls_puts,
-	bio_rdp_tls_gets,
-	bio_rdp_tls_ctrl,
-	bio_rdp_tls_new,
-	bio_rdp_tls_free,
-	bio_rdp_tls_callback_ctrl,
-};
-
 BIO_METHOD* BIO_s_rdp_tls(void)
 {
-	return &bio_rdp_tls_methods;
+	static BIO_METHOD* bio_methods = NULL;
+
+	if (bio_methods == NULL)
+	{
+		if (!(bio_methods = BIO_meth_new(BIO_TYPE_RDP_TLS, "RdpTls")))
+			return NULL;
+
+		BIO_meth_set_write(bio_methods, bio_rdp_tls_write);
+		BIO_meth_set_read(bio_methods, bio_rdp_tls_read);
+		BIO_meth_set_puts(bio_methods, bio_rdp_tls_puts);
+		BIO_meth_set_gets(bio_methods, bio_rdp_tls_gets);
+		BIO_meth_set_ctrl(bio_methods, bio_rdp_tls_ctrl);
+		BIO_meth_set_create(bio_methods, bio_rdp_tls_new);
+		BIO_meth_set_destroy(bio_methods, bio_rdp_tls_free);
+		BIO_meth_set_callback_ctrl(bio_methods, bio_rdp_tls_callback_ctrl);
+	}
+
+	return bio_methods;
 }
 
 BIO* BIO_new_rdp_tls(SSL_CTX* ctx, int client)
@@ -825,6 +848,8 @@ BOOL tls_disconnect(rdpTls* tls)
 	if (!tls->ssl)
 		return TRUE;
 
+	/* Not functional with newer OpenSSL */
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	if (tls->alertDescription != TLS_ALERT_DESCRIPTION_CLOSE_NOTIFY)
 	{
 		/**
@@ -855,6 +880,7 @@ BOOL tls_disconnect(rdpTls* tls)
 	{
 		SSL_shutdown(tls->ssl);
 	}
+#endif
 
 	return TRUE;
 }
@@ -868,7 +894,7 @@ BIO *findBufferedBio(BIO *front)
 	{
 		if (BIO_method_type(ret) == BIO_TYPE_BUFFERED)
 			return ret;
-		ret = ret->next_bio;
+		ret = BIO_next(ret);
 	}
 
 	return ret;
@@ -896,7 +922,7 @@ int tls_write_all(rdpTls* tls, const BYTE* data, int l
 		return -1;
 	}
 
-	tcp = (rdpTcp*) bufferedBio->ptr;
+	tcp = (rdpTcp*) BIO_get_data(bufferedBio);
 
 	do
 	{
