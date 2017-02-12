--- src/libs/zbxcrypto/tls.c.orig	2016-12-21 08:08:40 UTC
+++ src/libs/zbxcrypto/tls.c
@@ -54,7 +54,8 @@
 #	define ZBX_TLS_CIPHERSUITE_ALL	2			/* select ciphersuites with certificate and PSK */
 #endif
 
-#if defined(HAVE_OPENSSL) && OPENSSL_VERSION_NUMBER < 0x1010000fL	/* for OpenSSL 1.0.1/1.0.2 (before 1.1.0) */
+#if defined(HAVE_OPENSSL) && OPENSSL_VERSION_NUMBER < 0x1010000fL \
+	|| defined(LIBRESSL_VERSION_NUMBER)	/* for OpenSSL 1.0.1/1.0.2 (before 1.1.0) */
 
 /* mutexes for multi-threaded OpenSSL (see "man 3ssl threads" and example in crypto/threads/mttest.c) */
 
@@ -178,8 +179,10 @@ extern char				*CONFIG_TLS_SERVER_CERT_I
 extern char				*CONFIG_TLS_SERVER_CERT_SUBJECT;
 extern char				*CONFIG_TLS_CERT_FILE;
 extern char				*CONFIG_TLS_KEY_FILE;
+#ifndef OPENSSL_NO_PSK
 extern char				*CONFIG_TLS_PSK_IDENTITY;
 extern char				*CONFIG_TLS_PSK_FILE;
+#endif
 
 ZBX_THREAD_LOCAL static char		*my_psk_identity	= NULL;
 ZBX_THREAD_LOCAL static size_t		my_psk_identity_len	= 0;
@@ -216,11 +219,13 @@ ZBX_THREAD_LOCAL static const SSL_METHOD
 ZBX_THREAD_LOCAL static SSL_CTX			*ctx_cert		= NULL;
 ZBX_THREAD_LOCAL static SSL_CTX			*ctx_psk		= NULL;
 ZBX_THREAD_LOCAL static SSL_CTX			*ctx_all		= NULL;
+#ifndef OPENSSL_NO_PSK
 /* variables for passing required PSK identity and PSK info to client callback function */
 ZBX_THREAD_LOCAL static char			*psk_identity_for_cb	= NULL;
 ZBX_THREAD_LOCAL static size_t			psk_identity_len_for_cb	= 0;
 ZBX_THREAD_LOCAL static char			*psk_for_cb		= NULL;
 ZBX_THREAD_LOCAL static size_t			psk_len_for_cb		= 0;
+#endif
 static int					init_done 		= 0;
 /* buffer for messages produced by zbx_openssl_info_cb() */
 ZBX_THREAD_LOCAL char				info_buf[256];
@@ -532,11 +537,13 @@ static const char	*zbx_tls_parameter_nam
 	if (&CONFIG_TLS_KEY_FILE == param)
 		return ZBX_TLS_PARAMETER_CONFIG_FILE == type ? "TLSKeyFile" : "--tls-key-file";
 
+#ifndef OPENSSL_NO_PSK
 	if (&CONFIG_TLS_PSK_IDENTITY == param)
 		return ZBX_TLS_PARAMETER_CONFIG_FILE == type ? "TLSPSKIdentity" : "--tls-psk-identity";
 
 	if (&CONFIG_TLS_PSK_FILE == param)
 		return ZBX_TLS_PARAMETER_CONFIG_FILE == type ? "TLSPSKFile" : "--tls-psk-file";
+#endif
 
 	THIS_SHOULD_NEVER_HAPPEN;
 
@@ -742,8 +749,10 @@ void	zbx_tls_validate_config(void)
 	zbx_tls_parameter_not_empty(&CONFIG_TLS_SERVER_CERT_SUBJECT);
 	zbx_tls_parameter_not_empty(&CONFIG_TLS_CERT_FILE);
 	zbx_tls_parameter_not_empty(&CONFIG_TLS_KEY_FILE);
+#ifndef OPENSSL_NO_PSK
 	zbx_tls_parameter_not_empty(&CONFIG_TLS_PSK_IDENTITY);
 	zbx_tls_parameter_not_empty(&CONFIG_TLS_PSK_FILE);
+#endif
 
 	/* parse and validate 'TLSConnect' parameter (in zabbix_proxy.conf, zabbix_agentd.conf) and '--tls-connect' */
 	/* parameter (in zabbix_get and zabbix_sender) */
@@ -756,8 +765,10 @@ void	zbx_tls_validate_config(void)
 			configured_tls_connect_mode = ZBX_TCP_SEC_UNENCRYPTED;
 		else if (0 == strcmp(CONFIG_TLS_CONNECT, ZBX_TCP_SEC_TLS_CERT_TXT))
 			configured_tls_connect_mode = ZBX_TCP_SEC_TLS_CERT;
+#ifndef OPENSSL_NO_PSK
 		else if (0 == strcmp(CONFIG_TLS_CONNECT, ZBX_TCP_SEC_TLS_PSK_TXT))
 			configured_tls_connect_mode = ZBX_TCP_SEC_TLS_PSK;
+#endif
 		else
 			zbx_tls_validation_error(ZBX_TLS_VALIDATION_INVALID, &CONFIG_TLS_CONNECT, NULL);
 	}
@@ -785,8 +796,10 @@ void	zbx_tls_validate_config(void)
 				accept_modes_tmp |= ZBX_TCP_SEC_UNENCRYPTED;
 			else if (0 == strcmp(p, ZBX_TCP_SEC_TLS_CERT_TXT))
 				accept_modes_tmp |= ZBX_TCP_SEC_TLS_CERT;
+#ifndef OPENSSL_NO_PSK
 			else if (0 == strcmp(p, ZBX_TCP_SEC_TLS_PSK_TXT))
 				accept_modes_tmp |= ZBX_TCP_SEC_TLS_PSK;
+#endif
 			else
 			{
 				zbx_free(s);
@@ -841,6 +854,7 @@ void	zbx_tls_validate_config(void)
 				&CONFIG_TLS_CERT_FILE);
 	}
 
+#ifndef OPENSSL_NO_PSK
 	/* either both a PSK and a PSK identity must be defined or none of them */
 
 	if (NULL != CONFIG_TLS_PSK_FILE && NULL == CONFIG_TLS_PSK_IDENTITY)
@@ -852,6 +866,7 @@ void	zbx_tls_validate_config(void)
 	/* PSK identity must be a valid UTF-8 string (RFC 4279 says Unicode) */
 	if (NULL != CONFIG_TLS_PSK_IDENTITY && SUCCEED != zbx_is_utf8(CONFIG_TLS_PSK_IDENTITY))
 		zbx_tls_validation_error(ZBX_TLS_VALIDATION_UTF8, &CONFIG_TLS_PSK_IDENTITY, NULL);
+#endif
 
 	/* active agentd, active proxy, zabbix_get, and zabbix_sender specific validation */
 
@@ -867,11 +882,13 @@ void	zbx_tls_validate_config(void)
 					&CONFIG_TLS_CONNECT);
 		}
 
+#ifndef OPENSSL_NO_PSK
 		if (NULL != CONFIG_TLS_PSK_FILE && NULL == CONFIG_TLS_CONNECT)
 		{
 			zbx_tls_validation_error(ZBX_TLS_VALIDATION_DEPENDENCY, &CONFIG_TLS_PSK_FILE,
 					&CONFIG_TLS_CONNECT);
 		}
+#endif
 
 		if (0 != (configured_tls_connect_mode & ZBX_TCP_SEC_TLS_CERT) && NULL == CONFIG_TLS_CERT_FILE)
 		{
@@ -879,11 +896,13 @@ void	zbx_tls_validate_config(void)
 					&CONFIG_TLS_CERT_FILE);
 		}
 
+#ifndef OPENSSL_NO_PSK
 		if (0 != (configured_tls_connect_mode & ZBX_TCP_SEC_TLS_PSK) && NULL == CONFIG_TLS_PSK_FILE)
 		{
 			zbx_tls_validation_error(ZBX_TLS_VALIDATION_REQUIREMENT, &CONFIG_TLS_CONNECT,
 					&CONFIG_TLS_PSK_FILE);
 		}
+#endif
 	}
 
 	/* passive agentd and passive proxy specific validation */
@@ -899,11 +918,13 @@ void	zbx_tls_validate_config(void)
 					&CONFIG_TLS_ACCEPT);
 		}
 
+#ifndef OPENSSL_NO_PSK
 		if (NULL != CONFIG_TLS_PSK_FILE && NULL == CONFIG_TLS_ACCEPT)
 		{
 			zbx_tls_validation_error(ZBX_TLS_VALIDATION_DEPENDENCY, &CONFIG_TLS_PSK_FILE,
 					&CONFIG_TLS_ACCEPT);
 		}
+#endif
 
 		if (0 != (configured_tls_accept_modes & ZBX_TCP_SEC_TLS_CERT) && NULL == CONFIG_TLS_CERT_FILE)
 		{
@@ -911,11 +932,13 @@ void	zbx_tls_validate_config(void)
 					&CONFIG_TLS_CERT_FILE);
 		}
 
+#ifndef OPENSSL_NO_PSK
 		if (0 != (configured_tls_accept_modes & ZBX_TCP_SEC_TLS_PSK) && NULL == CONFIG_TLS_PSK_FILE)
 		{
 			zbx_tls_validation_error(ZBX_TLS_VALIDATION_REQUIREMENT, &CONFIG_TLS_ACCEPT,
 					&CONFIG_TLS_PSK_FILE);
 		}
+#endif
 	}
 }
 #endif	/* defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL) */
@@ -1363,6 +1386,7 @@ static int	zbx_psk_cb(gnutls_session_t s
  *     by this callback function. We use global variables to pass this info.  *
  *                                                                            *
  ******************************************************************************/
+#ifndef OPENSSL_NO_PSK
 static unsigned int	zbx_psk_client_cb(SSL *ssl, const char *hint, char *identity,
 		unsigned int max_identity_len, unsigned char *psk, unsigned int max_psk_len)
 {
@@ -1396,6 +1420,7 @@ static unsigned int	zbx_psk_client_cb(SS
 
 	return (unsigned int)psk_len_for_cb;
 }
+#endif
 
 /******************************************************************************
  *                                                                            *
@@ -1529,6 +1554,7 @@ static void	zbx_check_psk_identity_len(s
  *     at runtime.                                                            *
  *                                                                            *
  ******************************************************************************/
+#ifndef OPENSSL_NO_PSK
 static void	zbx_read_psk_file(void)
 {
 	FILE		*f;
@@ -1593,6 +1619,7 @@ out:
 	zbx_tls_free();
 	exit(EXIT_FAILURE);
 }
+#endif /* OPENSSL_NO_PSK */
 #endif
 
 #if defined(HAVE_POLARSSL)
@@ -3152,6 +3179,7 @@ void	zbx_tls_init_child(void)
 
 	/* Create context for PSK-only authentication. PSK can come from configuration file (in proxy, agentd) */
 	/* and later from database (in server, proxy). */
+#ifndef OPENSSL_NO_PSK
 	if (NULL != CONFIG_TLS_PSK_FILE || 0 != (program_type & (ZBX_PROGRAM_TYPE_SERVER | ZBX_PROGRAM_TYPE_PROXY)))
 	{
 		if (NULL == (ctx_psk = SSL_CTX_new(method)))
@@ -3160,6 +3188,7 @@ void	zbx_tls_init_child(void)
 		if (1 != SSL_CTX_set_min_proto_version(ctx_psk, TLS1_2_VERSION))
 			goto out_method;
 	}
+#endif
 
 	/* Sometimes we need to be ready for both certificate and PSK whichever comes in. Set up a universal context */
 	/* for certificate and PSK authentication to prepare for both. */
@@ -3314,6 +3343,7 @@ void	zbx_tls_init_child(void)
 
 	/* 'TLSPSKIdentity' and 'TLSPSKFile' parameters (in zabbix_proxy.conf, zabbix_agentd.conf). */
 	/*  Load pre-shared key and identity to be used with the pre-shared key. */
+#ifndef OPENSSL_NO_PSK
 	if (NULL != CONFIG_TLS_PSK_FILE)
 	{
 		my_psk_identity = CONFIG_TLS_PSK_IDENTITY;
@@ -3339,6 +3369,7 @@ void	zbx_tls_init_child(void)
 		psk_for_cb = my_psk;
 		psk_len_for_cb = my_psk_len;
 	}
+#endif
 
 	if (NULL != ctx_cert)
 	{
@@ -3375,6 +3406,7 @@ void	zbx_tls_init_child(void)
 		zbx_log_ciphersuites(__function_name, "certificate", ctx_cert);
 	}
 
+#ifndef OPENSSL_NO_PSK
 	if (NULL != ctx_psk)
 	{
 		const char	*ciphers;
@@ -3408,6 +3440,7 @@ void	zbx_tls_init_child(void)
 
 		zbx_log_ciphersuites(__function_name, "PSK", ctx_psk);
 	}
+#endif
 
 	if (NULL != ctx_all)
 	{
@@ -3415,8 +3448,10 @@ void	zbx_tls_init_child(void)
 
 		SSL_CTX_set_info_callback(ctx_all, zbx_openssl_info_cb);
 
+#ifndef OPENSSL_NO_PSK
 		if (0 != (program_type & (ZBX_PROGRAM_TYPE_SERVER | ZBX_PROGRAM_TYPE_PROXY | ZBX_PROGRAM_TYPE_AGENTD)))
 			SSL_CTX_set_psk_server_callback(ctx_all, zbx_psk_server_cb);
+#endif
 
 		SSL_CTX_set_mode(ctx_all, SSL_MODE_AUTO_RETRY);
 		SSL_CTX_set_options(ctx_all, SSL_OP_CIPHER_SERVER_PREFERENCE | SSL_OP_NO_TICKET);
@@ -4188,6 +4223,7 @@ int	zbx_tls_connect(zbx_socket_t *s, uns
 			goto out;
 		}
 	}
+#ifndef OPENSSL_NO_PSK
 	else if (ZBX_TCP_SEC_TLS_PSK == tls_connect)
 	{
 		zabbix_log(LOG_LEVEL_DEBUG, "In %s(): psk_identity:\"%s\"", __function_name,
@@ -4242,6 +4278,7 @@ int	zbx_tls_connect(zbx_socket_t *s, uns
 			psk_len_for_cb = (size_t)psk_len;
 		}
 	}
+#endif
 	else
 	{
 		*error = zbx_strdup(*error, "invalid connection parameters");
@@ -5675,7 +5712,8 @@ int	zbx_tls_get_attr_cert(const zbx_sock
 }
 #endif
 
-#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
+#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) \
+	|| (defined(HAVE_OPENSSL) && !defined(OPENSSL_NO_PSK))
 /******************************************************************************
  *                                                                            *
  * Function: zbx_tls_get_attr_psk                                             *
