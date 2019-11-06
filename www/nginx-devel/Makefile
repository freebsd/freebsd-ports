# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nginx
PORTVERSION=	1.17.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://nginx.org/download/ \
		LOCAL/osa
PKGNAMESUFFIX?=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	osa@FreeBSD.org
COMMENT?=	Robust and small WWW server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	nginx

PORTSCOUT=	limit:^1\.15\.[0-9]*

USES=		cpe

CPE_VENDOR=	nginx
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
USE_RC_SUBR=	nginx
SUB_FILES=	pkg-message
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
		--user=${WWWOWN} --group=${WWWGRP}
ALL_TARGET=

PLIST_SUB+=	NGINX_TMPDIR=${NGINX_TMPDIR} NGINX_LOGDIR=${NGINX_LOGDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

USERS?=	${WWWOWN}
GROUPS?=${WWWGRP}

NO_OPTIONS_SORT=	yes

OPTIONS_GROUP=	MAILGRP HTTPGRP
# Modules that are part of the base nginx distribution
OPTIONS_GROUP_HTTPGRP= GOOGLE_PERFTOOLS HTTP HTTP_ADDITION HTTP_AUTH_REQ \
	HTTP_CACHE HTTP_DAV HTTP_FLV HTTP_GUNZIP_FILTER HTTP_GZIP_STATIC \
	HTTP_IMAGE_FILTER HTTP_MP4 HTTP_PERL HTTP_RANDOM_INDEX HTTP_REALIP \
	HTTP_REWRITE HTTP_SECURE_LINK HTTP_SLICE HTTP_SSL HTTP_STATUS \
	HTTP_SUB HTTP_XSLT HTTPV2 STREAM STREAM_SSL STREAM_SSL_PREREAD

# External modules (arrayvar MUST appear after devel_kit for build-dep)
OPTIONS_GROUP_HTTPGRP+=	AJP AWS_AUTH BROTLI CACHE_PURGE CLOJURE CT DEVEL_KIT \
	ARRAYVAR DRIZZLE DYNAMIC_UPSTREAM ECHO ENCRYPTSESSION FASTDFS FORMINPUT \
	GRIDFS HEADERS_MORE HTTP_ACCEPT_LANGUAGE HTTP_AUTH_DIGEST HTTP_AUTH_KRB5 \
	HTTP_AUTH_LDAP HTTP_AUTH_PAM HTTP_DAV_EXT HTTP_EVAL HTTP_FANCYINDEX \
	HTTP_FOOTER HTTP_GEOIP2 HTTP_IP2LOCATION HTTP_IP2PROXY HTTP_JSON_STATUS \
	HTTP_MOGILEFS HTTP_MP4_H264 HTTP_NOTICE HTTP_PUSH HTTP_PUSH_STREAM \
	HTTP_REDIS HTTP_RESPONSE HTTP_SLICE_AHEAD HTTP_SUBS_FILTER \
	HTTP_TARANTOOL HTTP_UPLOAD HTTP_UPLOAD_PROGRESS HTTP_UPSTREAM_CHECK \
	HTTP_UPSTREAM_FAIR HTTP_UPSTREAM_STICKY HTTP_VIDEO_THUMBEXTRACTOR \
	HTTP_ZIP ICONV LET LUA MEMC MODSECURITY MODSECURITY3 NAXSI NJS PASSENGER \
	POSTGRES RDS_CSV RDS_JSON REDIS2 RTMP SET_MISC SFLOW SHIBBOLETH \
	SLOWFS_CACHE SMALL_LIGHT SRCACHE VOD VTS XSS WEBSOCKIFY
OPTIONS_GROUP_MAILGRP=	MAIL MAIL_IMAP MAIL_POP3 MAIL_SMTP MAIL_SSL
OPTIONS_DEFINE=		DEBUG DEBUGLOG DSO FILE_AIO IPV6 THREADS WWW
OPTIONS_DEFAULT?=	DSO FILE_AIO HTTP HTTP_ADDITION HTTP_AUTH_REQ HTTP_CACHE \
		HTTP_DAV HTTP_FLV HTTP_GZIP_STATIC HTTP_GUNZIP_FILTER \
		HTTP_MP4 HTTP_RANDOM_INDEX HTTP_REALIP HTTP_SECURE_LINK \
		HTTP_SLICE HTTP_REWRITE HTTP_SSL HTTP_STATUS HTTP_SUB \
		HTTPV2 MAIL MAIL_SSL STREAM STREAM_SSL STREAM_SSL_PREREAD \
		THREADS WWW

OPTIONS_RADIO+=		GSSAPI
OPTIONS_RADIO_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
GSSAPI_BASE_USES=	gssapi
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

GSSAPI_BASE_IMPLIES=	HTTP_AUTH_KRB5
GSSAPI_HEIMDAL_IMPLIES=	HTTP_AUTH_KRB5
GSSAPI_MIT_IMPLIES=	HTTP_AUTH_KRB5

# If the target is makesum, make sure that every distfile is fetched.
.if ${.TARGETS:Mmakesum}
OPTIONS_DEFAULT=	${OPTIONS_DEFINE} ${OPTIONS_GROUP_HTTP} ${OPTIONS_GROUP_MAIL}
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
HTTP_FLV_CONFIGURE_ON=		--with-http_flv_module
HTTP_GZIP_STATIC_CONFIGURE_ON=	--with-http_gzip_static_module
HTTP_GUNZIP_FILTER_CONFIGURE_ON=--with-http_gunzip_module
HTTP_IMAGE_FILTER_LIB_DEPENDS=	libgd.so:graphics/gd
HTTP_IMAGE_FILTER_VARS=		DSO_BASEMODS+=http_image_filter_module
HTTP_MP4_CONFIGURE_ON=		--with-http_mp4_module
HTTP_PERL_CATEGORIES=		perl5
HTTP_PERL_USES=			perl5
HTTP_PERL_VARS=			DSO_BASEMODS+=http_perl_module
HTTP_RANDOM_INDEX_CONFIGURE_ON=	--with-http_random_index_module
HTTP_REALIP_CONFIGURE_ON=	--with-http_realip_module
HTTP_REWRITE_LIB_DEPENDS=	libpcre.so:devel/pcre
HTTP_REWRITE_CONFIGURE_ON=	--with-pcre
HTTP_REWRITE_CONFIGURE_OFF=	--without-http_rewrite_module
HTTP_SECURE_LINK_CONFIGURE_ON=	--with-http_secure_link_module
HTTP_SLICE_CONFIGURE_ON=	--with-http_slice_module
HTTP_SSL_CONFIGURE_ON=		--with-http_ssl_module
HTTP_SSL_USES=			ssl
HTTP_STATUS_CONFIGURE_ON=	--with-http_stub_status_module
HTTP_SUB_CONFIGURE_ON=		--with-http_sub_module
HTTP_XSLT_USE=			GNOME=libxml2,libxslt
HTTP_XSLT_VARS=			DSO_BASEMODS+=http_xslt_module
HTTPV2_IMPLIES=			HTTP_SSL
HTTPV2_CONFIGURE_ON=		--with-http_v2_module
MAIL_VARS=			DSO_BASEMODS+=mail
MAIL_IMAP_CONFIGURE_OFF=	--without-mail_imap_module
MAIL_POP3_CONFIGURE_OFF=	--without-mail_pop3_module
MAIL_SMTP_CONFIGURE_OFF=	--without-mail_smtp_module
MAIL_SSL_USES=			ssl
MAIL_SSL_CONFIGURE_ON=		--with-mail_ssl_module
STREAM_VARS=			DSO_BASEMODS+=stream
STREAM_SSL_IMPLIES=		HTTP_SSL
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

.if !${PORT_OPTIONS:MHTTP_REWRITE} && !defined(USE_HTTP_REWRITE)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nopcre
.endif

.if ${PORT_OPTIONS:MPASSENGER} && empty(PORT_OPTIONS:MDEBUG)
CONFIGURE_ENV+=	OPTIMIZE="yes"
CFLAGS+=	-DNDEBUG
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

post-extract-GRIDFS-on:
	@${RMDIR} ${WRKSRC_gridfs}/mongo-c-driver/
	@${MV} ${WRKSRC_mongo_c} ${WRKSRC_gridfs}/mongo-c-driver

post-patch:
	@${REINPLACE_CMD} 's!%%HTTP_PORT%%!${HTTP_PORT}!; \
		s!%%PREFIX%%!${PREFIX}!; \
		s!%%NGINX_ERRORLOG%%!${NGINX_ERRORLOG}!' \
		${WRKSRC}/conf/nginx.conf

post-patch-BROTLI-on:
	@${REINPLACE_CMD} -E 's!^brotli=.*!brotli="${LOCALBASE}"!' ${WRKSRC_brotli}/config

post-patch-DRIZZLE-on:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC_drizzle}/config

post-patch-FASTDFS-on:
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${PREFIX}!g;s!%%LOCALBASE%%!${LOCALBASE}!g' \
		${WRKSRC_fastdfs}/src/config

# Respect CFLAGS by remove needless --std=c99 flag
post-patch-GRIDFS-on:
	@${REINPLACE_CMD} 's!--std=c99!-DMONGO_HAVE_STDINT!' ${WRKSRC_gridfs}/config

post-patch-HTTP_AUTH_KRB5-on:
	@${REINPLACE_CMD} 's!%%GSSAPILIBS%%!${GSSAPILIBS}!g; \
		s!%%GSSAPIINCDIR%%!${GSSAPIINCDIR}!g' ${WRKSRC_auth_krb5}/config

post-patch-HTTP_TARANTOOL-on:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC_nginx_tarantool}/config

# linker error acquire if --std=c99 defined, add "static" to inline function
post-patch-HTTP_ZIP-on:
	@${REINPLACE_CMD} \
		's!^inline!static inline!' \
		${WRKSRC_mod_zip}/ngx_http_zip_parsers.*

post-patch-ICONV-on:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC_iconv}/config

post-patch-MODSECURITY-on:
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKSRC_MODSECURITY}/configure

post-patch-PASSENGER-on:
	@${REINPLACE_CMD} \
		'177,179s!true!false!' \
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

post-patch-VOD-on:
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKSRC_vod}/config

pre-configure-MODSECURITY-on:
	( cd ${WRKSRC_MODSECURITY} && \
		CC="${CC}" ${CONFIGURE_CMD} --enable-standalone-module \
		--with-pcre=${LOCALBASE} --with-yajl=${LOCALBASE} \
		--with-curl=${LOCALBASE} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} )

pre-configure-SMALL_LIGHT-on:
	( cd ${WRKSRC_small_light} && ./setup )

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

do-install-FASTDFS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fdfs
	${INSTALL_DATA} ${WRKSRC_fastdfs}/src/mod_fastdfs.conf ${STAGEDIR}${PREFIX}/etc/fdfs/mod_fastdfs.conf.sample

do-install-MODSECURITY-on:
	${INSTALL_DATA} \
	${WRKDIR}/modsecurity-${MODSECURITY_VERSION}/unicode.mapping \
	${STAGEDIR}${ETCDIR}

do-install-NAXSI-on:
	${INSTALL_DATA} \
	${WRKDIR}/naxsi-${NAXSI_NGINX_VER}/naxsi_config/naxsi_core.rules \
	${STAGEDIR}${ETCDIR}

do-install-NJS-on:
	${INSTALL_PROGRAM} ${WRKSRC_njs}/build/njs ${STAGEDIR}${PREFIX}/sbin

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles
	cd ${WRKSRC}/contrib/vim && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/vim/vimfiles
	${INSTALL_MAN} ${WRKSRC}/objs/nginx.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${CAT} ${WRKSRC}/conf/nginx.conf >> ${STAGEDIR}${ETCDIR}/nginx.conf-dist

post-install-WWW-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/nginx-dist
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/nginx-dist && \
	${TOUCH} ${STAGEDIR}${PREFIX}/www/nginx-dist/EXAMPLE_DIRECTORY-DONT_ADD_OR_TOUCH_ANYTHING)

.include <bsd.port.post.mk>
