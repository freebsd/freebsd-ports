--- stone.c.orig	2008-02-04 23:00:00 UTC
+++ stone.c
@@ -2452,15 +2452,16 @@ int modPairDest(Pair *p1, struct sockaddr *dst, sockle
 	    unsigned char **match;
 	    if (Debug > 2) {
 		char str[SSL_MAX_SSL_SESSION_ID_LENGTH * 2 + 1];
-		int len = sess->session_id_length;
+		const unsigned char *sid; unsigned len;
+		sid = SSL_SESSION_get_id(sess, &len);
 		int i;
 		if (len > SSL_MAX_SSL_SESSION_ID_LENGTH)
 		    len = SSL_MAX_SSL_SESSION_ID_LENGTH;
 		for (i=0; i < len; i++)
-		    sprintf(&str[i*2], "%02x", sess->session_id[i]);
+		    sprintf(&str[i*2], "%02x", sid[i]);
 		str[i*2] = '\0';
 		message(LOG_DEBUG, "%d TCP %d: SSL session ID=%s len=%d",
-			p2->stone->sd, p2->sd, str, sess->session_id_length);
+			p2->stone->sd, p2->sd, str, len);
 	    }
 	    match = SSL_SESSION_get_ex_data(sess, MatchIndex);
 	    if (match && p2->stone->ssl_server) {
@@ -3265,7 +3266,7 @@ int doSSL_accept(Pair *pair) {
     if (Debug > 7)
 	message(LOG_DEBUG, "%d TCP %d: SSL_accept ret=%d, state=%x, "
 		"finished=%x, in_init=%x/%x", pair->stone->sd,
-		sd, ret, SSL_state(ssl), SSL_is_init_finished(ssl),
+		sd, ret, SSL_get_state(ssl), SSL_is_init_finished(ssl),
 		SSL_in_init(ssl), SSL_in_accept_init(ssl));
     if (ret > 0) {	/* success */
 	if (SSL_in_accept_init(ssl)) {
@@ -8875,7 +8876,7 @@ void sslopts_default(SSLOpts *opts, int isserver) {
 	opts->meth = SSLv23_server_method();
 #elif !defined(OPENSSL_NO_SSL3)
 	opts->meth = SSLv3_server_method();
-#elif !defined(OPENSSL_NO_SSL2)
+#elif !defined(OPENSSL_NO_SSL2) && OPENSSL_VERSION_NUMBER < 0x10100000L
 	opts->meth = SSLv2_server_method();
 #endif
     } else {
@@ -8885,7 +8886,7 @@ void sslopts_default(SSLOpts *opts, int isserver) {
 	opts->meth = SSLv23_client_method();
 #elif !defined(OPENSSL_NO_SSL3)
 	opts->meth = SSLv3_client_method();
-#elif !defined(OPENSSL_NO_SSL2)
+#elif !defined(OPENSSL_NO_SSL2) && OPENSSL_VERSION_NUMBER < 0x10100000L
 	opts->meth = SSLv2_client_method();
 #endif
     }
@@ -8976,7 +8977,7 @@ int sslopts(int argc, int argi, char *argv[], SSLOpts 
 	if (isserver) opts->meth = SSLv3_server_method();
 	else opts->meth = SSLv3_client_method();
 #endif
-#ifndef OPENSSL_NO_SSL2
+#if !defined(OPENSSL_NO_SSL2) && OPENSSL_VERSION_NUMBER < 0x10100000L
     } else if (!strcmp(argv[argi], "ssl2")) {
 	if (isserver) opts->meth = SSLv2_server_method();
 	else opts->meth = SSLv2_client_method();
