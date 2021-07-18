--- src/vmod_ip2proxy.c.orig	2020-11-23 23:20:35 UTC
+++ src/vmod_ip2proxy.c
@@ -1,268 +1,109 @@
+/*
+ * IP2Proxy Varnish library is distributed under LGPL version 3
+ * Copyright (c) 2013-2020 IP2Proxy.com. support at ip2location dot com
+ *
+ * This library is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 3 of the License, or any later version.
+ *
+ * This library is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General Public
+ * License along with this library; if not see <http://www.gnu.org/licenses/>.
+ *
+ */
 #include <stdlib.h>
 #include <string.h>
-#include <IP2Proxy.h>
-
-#include <sys/types.h>
-#include <sys/stat.h>
-#include <unistd.h>
-#include <pthread.h>
 
-#ifdef __FreeBSD__
-#include <stdio.h>
-#define gcvt(v, d, c) sprintf(c, "%*g", d, v);
-#endif
+#include <IP2Proxy.h>
 
 #include "cache/cache.h"
 
-/* Varnish < 6.2 compat */
-#ifndef VPFX
-#	define VPFX(a) vmod_ ## a
-#	define VARGS(a) vmod_ ## a ## _arg
-#	define VENUM(a) vmod_enum_ ## a
-#	define VEVENT(a) a
-#else
-#	define VEVENT(a) VPFX(a)
-#endif
-
-#ifndef VRT_H_INCLUDED
-#include "vrt.h"
-#endif
-
-/* Defined options for querying IP2Proxy data */
-#define query_COUNTRY_SHORT			1
-#define query_COUNTRY_LONG			2
-#define query_REGION				3
-#define query_CITY					4
-#define query_ISP					5
-#define query_DOMAIN				6
-#define query_USAGETYPE				7
-#define query_PROXYTYPE				8
-#define query_ASN					9
-#define query_AS					10
-#define query_LASTSEEN				11
-#define query_ISPROXY				12
-#define query_THREAT				13
-
-typedef struct vmod_ip2proxy_data {
-	time_t			ip2p_db_ts;	 /* timestamp of the database file */
-	IP2Proxy		*ip2p_handle;
-	pthread_mutex_t	lock;
-} ip2proxy_data_t;
-
-void
-ip2p_free(void *d)
+static void
+ip2proxy_free(VRT_CTX, void *ptr)
 {
-	ip2proxy_data_t *data = d;
-
-	if (data->ip2p_handle != NULL) {
-		IP2Proxy_close(data->ip2p_handle);
-	}
+	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
+	IP2Proxy_close((IP2Proxy *)ptr);
 }
 
+static const struct vmod_priv_methods ip2p_methods[1] = {{
+	.magic = VMOD_PRIV_METHODS_MAGIC,
+	.type = "vmod_std_ip2proxy",
+	.fini = ip2proxy_free
+}};
+
 VCL_VOID
-VPFX(init_db)(VRT_CTX, struct VPFX(priv) *priv, char *filename, char *memtype)
+vmod_init_db(VRT_CTX, struct vmod_priv *priv, char *filename, char *memtype)
 {
-	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
-
-	if (priv->priv == NULL) {
-		IP2Proxy *IP2ProxyObj = IP2Proxy_open((char *) filename);
-
-		if (IP2ProxyObj == NULL) {
-			printf("Not able to load IP2Proxy Database \"%s\".\n", (char *) filename);
-
-			exit(0);
-		}
-
-		printf("IP2Proxy Database %s is loaded.\n", (char *) filename);
-
-		priv->priv = IP2ProxyObj;
-
-		if (strcmp(memtype, "IP2PROXY_FILE_IO") == 0) {
-			IP2Proxy_set_lookup_mode(priv->priv, IP2PROXY_FILE_IO);
-		} else if (strcmp(memtype, "IP2PROXY_CACHE_MEMORY") == 0) {
-			IP2Proxy_set_lookup_mode(priv->priv, IP2PROXY_CACHE_MEMORY);
-		} else if (strcmp(memtype, "IP2PROXY_SHARED_MEMORY") == 0) {
-			IP2Proxy_set_lookup_mode(priv->priv, IP2PROXY_SHARED_MEMORY);
-		}
-
-		AN(priv->priv);
-		priv->free = ip2p_free;
-	}
-}
+	IP2Proxy *IP2ProxyObj;
+	enum IP2Proxy_lookup_mode mtype;
 
-// Use this function to query result, and then extract the field based on user selection
-void *
-query_all(VRT_CTX, struct VPFX(priv) *priv, char * ip, int option)
-{
-	IP2ProxyRecord *r;
-	IP2Proxy *handle;
-	char *result = NULL;
-	
-	printf("The client IP is %s.\n", (char *) ip);
-	
 	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
+	AN(priv);
+	AN(memtype);
 
-	if (priv->priv != NULL) {
-		handle = priv->priv;
-		r = IP2Proxy_get_all(handle, (char *) ip);
-
-		if (r != NULL) {
-			switch (option) {
-				case query_COUNTRY_SHORT:
-					result = WS_Copy(ctx->ws, r->country_short, -1);
-					break;
-				case query_COUNTRY_LONG:
-					result = WS_Copy(ctx->ws, r->country_long, -1);
-					break;
-				case query_REGION:
-					result = WS_Copy(ctx->ws, r->region, -1);
-					break;
-				case query_CITY:
-					result = WS_Copy(ctx->ws, r->city, -1);
-					break;
-				case query_ISP:
-					result = WS_Copy(ctx->ws, r->isp, -1);
-					break;
-				case query_DOMAIN:
-					result = WS_Copy(ctx->ws, r->domain, -1);
-					break;
-				case query_USAGETYPE:
-					result = WS_Copy(ctx->ws, r->usage_type, -1);
-					break;
-				case query_PROXYTYPE:
-					result = WS_Copy(ctx->ws, r->proxy_type, -1);
-					break;
-				case query_ASN:
-					result = WS_Copy(ctx->ws, r->asn, -1);
-					break;
-				case query_AS:
-					result = WS_Copy(ctx->ws, r->as_, -1);
-					break;
-				case query_LASTSEEN:
-					result = WS_Copy(ctx->ws, r->last_seen, -1);
-					break;
-				case query_ISPROXY:
-					result = WS_Copy(ctx->ws, r->is_proxy, -1);
-					break;
-				case query_THREAT:
-					result = WS_Copy(ctx->ws, r->threat, -1);
-					break;
-				default:
-					result = WS_Copy(ctx->ws, "-", -1);
-					break;
-			}
-
-			IP2Proxy_free_record(r);
-
-			return (result);
-		}
+	if (strcmp(memtype, "IP2PROXY_FILE_IO") == 0)
+		mtype = IP2PROXY_FILE_IO;
+	else if (strcmp(memtype, "IP2PROXY_SHARED_MEMORY") == 0)
+		mtype = IP2PROXY_SHARED_MEMORY;
+	else if (strcmp(memtype, "IP2PROXY_CACHE_MEMORY") == 0)
+		mtype = IP2PROXY_CACHE_MEMORY;
+	else {
+		VRT_fail(ctx, "IP2Proxy: invalid memtype (%s)", memtype);
+		return;
 	}
 
-	// VMOD_LOG("ERROR: IP2Proxy database failed to load");
-
-	return WS_Copy(ctx->ws, "????", -1);
-}
-
-VCL_STRING
-VPFX(country_short)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_COUNTRY_SHORT);
-	return (result);
-}
-
-VCL_STRING
-VPFX(country_long)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_COUNTRY_LONG);
-	return (result);
-}
-
-VCL_STRING
-VPFX(region)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_REGION);
-	return (result);
-}
-
-VCL_STRING
-VPFX(city)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_CITY);
-	return (result);
-}
-
-VCL_STRING
-VPFX(isp)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_ISP);
-	return (result);
-}
-
-VCL_STRING
-VPFX(domain)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_DOMAIN);
-	return (result);
-}
-
-VCL_STRING
-VPFX(usage_type)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_USAGETYPE);
-	return (result);
-}
-
-VCL_STRING
-VPFX(proxy_type)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_PROXYTYPE);
-	return (result);
-}
-
-VCL_STRING
-VPFX(asn)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_ASN);
-	return (result);
-}
+	if (priv->priv != NULL)
+		IP2Proxy_close((IP2Proxy *)priv->priv);
 
-VCL_STRING
-VPFX(as)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_AS);
-	return (result);
-}
+	IP2ProxyObj = IP2Proxy_open(filename);
+	if (!IP2ProxyObj) {
+		VRT_fail(ctx, "IP2Proxy: can't open database (%s)", filename);
+		return;
+	}
+	IP2Proxy_open_mem(IP2ProxyObj, mtype);
 
-VCL_STRING
-VPFX(last_seen)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_LASTSEEN);
-	return (result);
+	priv->priv = IP2ProxyObj;
+	priv->methods = ip2p_methods;
 }
 
-VCL_STRING
-VPFX(is_proxy)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_ISPROXY);
-	return (result);
+#define FUNC(lower, field)					\
+VCL_STRING							\
+vmod_ ## lower(VRT_CTX, struct vmod_priv *priv, char * ip)	\
+{								\
+	char *result;						\
+	IP2ProxyRecord *r;					\
+								\
+	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);			\
+	AN(priv);						\
+								\
+	if (!ip || !priv->priv)					\
+		return ("-");					\
+								\
+	r = IP2Proxy_get_all((IP2Proxy *)priv->priv, ip);	\
+	if (!r)							\
+		return ("-");					\
+								\
+	result = WS_Copy(ctx->ws, r->field, -1);		\
+	IP2Proxy_free_record(r);				\
+								\
+	return (result);					\
 }
 
-VCL_STRING
-VPFX(threat)(VRT_CTX, struct VPFX(priv) *priv, char * ip)
-{
-	const char *result = NULL;
-	result = query_all(ctx, priv, ip, query_THREAT);
-	return (result);
-}
\ No newline at end of file
+FUNC(country_short,  country_short)
+FUNC(country_long,   country_long)
+FUNC(region,         region)
+FUNC(city,           city)
+FUNC(isp,            isp)
+FUNC(domain,         domain)
+FUNC(usage_type,     usage_type)
+FUNC(proxy_type,     proxy_type)
+FUNC(asn,            asn)
+FUNC(as,             as_)
+FUNC(last_seen,      last_seen)
+FUNC(is_proxy,       is_proxy)
+FUNC(threat,         threat)
