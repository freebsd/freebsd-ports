--- Curl_Multi.xsh.orig	2025-08-13 15:48:34 UTC
+++ Curl_Multi.xsh
@@ -65,15 +65,39 @@ cb_multi_socket( CURL *easy_handle, curl_socket_t s, i
 
 	perl_curl_multi_t *multi;
 	perl_curl_easy_t *easy;
+	SV *easy_sv;
 
+	/* Check if userptr is NULL */
+	if (!userptr) {
+		return -1;
+	}
+
 	multi = (perl_curl_multi_t *) userptr;
 
-	(void) curl_easy_getinfo( easy_handle, CURLINFO_PRIVATE, (void *) &easy );
+	if ( ! multi->cb[ CB_MULTI_SOCKET ].func || ! SvOK( multi->cb[ CB_MULTI_SOCKET ].func ) ) {
+		return 0; /* Ignore socket events if no Perl callback is registered */
+	}
 
+	CURLcode res = curl_easy_getinfo( easy_handle, CURLINFO_PRIVATE, (void *) &easy );
+	if (res != CURLE_OK || !easy) {
+		return -1;
+	}
+
+	/* Check if the callback is set - note: the above check might obviate this check */
+	if (multi->cb[CB_MULTI_SOCKET].func == NULL) {
+		return -1;
+	}
+
+	if ( easy ) {
+		easy_sv = SELF2PERL( easy );
+	} else {
+		easy_sv = &PL_sv_undef;
+	}
+
 	/* $multi, $easy, $socket, $what, $socketdata, $userdata */
 	SV *args[] = {
 		/* 0 */ SELF2PERL( multi ),
-		/* 1 */ SELF2PERL( easy ),
+		/* 1 */ easy_sv,
 		/* 2 */ newSVuv( s ),
 		/* 3 */ newSViv( what ),
 		/* 4 */ &PL_sv_undef
@@ -91,6 +115,10 @@ cb_multi_timer( CURLM *multi_handle, long timeout_ms, 
 
 	perl_curl_multi_t *multi;
 	multi = (perl_curl_multi_t *) userptr;
+
+	if ( ! multi->cb[ CB_MULTI_TIMER ].func || ! SvOK( multi->cb[ CB_MULTI_TIMER ].func ) ) {
+		return 0; /* Ignore timer events if no Perl callback is registered */
+	}
 
 	/* $multi, $timeout, $userdata */
 	SV *args[] = {
