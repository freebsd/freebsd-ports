PORTNAME?=	nginx
PORTVERSION=	${NGINX_VERSION}
.include "version.mk"
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://nginx.org/download/
PKGNAMESUFFIX?=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	joneum@FreeBSD.org
COMMENT?=	Robust and small WWW server
WWW=		https://nginx.com/

LICENSE?=	BSD2CLAUSE
LICENSE_FILE?=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	nginx

PORTSCOUT=	limit:^1\.31\.[0-9]*

USES=		cpe compiler:env

CPE_VENDOR=	f5
CPE_PRODUCT=	nginx
USE_GITHUB=	nodefault

NGINX_VARDIR?=	/var
NGINX_LOGDIR?=	${NGINX_VARDIR}/log/nginx
NGINX_RUNDIR?=	${NGINX_VARDIR}/run
NGINX_TMPDIR?=	${NGINX_VARDIR}/tmp/nginx
HTTP_PORT?=	80

NGINX_ACCESSLOG?=	${NGINX_LOGDIR}/access.log
NGINX_ERRORLOG?=	${NGINX_LOGDIR}/error.log

CONFLICTS?=	nginx-1.* \
		nginx-full-1.* \
		nginx-lite-1.* \
		nginx-naxsi-1.*
USE_RC_SUBR?=	nginx
SUB_FILES?=	pkg-message
SUB_LIST+=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP} \
		NGINX_RUNDIR=${NGINX_RUNDIR} \
		NGINX_TMPDIR=${NGINX_TMPDIR} \
		PREFIX=${PREFIX}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${ETCDIR} \
		--with-cc-opt="-I ${LOCALBASE}/include ${_NJS_QJS_CFLAGS}" \
		--with-ld-opt="-L ${LOCALBASE}/lib" \
		--conf-path=${ETCDIR}/nginx.conf \
		--sbin-path=${PREFIX}/sbin/nginx \
		--pid-path=${NGINX_RUNDIR}/nginx.pid \
		--error-log-path=${NGINX_ERRORLOG} \
		--user=${WWWOWN} --group=${WWWGRP} \
		--with-compat \
		--with-pcre
ALL_TARGET=

PLIST_SUB+=	NGINX_TMPDIR=${NGINX_TMPDIR} NGINX_LOGDIR=${NGINX_LOGDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

USERS?=	${WWWOWN}
GROUPS?=${WWWGRP}

NO_OPTIONS_SORT=	yes

OPTIONS_GROUP=	HTTPGRP MAILGRP STREAMGRP
# Modules that are part of the base nginx distribution
OPTIONS_GROUP_HTTPGRP=	GOOGLE_PERFTOOLS HTTP HTTP_ADDITION HTTP_AUTH_REQ \
	HTTP_CACHE HTTP_DAV HTTP_DEGRADATION HTTP_FLV HTTP_GEOIP \
	HTTP_GUNZIP_FILTER HTTP_GZIP_STATIC HTTP_IMAGE_FILTER HTTP_MP4 \
	HTTP_PERL HTTP_RANDOM_INDEX HTTP_REALIP HTTP_SECURE_LINK \
	HTTP_SLICE HTTP_SSL HTTP_STATUS HTTP_SUB HTTP_XSLT HTTPV2 HTTPV3 \
	HTTPV3_BORING HTTPV3_LSSL HTTPV3_OSSL

OPTIONS_GROUP_MAILGRP=	MAIL MAIL_IMAP MAIL_POP3 MAIL_SMTP MAIL_SSL

OPTIONS_GROUP_STREAMGRP=	STREAM STREAM_GEOIP STREAM_REALIP STREAM_SSL \
	STREAM_SSL_PREREAD

OPTIONS_DEFINE=		DEBUG DEBUGLOG DSO FILE_AIO IPV6 NJS NJS_QJS NJS_XML OTEL THREADS WWW
OPTIONS_DEFAULT?=	DSO FILE_AIO HTTP HTTP_ADDITION HTTP_AUTH_REQ HTTP_CACHE \
		HTTP_DAV HTTP_FLV HTTP_GUNZIP_FILTER HTTP_GZIP_STATIC HTTP_MP4 \
		HTTP_RANDOM_INDEX HTTP_REALIP HTTP_SECURE_LINK HTTP_SLICE HTTP_SSL \
		HTTP_STATUS HTTP_SUB HTTPV2 HTTPV3 MAIL MAIL_SSL STREAM \
		STREAM_REALIP STREAM_SSL STREAM_SSL_PREREAD THREADS WWW

LIB_DEPENDS+=	libpcre2-8.so:devel/pcre2

OPTIONS_RADIO+=		GSSAPI
OPTIONS_RADIO_GSSAPI=	GSSAPI_HEIMDAL GSSAPI_MIT
GSSAPI_HEIMDAL_USES=	gssapi:heimdal,flags
GSSAPI_MIT_USES=	gssapi:mit

OPTIONS_SUB=	yes

.include "Makefile.options.desc"

.for opt in ${OPTIONS_GROUP_MAILGRP:NMAIL}
${opt}_IMPLIES=	MAIL
.endfor

.for opt in ${OPTIONS_GROUP_HTTPGRP:NHTTP} WWW
${opt}_IMPLIES=	HTTP
.endfor

.for opt in ${OPTIONS_GROUP_STREAMGRP:NSTREAM}
${opt}_IMPLIES=	STREAM
.endfor

GSSAPI_HEIMDAL_IMPLIES=	HTTP_AUTH_KRB5
GSSAPI_MIT_IMPLIES=	HTTP_AUTH_KRB5

# If the target is makesum, make sure that every distfile is fetched.
.if ${.TARGETS:Mmakesum}
OPTIONS_DEFAULT=	${OPTIONS_DEFINE} ${OPTIONS_GROUP_HTTPGRP} \
	${OPTIONS_GROUP_MAILGRP} ${OPTIONS_GROUP_STREAMGRP} \
	${OPTIONS_GROUP_THIRDPARTYGRP}
.endif

# Non-module options handling
DEBUG_CFLAGS=		-g
DEBUG_VARS=		STRIP=#do not strip if nginx with debug information
DEBUGLOG_CONFIGURE_ON=	--with-debug
DSO_CONFIGURE_ON=	--modules-path=${MODULESDIR}
DSO_VARS=		MODULESDIR=${PREFIX}/libexec/${PORTNAME}
FILE_AIO_CONFIGURE_ON=	--with-file-aio
IPV6_CONFIGURE_OFF=	--with-cc-opt="-DNGX_HAVE_INET6=0 -I ${LOCALBASE}/include ${_NJS_QJS_CFLAGS}"
THREADS_CONFIGURE_ON=	--with-threads

# Bundled modules
GOOGLE_PERFTOOLS_LIB_DEPENDS=	libprofiler.so:devel/google-perftools
GOOGLE_PERFTOOLS_CONFIGURE_ON=	--with-google_perftools_module
HTTP_CONFIGURE_ON=		--http-client-body-temp-path=${NGINX_TMPDIR}/client_body_temp \
				--http-fastcgi-temp-path=${NGINX_TMPDIR}/fastcgi_temp \
				--http-proxy-temp-path=${NGINX_TMPDIR}/proxy_temp \
				--http-scgi-temp-path=${NGINX_TMPDIR}/scgi_temp \
				--http-uwsgi-temp-path=${NGINX_TMPDIR}/uwsgi_temp \
				--http-log-path=${NGINX_ACCESSLOG}
HTTP_CONFIGURE_OFF=		--without-http
HTTP_ADDITION_CONFIGURE_ON=	--with-http_addition_module
HTTP_AUTH_REQ_CONFIGURE_ON=	--with-http_auth_request_module
HTTP_CACHE_CONFIGURE_OFF=	--without-http-cache
HTTP_DAV_CONFIGURE_ON=		--with-http_dav_module
HTTP_DEGRADATION_CONFIGURE_ON=	--with-http_degradation_module
HTTP_FLV_CONFIGURE_ON=		--with-http_flv_module
HTTP_GEOIP_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
HTTP_GEOIP_VARS=		DSO_BASEMODS+=http_geoip_module
HTTP_GZIP_STATIC_CONFIGURE_ON=	--with-http_gzip_static_module
HTTP_GUNZIP_FILTER_CONFIGURE_ON=--with-http_gunzip_module
HTTP_IMAGE_FILTER_LIB_DEPENDS=	libgd.so:graphics/gd
HTTP_IMAGE_FILTER_VARS=		DSO_BASEMODS+=http_image_filter_module
HTTP_MP4_CONFIGURE_ON=		--with-http_mp4_module
HTTP_PERL_CATEGORIES=		perl5
HTTP_PERL_USES=			perl5
# Fix build failure on clang >= 12
HTTP_PERL_CFLAGS=		-Wno-compound-token-split-by-macro
HTTP_PERL_VARS=			DSO_BASEMODS+=http_perl_module
HTTP_RANDOM_INDEX_CONFIGURE_ON=	--with-http_random_index_module
HTTP_REALIP_CONFIGURE_ON=	--with-http_realip_module
HTTP_SECURE_LINK_CONFIGURE_ON=	--with-http_secure_link_module
HTTP_SLICE_CONFIGURE_ON=	--with-http_slice_module
HTTP_SSL_CONFIGURE_ON=		--with-http_ssl_module
HTTP_SSL_USES=			ssl
HTTP_STATUS_CONFIGURE_ON=	--with-http_stub_status_module
HTTP_SUB_CONFIGURE_ON=		--with-http_sub_module
HTTP_XSLT_CONFIGURE_ON=		--with-http_xslt_module
HTTP_XSLT_LIB_DEPENDS=		libxml2.so:textproc/libxml2 \
				libxslt.so:textproc/libxslt
HTTP_XSLT_VARS=			DSO_BASEMODS+=http_xslt_module
HTTPV2_IMPLIES=			HTTP_SSL
HTTPV2_CONFIGURE_ON=		--with-http_v2_module
HTTPV3_CONFIGURE_ON=		--with-http_v3_module
HTTPV3_BORING_BUILD_DEPENDS=	${LOCALBASE}/bin/bssl:security/boringssl
HTTPV3_BORING_RUN_DEPENDS=	${LOCALBASE}/bin/bssl:security/boringssl
HTTPV3_BORING_IMPLIES=		HTTPV3
HTTPV3_BORING_PREVENTS=		HTTPV3_LSSL HTTPV3_OSSL
HTTPV3_LSSL_BUILD_DEPENDS=	${LOCALBASE}/include/tls.h:security/libressl-devel
HTTPV3_LSSL_RUN_DEPENDS=	${LOCALBASE}/include/tls.h:security/libressl-devel
HTTPV3_LSSL_IMPLIES=		HTTPV3
HTTPV3_LSSL_PREVENTS=		HTTPV3_BORING HTTPV3_OSSL
HTTPV3_OSSL_BUILD_DEPENDS=	${LOCALBASE}/include/openssl/quic.h:security/openssl
HTTPV3_OSSL_RUN_DEPENDS=	${LOCALBASE}/include/openssl/quic.h:security/openssl
HTTPV3_OSSL_IMPLIES=		HTTPV3
HTTPV3_OSSL_PREVENTS=		HTTPV3_BORING HTTPV3_LSSL
MAIL_VARS=			DSO_BASEMODS+=mail
MAIL_IMAP_CONFIGURE_OFF=	--without-mail_imap_module
MAIL_POP3_CONFIGURE_OFF=	--without-mail_pop3_module
MAIL_SMTP_CONFIGURE_OFF=	--without-mail_smtp_module
MAIL_SSL_USES=			ssl
MAIL_SSL_CONFIGURE_ON=		--with-mail_ssl_module
STREAM_VARS=			DSO_BASEMODS+=stream
STREAM_CONFIGURE_ON=		--with-stream
STREAM_GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
STREAM_GEOIP_VARS=		DSO_BASEMODS+=stream_geoip_module
STREAM_REALIP_CONFIGURE_ON=	--with-stream_realip_module
STREAM_SSL_USES=		ssl
STREAM_SSL_CONFIGURE_ON=	--with-stream_ssl_module
STREAM_SSL_PREREAD_CONFIGURE_ON=--with-stream_ssl_preread_module

### External modules
.include "Makefile.extmod"

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDSO}
_addbasemod=	=dynamic
_addextmod=	add-dynamic-module
.else
_addextmod=	add-module
.endif

.for mod in ${DSO_BASEMODS}
CONFIGURE_ARGS+=	--with-${mod}${_addbasemod}
.endfor

# Some modules depend on other being there before, for example, devel_kit needs
# to be there before a few other.
.for mod in ${FIRST_DSO_EXTMODS}
CONFIGURE_ARGS+=	--${_addextmod}=${WRKSRC_${mod}}${${mod:tu}_SUBDIR}
.endfor

.for mod in ${DSO_EXTMODS}
CONFIGURE_ARGS+=	--${_addextmod}=${WRKSRC_${mod}}${${mod:tu}_SUBDIR}
.endfor
# For non-GitHub hosted modules
.for moddir in ${DSO_EXTDIRS}
CONFIGURE_ARGS+=	--${_addextmod}=${WRKDIR}/${moddir}
.endfor

.if empty(PORT_OPTIONS:MHTTP) && empty(PORT_OPTIONS:MMAIL)
IGNORE=		requires at least HTTP or MAIL to \
		be defined.  Please do 'make config' again
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_KRB5} && (empty(PORT_OPTIONS:MGSSAPI_HEIMDAL) && empty(PORT_OPTIONS:MGSSAPI_MIT))
IGNORE=		required at least GSSAPI_HEIMDAL or \
		GSSAPI_MIT to be defined. Please do \
		'make config' again
.endif

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 191
CFLAGS+=	-Wno-error=cast-function-type-mismatch
.endif

.if ${PORT_OPTIONS:MPASSENGER} && empty(PORT_OPTIONS:MDEBUG)
CONFIGURE_ENV+=	OPTIMIZE="yes"
CFLAGS+=	-DNDEBUG
.endif

.if ${PORT_OPTIONS:MPASSENGER}
CONFIGURE_ENV+=	EXTRA_PRE_CXXFLAGS="-std=c++14"
.endif

.if ${PORT_OPTIONS:MNJS} && empty(PORT_OPTIONS:MNJS_XML)
CONFIGURE_ENV+=		NJS_LIBXSLT=NO
NJS_CONFIGURE_ARGS=	--no-libxml2
.endif

.if ${PORT_OPTIONS:MNJS_QJS}
_NJS_QJS_CFLAGS=		-I ${LOCALBASE}/include/quickjs
NJS_CONFIGURE_ARGS+=	--cc-opt="${CFLAGS} -I${LOCALBASE}/include/quickjs" \
			--ld-opt="-L${LOCALBASE}/lib" \
			--with-quickjs
.endif

pre-everything::
	@${ECHO_MSG}
.if ${PORT_OPTIONS:MHTTP_NOTICE}
	@${ECHO_MSG} "${PORTNAME} can return a fixed body itself.  HTTP_NOTICE will be"
	@${ECHO_MSG} "removed after 2026-12-31: replace notice with return 200 and the"
	@${ECHO_MSG} "text, and notice_type with default_type.  Unlike a static file,"
	@${ECHO_MSG} "return answers every request method."
.endif
.if ${PORT_OPTIONS:MHTTP_UPSTREAM_FAIR}
	@${ECHO_MSG} "${PORTNAME} can balance by least connections itself.  HTTP_UPSTREAM_FAIR"
	@${ECHO_MSG} "will be removed after 2026-12-31: replace fair; with least_conn;, and"
	@${ECHO_MSG} "fair weight_mode=peak; with least_conn; plus a max_conns= parameter on"
	@${ECHO_MSG} "each server."
	@${ECHO_MSG} "Enable http_ssl module to build upstream_fair with SSL support"
.endif
.if ${PORT_OPTIONS:MHTTP_UPSTREAM_STICKY}
	@${ECHO_MSG} "${PORTNAME} has its own sticky directive since 1.29.6, and the module"
	@${ECHO_MSG} "defines the same name.  HTTP_UPSTREAM_STICKY will be removed after"
	@${ECHO_MSG} "2026-12-31: drop the option and use the built-in sticky, which takes"
	@${ECHO_MSG} "domain=, path=, expires= and samesite=."
.endif
.if ${PORT_OPTIONS:MNJS}
	@${ECHO_MSG} "The built-in njs scripting engine is EOL, deprecated since njs 1.0.0."
	@${ECHO_MSG} "Upstream recommends the QuickJS engine instead: enable the NJS_QJS"
	@${ECHO_MSG} "option and select it in nginx.conf via the js_engine qjs directive."
.endif
.if ${PORT_OPTIONS:MPASSENGER}
	@${ECHO_MSG} "This port install Passenger module only"
.endif
	@${ECHO_MSG}

post-extract-NAXSI-on:
	@${RMDIR} ${WRKSRC_naxsi}/naxsi_src/libinjection
	@${LN} -s ${WRKSRC_libinjection} ${WRKSRC_naxsi}/naxsi_src/libinjection

post-patch:
	@${REINPLACE_CMD} 's!%%HTTP_PORT%%!${HTTP_PORT}!; \
		s!%%PREFIX%%!${PREFIX}!; \
		s!%%NGINX_ERRORLOG%%!${NGINX_ERRORLOG}!' \
		${WRKSRC}/conf/nginx.conf

post-patch-BROTLI-on:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC_brotli}/filter/config

post-patch-DRIZZLE-on:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC_drizzle}/config

post-patch-FASTDFS-on:
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${PREFIX}!g;s!%%LOCALBASE%%!${LOCALBASE}!g' \
		${WRKSRC_fastdfs}/src/config

post-patch-HTTP_AUTH_KRB5-on:
	@${REINPLACE_CMD} 's!%%GSSAPILIBS%%!${GSSAPILIBS}!g; \
		s!%%GSSAPIINCDIR%%!${GSSAPIINCDIR}!g; \
		s!%%GSSAPILIBDIR%%!${GSSAPILIBDIR}!g' ${WRKSRC_auth_krb5}/config

post-patch-HTTP_TARANTOOL-on:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC_nginx_tarantool}/config

pre-configure-SMALL_LIGHT-on:
	( cd ${WRKSRC_small_light} && ./setup )

pre-configure-AJP-on:
	@${RM} -rf ${WRKSRC_ajp}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-ajp ${WRKSRC_ajp}
	@${CHMOD} -R u+w ${WRKSRC_ajp}

pre-configure-ARRAYVAR-on:
	@${RM} -rf ${WRKSRC_arrayvar}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-array-var ${WRKSRC_arrayvar}
	@${CHMOD} -R u+w ${WRKSRC_arrayvar}

pre-configure-AWS_AUTH-on:
	@${RM} -rf ${WRKSRC_aws_auth}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-aws-auth ${WRKSRC_aws_auth}
	@${CHMOD} -R u+w ${WRKSRC_aws_auth}

pre-configure-CACHE_PURGE-on:
	@${RM} -rf ${WRKSRC_cache_purge}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-cache-purge ${WRKSRC_cache_purge}
	@${CHMOD} -R u+w ${WRKSRC_cache_purge}

pre-configure-CERT_EXPIRY-on:
	@${RM} -rf ${WRKSRC_cert_expiry}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-cert-expiry ${WRKSRC_cert_expiry}
	@${CHMOD} -R u+w ${WRKSRC_cert_expiry}

pre-configure-DEVEL_KIT-on:
	@${RM} -rf ${WRKSRC_devel_kit}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-ndk ${WRKSRC_devel_kit}
	@${CHMOD} -R u+w ${WRKSRC_devel_kit}

pre-configure-FIPS_CHECK-on:
	@${RM} -rf ${WRKSRC_fipscheck}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-fips-check ${WRKSRC_fipscheck}
	@${CHMOD} -R u+w ${WRKSRC_fipscheck}

pre-configure-FORMINPUT-on:
	@${RM} -rf ${WRKSRC_forminput}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-form-input ${WRKSRC_forminput}
	@${CHMOD} -R u+w ${WRKSRC_forminput}

pre-configure-GRIDFS-on:
	@${RM} -rf ${WRKSRC_gridfs}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-gridfs ${WRKSRC_gridfs}
	@${CHMOD} -R u+w ${WRKSRC_gridfs}

pre-configure-HTTP_ACCEPT_LANGUAGE-on:
	@${RM} -rf ${WRKSRC_accept_language}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-accept-language ${WRKSRC_accept_language}
	@${CHMOD} -R u+w ${WRKSRC_accept_language}

pre-configure-ICONV-on:
	@${RM} -rf ${WRKSRC_iconv}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-iconv ${WRKSRC_iconv}
	@${CHMOD} -R u+w ${WRKSRC_iconv}

pre-configure-IP_ANON-on:
	@${RM} -rf ${WRKSRC_ip_anon}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-ip-anon ${WRKSRC_ip_anon}
	@${CHMOD} -R u+w ${WRKSRC_ip_anon}

pre-configure-HTTP_JSON_STATUS-on:
	@${RM} -rf ${WRKSRC_json_status}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-json-status \
		${WRKSRC_json_status}
	@${CHMOD} -R u+w ${WRKSRC_json_status}

pre-configure-MEMC-on:
	@${RM} -rf ${WRKSRC_memc}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-memc \
		${WRKSRC_memc}
	@${CHMOD} -R u+w ${WRKSRC_memc}

pre-configure-ENCRYPTSESSION-on:
	@${RM} -rf ${WRKSRC_encryptsession}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-encrypted-session \
		${WRKSRC_encryptsession}
	@${CHMOD} -R u+w ${WRKSRC_encryptsession}

pre-configure-HTTP_FANCYINDEX-on:
	@${RM} -rf ${WRKSRC_fancyindex}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-fancyindex \
		${WRKSRC_fancyindex}
	@${CHMOD} -R u+w ${WRKSRC_fancyindex}

pre-configure-HTTP_AUTH_LDAP-on:
	@${RM} -rf ${WRKSRC_http_auth_ldap}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-auth-ldap ${WRKSRC_http_auth_ldap}
	@${CHMOD} -R u+w ${WRKSRC_http_auth_ldap}

pre-configure-HTTP_AUTH_PAM-on:
	@${RM} -rf ${WRKSRC_auth_pam}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-auth-pam \
		${WRKSRC_auth_pam}
	@${CHMOD} -R u+w ${WRKSRC_auth_pam}

pre-configure-HTTP_GEOIP2-on:
	@${RM} -rf ${WRKSRC_geoip2}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-geoip2 \
		${WRKSRC_geoip2}
	@${CHMOD} -R u+w ${WRKSRC_geoip2}

pre-configure-LET-on:
	@${RM} -rf ${WRKSRC_let}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-let ${WRKSRC_let}
	@${CHMOD} -R u+w ${WRKSRC_let}

pre-configure-LUA-on:
	@${RM} -rf ${WRKSRC_lua}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-lua ${WRKSRC_lua}
	@${CHMOD} -R u+w ${WRKSRC_lua}

pre-configure-LUASTREAM-on:
	@${RM} -rf ${WRKSRC_luastream}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-lua-stream ${WRKSRC_luastream}
	@${CHMOD} -R u+w ${WRKSRC_luastream}

pre-configure-MODSECURITY3-on:
	@${RM} -rf ${WRKSRC_modsecurity3}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-modsecurity3 ${WRKSRC_modsecurity3}
	@${CHMOD} -R u+w ${WRKSRC_modsecurity3}

pre-configure-NJS-on:
	@${RM} -rf ${WRKSRC_njs}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-njs ${WRKSRC_njs}
	@${CHMOD} -R u+w ${WRKSRC_njs}
	@${CHMOD} u+x ${WRKSRC_njs}/configure

pre-configure-POSTGRES-on:
	@${RM} -rf ${WRKSRC_postgres}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-postgres ${WRKSRC_postgres}
	@${CHMOD} -R u+w ${WRKSRC_postgres}

pre-configure-REDIS2-on:
	@${RM} -rf ${WRKSRC_redis2}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-redis2 ${WRKSRC_redis2}
	@${CHMOD} -R u+w ${WRKSRC_redis2}

pre-configure-SFLOW-on:
	@${RM} -rf ${WRKSRC_sflow}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-sflow ${WRKSRC_sflow}
	@${CHMOD} -R u+w ${WRKSRC_sflow}
	@${REINPLACE_CMD} 's!"/etc/hsflowd.auto"!"${LOCALBASE}/etc/hsflowd.auto"!' \
		${WRKSRC_sflow}/src/ngx_http_sflow_config.h

pre-configure-SLOWFS_CACHE-on:
	@${RM} -rf ${WRKSRC_slowfs_cache}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-slowfs-cache ${WRKSRC_slowfs_cache}
	@${CHMOD} -R u+w ${WRKSRC_slowfs_cache}

pre-configure-PASSENGER-on:
	@${RM} -rf ${WRKSRC_passenger}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-passenger \
		${WRKSRC_passenger}
	@${CHMOD} -R u+w ${WRKSRC_passenger}

pre-configure-STREAM_LIMIT_REQ-on:
	@${RM} -rf ${WRKSRC_stream_limit_req}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-stream-limit-req ${WRKSRC_stream_limit_req}
	@${CHMOD} -R u+w ${WRKSRC_stream_limit_req}

pre-configure-STS-on:
	@${RM} -rf ${WRKSRC_sts}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-sts ${WRKSRC_sts}
	@${CHMOD} -R u+w ${WRKSRC_sts}

pre-configure-SYSLOG5424-on:
	@${RM} -rf ${WRKSRC_syslog5424}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-syslog5424 ${WRKSRC_syslog5424}
	@${CHMOD} -R u+w ${WRKSRC_syslog5424}

pre-configure-VOD-on:
	@${RM} -rf ${WRKSRC_vod}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-vod ${WRKSRC_vod}
	@${CHMOD} -R u+w ${WRKSRC_vod}

pre-configure-WEBSOCKIFY-on:
	@${RM} -rf ${WRKSRC_websockify}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-websockify ${WRKSRC_websockify}
	@${CHMOD} -R u+w ${WRKSRC_websockify}

pre-configure-ZSTD-on:
	@${RM} -rf ${WRKSRC_zstd}
	@${CP} -R ${LOCALBASE}/share/nginx/modules/nginx-module-zstd ${WRKSRC_zstd}
	@${CHMOD} -R u+w ${WRKSRC_zstd}

do-configure-NJS-on:
	( cd ${WRKSRC_njs} && ${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${NJS_CONFIGURE_ARGS} )

.if !target(do-install)
do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${NGINX_TMPDIR}
	${MKDIR} ${STAGEDIR}${NGINX_LOGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${STAGEDIR}${PREFIX}/sbin
.for i in koi-utf koi-win win-utf
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${STAGEDIR}${ETCDIR}
.endfor
.for i in fastcgi_params mime.types scgi_params uwsgi_params
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${STAGEDIR}${ETCDIR}/${i}-dist
.endfor

do-install-HTTP_PERL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/nginx
	${INSTALL_PROGRAM} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.so \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/lib/nginx.pm \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/

# Install dynamic modules
do-install-DSO-on:
	${MKDIR} ${STAGEDIR}${MODULESDIR}
	(cd ${WRKSRC}/objs/ && ${FIND} . -name '*.so' -maxdepth 1 -type f \
		-exec ${INSTALL_PROGRAM} {} ${STAGEDIR}${MODULESDIR} \;)

do-install-LINK-on:
	${INSTALL_DATA} ${WRKSRC_link}/src/ngx_link_func_module.h ${STAGEDIR}${PREFIX}/include

do-install-NAXSI-on:
	${INSTALL_DATA} \
	${WRKDIR}/naxsi-${NAXSI_NGINX_VER}/naxsi_rules/naxsi_core.rules \
	${STAGEDIR}${ETCDIR}
.endif

.if !target(post-install)
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles
	cd ${WRKSRC}/contrib/vim && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/vim/vimfiles
	${INSTALL_MAN} ${WRKSRC}/objs/nginx.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${CAT} ${WRKSRC}/conf/nginx.conf >> ${STAGEDIR}${ETCDIR}/nginx.conf-dist

post-install-WWW-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/nginx-dist
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/nginx-dist && \
	${TOUCH} ${STAGEDIR}${PREFIX}/www/nginx-dist/EXAMPLE_DIRECTORY-DONT_ADD_OR_TOUCH_ANYTHING)
.endif

.include <bsd.port.post.mk>
