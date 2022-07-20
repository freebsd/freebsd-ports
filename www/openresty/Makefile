PORTNAME=	openresty
PORTVERSION=	1.21.4.1
CATEGORIES=	www
MASTER_SITES=	https://openresty.org/download/

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	OpenResty a powerful web app server by extending nginx

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-openresty \
		libpcre.so:devel/pcre

USES=		cpe gmake perl5 ssl

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--group=${WWWGRP} \
		--prefix=${PREFIX} \
		--user=${WWWOWN} \
		--with-cc-opt="-I ${LOCALBASE}/include" \
		--with-ld-opt="-L ${LOCALBASE}/lib" \
		--with-luajit=${LOCALBASE}

OPTIONS_DEFINE=		ARRAYVAR AUTHREQ COOLKIT DRIZZLE ECHO ENCSESSION \
			HEADERSMORE ICONV LUACJSON LUARDS LUAREDISPARS \
			LUARESTYDNS LUARESTYMEM LUARESTYMYSQL LUARESTYREDIS \
			LUARESTYSTRING LUARESTYUPLOAD MEMC MISC NDK POSTGRES \
			RDSCSV RDSJSON REDIS REDIS2 SRCACHE XSS
OPTIONS_DEFAULT=	ARRAYVAR AUTHREQ COOLKIT ECHO ENCSESSION HEADERMORE \
			ICONV MEMC MISC NDK PORTGRES RDSCSV RDSJSON REDIS \
			REDIS2 SRCACHE XSS

OPTIONS_SUB=	yes

ARRAYVAR_DESC=		Add support for array variables to config
AUTHREQ_DESC=		Auth request module
COOLKIT_DESC=		Collection of small and useful nginx add-ons
DRIZZLE_DESC=		Module for talking to MySQL and Drizzle
ECHO_DESC=		Brings echo/sleep/time and more shell-style
ENCSESSION_DESC=	Encrypt and decrypt nginx variable values
HEADERSMORE_DESC=	Set and clear input and output headers
ICONV_DESC=		Iconv support
LUACJSON_DESC=		Lua cjson library
LUARDS_DESC=		Lua rds library
LUAREDISPARS_DESC=	Lua redis parser library
LUARESTYDNS_DESC=	Lua resty dns library
LUARESTYMEM_DESC=	Lua resty memcached library
LUARESTYMYSQL_DESC=	Lua resty mysql library
LUARESTYREDIS_DESC=	Lua resty redis library
LUARESTYSTRING_DESC=	Lua resty string library
LUARESTYUPLOAD_DESC=	Lua resty upload library
MEMC_DESC=		An extended memcached module
MISC_DESC=		Various set_xxx directives added
NDK_DESC=		Nginx Development Kit
POSTGRES_DESC=		Module for talking to Postgeres
RDSCSV_DESC=		Output filter module to convert CSV
RDSJSON_DESC=		An output filter that formats Resty
REDIS2_DESC=		Module for the Redis 2.0 protocol
REDIS_DESC=		HTTP redis module
SRCACHE_DESC=		Transparent subrequest-based caching layout
XSS_DESC=		Native cross-site scripting support in nginx

ARRAYVAR_CONFIGURE_OFF=		--without-http_array_var_module
AUTHREQ_CONFIGURE_ON=		--with-http_auth_request_module
COOLKIT_CONFIGURE_OFF=		--without-http_coolkit_module
DRIZZLE_LIB_DEPENDS=		libdrizzle.so:databases/libdrizzle
DRIZZLE_CONFIGURE_ON=		--with-http_drizzle_module
ECHO_CONFIGURE_OFF=		--without-http_echo_module
ENCSESSION_CONFIGURE_OFF=	--without-http_encrypted_session_module
HEADERSMORE_CONFIGURE_OFF=	--without-http_headers_more_module
ICONV_CONFIGURE_ON=		--with-http_iconv_module
LUACJSON_CONFIGURE_OFF=		--without-lua_cjson
LUARDS_CONFIGURE_OFF=		--without-lua_rds_parser
LUAREDISPARS_CONFIGURE_OFF=	--without-lua_redis_parser
LUARESTYDNS_CONFIGURE_OFF=	--without-lua_resty_dns
LUARESTYMEM_CONFIGURE_OFF=	--without-lua_resty_memcached
LUARESTYMYSQL_CONFIGURE_OFF=	--without-lua_resty_mysql
LUARESTYREDIS_CONFIGURE_OFF=	--without-lua_resty_redis
LUARESTYSTRING_CONFIGURE_OFF=	--without-lua_resty_string
LUARESTYUPLOAD_CONFIGURE_OFF=	--without-lua_resty_upload
MEMC_CONFIGURE_OFF=		--without-http_memc_module
MISC_CONFIGURE_OFF=		--without-http_set_misc_module
NDK_CONFIGURE_OFF=		--without-ngx_devel_kit_module
POSTGRES_USES=			pgsql
POSTGRES_CONFIGURE_ON=		--with-http_postgres_module
RDSCSV_CONFIGURE_OFF=		--without-http_rds_csv_module
RDSJSON_CONFIGURE_OFF=		--without-http_rds_json_module
REDIS2_CONFIGURE_OFF=		--without-http_redis2_module
REDIS_CONFIGURE_OFF=		--without-http_redis_module
SRCACHE_CONFIGURE_OFF=		--without-http_srcache_module
XSS_CONFIGURE_OFF=		--without-http_xss_module

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/nginx/sbin/nginx
	${FIND} ${STAGEDIR}${PREFIX} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
