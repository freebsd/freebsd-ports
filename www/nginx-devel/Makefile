PORTNAME?=	nginx
PORTVERSION=	${NGINX_VERSION}
.include "version.mk"
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://nginx.org/download/ \
		LOCAL/osa
PKGNAMESUFFIX?=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	osa@FreeBSD.org
COMMENT?=	Robust and small WWW server
WWW=		https://nginx.com/

LICENSE?=	BSD2CLAUSE
LICENSE_FILE?=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	nginx

PORTSCOUT=	limit:^1\.2[8-9]\.[0-9]*

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
		--with-cc-opt="-I ${LOCALBASE}/include" \
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
	HTTP_CACHE HTTP_DAV HTTP_DEGRADATION HTTP_FLV HTTP_GUNZIP_FILTER \
	HTTP_GZIP_STATIC HTTP_IMAGE_FILTER HTTP_MP4 HTTP_PERL \
	HTTP_RANDOM_INDEX HTTP_REALIP HTTP_SECURE_LINK HTTP_SLICE HTTP_SSL \
	HTTP_STATUS HTTP_SUB HTTP_XSLT HTTPV2 HTTPV3 HTTPV3_BORING HTTPV3_LSSL \
	HTTPV3_OSSL35

OPTIONS_GROUP_MAILGRP=	MAIL MAIL_IMAP MAIL_POP3 MAIL_SMTP MAIL_SSL

OPTIONS_GROUP_STREAMGRP=	STREAM STREAM_REALIP STREAM_SSL \
	STREAM_SSL_PREREAD

OPTIONS_DEFINE=		DEBUG DEBUGLOG DSO FILE_AIO IPV6 NJS OTEL THREADS WWW
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
IPV6_CONFIGURE_OFF=	--with-cc-opt="-DNGX_HAVE_INET6=0 -I ${LOCALBASE}/include"
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
HTTPV3_BORING_PREVENTS=		HTTPV3_LSSL HTTPV3_OSSL35
HTTPV3_LSSL_BUILD_DEPENDS=	${LOCALBASE}/include/tls.h:security/libressl-devel
HTTPV3_LSSL_RUN_DEPENDS=	${LOCALBASE}/include/tls.h:security/libressl-devel
HTTPV3_LSSL_IMPLIES=		HTTPV3
HTTPV3_LSSL_PREVENTS=		HTTPV3_BORING HTTPV3_OSSL35
HTTPV3_OSSL35_BUILD_DEPENDS=	${LOCALBASE}/include/openssl/quic.h:security/openssl35
HTTPV3_OSSL35_RUN_DEPENDS=	${LOCALBASE}/include/openssl/quic.h:security/openssl35
HTTPV3_OSSL35_IMPLIES=		HTTPV3
HTTPV3_OSSL35_PREVENTS=		HTTPV3_BORING HTTPV3_LSSL
MAIL_VARS=			DSO_BASEMODS+=mail
MAIL_IMAP_CONFIGURE_OFF=	--without-mail_imap_module
MAIL_POP3_CONFIGURE_OFF=	--without-mail_pop3_module
MAIL_SMTP_CONFIGURE_OFF=	--without-mail_smtp_module
MAIL_SSL_USES=			ssl
MAIL_SSL_CONFIGURE_ON=		--with-mail_ssl_module
STREAM_VARS=			DSO_BASEMODS+=stream
STREAM_CONFIGURE_ON=		--with-stream
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

.if (PORT_OPTIONS:MMODSECURITY3)
CONFIGURE_ARGS+=	--with-ld-opt="-L ${LOCALBASE}/lib -lpcre"
LIB_DEPENDS+=		libpcre.so:devel/pcre
.endif

.if ${PORT_OPTIONS:MNJS}
NJS_CONFIGURE_ARGS=	--cc-opt="${CFLAGS} -I${LOCALBASE}/include/quickjs" \
			--ld-opt="-L${LOCALBASE}/lib" \
			--with-quickjs
.endif

pre-everything::
	@${ECHO_MSG}
.if ${PORT_OPTIONS:MHTTP_UPSTREAM_FAIR}
	@${ECHO_MSG} "Enable http_ssl module to build upstream_fair with SSL support"
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

post-patch-GRIDFS-on:
	@${REINPLACE_CMD} 's!\/usr!${LOCALBASE}!g' \
		${WRKSRC_gridfs}/nginx-gridfs/config

post-patch-HTTP_AUTH_KRB5-on:
	@${REINPLACE_CMD} 's!%%GSSAPILIBS%%!${GSSAPILIBS}!g; \
		s!%%GSSAPIINCDIR%%!${GSSAPIINCDIR}!g; \
		s!%%GSSAPILIBDIR%%!${GSSAPILIBDIR}!g' ${WRKSRC_auth_krb5}/config

post-patch-HTTP_TARANTOOL-on:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC_nginx_tarantool}/config

post-patch-ICONV-on:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC_iconv}/config

post-patch-NJS_QJS-on:
	@${REINPLACE_CMD} 's!%%LOCALBASE%%!${LOCALBASE}!g' ${WRKSRC_njs}/auto/quickjs \
		${WRKSRC_njs}/nginx/config

post-patch-PASSENGER-on:
	@${REINPLACE_CMD} \
		'176,178s!true!false!' \
		${WRKSRC_PASSENGER}/build/basics.rb
	@${REINPLACE_CMD} \
		's!-I/usr/include/libev!!; \
		s!-lev!!; \
		s!-Iext/libev!!; \
		s!-I/usr/include/libeio!!; \
		s!-leio!!; \
		s!-Iext/libeio!!' \
		${WRKSRC_PASSENGER}/build/common_library.rb

post-patch-POSTGRES-on:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC_postgres}/config

post-patch-SFLOW-on:
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKSRC_sflow}/ngx_http_sflow_config.h

pre-configure-SMALL_LIGHT-on:
	( cd ${WRKSRC_small_light} && ./setup )

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
