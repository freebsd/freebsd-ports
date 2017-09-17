--- src/libs/zbxdbcache/dbconfig.c.orig	2016-12-21 08:08:40 UTC
+++ src/libs/zbxdbcache/dbconfig.c
@@ -33,6 +33,7 @@
 #include "zbxregexp.h"
 #include "cfg.h"
 #include "../zbxcrypto/tls_tcp_active.h"
+#include <openssl/opensslconf.h>
 
 static int	sync_in_progress = 0;
 
@@ -273,7 +274,8 @@ ZBX_DC_CALCITEM;
 
 typedef zbx_item_history_value_t	ZBX_DC_DELTAITEM;
 
-#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
+#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || \
+	(defined(HAVE_OPENSSL) && !defined(OPENSSL_NO_PSK))
 typedef struct
 {
 	const char	*tls_psk_identity;	/* pre-shared key identity           */
@@ -321,7 +323,9 @@ typedef struct
 #if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
 	const char	*tls_issuer;
 	const char	*tls_subject;
+#ifndef OPENSSL_NO_PSK
 	ZBX_DC_PSK	*tls_dc_psk;
+#endif /* OPENSSL_NO_PSK */
 #endif
 	const char	*error;
 	const char	*snmp_error;
@@ -1370,7 +1374,8 @@ static void	DCsync_hosts(DB_RESULT resul
 	time_t			now;
 	signed char		ipmi_authtype;
 	unsigned char		ipmi_privilege;
-#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
+#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || \
+	(defined(HAVE_OPENSSL) && !defined(OPENSSL_NO_PSK))
 	ZBX_DC_PSK		*psk_i, psk_i_local;
 	zbx_ptr_pair_t		*psk_owner, psk_owner_local;
 	zbx_hashset_t		psk_owners;
@@ -1380,7 +1385,8 @@ static void	DCsync_hosts(DB_RESULT resul
 	zbx_vector_uint64_create(&ids);
 	zbx_vector_uint64_reserve(&ids, config->hosts.num_data + 32);
 
-#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
+#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || \
+	(defined(HAVE_OPENSSL) && !defined(OPENSSL_NO_PSK))
 	zbx_hashset_create(&psk_owners, 0, ZBX_DEFAULT_PTR_HASH_FUNC, ZBX_DEFAULT_PTR_COMPARE_FUNC);
 #endif
 	now = time(NULL);
@@ -1523,7 +1529,7 @@ static void	DCsync_hosts(DB_RESULT resul
 		/*                               done                                        */
 		/*                                                                           */
 		/*****************************************************************************/
-
+#ifndef OPENSSL_NO_PSK
 		psk_owner = NULL;
 
 		if ('\0' == *row[33] || '\0' == *row[34])	/* new PSKid or value empty */
@@ -1645,6 +1651,7 @@ done:
 				zbx_hashset_insert(&psk_owners, &psk_owner_local, sizeof(psk_owner_local));
 			}
 		}
+#endif /* OPENSSL_NO_PSK */
 #endif
 		ZBX_STR2UCHAR(host->tls_connect, row[29]);
 		ZBX_STR2UCHAR(host->tls_accept, row[30]);
@@ -1841,6 +1848,7 @@ done:
 		zbx_strpool_release(host->tls_issuer);
 		zbx_strpool_release(host->tls_subject);
 
+#ifndef OPENSSL_NO_PSK
 		/* Maintain 'psks' index. Unlink and delete the PSK identity. */
 		if (NULL != host->tls_dc_psk)
 		{
@@ -1854,13 +1862,15 @@ done:
 				zbx_hashset_remove_direct(&config->psks, psk_i);
 			}
 		}
+#endif /* OPENSSL_NO_PSK */
 #endif
 		zbx_hashset_iter_remove(&iter);
 	}
 
 	zbx_vector_uint64_destroy(&ids);
 
-#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
+#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || \
+	(defined(HAVE_OPENSSL) && !defined(OPENSSL_NO_PSK))
 	zbx_hashset_destroy(&psk_owners);
 #endif
 	zabbix_log(LOG_LEVEL_DEBUG, "End of %s()", __function_name);
@@ -5169,7 +5179,8 @@ static int	__config_regexp_compare(const
 	return r1->name == r2->name ? 0 : strcmp(r1->name, r2->name);
 }
 
-#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
+#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || \
+	(defined(HAVE_OPENSSL) && !defined(OPENSSL_NO_PSK))
 static zbx_hash_t	__config_psk_hash(const void *data)
 {
 	const ZBX_DC_PSK	*psk_i = (const ZBX_DC_PSK *)data;
@@ -5284,7 +5295,8 @@ void	init_configuration_cache(void)
 	CREATE_HASHSET_EXT(config->interface_snmpaddrs, 0, __config_interface_addr_hash, __config_interface_addr_compare);
 	CREATE_HASHSET_EXT(config->regexps, 0, __config_regexp_hash, __config_regexp_compare);
 
-#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
+#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || \
+	(defined(HAVE_OPENSSL) && !defined(OPENSSL_NO_PSK))
 	CREATE_HASHSET_EXT(config->psks, 0, __config_psk_hash, __config_psk_compare);
 #endif
 	for (i = 0; i < CONFIG_TIMER_FORKS; i++)
@@ -5473,6 +5485,7 @@ static void	DCget_host(DC_HOST *dst_host
 	strscpy(dst_host->tls_issuer, src_host->tls_issuer);
 	strscpy(dst_host->tls_subject, src_host->tls_subject);
 
+#ifndef OPENSSL_NO_PSK
 	if (NULL == src_host->tls_dc_psk)
 	{
 		*dst_host->tls_psk_identity = '\0';
@@ -5483,6 +5496,7 @@ static void	DCget_host(DC_HOST *dst_host
 		strscpy(dst_host->tls_psk_identity, src_host->tls_dc_psk->tls_psk_identity);
 		strscpy(dst_host->tls_psk, src_host->tls_dc_psk->tls_psk);
 	}
+#endif /* OPENSSL_NO_PSK */
 #endif
 	if (NULL != (ipmihost = zbx_hashset_search(&config->ipmihosts, &src_host->hostid)))
 	{
@@ -5573,6 +5587,7 @@ int	DCcheck_proxy_permissions(const char
 			return FAIL;
 		}
 	}
+#ifndef OPENSSL_NO_PSK
 	else if (ZBX_TCP_SEC_TLS_PSK == sock->connection_type)
 	{
 		if (SUCCEED != zbx_tls_get_attr_psk(sock, &attr))
@@ -5582,6 +5597,7 @@ int	DCcheck_proxy_permissions(const char
 			return FAIL;
 		}
 	}
+#endif
 	else if (ZBX_TCP_SEC_UNENCRYPTED != sock->connection_type)
 	{
 		*error = zbx_strdup(*error, "internal error: invalid connection type");
@@ -5632,6 +5648,7 @@ int	DCcheck_proxy_permissions(const char
 			return FAIL;
 		}
 	}
+#ifndef OPENSSL_NO_PSK
 	else if (ZBX_TCP_SEC_TLS_PSK == sock->connection_type)
 	{
 		if (NULL != dc_host->tls_dc_psk)
@@ -5653,6 +5670,7 @@ int	DCcheck_proxy_permissions(const char
 			return FAIL;
 		}
 	}
+#endif /* OPENSSL_NO_PSK */
 #endif
 	*hostid = dc_host->hostid;
 
@@ -5661,7 +5679,8 @@ int	DCcheck_proxy_permissions(const char
 	return SUCCEED;
 }
 
-#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
+#if defined(HAVE_POLARSSL) || defined(HAVE_GNUTLS) || \
+	(defined(HAVE_OPENSSL) && !defined(OPENSSL_NO_PSK))
 /******************************************************************************
  *                                                                            *
  * Function: DCget_psk_by_identity                                            *
@@ -7987,11 +8006,13 @@ static void	DCget_proxy(DC_PROXY *dst_pr
 			strscpy(dst_proxy->tls_arg1, host->tls_issuer);
 			strscpy(dst_proxy->tls_arg2, host->tls_subject);
 		}
+#ifndef OPENSSL_NO_PSK
 		else if (ZBX_TCP_SEC_TLS_PSK == host->tls_connect && NULL != host->tls_dc_psk)
 		{
 			strscpy(dst_proxy->tls_arg1, host->tls_dc_psk->tls_psk_identity);
 			strscpy(dst_proxy->tls_arg2, host->tls_dc_psk->tls_psk);
 		}
+#endif /* OPENSSL_NO_PSK */
 		else	/* ZBX_TCP_SEC_UNENCRYPTED */
 #endif
 		{
