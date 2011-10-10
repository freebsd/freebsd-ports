# New ports collection makefile for:	nginx
# Date created:				11 Oct 2004
# Whom:					osa
#
# $FreeBSD$
#

PORTNAME=	nginx
PORTVERSION=	1.0.8
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://nginx.org/download/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	osa
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Robust and small WWW server

LICENSE=	BSD

OPTIONS=	DEBUG			"Enable nginx debugging" off \
		DEBUGLOG		"Enable debug log (--with-debug)" off \
		FILE_AIO		"Enable file aio" off \
		IPV6			"Enable IPv6" on \
		GOOGLE_PERFTOOLS	"Enable google perftools module" off \
		HTTP_MODULE		"Enable HTTP module" on \
		HTTP_ADDITION_MODULE	"Enable http_addition module" off \
		HTTP_CACHE_MODULE	"Enable http_cache module" on \
		HTTP_DAV_MODULE		"Enable http_webdav module" off \
		HTTP_FLV_MODULE		"Enable http_flv module" off \
		HTTP_GEOIP_MODULE	"Enable http_geoip module" off \
		HTTP_GZIP_STATIC_MODULE "Enable http_gzip_static module" off \
		HTTP_IMAGE_FILTER_MODULE "Enable http_image_filter module" off \
		HTTP_MP4_MODULE		"Enable http_mp4 module" off \
		HTTP_PERL_MODULE	"Enable http_perl module" off \
		HTTP_RANDOM_INDEX_MODULE "Enable http_random_index module" off \
		HTTP_REALIP_MODULE	"Enable http_realip module" off \
		HTTP_REWRITE_MODULE	"Enable http_rewrite module" on \
		HTTP_SECURE_LINK_MODULE "Enable http_secure_link module" off \
		HTTP_SSL_MODULE		"Enable http_ssl module" off \
		HTTP_STATUS_MODULE	"Enable http_stub_status module" on \
		HTTP_SUB_MODULE		"Enable http_sub module" off \
		HTTP_XSLT_MODULE	"Enable http_xslt module" off \
		MAIL_MODULE		"Enable IMAP4/POP3/SMTP proxy module" off \
		MAIL_IMAP_MODULE	"Enable IMAP4 proxy module" off \
		MAIL_POP3_MODULE	"Enable POP3 proxy module" off \
		MAIL_SMTP_MODULE	"Enable SMTP proxy module" off \
		MAIL_SSL_MODULE		"Enable mail_ssl module" off \
		WWW			"Enable html sample files" on \
		CACHE_PURGE_MODULE	"3rd party cache_purge module" off \
		ECHO_MODULE		"3rd party echo module" off \
		HEADERS_MORE_MODULE	"3rd party headers_more module" off \
		HTTP_ACCEPT_LANGUAGE	"3rd party accept_language module" off \
		HTTP_ACCESSKEY_MODULE	"3rd party http_accesskey module" off \
		HTTP_AUTH_PAM_MODULE	"3rd party http_auth_pam module" off \
		HTTP_AUTH_REQ_MODULE	"3rd party http_auth_request module" off \
		HTTP_EVAL_MODULE	"3rd party eval module" off \
		HTTP_FANCYINDEX_MODULE	"3rd party http_fancyindex module" off \
		HTTP_GUNZIP_FILTER	"3rd party http_gunzip_filter module" off \
		HTTP_MOGILEFS_MODULE	"3rd party mogilefs module" off \
		HTTP_MP4_H264_MODULE	"3rd party mp4/h264 module" off \
		HTTP_NOTICE_MODULE	"3rd party notice module" off \
		HTTP_PUSH_MODULE	"3rd party push module" off \
		HTTP_REDIS_MODULE	"3rd party http_redis module" off \
		HTTP_RESPONSE_MODULE	"3rd party http_response module" off \
		HTTP_SUBS_FILTER_MODULE	"3rd party subs filter module" off \
		HTTP_UPLOAD_MODULE	"3rd party upload module" off \
		HTTP_UPLOAD_PROGRESS	"3rd party uploadprogress module" off \
		HTTP_UPSTREAM_FAIR	"3rd party upstream fair module" off \
		HTTP_UPSTREAM_HASH	"3rd party upstream hash module" off \
		HTTP_UPSTREAM_KEEPALIVE "3rd party upstream keepalive module" off \
		HTTP_ZIP_MODULE		"3rd party http_zip module" off \
		CHUNKIN_MODULE		"3rd party chunkin module" off \
		DEVEL_KIT_MODULE	"3rd party devel_kit module" off \
		GRIDFS_MODULE		"3rd party gridfs module" off \
		LUA_MODULE		"3rd party lua module" off \
		MEMC_MODULE		"3rd party memc (memcached) module" off \
		PASSENGER_MODULE	"3rd party passenger module" off \
		POSTGRES_MODULE		"3rd party postgresql module" off \
		REDIS2_MODULE		"3rd party redis2 module" off \
		SLOWFS_CACHE_MODULE	"3rd party slowfs_cache module" off \
		SRCACHE_MODULE		"3rd party srcache module" off \
		SUPERVISORD_MODULE	"3rd party supervisord module" off \
		SYSLOG_SUPPORT		"3rd party syslog support" off \
		UDPLOG_MODULE		"3rd party udplog (syslog) module" off \
		XSS_MODULE		"3rd party xss module" off

WANT_GNOME=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if defined(WITH_PASSENGER_MODULE)
CATEGORIES+=	ruby
USE_RUBY=	yes
USE_RAKE=	yes
.endif

NGINX_VARDIR?=	/var
NGINX_LOGDIR?=	${NGINX_VARDIR}/log
NGINX_RUNDIR?=	${NGINX_VARDIR}/run
NGINX_TMPDIR?=	${NGINX_VARDIR}/tmp/nginx
HTTP_PORT?=	80

NGINX_ACCESSLOG?=	${NGINX_LOGDIR}/nginx-access.log
NGINX_ERRORLOG?=	${NGINX_LOGDIR}/nginx-error.log

CONFLICTS?=	nginx-devel-1.*
USE_RC_SUBR=	nginx.sh
SUB_LIST+=	WWWOWN=${WWWOWN}
.if !defined(NO_INSTALL_MANPAGES)
MAN8=		nginx.8
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${ETCDIR} \
		--with-cc-opt="-I ${LOCALBASE}/include" \
		--with-ld-opt="-L ${LOCALBASE}/lib" \
		--conf-path=${ETCDIR}/nginx.conf \
		--sbin-path=${PREFIX}/sbin/nginx \
		--pid-path=${NGINX_RUNDIR}/nginx.pid \
		--error-log-path=${NGINX_ERRORLOG} \
		--user=${WWWOWN} --group=${WWWGRP}

.if defined(WITHOUT_HTTP_MODULE) && defined(WITHOUT_MAIL_MODULE)
IGNORE=		requires at least HTTP_MODULE or MAIL_MODULE to \
		be defined.  Please 'make config' again
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-g -DNGX_DEBUG_MALLOC
STRIP=		#do not strip if nginx with debug information
.endif

.if defined(WITH_DEBUGLOG)
CONFIGURE_ARGS+=--with-debug
.endif

.if defined(WITH_FILE_AIO)
CONFIGURE_ARGS+=--with-file-aio
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--with-ipv6
CATEGORIES+=	ipv6
.endif

.if defined(WITH_GOOGLE_PERFTOOLS)
LIB_DEPENDS+=	profiler.1:${PORTSDIR}/devel/google-perftools
CONFIGURE_ARGS+=--with-google_perftools_module
.endif

.if defined(WITH_HTTP_MODULE)
CONFIGURE_ARGS+=--http-client-body-temp-path=${NGINX_TMPDIR}/client_body_temp \
		--http-fastcgi-temp-path=${NGINX_TMPDIR}/fastcgi_temp \
		--http-proxy-temp-path=${NGINX_TMPDIR}/proxy_temp \
		--http-scgi-temp-path=${NGINX_TMPDIR}/scgi_temp \
		--http-uwsgi-temp-path=${NGINX_TMPDIR}/uwsgi_temp \
		--http-log-path=${NGINX_ACCESSLOG}

.if defined(WITH_HTTP_ACCEPT_LANGUAGE)
GIT_ACCEPT_LANGUAGE_MODULE_VERSION=	02262ce
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/giom/nginx_accept_language_module/tarball/master/:accept_language
DISTFILES+=	giom-nginx_accept_language_module-${GIT_ACCEPT_LANGUAGE_MODULE_VERSION}.tar.gz:accept_language
CONFIGURE_ARGS+=--add-module=${WRKDIR}/giom-nginx_accept_language_module-${GIT_ACCEPT_LANGUAGE_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_ACCESSKEY_MODULE)
NGINX_ACCESSKEY_MODULE_VERSION=	2.0.3
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:accesskey/}
MASTER_SITE_SUBDIR+=	osa/:accesskey
DISTFILES+=	nginx-accesskey-${NGINX_ACCESSKEY_MODULE_VERSION}.tar.gz:accesskey
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-accesskey-${NGINX_ACCESSKEY_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_ADDITION_MODULE)
CONFIGURE_ARGS+=--with-http_addition_module
.endif

.if defined(WITH_HTTP_AUTH_PAM_MODULE)
NGINX_AUTH_PAM_MODULE_VERSION=	1.2
MASTER_SITES+=	http://web.iti.upv.es/~sto/nginx/:auth_pam
DISTFILES+=	ngx_http_auth_pam_module-${NGINX_AUTH_PAM_MODULE_VERSION}.tar.gz:auth_pam
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_auth_pam_module-${NGINX_AUTH_PAM_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_AUTH_REQ_MODULE)
NGINX_AUTH_REQ_MODULE_VERSION=	0.2
MASTER_SITES+=	http://mdounin.ru/files/:auth_request
DISTFILES+=	ngx_http_auth_request_module-${NGINX_AUTH_REQ_MODULE_VERSION}.tar.gz:auth_request
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_auth_request_module-${NGINX_AUTH_REQ_MODULE_VERSION}
.endif

.if defined(WITHOUT_HTTP_CACHE_MODULE)
CONFIGURE_ARGS+=--without-http-cache
.endif

.if defined(WITH_CACHE_PURGE_MODULE)
NGINX_CACHE_PURGE_MODULE_VERSION=	1.4
MASTER_SITES+=	http://labs.frickle.com/files/:cache_purge
DISTFILES+=	ngx_cache_purge-${NGINX_CACHE_PURGE_MODULE_VERSION}.tar.gz:cache_purge
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_cache_purge-${NGINX_CACHE_PURGE_MODULE_VERSION}
.endif

.if defined(WITH_ECHO_MODULE)
NGINX_ECHO_MODULE_VERSION=	0.36
GIT_ECHO_MODULE_VERSION=	0-g13dd12f
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/echo-nginx-module/tarball/v${NGINX_ECHO_MODULE_VERSION}/:echo
DISTFILES+=	agentzh-echo-nginx-module-v${NGINX_ECHO_MODULE_VERSION}-${GIT_ECHO_MODULE_VERSION}.tar.gz:echo
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-echo-nginx-module-${GIT_ECHO_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITH_HEADERS_MORE_MODULE)
NGINX_HEADERS_MORE_MODULE_VERSION=	0.15
GIT_HEADERS_MORE_MODULE_VERSION=	0-g137855d
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/headers-more-nginx-module/tarball/v${NGINX_HEADERS_MORE_MODULE_VERSION}/:headers_more
DISTFILES+=	agentzh-headers-more-nginx-module-v${NGINX_HEADERS_MORE_MODULE_VERSION}-${GIT_HEADERS_MORE_MODULE_VERSION}.tar.gz:headers_more
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-headers-more-nginx-module-${GIT_HEADERS_MORE_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITH_HTTP_DAV_MODULE)
CONFIGURE_ARGS+=--with-http_dav_module
.endif

.if defined(WITH_HTTP_EVAL_MODULE)
NGINX_EVAL_MODULE_VERSION=	1.0.3
GIT_EVAL_MODULE_VERSION=	0-g125fa2e
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/vkholodkov/nginx-eval-module/tarball/${NGINX_EVAL_MODULE_VERSION}/:eval
DISTFILES+=	vkholodkov-nginx-eval-module-${NGINX_EVAL_MODULE_VERSION}-${GIT_EVAL_MODULE_VERSION}.tar.gz:eval
CONFIGURE_ARGS+=--add-module=${WRKDIR}/vkholodkov-nginx-eval-module-${GIT_EVAL_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITH_HTTP_FANCYINDEX_MODULE)
NGINX_FANCYINDEX_MODULE_VERSION=	0.3.1
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:fancyindex/}
MASTER_SITE_SUBDIR+=	osa/:fancyindex
DISTFILES+=	ngx-fancyindex-${NGINX_FANCYINDEX_MODULE_VERSION}.tar.gz:fancyindex
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx-fancyindex-${NGINX_FANCYINDEX_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_GUNZIP_FILTER)
NGINX_GUNZIP_FILTER_MODULE_VERSION=	0.4
MASTER_SITES+=	http://mdounin.ru/files/:gunzipfilter
DISTFILES+=	ngx_http_gunzip_filter_module-${NGINX_GUNZIP_FILTER_MODULE_VERSION}.tar.gz:gunzipfilter
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_gunzip_filter_module-${NGINX_GUNZIP_FILTER_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_FLV_MODULE)
CONFIGURE_ARGS+=--with-http_flv_module
.endif

.if defined(WITH_HTTP_GEOIP_MODULE)
CONFIGURE_ARGS+=--with-http_geoip_module
LIB_DEPENDS+=	GeoIP.5:${PORTSDIR}/net/GeoIP
.endif

.if defined(WITH_HTTP_GZIP_STATIC_MODULE)
CONFIGURE_ARGS+=--with-http_gzip_static_module
.endif

.if defined(WITH_HTTP_IMAGE_FILTER_MODULE)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS+=--with-http_image_filter_module
.endif

.if defined(WITH_HTTP_MP4_MODULE) && defined(WITH_HTTP_MP4_H264_MODULE)
IGNORE=	http_mp4 and third-party http_mp4_h264 modules are incompatible. Please select one
.endif

.if defined(WITH_HTTP_MP4_MODULE)
CONFIGURE_ARGS+=--with-http_mp4_module
.endif

.if defined(WITH_HTTP_MOGILEFS_MODULE)
NGINX_MOGILEFS_MODULE_VERSION=	1.0.4
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:mogilefs
DISTFILES+=	nginx_mogilefs_module-${NGINX_MOGILEFS_MODULE_VERSION}.tar.gz:mogilefs
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mogilefs_module-${NGINX_MOGILEFS_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_MP4_H264_MODULE)
NGINX_H264_MODULE_VERSION=	2.2.7
MASTER_SITES+=	http://h264.code-shop.com/download/:mp4streaming
DISTFILES+=	nginx_mod_h264_streaming-${NGINX_H264_MODULE_VERSION}.tar.gz:mp4streaming
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mod_h264_streaming-${NGINX_H264_MODULE_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_streaming_module.c
.endif

.if defined(WITH_HTTP_NOTICE_MODULE)
MASTER_SITES+=	http://xph.us/dist/nginx-notice/:notice2
DISTFILES+=	nginx-notice-2.tar.gz:notice2
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-notice-2
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_notice_module.c
.endif

.if defined(WITH_HTTP_PERL_MODULE)
CATEGORIES+=	perl5
CONFIGURE_ARGS+=--with-http_perl_module
USE_PERL5=	yes
.endif

.if defined(WITH_HTTP_PUSH_MODULE)
NGINX_PUSH_MODULE_VERSION=	0.692
MASTER_SITES+=	http://pushmodule.slact.net/downloads/:push
DISTFILES+=	nginx_http_push_module-${NGINX_PUSH_MODULE_VERSION}.tar.gz:push
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_http_push_module-${NGINX_PUSH_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_RANDOM_INDEX_MODULE)
CONFIGURE_ARGS+=--with-http_random_index_module
.endif

.if defined(WITH_HTTP_REALIP_MODULE)
CONFIGURE_ARGS+=--with-http_realip_module
.endif

.if defined(WITH_HTTP_REDIS_MODULE)
NGINX_REDIS_MODULE_VERSION=	0.3.5
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:redis/}
MASTER_SITE_SUBDIR+=	osa/:redis
DISTFILES+=	ngx_http_redis-${NGINX_REDIS_MODULE_VERSION}.tar.gz:redis
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_redis-${NGINX_REDIS_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_RESPONSE_MODULE)
NGINX_RESPONSE_MODULE_VERSION=	0.3
MASTER_SITES+=	http://catap.ru/downloads/nginx/:response
DISTFILES+=	ngx_http_response-${NGINX_RESPONSE_MODULE_VERSION}.tar.gz:response
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_response-${NGINX_RESPONSE_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_SUBS_FILTER_MODULE)
NGINX_HTTP_SUBS_FILTER_MODULE_VERSION=	0.5.2.r45
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:subs_filter/}
MASTER_SITE_SUBDIR+=	osa/:subs_filter
DISTFILES+=	ngx_http_subs_filter_module-${NGINX_HTTP_SUBS_FILTER_MODULE_VERSION}.tar.gz:subs_filter
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_subs_filter_module-${NGINX_HTTP_SUBS_FILTER_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_SECURE_LINK_MODULE)
CONFIGURE_ARGS+=--with-http_secure_link_module
.endif

.if defined(WITH_HTTP_SSL_MODULE)
NGINX_OPENSSL=	yes
CONFIGURE_ARGS+=--with-http_ssl_module
.endif

.if defined(WITH_HTTP_STATUS_MODULE)
CONFIGURE_ARGS+=--with-http_stub_status_module
.endif

.if defined(WITH_HTTP_SUB_MODULE)
CONFIGURE_ARGS+=--with-http_sub_module
.endif

.if defined(WITH_HTTP_UPLOAD_MODULE)
NGINX_UPLOAD_MODULE_VERSION=	2.2.0
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:upload
DISTFILES+=	nginx_upload_module-${NGINX_UPLOAD_MODULE_VERSION}.tar.gz:upload
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upload_module-${NGINX_UPLOAD_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_UPLOAD_PROGRESS)
NGINX_UPLOADPROGRESS_MODULE_VERSION=	0.8.2
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:uploadprogress/}
MASTER_SITE_SUBDIR+=	osa/:uploadprogress
DISTFILES+=	nginx_uploadprogress_module-${NGINX_UPLOADPROGRESS_MODULE_VERSION}.tar.gz:uploadprogress
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_uploadprogress_module-${NGINX_UPLOADPROGRESS_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_UPSTREAM_FAIR) || defined(WITH_SUPERVISORD_MODULE)
NGINX_UPSTREAM_FAIR_VERSION=	20090923
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:upstreamfair/}
MASTER_SITE_SUBDIR+=	osa/:upstreamfair
DISTFILES+=	nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}.tar.gz:upstreamfair
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}
.endif

.if defined(WITH_HTTP_UPSTREAM_HASH)
NGINX_UPSTREAM_HASH_VERSION=	0.3.1
MASTER_SITES+=	http://wiki.nginx.org/images/1/11/:upstreamhash
DISTFILES+=	Nginx_upstream_hash-${NGINX_UPSTREAM_HASH_VERSION}.tar.gz:upstreamhash
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upstream_hash-${NGINX_UPSTREAM_HASH_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_upstream.h
.endif

.if defined(WITH_HTTP_UPSTREAM_KEEPALIVE)
NGINX_UPSTREAM_KEEPALIVE_VERSION=	0.4
MASTER_SITES+=	http://mdounin.ru/files/:upstream
DISTFILES+=	ngx_http_upstream_keepalive-${NGINX_UPSTREAM_KEEPALIVE_VERSION}.tar.gz:upstream
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_upstream_keepalive-${NGINX_UPSTREAM_KEEPALIVE_VERSION}
.endif

.if defined(WITH_HTTP_XSLT_MODULE)
USE_GNOME=	libxml2 libxslt
CONFIGURE_ARGS+=--with-http_xslt_module
.endif

.if defined(WITH_HTTP_ZIP_MODULE)
NGINX_ZIP_MODULE_VERSION=	1.1.6
MASTER_SITES+=	${MASTER_SITE_GOOGLE_CODE}:zip
PROJECTHOST=	mod-zip
DISTFILES+=	mod_zip-${NGINX_ZIP_MODULE_VERSION}.tar.gz:zip
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mod_zip-${NGINX_ZIP_MODULE_VERSION}
.endif

.if defined(WITH_CHUNKIN_MODULE)
NGINX_CHUNKIN_MODULE_VERSION=	0.22rc1
GIT_CHUNKIN_MODULE_VERSION=	0-gb0a3ee3
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/chunkin-nginx-module/tarball/v${NGINX_CHUNKIN_MODULE_VERSION}/:chunkin
DISTFILES+=	agentzh-chunkin-nginx-module-v${NGINX_CHUNKIN_MODULE_VERSION}-${GIT_CHUNKIN_MODULE_VERSION}.tar.gz:chunkin
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-chunkin-nginx-module-${GIT_CHUNKIN_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITH_DEVEL_KIT_MODULE)
NGINX_DEVEL_KIT_MODULE_VERSION=	0.2.17
GIT_DEVEL_KIT_MODULE_VERSION=	0-gbc97eea
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/simpl/ngx_devel_kit/tarball/v${NGINX_DEVEL_KIT_MODULE_VERSION}/:devel_kit
DISTFILES+=	simpl-ngx_devel_kit-v${NGINX_DEVEL_KIT_MODULE_VERSION}-${GIT_DEVEL_KIT_MODULE_VERSION}.tar.gz:devel_kit
CONFIGURE_ARGS+=--add-module=${WRKDIR}/simpl-ngx_devel_kit-${GIT_DEVEL_KIT_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITH_GRIDFS_MODULE)
NGINX_GRIDFS_MODULE_VERSION=	0.8
GIT_GRIDFS_MODULE_VERSION=	0-gb5f8113
MONGO_C_DRIVER_VERSION=		0.3.1
GIT_MONGO_C_DRIVER_VERSION=	0-g9b4b232
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/mdirolf/nginx-gridfs/tarball/v${NGINX_GRIDFS_MODULE_VERSION}/:gridfs
MASTER_SITES+=	https://github.com/mongodb/mongo-c-driver/tarball/v${MONGO_C_DRIVER_VERSION}/:mongo_c
DISTFILES+=	mdirolf-nginx-gridfs-v${NGINX_GRIDFS_MODULE_VERSION}-${GIT_GRIDFS_MODULE_VERSION}.tar.gz:gridfs
DISTFILES+=	mongodb-mongo-c-driver-v${MONGO_C_DRIVER_VERSION}-${GIT_MONGO_C_DRIVER_VERSION}.tar.gz:mongo_c
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mdirolf-nginx-gridfs-${GIT_GRIDFS_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITH_LUA_MODULE)
.if !defined(WITH_DEVEL_KIT_MODULE)
BROKEN=		for lua module build devel_kit also should be defined
.endif
USE_LUA=	5.1+
NGINX_LUA_MODULE_VERSION=	0.3.0
GIT_LUA_MODULE_VERSION=	0-gdd0d4d0
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/chaoslawful/lua-nginx-module/tarball/v${NGINX_LUA_MODULE_VERSION}/:lua
DISTFILES+=	chaoslawful-lua-nginx-module-v${NGINX_LUA_MODULE_VERSION}-${GIT_LUA_MODULE_VERSION}.tar.gz:lua
CONFIGURE_ARGS+=--add-module=${WRKDIR}/chaoslawful-lua-nginx-module-${GIT_LUA_MODULE_VERSION:S/^0-g//}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-chaoslawful-lua-nginx-module::config
.endif

.if defined(WITH_MEMC_MODULE)
NGINX_MEMC_MODULE_VERSION=	0.12
GIT_MEMC_MODULE_VERSION=	0-g4f1952c
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/memc-nginx-module/tarball/v${NGINX_MEMC_MODULE_VERSION}/:memc
DISTFILES+=	agentzh-memc-nginx-module-v${NGINX_MEMC_MODULE_VERSION}-${GIT_MEMC_MODULE_VERSION}.tar.gz:memc
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-memc-nginx-module-${GIT_MEMC_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITHOUT_HTTP_REWRITE_MODULE) || defined(WITHOUT_PCRE)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nopcre
CONFIGURE_ARGS+=--without-http_rewrite_module \
		--without-pcre
.else
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-pcre
.endif

.if defined(WITH_PASSENGER_MODULE)
PASSENGER_VERSION=	3.0.9
MASTER_SITES+=	RF/passenger/:passenger
DISTFILES+=	passenger-${PASSENGER_VERSION}.tar.gz:passenger
CONFIGURE_ARGS+=--add-module=${WRKDIR}/passenger-${PASSENGER_VERSION}/ext/nginx
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-passenger::build::nginx.rb
.if !defined(WITH_DEBUG)
CONFIGURE_ENV+=	OPTIMIZE="yes"
CFLAGS+=	-DNDEBUG
.endif
.endif

.if defined(WITH_POSTGRES_MODULE)
USE_PGSQL=	yes
NGINX_POSTGRES_MODULE_VERSION=	0.8
MASTER_SITES+=	http://labs.frickle.com/files/:postgres
DISTFILES+=	ngx_postgres-${NGINX_POSTGRES_MODULE_VERSION}.tar.gz:postgres
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_postgres-${NGINX_POSTGRES_MODULE_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_postgres::config
.endif

.if defined(WITH_REDIS2_MODULE)
NGINX_REDIS2_MODULE_VERSION=	0.07
GIT_REDIS2_MODULE_VERSION=	0-g6f7fc37
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/redis2-nginx-module/tarball/v${NGINX_REDIS2_MODULE_VERSION}/:redis2
DISTFILES+=	agentzh-redis2-nginx-module-v${NGINX_REDIS2_MODULE_VERSION}-${GIT_REDIS2_MODULE_VERSION}.tar.gz:redis2
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-redis2-nginx-module-${GIT_REDIS2_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITH_SLOWFS_CACHE_MODULE)
NGINX_SLOWFS_CACHE_MODULE_VERSION=	1.6
MASTER_SITES+=	http://labs.frickle.com/files/:slowfs_cache
DISTFILES+=	ngx_slowfs_cache-${NGINX_SLOWFS_CACHE_MODULE_VERSION}.tar.gz:slowfs_cache
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_slowfs_cache-${NGINX_SLOWFS_CACHE_MODULE_VERSION}
.endif

.if defined(WITH_SRCACHE_MODULE)
NGINX_SRCACHE_MODULE_VERSION=	0.12
GIT_SRCACHE_MODULE_VERSION=	0-g362530f
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/srcache-nginx-module/tarball/v${NGINX_SRCACHE_MODULE_VERSION}/:srcache
DISTFILES+=	agentzh-srcache-nginx-module-v${NGINX_SRCACHE_MODULE_VERSION}-${GIT_SRCACHE_MODULE_VERSION}.tar.gz:srcache
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-srcache-nginx-module-${GIT_SRCACHE_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITH_SUPERVISORD_MODULE)
NGINX_SUPERVISORD_MODULE_VERSION=	1.4
MASTER_SITES+=	http://labs.frickle.com/files/:supervisord
DISTFILES+=	ngx_supervisord-${NGINX_SUPERVISORD_MODULE_VERSION}.tar.gz:supervisord
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_MODULE_VERSION}
.endif

.if defined(WITH_SYSLOG_SUPPORT)
NGINX_SYSLOG_SUPPORT_FACILITY?=	LOG_DAEMON
CONFIGURE_ARGS+=--with-syslog --with-syslog-facility=${NGINX_SYSLOG_SUPPORT_FACILITY}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-syslog_support
.endif

.if defined(WITH_UDPLOG_MODULE)
NGINX_UDPLOG_MODULE_VERSION=	1.0.0
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:udplog
DISTFILES+=	nginx_udplog_module-${NGINX_UDPLOG_MODULE_VERSION}.tar.gz:udplog
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_udplog_module-${NGINX_UDPLOG_MODULE_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_udplog_module.c
.endif

.if defined(WITH_XSS_MODULE)
NGINX_XSS_MODULE_VERSION=	0.03rc3
GIT_XSS_MODULE_VERSION=	0-g8618dd3
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/xss-nginx-module/tarball/v${NGINX_XSS_MODULE_VERSION}/:xss
DISTFILES+=	agentzh-xss-nginx-module-v${NGINX_XSS_MODULE_VERSION}-${GIT_XSS_MODULE_VERSION}.tar.gz:xss
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-xss-nginx-module-${GIT_XSS_MODULE_VERSION:S/^0-g//}
.endif

.if defined(WITH_WWW)
PLIST_SUB+=	WWWDATA=""
.else
PLIST_SUB+=	WWWDATA="@comment "
.endif

.else
CONFIGURE_ARGS+=--without-http
PLIST_SUB+=	WWWDATA="@comment "
.endif		# WITH_HTTP_MODULE

.if defined(WITH_MAIL_MODULE)
CONFIGURE_ARGS+=--with-mail
.if defined(WITHOUT_MAIL_IMAP_MODULE)
CONFIGURE_ARGS+=--without-mail_imap_module
.endif
.if defined(WITHOUT_MAIL_POP3_MODULE)
CONFIGURE_ARGS+=--without-mail_pop3_module
.endif
.if defined(WITHOUT_MAIL_SMTP_MODULE)
CONFIGURE_ARGS+=--without-mail_smtp_module
.endif
.if defined(WITH_MAIL_SSL_MODULE)
NGINX_OPENSSL=	yes
CONFIGURE_ARGS+=--with-mail_ssl_module
.endif
.endif		# WITH_MAIL_MODULE

.if defined(NGINX_OPENSSL)
USE_OPENSSL=	yes
.endif

PLIST_SUB+=	NGINX_TMPDIR=${NGINX_TMPDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG}
.if defined(WITH_HTTP_UPSTREAM_FAIR)
	@${ECHO_MSG} "Enable http_ssl module to build upstream_fair with SSL support"
.endif
.if defined(WITH_PASSENGER_MODULE)
	@${ECHO_MSG} "This port install Passenger module only"
.endif
	@${ECHO_MSG}

post-extract:
.if defined(WITH_GRIDFS_MODULE)
	@${RMDIR} ${WRKDIR}/mdirolf-nginx-gridfs-${GIT_GRIDFS_MODULE_VERSION:S/^0-g//}/mongo-c-driver/
	@${MV} \
	${WRKDIR}/mongodb-mongo-c-driver-${GIT_MONGO_C_DRIVER_VERSION:S/^0-g//}/ \
	${WRKDIR}/mdirolf-nginx-gridfs-${GIT_GRIDFS_MODULE_VERSION:S/^0-g//}/mongo-c-driver/
.endif

post-patch:
	@${REINPLACE_CMD} 's!%%HTTP_PORT%%!${HTTP_PORT}!; \
		s!%%PREFIX%%!${PREFIX}!' \
		${WRKSRC}/conf/nginx.conf
.if defined(WITH_HTTP_ACCESSKEY_MODULE)
	@${REINPLACE_CMD} \
		's!$$HTTP_ACCESSKEY_MODULE!ngx_http_accesskey_module!' \
		${WRKDIR}/nginx-accesskey-${NGINX_ACCESSKEY_MODULE_VERSION}/config
.endif
# linker error acquire if --std=c99 defined, add "static" to inline function
.if defined(WITH_HTTP_ZIP_MODULE)
	@${REINPLACE_CMD} \
		's!^inline!static inline!' \
		${WRKDIR}/mod_zip-${NGINX_ZIP_MODULE_VERSION}/ngx_http_zip_parsers.*
.endif
# Respect CFLAGS by remove needless --std=c99 flag
.if defined(WITH_GRIDFS_MODULE)
	@${REINPLACE_CMD} \
		's!--std=c99!-DMONGO_HAVE_STDINT!' \
		${WRKDIR}/mdirolf-nginx-gridfs-${GIT_GRIDFS_MODULE_VERSION:S/^0-g//}/config
.endif
.if defined(WITH_LUA_MODULE)
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${PREFIX}!' \
		${WRKDIR}/chaoslawful-lua-nginx-module-${GIT_LUA_MODULE_VERSION:S/^0-g//}/config
.endif
.if defined(WITH_PASSENGER_MODULE)
	@${REINPLACE_CMD} 's!-lpthread!${PTHREAD_LIBS}!g' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/ext/nginx/config
	@${REINPLACE_CMD} 's!-Wall!!g; \
		s!#{PlatformInfo.debugging_cflags}!${CFLAGS}!g; \
		s!-O2!!g; \
		42s!true!false!' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/build/config.rb
	@${REINPLACE_CMD} \
		's!-I/usr/include/libev!!; \
		s!-lev!!; \
		s!-Iext/libev!!' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/build/common_library.rb
	@${REINPLACE_CMD} 's!-lpthread!${PTHREAD_LIBS}!g' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/lib/phusion_passenger/platform_info/compiler.rb
.endif
.if defined(WITH_POSTGRES_MODULE)
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${PREFIX}!' \
		${WRKDIR}/ngx_postgres-${NGINX_POSTGRES_MODULE_VERSION}/config
.endif
.if defined(WITH_SUPERVISORD_MODULE)
	( cd ${WRKDIR}/nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION} && \
		${PATCH} -p0 < \
			${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_MODULE_VERSION}/patches/ngx_http_upstream_fair_module.patch )
	( cd ${WRKSRC} && \
		${PATCH} -p0 < \
			${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_MODULE_VERSION}/patches/ngx_http_upstream_init_busy-0.8.17.patch )
.endif

do-build:
	@cd ${WRKSRC} && ${MAKE}

do-install:
	${MKDIR} ${ETCDIR} ${NGINX_TMPDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${NGINX_TMPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${PREFIX}/sbin
.for i in koi-utf koi-win win-utf
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${ETCDIR}
.endfor
.for i in fastcgi_params mime.types nginx.conf scgi_params uwsgi_params
	[ -f ${ETCDIR}/${i} ] || \
		${INSTALL_DATA} ${WRKSRC}/conf/${i} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${ETCDIR}/${i}-dist
.endfor
.if defined(WITH_HTTP_MODULE) && defined(WITH_WWW)
	${MKDIR} ${PREFIX}/www/nginx-dist
.for i in index.html 50x.html
	${INSTALL_DATA} ${WRKSRC}/html/${i} ${PREFIX}/www/nginx-dist
.endfor
	${ECHO_CMD} "" >>${PREFIX}/www/nginx-dist/EXAMPLE_DIRECTORY-DONT_ADD_OR_TOUCH_ANYTHING
	[ -e ${PREFIX}/www/nginx ] || \
		${LN} -sf ${PREFIX}/www/nginx-dist ${PREFIX}/www/nginx
.endif

.if defined(WITH_HTTP_MODULE) && defined(WITH_HTTP_PERL_MODULE)
	${MKDIR} ${SITE_PERL}/${PERL_ARCH}/auto/nginx
	${INSTALL_PROGRAM} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.so \
		${SITE_PERL}/${PERL_ARCH}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.bs \
		${SITE_PERL}/${PERL_ARCH}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/lib/nginx.pm \
		${SITE_PERL}/${PERL_ARCH}/
.endif

post-install:
.if defined(WITH_HTTP_MODULE) && defined(WITH_HTTP_PERL_MODULE)
	${ECHO_CMD} ${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx/nginx.so >> ${TMPPLIST}
	${ECHO_CMD} ${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx/nginx.bs >> ${TMPPLIST}
	${ECHO_CMD} ${SITE_PERL_REL}/${PERL_ARCH}/nginx.pm >> ${TMPPLIST}
	${ECHO_CMD} @dirrm ${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx >> ${TMPPLIST}
.endif
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/objs/nginx.8 ${MAN8PREFIX}/man/man8
.endif

.include <bsd.port.post.mk>
