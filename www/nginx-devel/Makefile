# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nginx
PORTVERSION=	1.5.6
CATEGORIES=	www
MASTER_SITES=	http://nginx.org/download/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	osa
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Robust and small WWW server

LICENSE=	BSD

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=	\
	DEBUG \
	DEBUGLOG \
	FILE_AIO \
	IPV6 \
	GOOGLE_PERFTOOLS \
	HTTP \
	HTTP_ADDITION \
	HTTP_AUTH_REQ \
	HTTP_CACHE \
	HTTP_DAV \
	HTTP_FLV \
	HTTP_GEOIP \
	HTTP_GZIP_STATIC \
	HTTP_GUNZIP_FILTER \
	HTTP_IMAGE_FILTER \
	HTTP_PERL \
	HTTP_RANDOM_INDEX \
	HTTP_REALIP \
	HTTP_REWRITE \
	HTTP_SECURE_LINK \
	HTTP_SSL \
	HTTP_STATUS \
	HTTP_SUB \
	HTTP_XSLT \
	MAIL \
	MAIL_IMAP \
	MAIL_POP3 \
	MAIL_SMTP \
	MAIL_SSL \
	SPDY \
	WWW \
	CACHE_PURGE \
	CTPP2 \
	ECHO \
	HEADERS_MORE \
	HTTP_ACCEPT_LANGUAGE \
	HTTP_ACCESSKEY \
	HTTP_AUTH_DIGEST \
	HTTP_AUTH_LDAP \
	HTTP_AUTH_PAM \
	HTTP_DAV_EXT \
	HTTP_EVAL \
	HTTP_FANCYINDEX \
	HTTP_MOGILEFS \
	HTTP_NOTICE \
	HTTP_PUSH \
	HTTP_PUSH_STREAM \
	HTTP_REDIS \
	HTTP_RESPONSE \
	HTTP_SUBS_FILTER \
	HTTP_UPLOAD \
	HTTP_UPLOAD_PROGRESS \
	HTTP_UPSTREAM_FAIR \
	HTTP_UPSTREAM_HASH \
	HTTP_UPSTREAM_STICKY \
	HTTP_ZIP \
	ARRAYVAR \
	DRIZZLE \
	ENCRYPTSESSION \
	FORMINPUT \
	GRIDFS \
	ICONV \
	LET \
	LUA \
	MEMC \
	MODSECURITY \
	NAXSI \
	PASSENGER \
	POSTGRES \
	RDS_CSV \
	RDS_JSON \
	REDIS2 \
	RTMP \
	SET_MISC \
	SFLOW \
	SLOWFS_CACHE \
	SRCACHE \
	SUPERVISORD \
	SYSLOG_SUPPORT \
	TCP_PROXY \
	UDPLOG \
	XRID_HEADER \
	XSS \
	VIDEO

OPTIONS_SINGLE=		VIDEO
OPTIONS_SINGLE_VIDEO=	HTTP_MP4 HTTP_MP4_H264
OPTIONS_DEFAULT=	IPV6 HTTP HTTP_CACHE HTTP_REWRITE HTTP_STATUS WWW

DEBUGLOG_DESC=			Enable debug log (--with-debug)
FILE_AIO_DESC=			Enable file aio
GOOGLE_PERFTOOLS_DESC=		Enable google perftools module
HTTP_DESC=			Enable HTTP module
HTTP_ADDITION_DESC=		Enable http_addition module
HTTP_AUTH_REQ_DESC=		Enable http_auth_request module
HTTP_CACHE_DESC=		Enable http_cache module
HTTP_DAV_DESC=			Enable http_webdav module
HTTP_FLV_DESC=			Enable http_flv module
HTTP_GEOIP_DESC=		Enable http_geoip module
HTTP_GZIP_STATIC_DESC=		Enable http_gzip_static module
HTTP_GUNZIP_FILTER_DESC=	Enable http_gunzip_filter module
HTTP_IMAGE_FILTER_DESC=		Enable http_image_filter module
HTTP_MP4_DESC=			Enable http_mp4 module
HTTP_PERL_DESC=			Enable http_perl module
HTTP_RANDOM_INDEX_DESC=		Enable http_random_index module
HTTP_REALIP_DESC=		Enable http_realip module
HTTP_REWRITE_DESC=		Enable http_rewrite module
HTTP_SECURE_LINK_DESC=		Enable http_secure_link module
HTTP_SSL_DESC=			Enable http_ssl module
HTTP_STATUS_DESC=		Enable http_stub_status module
HTTP_SUB_DESC=			Enable http_sub module
HTTP_XSLT_DESC=			Enable http_xslt module
MAIL_DESC=			Enable IMAP4/POP3/SMTP proxy module
MAIL_IMAP_DESC=			Enable IMAP4 proxy module
MAIL_POP3_DESC=			Enable POP3 proxy module
MAIL_SMTP_DESC=			Enable SMTP proxy module
MAIL_SSL_DESC=			Enable mail_ssl module
SPDY_DESC=			Enable SPDY protocol support (SSL req.)
WWW_DESC=			Enable html sample files
CACHE_PURGE_DESC=		3rd party cache_purge module
CTPP2_DESC=			3rd party CT++ module
ECHO_DESC=			3rd party echo module
HEADERS_MORE_DESC=		3rd party headers_more module
HTTP_ACCEPT_LANGUAGE_DESC=	3rd party accept_language module
HTTP_ACCESSKEY_DESC=		3rd party http_accesskey module
HTTP_AUTH_DIGEST_DESC=		3rd party http_authdigest module
HTTP_AUTH_LDAP_DESC=		3rd party http_auth_ldap module
HTTP_AUTH_PAM_DESC=		3rd party http_auth_pam module
HTTP_DAV_EXT_DESC=		3rd party webdav_ext module
HTTP_EVAL_DESC=			3rd party eval module
HTTP_FANCYINDEX_DESC=		3rd party http_fancyindex module
HTTP_MOGILEFS_DESC=		3rd party mogilefs module
HTTP_MP4_H264_DESC=		3rd party mp4/h264 module
HTTP_NOTICE_DESC=		3rd party notice module
HTTP_PUSH_DESC=			3rd party push module
HTTP_PUSH_STREAM_DESC=		3rd party push stream module
HTTP_REDIS_DESC=		3rd party http_redis module
HTTP_RESPONSE_DESC=		3rd party http_response module
HTTP_SUBS_FILTER_DESC=		3rd party subs filter module
HTTP_UPLOAD_DESC=		3rd party upload module
HTTP_UPLOAD_PROGRESS_DESC=	3rd party uploadprogress module
HTTP_UPSTREAM_FAIR_DESC=	3rd party upstream fair module
HTTP_UPSTREAM_HASH_DESC=	3rd party upstream hash module
HTTP_UPSTREAM_STICKY_DESC=	3rd party upstream sticky module
HTTP_ZIP_DESC=			3rd party http_zip module
ARRAYVAR_DESC=			3rd party array_var module
DRIZZLE_DESC=			3rd party drizzlie module
ENCRYPTSESSION_DESC=		3rd party encrypted_session module
FORMINPUT_DESC=			3rd party form_input module
GRIDFS_DESC=			3rd party gridfs module
ICONV_DESC=			3rd party iconv module
LET_DESC=			3rd party let module
LUA_DESC=			3rd party lua module
MEMC_DESC=			3rd party memc (memcached) module
MODSECURITY_DESC=		3rd party mod_security module
NAXSI_DESC=			3rd party naxsi module
PASSENGER_DESC=			3rd party passenger module
POSTGRES_DESC=			3rd party postgresql module
RDS_CSV_DESC=			3rd party rds_csv module
RDS_JSON_DESC=			3rd party rds_json module
REDIS2_DESC=			3rd party redis2 module
RTMP_DESC=			3rd party rtmp module
SET_MISC_DESC=			3rd party set_misc module
SFLOW_DESC=			3rd party sflow module
SLOWFS_CACHE_DESC=		3rd party slowfs_cache module
SRCACHE_DESC=			3rd party srcache module
SUPERVISORD_DESC=		3rd party supervisord module
SYSLOG_SUPPORT_DESC=		3rd party syslog support
TCP_PROXY_DESC=			3rd party tcp_proxy module
UDPLOG_DESC=			3rd party udplog (syslog) module
XRID_HEADER_DESC=		3rd party x-rid header module
XSS_DESC=			3rd party xss module
VIDEO_DESC=			Video module support

WANT_GNOME=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPASSENGER}
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

CONFLICTS?=	nginx-1.*
USE_RC_SUBR=	nginx
SUB_LIST+=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP} \
		NGINX_RUNDIR=${NGINX_RUNDIR} \
		NGINX_TMPDIR=${NGINX_TMPDIR}
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

.if empty(PORT_OPTIONS:MHTTP) && empty(PORT_OPTIONS:MMAIL)
IGNORE=		requires at least HTTP or MAIL to \
		be defined.  Please do 'make config' again
.endif

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-g
STRIP=		#do not strip if nginx with debug information
.endif

.if ${PORT_OPTIONS:MDEBUGLOG}
CONFIGURE_ARGS+=--with-debug
.endif

.if ${PORT_OPTIONS:MFILE_AIO}
CONFIGURE_ARGS+=--with-file-aio
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--with-ipv6
CATEGORIES+=	ipv6
.endif

.if ${PORT_OPTIONS:MGOOGLE_PERFTOOLS}
LIB_DEPENDS+=	profiler:${PORTSDIR}/devel/google-perftools
CONFIGURE_ARGS+=--with-google_perftools_module
.endif

.if ${PORT_OPTIONS:MHTTP}
CONFIGURE_ARGS+=--http-client-body-temp-path=${NGINX_TMPDIR}/client_body_temp \
		--http-fastcgi-temp-path=${NGINX_TMPDIR}/fastcgi_temp \
		--http-proxy-temp-path=${NGINX_TMPDIR}/proxy_temp \
		--http-scgi-temp-path=${NGINX_TMPDIR}/scgi_temp \
		--http-uwsgi-temp-path=${NGINX_TMPDIR}/uwsgi_temp \
		--http-log-path=${NGINX_ACCESSLOG}

.if ${PORT_OPTIONS:MHTTP_ACCEPT_LANGUAGE}
GIT_ACCEPT_LANGUAGE_VERSION=	02262ce
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/giom/nginx_accept_language_module/tarball/master/:accept_language
DISTFILES+=	giom-nginx_accept_language_module-${GIT_ACCEPT_LANGUAGE_VERSION}.tar.gz:accept_language
CONFIGURE_ARGS+=--add-module=${WRKDIR}/giom-nginx_accept_language_module-${GIT_ACCEPT_LANGUAGE_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_ACCESSKEY}
NGINX_ACCESSKEY_VERSION=	2.0.3
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:accesskey/}
MASTER_SITE_SUBDIR+=	osa/:accesskey
DISTFILES+=	nginx-accesskey-${NGINX_ACCESSKEY_VERSION}.tar.gz:accesskey
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-accesskey-${NGINX_ACCESSKEY_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_ADDITION}
CONFIGURE_ARGS+=--with-http_addition_module
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_DIGEST}
GIT_AUTH_DIGEST_VERSION=	bd1c86a
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/samizdatco/nginx-http-auth-digest/tarball/master/:auth_digest
DISTFILES+=	samizdatco-nginx-http-auth-digest-${GIT_AUTH_DIGEST_VERSION}.tar.gz:auth_digest
CONFIGURE_ARGS+=--add-module=${WRKDIR}/samizdatco-nginx-http-auth-digest-${GIT_AUTH_DIGEST_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_LDAP}
# WWW: https://github.com/kvspb/nginx-auth-ldap
GIT_HTTP_AUTH_LDAP_VERSION=  c4dc7c9153
MASTER_SITES+=	LOCAL/rm:http_auth_ldap
DISTFILES+=	http_auth_ldap-${GIT_HTTP_AUTH_LDAP_VERSION}.tar.gz:http_auth_ldap
CONFIGURE_ARGS+=--add-module=${WRKDIR}/http_auth_ldap-${GIT_HTTP_AUTH_LDAP_VERSION}
USE_OPENLDAP=	yes
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_PAM}
NGINX_AUTH_PAM_VERSION=	1.2
MASTER_SITES+=	http://web.iti.upv.es/~sto/nginx/:auth_pam
DISTFILES+=	ngx_http_auth_pam_module-${NGINX_AUTH_PAM_VERSION}.tar.gz:auth_pam
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_auth_pam_module-${NGINX_AUTH_PAM_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_REQ}
CONFIGURE_ARGS+=--with-http_auth_request_module
.endif

.if empty(PORT_OPTIONS:MHTTP_CACHE)
CONFIGURE_ARGS+=--without-http-cache
.endif

.if ${PORT_OPTIONS:MCACHE_PURGE}
NGINX_CACHE_PURGE_VERSION=	2.1
MASTER_SITES+=	http://labs.frickle.com/files/:cache_purge
DISTFILES+=	ngx_cache_purge-${NGINX_CACHE_PURGE_VERSION}.tar.gz:cache_purge
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_cache_purge-${NGINX_CACHE_PURGE_VERSION}
.endif

.if ${PORT_OPTIONS:MCTPP2}
LIB_DEPENDS+=	ctpp2:${PORTSDIR}/textproc/ctpp2
NGINX_CTPP2_VERSION=	0.5
MASTER_SITES+=	http://dl.vbart.ru/ngx-ctpp/:ctpp2
DISTFILES+=	ngx_ctpp2-${NGINX_CTPP2_VERSION}.tar.gz:ctpp2
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_ctpp2-${NGINX_CTPP2_VERSION}
.endif

.if ${PORT_OPTIONS:MECHO}
NGINX_ECHO_VERSION=	0.46
GIT_ECHO_VERSION=	0-g4de92b1
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/echo-nginx-module/tarball/v${NGINX_ECHO_VERSION}/:echo
DISTFILES+=	agentzh-echo-nginx-module-v${NGINX_ECHO_VERSION}-${GIT_ECHO_VERSION}.tar.gz:echo
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-echo-nginx-module-${GIT_ECHO_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MHEADERS_MORE}
NGINX_HEADERS_MORE_VERSION=	0.22
GIT_HEADERS_MORE_VERSION=	0-g6d19a39
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/headers-more-nginx-module/tarball/v${NGINX_HEADERS_MORE_VERSION}/:headers_more
DISTFILES+=	agentzh-headers-more-nginx-module-v${NGINX_HEADERS_MORE_VERSION}-${GIT_HEADERS_MORE_VERSION}.tar.gz:headers_more
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-headers-more-nginx-module-${GIT_HEADERS_MORE_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MHTTP_DAV} || defined(USE_HTTP_DAV)
CONFIGURE_ARGS+=--with-http_dav_module
.endif

.if ${PORT_OPTIONS:MHTTP_DAV_EXT}
USE_HTTP_DAV=	yes
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2
NGINX_DAV_EXT_VERSION=	0.0.2
GIT_DAV_EXT_VERSION=	0-g0e07a3e
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/arut/nginx-dav-ext-module/tarball/v${NGINX_DAV_EXT_VERSION}/:dav_ext
DISTFILES+=	arut-nginx-dav-ext-module-v${NGINX_DAV_EXT_VERSION}-${GIT_DAV_EXT_VERSION}.tar.gz:dav_ext
CONFIGURE_ARGS+=--add-module=${WRKDIR}/arut-nginx-dav-ext-module-${GIT_DAV_EXT_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MHTTP_EVAL}
NGINX_EVAL_VERSION=	1.0.3
GIT_EVAL_VERSION=	0-g125fa2e
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/vkholodkov/nginx-eval-module/tarball/${NGINX_EVAL_VERSION}/:eval
DISTFILES+=	vkholodkov-nginx-eval-module-${NGINX_EVAL_VERSION}-${GIT_EVAL_VERSION}.tar.gz:eval
CONFIGURE_ARGS+=--add-module=${WRKDIR}/vkholodkov-nginx-eval-module-${GIT_EVAL_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MHTTP_FANCYINDEX}
NGINX_FANCYINDEX_VERSION=	0.3.1
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:fancyindex/}
MASTER_SITE_SUBDIR+=	osa/:fancyindex
DISTFILES+=	ngx-fancyindex-${NGINX_FANCYINDEX_VERSION}.tar.gz:fancyindex
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx-fancyindex-${NGINX_FANCYINDEX_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_FLV}
CONFIGURE_ARGS+=--with-http_flv_module
.endif

.if ${PORT_OPTIONS:MHTTP_GEOIP}
CONFIGURE_ARGS+=--with-http_geoip_module
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
.endif

.if ${PORT_OPTIONS:MHTTP_GZIP_STATIC}
CONFIGURE_ARGS+=--with-http_gzip_static_module
.endif

.if ${PORT_OPTIONS:MHTTP_GUNZIP_FILTER}
CONFIGURE_ARGS+=--with-http_gunzip_module
.endif

.if ${PORT_OPTIONS:MHTTP_IMAGE_FILTER}
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS+=--with-http_image_filter_module
.endif

.if ${PORT_OPTIONS:MHTTP_MP4}
CONFIGURE_ARGS+=--with-http_mp4_module
.endif

.if ${PORT_OPTIONS:MHTTP_MOGILEFS}
NGINX_MOGILEFS_VERSION=	1.0.4
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:mogilefs
DISTFILES+=	nginx_mogilefs_module-${NGINX_MOGILEFS_VERSION}.tar.gz:mogilefs
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mogilefs_module-${NGINX_MOGILEFS_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_MP4_H264}
NGINX_H264_VERSION=	2.2.7
MASTER_SITES+=	http://h264.code-shop.com/download/:mp4streaming
DISTFILES+=	nginx_mod_h264_streaming-${NGINX_H264_VERSION}.tar.gz:mp4streaming
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mod_h264_streaming-${NGINX_H264_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_streaming_module.c
.endif

.if ${PORT_OPTIONS:MHTTP_NOTICE}
GIT_NOTICE_VERSION=	0-g3c95966
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/kr/nginx-notice/tarball/master/:notice
DISTFILES+=	kr-nginx-notice-${GIT_NOTICE_VERSION}.tar.gz:notice
CONFIGURE_ARGS+=--add-module=${WRKDIR}/kr-nginx-notice-${GIT_NOTICE_VERSION:S/^0-g//}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_notice_module.c
.endif

.if ${PORT_OPTIONS:MHTTP_PERL}
CATEGORIES+=	perl5
CONFIGURE_ARGS+=--with-http_perl_module
USES+=		perl5
.endif

.if ${PORT_OPTIONS:MHTTP_PUSH}
NGINX_PUSH_VERSION=	0.692
MASTER_SITES+=	http://pushmodule.slact.net/downloads/:push
DISTFILES+=	nginx_http_push_module-${NGINX_PUSH_VERSION}.tar.gz:push
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_http_push_module-${NGINX_PUSH_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_PUSH_STREAM}
NGINX_PUSH_STREAM_VERSION=	0.3.5
GIT_PUSH_STREAM_VERSION=	0-gb6a8c46
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/wandenberg/nginx-push-stream-module/tarball/${NGINX_PUSH_STREAM_VERSION}/:pushstream
DISTFILES+=	wandenberg-nginx-push-stream-module-${NGINX_PUSH_STREAM_VERSION}-${GIT_PUSH_STREAM_VERSION}.tar.gz:pushstream
CONFIGURE_ARGS+=--add-module=${WRKDIR}/wandenberg-nginx-push-stream-module-${GIT_PUSH_STREAM_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MHTTP_RANDOM_INDEX}
CONFIGURE_ARGS+=--with-http_random_index_module
.endif

.if ${PORT_OPTIONS:MHTTP_REALIP}
CONFIGURE_ARGS+=--with-http_realip_module
.endif

.if ${PORT_OPTIONS:MHTTP_REDIS}
NGINX_REDIS_VERSION=	0.3.6
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:redis/}
MASTER_SITE_SUBDIR+=	osa/:redis
DISTFILES+=	ngx_http_redis-${NGINX_REDIS_VERSION}.tar.gz:redis
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_redis-${NGINX_REDIS_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_RESPONSE}
NGINX_RESPONSE_VERSION=	0.3
MASTER_SITES+=	http://catap.ru/downloads/nginx/:response
DISTFILES+=	ngx_http_response-${NGINX_RESPONSE_VERSION}.tar.gz:response
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_response-${NGINX_RESPONSE_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_SUBS_FILTER}
NGINX_HTTP_SUBS_FILTER_VERSION=	0.6.2
GIT_HTTP_SUBS_FILTER_VERSION=	0-g27a01b3
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/yaoweibin/ngx_http_substitutions_filter_module/tarball/${NGINX_HTTP_SUBS_FILTER_VERSION}/:subs_filter
DISTFILES+=	yaoweibin-ngx_http_substitutions_filter_module-${NGINX_HTTP_SUBS_FILTER_VERSION}-${GIT_HTTP_SUBS_FILTER_VERSION}.tar.gz:subs_filter
CONFIGURE_ARGS+=--add-module=${WRKDIR}/yaoweibin-ngx_http_substitutions_filter_module-${GIT_HTTP_SUBS_FILTER_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MHTTP_SECURE_LINK}
CONFIGURE_ARGS+=--with-http_secure_link_module
.endif

.if ${PORT_OPTIONS:MHTTP_STATUS}
CONFIGURE_ARGS+=--with-http_stub_status_module
.endif

.if ${PORT_OPTIONS:MHTTP_SUB}
CONFIGURE_ARGS+=--with-http_sub_module
.endif

.if ${PORT_OPTIONS:MHTTP_UPLOAD}
NGINX_UPLOAD_VERSION=	2.2.0
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:upload
DISTFILES+=	nginx_upload_module-${NGINX_UPLOAD_VERSION}.tar.gz:upload
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upload_module-${NGINX_UPLOAD_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_upload_module.c
.endif

.if ${PORT_OPTIONS:MHTTP_UPLOAD_PROGRESS}
NGINX_UPLOADPROGRESS_VERSION=	0.9.0
GIT_UPLOADPROGRESS_VERSION=	0-ga788dea
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/masterzen/nginx-upload-progress-module/tarball/v${NGINX_UPLOADPROGRESS_VERSION}/:uploadprogress
DISTFILES+=	masterzen-nginx-upload-progress-module-v${NGINX_UPLOADPROGRESS_VERSION}-${GIT_UPLOADPROGRESS_VERSION}.tar.gz:uploadprogress
CONFIGURE_ARGS+=--add-module=${WRKDIR}/masterzen-nginx-upload-progress-module-${GIT_UPLOADPROGRESS_VERSION:S/^0-g//}
.endif

.if !empty(PORT_OPTIONS:MHTTP_UPSTREAM_FAIR) || !empty(PORT_OPTIONS:MSUPERVISORD)
NGINX_UPSTREAM_FAIR_VERSION=	20090923
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:upstreamfair/}
MASTER_SITE_SUBDIR+=	osa/:upstreamfair
DISTFILES+=	nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}.tar.gz:upstreamfair
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_UPSTREAM_HASH}
NGINX_UPSTREAM_HASH_VERSION=	0.3.1
MASTER_SITES+=	http://wiki.nginx.org/images/1/11/:upstreamhash
DISTFILES+=	Nginx_upstream_hash-${NGINX_UPSTREAM_HASH_VERSION}.tar.gz:upstreamhash
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upstream_hash-${NGINX_UPSTREAM_HASH_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_upstream.h
.endif

.if ${PORT_OPTIONS:MHTTP_UPSTREAM_STICKY}
IGNORE=	HTTP_UPSTREAM_STICKY: update require
USE_HTTP_SSL=	yes
NGINX_UPSTREAM_STICKY_VERSION=	1.1
MASTER_SITES+=	http://nginx-sticky-module.googlecode.com/files/:upstreamsticky
DISTFILES+=	nginx-sticky-module-${NGINX_UPSTREAM_STICKY_VERSION}.tar.gz:upstreamsticky
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-sticky-module-${NGINX_UPSTREAM_STICKY_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_XSLT}
USE_GNOME=	libxml2 libxslt
CONFIGURE_ARGS+=--with-http_xslt_module
.endif

.if ${PORT_OPTIONS:MHTTP_ZIP}
NGINX_ZIP_VERSION=	1.1.6
MASTER_SITES+=	http://mod-zip.googlecode.com/files/:zip
DISTFILES+=	mod_zip-${NGINX_ZIP_VERSION}.tar.gz:zip
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mod_zip-${NGINX_ZIP_VERSION}
.endif

.if ${PORT_OPTIONS:MDRIZZLE}
IGNORE=	DRIZZLE: update require
LIB_DEPENDS+=	drizzle:${PORTSDIR}/databases/libdrizzle
NGINX_DRIZZLE_VERSION=	0.1.5
GIT_DRIZZLE_VERSION=	0-g943c915
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/chaoslawful/drizzle-nginx-module/tarball/v${NGINX_DRIZZLE_VERSION}/:drizzle
DISTFILES+=	chaoslawful-drizzle-nginx-module-v${NGINX_DRIZZLE_VERSION}-${GIT_DRIZZLE_VERSION}.tar.gz:drizzle
CONFIGURE_ARGS+=--add-module=${WRKDIR}/chaoslawful-drizzle-nginx-module-${GIT_DRIZZLE_VERSION:S/^0-g//}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-chaoslawful-drizzle-nginx-module-config
.endif

.if ${PORT_OPTIONS:MARRAYVAR} || ${PORT_OPTIONS:MENCRYPTSESSION} || ${PORT_OPTIONS:MFORMINPUT} || ${PORT_OPTIONS:MICONV} || ${PORT_OPTIONS:MLUA} || ${PORT_OPTIONS:MSET_MISC}
NGINX_DEVEL_KIT_VERSION=	0.2.18
GIT_DEVEL_KIT_VERSION=	0-g48bc5dd
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/simpl/ngx_devel_kit/tarball/v${NGINX_DEVEL_KIT_VERSION}/:devel_kit
DISTFILES+=	simpl-ngx_devel_kit-v${NGINX_DEVEL_KIT_VERSION}-${GIT_DEVEL_KIT_VERSION}.tar.gz:devel_kit
CONFIGURE_ARGS+=--add-module=${WRKDIR}/simpl-ngx_devel_kit-${GIT_DEVEL_KIT_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MENCRYPTSESSION}
NGINX_ENCRYPTSESSION_VERSION=	0.03
GIT_ENCRYPTSESSION_VERSION=	0-g49d741b
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/encrypted-session-nginx-module/tarball/v${NGINX_ENCRYPTSESSION_VERSION}/:encryptsession
DISTFILES+=	agentzh-encrypted-session-nginx-module-v${NGINX_ENCRYPTSESSION_VERSION}-${GIT_ENCRYPTSESSION_VERSION}.tar.gz:encryptsession
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-encrypted-session-nginx-module-${GIT_ENCRYPTSESSION_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MGRIDFS}
NGINX_GRIDFS_VERSION=	0.8
GIT_GRIDFS_VERSION=	0-gb5f8113
MONGO_C_DRIVER_VERSION=		0.3.1
GIT_MONGO_C_DRIVER_VERSION=	0-g9b4b232
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/mdirolf/nginx-gridfs/tarball/v${NGINX_GRIDFS_VERSION}/:gridfs
MASTER_SITES+=	https://github.com/mongodb/mongo-c-driver/tarball/v${MONGO_C_DRIVER_VERSION}/:mongo_c
DISTFILES+=	mdirolf-nginx-gridfs-v${NGINX_GRIDFS_VERSION}-${GIT_GRIDFS_VERSION}.tar.gz:gridfs
DISTFILES+=	mongodb-mongo-c-driver-v${MONGO_C_DRIVER_VERSION}-${GIT_MONGO_C_DRIVER_VERSION}.tar.gz:mongo_c
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mdirolf-nginx-gridfs-${GIT_GRIDFS_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MLET}
NGINX_LET_VERSION=	0.0.4
GIT_LET_VERSION=	0-ga5e1dc5
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/arut/nginx-let-module/tarball/v${NGINX_LET_VERSION}/:let
DISTFILES+=	arut-nginx-let-module-v${NGINX_LET_VERSION}-${GIT_LET_VERSION}.tar.gz:let
CONFIGURE_ARGS+=--add-module=${WRKDIR}/arut-nginx-let-module-${GIT_LET_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MLUA}
LIB_DEPENDS+=	luajit-5.1:${PORTSDIR}/lang/luajit
CONFIGURE_ENV+=	"LUAJIT_INC=${LOCALBASE}/include/luajit-2.0"
CONFIGURE_ENV+=	"LUAJIT_LIB=${LOCALBASE}/lib"
NGINX_LUA_VERSION=	0.8.6
GIT_LUA_VERSION=	0-g940429a
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/chaoslawful/lua-nginx-module/tarball/v${NGINX_LUA_VERSION}/:lua
DISTFILES+=	chaoslawful-lua-nginx-module-v${NGINX_LUA_VERSION}-${GIT_LUA_VERSION}.tar.gz:lua
CONFIGURE_ARGS+=--add-module=${WRKDIR}/chaoslawful-lua-nginx-module-${GIT_LUA_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MMEMC}
NGINX_MEMC_VERSION=	0.13rc3
GIT_MEMC_VERSION=	0-g4007350
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/memc-nginx-module/tarball/v${NGINX_MEMC_VERSION}/:memc
DISTFILES+=	agentzh-memc-nginx-module-v${NGINX_MEMC_VERSION}-${GIT_MEMC_VERSION}.tar.gz:memc
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-memc-nginx-module-${GIT_MEMC_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MMODSECURITY}
NGINX_MODSECURITY_VERSION=	2.7.5
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre \
		apr-1:${PORTSDIR}/devel/apr1
USE_APACHE=	22+
USE_GNOME=	libxml2
MASTER_SITES+=	http://www.modsecurity.org/tarball/${NGINX_MODSECURITY_VERSION}/:modsecurity
DISTFILES+=	modsecurity-apache_${NGINX_MODSECURITY_VERSION}.tar.gz:modsecurity
CONFIGURE_ARGS+=--add-module=${WRKDIR}/modsecurity-apache_${NGINX_MODSECURITY_VERSION}/nginx/modsecurity
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-nginx-modsecurity-config
.endif

.if ${PORT_OPTIONS:MNAXSI}
NGINX_NAXSI_VERSION=	0.50
MASTER_SITES+=	http://naxsi.googlecode.com/files/:naxsi
DISTFILES+=	naxsi-core-${NGINX_NAXSI_VERSION}.tgz:naxsi
CONFIGURE_ARGS+=--add-module=${WRKDIR}/naxsi-core-${NGINX_NAXSI_VERSION}/naxsi_src
.endif

.if ${PORT_OPTIONS:MHTTP_REWRITE} || defined(USE_HTTP_REWRITE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-pcre
.else
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nopcre
CONFIGURE_ARGS+=--without-http_rewrite_module \
		--without-pcre
.endif

.if ${PORT_OPTIONS:MPASSENGER}
PASSENGER_VERSION=	4.0.23
MASTER_SITES+=	http://s3.amazonaws.com/phusion-passenger/releases/:passenger
DISTFILES+=	passenger-${PASSENGER_VERSION}.tar.gz:passenger
CONFIGURE_ARGS+=--add-module=${WRKDIR}/passenger-${PASSENGER_VERSION}/ext/nginx
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-passenger-build-nginx.rb
.if empty(PORT_OPTIONS:MDEBUG)
CONFIGURE_ENV+=	OPTIMIZE="yes"
CFLAGS+=	-DNDEBUG
.endif
.endif

.if ${PORT_OPTIONS:MPOSTGRES}
IGNORE=	POSTGRES: update require
USE_PGSQL=	yes
NGINX_POSTGRES_VERSION=	0.9
MASTER_SITES+=	http://labs.frickle.com/files/:postgres
DISTFILES+=	ngx_postgres-${NGINX_POSTGRES_VERSION}.tar.gz:postgres
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_postgres-${NGINX_POSTGRES_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_postgres-config
.endif

.if ${PORT_OPTIONS:MRDS_CSV}
NGINX_RDS_CSV_VERSION=	0.05rc2
GIT_RDS_CSV_VERSION=	0-gc15d3a4
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/rds-csv-nginx-module/tarball/v${NGINX_RDS_CSV_VERSION}/:rdscsv
DISTFILES+=	agentzh-rds-csv-nginx-module-v${NGINX_RDS_CSV_VERSION}-${GIT_RDS_CSV_VERSION}.tar.gz:rdscsv
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-rds-csv-nginx-module-${GIT_RDS_CSV_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MRDS_JSON}
NGINX_RDS_JSON_VERSION=	0.12rc10
GIT_RDS_JSON_VERSION=	0-g74c21b3
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/rds-json-nginx-module/tarball/v${NGINX_RDS_JSON_VERSION}/:rdsjson
DISTFILES+=	agentzh-rds-json-nginx-module-v${NGINX_RDS_JSON_VERSION}-${GIT_RDS_JSON_VERSION}.tar.gz:rdsjson
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-rds-json-nginx-module-${GIT_RDS_JSON_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MREDIS2}
NGINX_REDIS2_VERSION=	0.10
GIT_REDIS2_VERSION=	0-g78a7622
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/redis2-nginx-module/tarball/v${NGINX_REDIS2_VERSION}/:redis2
DISTFILES+=	agentzh-redis2-nginx-module-v${NGINX_REDIS2_VERSION}-${GIT_REDIS2_VERSION}.tar.gz:redis2
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-redis2-nginx-module-${GIT_REDIS2_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MRTMP}
NGINX_RTMP_VERSION=	1.0.3
GIT_RTMP_VERSION=	0-g7749d54
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/arut/nginx-rtmp-module/tarball/v${NGINX_RTMP_VERSION}/:rtmp
DISTFILES+=	arut-rtmp-nginx-module-v${NGINX_RTMP_VERSION}-${GIT_RTMP_VERSION}.tar.gz:rtmp
CONFIGURE_ARGS+=--add-module=${WRKDIR}/arut-nginx-rtmp-module-${GIT_RTMP_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MSET_MISC}
NGINX_SET_MISC_VERSION=	0.22rc8
GIT_SET_MISC_VERSION=	0-g658c235
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/set-misc-nginx-module/tarball/v${NGINX_SET_MISC_VERSION}/:setmisc
DISTFILES+=	agentzh-set-misc-nginx-module-v${NGINX_SET_MISC_VERSION}-${GIT_SET_MISC_VERSION}.tar.gz:setmisc
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-set-misc-nginx-module-${GIT_SET_MISC_VERSION:S/^0-g//}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-agentzh-set-misc-nginx-module-config
.endif

.if ${PORT_OPTIONS:MSFLOW}
NGINX_SFLOW_VERSION=	0.9.6
MASTER_SITES+=	http://nginx-sflow-module.googlecode.com/files/:sflow
DISTFILES+=	nginx-sflow-module-${NGINX_SFLOW_VERSION}.tar.gz:sflow
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-sflow-module-${NGINX_SFLOW_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_sflow_config.c \
		${PATCHDIR}/extra-patch-ngx_http_sflow_config.h
.endif

.if ${PORT_OPTIONS:MSLOWFS_CACHE}
NGINX_SLOWFS_CACHE_VERSION=	1.10
MASTER_SITES+=	http://labs.frickle.com/files/:slowfs_cache
DISTFILES+=	ngx_slowfs_cache-${NGINX_SLOWFS_CACHE_VERSION}.tar.gz:slowfs_cache
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_slowfs_cache-${NGINX_SLOWFS_CACHE_VERSION}
.endif

.if ${PORT_OPTIONS:MSRCACHE}
NGINX_SRCACHE_VERSION=	0.22
GIT_SRCACHE_VERSION=	0-gd0c7ff5
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/srcache-nginx-module/tarball/v${NGINX_SRCACHE_VERSION}/:srcache
DISTFILES+=	agentzh-srcache-nginx-module-v${NGINX_SRCACHE_VERSION}-${GIT_SRCACHE_VERSION}.tar.gz:srcache
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-srcache-nginx-module-${GIT_SRCACHE_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MSUPERVISORD}
NGINX_SUPERVISORD_VERSION=	1.4
MASTER_SITES+=	http://labs.frickle.com/files/:supervisord
DISTFILES+=	ngx_supervisord-${NGINX_SUPERVISORD_VERSION}.tar.gz:supervisord
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_VERSION}
.endif

.if ${PORT_OPTIONS:MSYSLOG_SUPPORT}
IGNORE=	SYSLOG: update require
NGINX_SYSLOG_SUPPORT_FACILITY?=	LOG_DAEMON
CONFIGURE_ARGS+=--with-syslog --with-syslog-facility=${NGINX_SYSLOG_SUPPORT_FACILITY}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-syslog_support
.endif

.if ${PORT_OPTIONS:MTCP_PROXY}
IGNORE=	TCP_PROXY: update require
NGINX_TCP_PROXY_VERSION=	0.26
GIT_TCP_PROXY_VERSION=	0-gb83e5a6
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/yaoweibin/nginx_tcp_proxy_module/tarball/v${NGINX_TCP_PROXY_VERSION}/:tcp_proxy
DISTFILES+=	yaoweibin-nginx_tcp_proxy_module-v${NGINX_TCP_PROXY_VERSION}-${GIT_TCP_PROXY_VERSION}.tar.gz:tcp_proxy
CONFIGURE_ARGS+=--add-module=${WRKDIR}/yaoweibin-nginx_tcp_proxy_module-${GIT_TCP_PROXY_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MUDPLOG}
NGINX_UDPLOG_VERSION=	1.0.0
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:udplog
DISTFILES+=	nginx_udplog_module-${NGINX_UDPLOG_VERSION}.tar.gz:udplog
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_udplog_module-${NGINX_UDPLOG_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_udplog_module.c
.endif

.if ${PORT_OPTIONS:MXRID_HEADER}
GIT_XRID_VERSION=	0daa3cc
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/gabor/nginx-x-rid-header/tarball/master/:xrid
DISTFILES+=	gabor-nginx-x-rid-header-${GIT_XRID_VERSION}.tar.gz:xrid
CONFIGURE_ARGS+=--add-module=${WRKDIR}/gabor-nginx-x-rid-header-${GIT_XRID_VERSION}
.endif

.if ${PORT_OPTIONS:MXSS}
NGINX_XSS_VERSION=	0.03rc9
GIT_XSS_VERSION=	0-gbeddbe1
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/xss-nginx-module/tarball/v${NGINX_XSS_VERSION}/:xss
DISTFILES+=	agentzh-xss-nginx-module-v${NGINX_XSS_VERSION}-${GIT_XSS_VERSION}.tar.gz:xss
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-xss-nginx-module-${GIT_XSS_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MSPDY}
USE_OPENSSL_PORT=	yes
USE_HTTP_SSL=	yes
CONFIGURE_ARGS+=--with-http_spdy_module
.endif

.if ${PORT_OPTIONS:MWWW}
PLIST_SUB+=	WWWDATA=""
.else
PLIST_SUB+=	WWWDATA="@comment "
.endif

.else
CONFIGURE_ARGS+=--without-http
PLIST_SUB+=	WWWDATA="@comment "
.endif		# WITH_HTTP

.if ${PORT_OPTIONS:MMAIL}
CONFIGURE_ARGS+=--with-mail
.if empty(PORT_OPTIONS:MMAIL_IMAP)
CONFIGURE_ARGS+=--without-mail_imap_module
.endif
.if empty(PORT_OPTIONS:MMAIL_POP3)
CONFIGURE_ARGS+=--without-mail_pop3_module
.endif
.if empty(PORT_OPTIONS:MMAIL_SMTP)
CONFIGURE_ARGS+=--without-mail_smtp_module
.endif
.if ${PORT_OPTIONS:MMAIL_SSL}
NGINX_OPENSSL=	yes
CONFIGURE_ARGS+=--with-mail_ssl_module
.endif
.endif		# WITH_MAIL

.if ${PORT_OPTIONS:MHTTP_SSL} || defined(USE_HTTP_SSL)
NGINX_OPENSSL=	yes
CONFIGURE_ARGS+=--with-http_ssl_module
.endif

.if ${PORT_OPTIONS:MARRAYVAR}
NGINX_ARRAYVAR_VERSION=	0.03rc1
GIT_ARRAYVAR_VERSION=	0-gfed751a
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/agentzh/array-var-nginx-module/tarball/v${NGINX_ARRAYVAR_VERSION}/:arrayvar
DISTFILES+=	agentzh-array-var-nginx-module-v${NGINX_ARRAYVAR_VERSION}-${GIT_ARRAYVAR_VERSION}.tar.gz:arrayvar
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-array-var-nginx-module-${GIT_ARRAYVAR_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MFORMINPUT}
NGINX_FORMINPUT_VERSION=	0.07
GIT_FORMINPUT_VERSION=	0-g78de845
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/calio/form-input-nginx-module/tarball/v${NGINX_FORMINPUT_VERSION}/:forminput
DISTFILES+=	calio-form-input-nginx-module-v${NGINX_FORMINPUT_VERSION}-${GIT_FORMINPUT_VERSION}.tar.gz:forminput
CONFIGURE_ARGS+=--add-module=${WRKDIR}/calio-form-input-nginx-module-${GIT_FORMINPUT_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
NGINX_ICONV_VERSION=	0.10
GIT_ICONV_VERSION=	0-gb37efb5
FETCH_ARGS=	-pRr
MASTER_SITES+=	https://github.com/calio/iconv-nginx-module/tarball/v${NGINX_ICONV_VERSION}/:iconv
DISTFILES+=	calio-iconv-nginx-module-v${NGINX_ICONV_VERSION}-${GIT_ICONV_VERSION}.tar.gz:iconv
CONFIGURE_ARGS+=--add-module=${WRKDIR}/calio-iconv-nginx-module-${GIT_ICONV_VERSION:S/^0-g//}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-calio-iconv-nginx-module-config
.endif

PLIST_SUB+=	NGINX_TMPDIR=${NGINX_TMPDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

USERS?=	${WWWOWN}
GROUPS?=${WWWGRP}

.if defined(NGINX_OPENSSL)
USE_OPENSSL=	yes
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

post-extract:
.if ${PORT_OPTIONS:MGRIDFS}
	@${RMDIR} ${WRKDIR}/mdirolf-nginx-gridfs-${GIT_GRIDFS_VERSION:S/^0-g//}/mongo-c-driver/
	@${MV} \
	${WRKDIR}/mongodb-mongo-c-driver-${GIT_MONGO_C_DRIVER_VERSION:S/^0-g//}/ \
	${WRKDIR}/mdirolf-nginx-gridfs-${GIT_GRIDFS_VERSION:S/^0-g//}/mongo-c-driver/
.endif

post-patch:
	@${REINPLACE_CMD} 's!%%HTTP_PORT%%!${HTTP_PORT}!; \
		s!%%PREFIX%%!${PREFIX}!' \
		${WRKSRC}/conf/nginx.conf
.if ${PORT_OPTIONS:MHTTP_ACCESSKEY}
	@${REINPLACE_CMD} \
		's!$$HTTP_ACCESSKEY_MODULE!ngx_http_accesskey_module!' \
		${WRKDIR}/nginx-accesskey-${NGINX_ACCESSKEY_VERSION}/config
.endif
# linker error acquire if --std=c99 defined, add "static" to inline function
.if ${PORT_OPTIONS:MHTTP_ZIP}
	@${REINPLACE_CMD} \
		's!^inline!static inline!' \
		${WRKDIR}/mod_zip-${NGINX_ZIP_VERSION}/ngx_http_zip_parsers.*
.endif
.if ${PORT_OPTIONS:MDRIZZLE}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKDIR}/chaoslawful-drizzle-nginx-module-${GIT_DRIZZLE_VERSION:S/^0-g//}/config
.endif
# Respect CFLAGS by remove needless --std=c99 flag
.if ${PORT_OPTIONS:MGRIDFS}
	@${REINPLACE_CMD} \
		's!--std=c99!-DMONGO_HAVE_STDINT!' \
		${WRKDIR}/mdirolf-nginx-gridfs-${GIT_GRIDFS_VERSION:S/^0-g//}/config
.endif
.if ${PORT_OPTIONS:MPASSENGER}
	@${REINPLACE_CMD} \
		'177,179s!true!false!' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/build/basics.rb
	@${REINPLACE_CMD} \
		's!-I/usr/include/libev!!; \
		s!-lev!!; \
		s!-Iext/libev!!; \
		s!-I/usr/include/libeio!!; \
		s!-leio!!; \
		s!-Iext/libeio!!' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/build/common_library.rb
	@${REINPLACE_CMD} \
		's!-lpthread!${PTHREAD_LIBS}!g' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/lib/phusion_passenger/platform_info/cxx_portability.rb
.endif
.if ${PORT_OPTIONS:MPOSTGRES}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKDIR}/ngx_postgres-${NGINX_POSTGRES_VERSION}/config
.endif
.if ${PORT_OPTIONS:MSFLOW}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKDIR}/nginx-sflow-module-${NGINX_SFLOW_VERSION}/ngx_http_sflow_config.h
.endif
.if ${PORT_OPTIONS:MSPDY}
.if ${PORT_OPTIONS:MDRIZZLE}
	@${REINPLACE_CMD} '584d' \
		${WRKDIR}/chaoslawful-drizzle-nginx-module-${GIT_DRIZZLE_VERSION:S/^0-g//}/src/ngx_http_drizzle_util.c
.endif
.if ${PORT_OPTIONS:MLUA}
	@${REINPLACE_CMD} '437d' \
		${WRKDIR}/chaoslawful-lua-nginx-module-${GIT_LUA_VERSION:S/^0-g//}/src/ngx_http_lua_socket_tcp.c
.endif
.endif
.if ${PORT_OPTIONS:MSUPERVISORD}
	( cd ${WRKDIR}/nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION} && \
		${PATCH} -p0 < \
			${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_VERSION}/patches/ngx_http_upstream_fair_module.patch )
	( cd ${WRKSRC} && \
		${PATCH} -p0 < \
			${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_VERSION}/patches/ngx_http_upstream_init_busy-0.8.17.patch )
.endif
.if ${PORT_OPTIONS:MTCP_PROXY}
	( cd ${WRKSRC} && \
		${PATCH} -p1 < \
			${WRKDIR}/yaoweibin-nginx_tcp_proxy_module-${GIT_TCP_PROXY_VERSION:S/^0-g//}/tcp.patch )
.endif
.if ${PORT_OPTIONS:MICONV}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKDIR}/calio-iconv-nginx-module-${GIT_ICONV_VERSION:S/^0-g//}/config
.endif
.if ${PORT_OPTIONS:MMODSECURITY}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKDIR}/modsecurity-apache_${NGINX_MODSECURITY_VERSION}/nginx/modsecurity/config
.endif

pre-configure:
.if ${PORT_OPTIONS:MMODSECURITY}
	( cd ${WRKDIR}/modsecurity-apache_${NGINX_MODSECURITY_VERSION} && \
		CC="${CC}" ./${CONFIGURE_SCRIPT} --enable-standalone-module && \
		${MAKE} )
.endif

do-build:
	@cd ${WRKSRC} && ${MAKE}

do-install:
	${MKDIR} ${ETCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${PREFIX}/sbin
.for i in koi-utf koi-win win-utf
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${ETCDIR}
.endfor
.for i in fastcgi_params mime.types nginx.conf scgi_params uwsgi_params
	[ -f ${ETCDIR}/${i} ] || \
		${INSTALL_DATA} ${WRKSRC}/conf/${i} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${ETCDIR}/${i}-dist
.endfor
.if !empty(PORT_OPTIONS:MHTTP) && !empty(PORT_OPTIONS:MWWW)
	${MKDIR} ${PREFIX}/www/nginx-dist
.for i in index.html 50x.html
	${INSTALL_DATA} ${WRKSRC}/html/${i} ${PREFIX}/www/nginx-dist
.endfor
	${ECHO_CMD} "" >>${PREFIX}/www/nginx-dist/EXAMPLE_DIRECTORY-DONT_ADD_OR_TOUCH_ANYTHING
	[ -e ${PREFIX}/www/nginx ] || \
		${LN} -sf ${PREFIX}/www/nginx-dist ${PREFIX}/www/nginx
.endif

.if !empty(PORT_OPTIONS:MHTTP) && !empty(PORT_OPTIONS:MHTTP_PERL)
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx
	${INSTALL_PROGRAM} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.so \
		${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.bs \
		${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/lib/nginx.pm \
		${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/
.endif

.if ${PORT_OPTIONS:MNAXSI}
	${INSTALL_DATA} \
	${WRKDIR}/naxsi-core-${NGINX_NAXSI_VERSION}/naxsi_config/naxsi_core.rules \
	${ETCDIR}
.endif

post-install:
.if !empty(PORT_OPTIONS:MHTTP) && !empty(PORT_OPTIONS:MHTTP_PERL)
	${ECHO_CMD} ${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx/nginx.so >> ${TMPPLIST}
	${ECHO_CMD} ${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx/nginx.bs >> ${TMPPLIST}
	${ECHO_CMD} ${SITE_PERL_REL}/${PERL_ARCH}/nginx.pm >> ${TMPPLIST}
	${ECHO_CMD} @dirrm ${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx >> ${TMPPLIST}
.endif
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/objs/nginx.8 ${MAN8PREFIX}/man/man8
.endif

.if ${PORT_OPTIONS:MNAXSI}
	${ECHO_CMD} etc/nginx/naxsi_core.rules >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
