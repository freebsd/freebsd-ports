# Created by: Jim Ohlstein <jim@ohlste.in>
# $FreeBSD$

PORTNAME=	tengine
PORTVERSION=	2.0.3
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	GH

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Robust and small WWW server forked from nginx by Taobao

LICENSE=	BSD2CLAUSE

WANT_GNOME=	yes
USE_GNOME=	libxml2 libxslt
USE_GITHUB=	yes
GH_ACCOUNT=	alibaba
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
GH_COMMIT=	5272608

LIB_DEPENDS+=	libluajit-5.1.so:${PORTSDIR}/lang/luajit \
		libeio.so:${PORTSDIR}/devel/libeio \
		libev.so:${PORTSDIR}/devel/libev \
		libgd.so:${PORTSDIR}/graphics/gd \
		libGeoIP.so:${PORTSDIR}/net/GeoIP

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=	\
	DEBUG \
	DEBUGLOG \
	FILE_AIO \
	IPV6 \
	HTTP \
	HTTP_CACHE \
	HTTP_DAV \
	HTTP_GZIP_STATIC \
	HTTP_PERL \
	HTTP_REALIP \
	HTTP_REWRITE \
	HTTP_SSL \
	HTTP_STATUS \
	MAIL \
	MAIL_IMAP \
	MAIL_POP3 \
	MAIL_SMTP \
	MAIL_SSL \
	SPDY \
	CPP_TEST \
	TFS \
	WWW \
	CACHE_PURGE \
	ECHO \
	HEADERS_MORE \
	HTTP_ACCEPT_LANGUAGE \
	HTTP_ACCESSKEY \
	HTTP_AUTH_DIGEST \
	HTTP_AUTH_LDAP \
	HTTP_AUTH_PAM \
	HTTP_AUTH_REQ \
	HTTP_DAV_EXT \
	HTTP_EVAL \
	HTTP_FANCYINDEX \
	HTTP_MOGILEFS \
	HTTP_NOTICE \
	HTTP_PUSH \
	HTTP_PUSH_STREAM \
	HTTP_REDIS \
	HTTP_RESPONSE \
	HTTP_UPLOAD \
	HTTP_UPLOAD_PROGRESS \
	HTTP_UPSTREAM_FAIR \
	HTTP_VIDEO_THUMBEXTRACTOR \
	HTTP_ZIP \
	ARRAYVAR \
	DRIZZLE \
	ENCRYPTSESSION \
	FORMINPUT \
	GRIDFS \
	ICONV \
	LET \
	MEMC \
	MODSECURITY \
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
	TCP_PROXY \
	XRID_HEADER \
	XSS

OPTIONS_DEFAULT=	IPV6 HTTP HTTP_CACHE HTTP_REWRITE HTTP_STATUS WWW

DEBUGLOG_DESC=			Enable debug log (--with-debug)
FILE_AIO_DESC=			Enable file aio
HTTP_DESC=			Enable HTTP module
HTTP_CACHE_DESC=		Enable http_cache module
HTTP_DAV_DESC=			Enable http_webdav module
HTTP_GZIP_STATIC_DESC=		Enable http_gzip_static module
HTTP_PERL_DESC=			Enable http_perl module
HTTP_REALIP_DESC=		Enable http_realip module
HTTP_REWRITE_DESC=		Enable http_rewrite module
HTTP_SSL_DESC=			Enable http_ssl module
HTTP_STATUS_DESC=		Enable http_stub_status module
MAIL_DESC=			Enable IMAP4/POP3/SMTP proxy module
MAIL_IMAP_DESC=			Enable IMAP4 proxy module
MAIL_POP3_DESC=			Enable POP3 proxy module
MAIL_SMTP_DESC=			Enable SMTP proxy module
MAIL_SSL_DESC=			Enable mail_ssl module
SPDY_DESC=			Enable SPDY v3 protocol support (SSL req.)
CPP_TEST_DESC=			Enable CPP Test module
TFS_DESC=			Enable TaoBao File System
WWW_DESC=			Enable html sample files
CACHE_PURGE_DESC=		3rd party cache_purge module
ECHO_DESC=			3rd party echo module
HEADERS_MORE_DESC=		3rd party headers_more module
HTTP_ACCEPT_LANGUAGE_DESC=	3rd party accept_language module
HTTP_ACCESSKEY_DESC=		3rd party http_accesskey module
HTTP_AUTH_DIGEST_DESC=		3rd party http_authdigest module
HTTP_AUTH_LDAP_DESC=		3rd party http_auth_ldap module
HTTP_AUTH_PAM_DESC=		3rd party http_auth_pam module
HTTP_AUTH_REQ_DESC=		3rd party http_auth_request module
HTTP_DAV_EXT_DESC=		3rd party webdav_ext module
HTTP_EVAL_DESC=			3rd party eval module
HTTP_FANCYINDEX_DESC=		3rd party http_fancyindex module
HTTP_MOGILEFS_DESC=		3rd party mogilefs module
HTTP_NOTICE_DESC=		3rd party notice module
HTTP_PUSH_DESC=			3rd party push module
HTTP_PUSH_STREAM_DESC=		3rd party push stream module
HTTP_REDIS_DESC=		3rd party http_redis module
HTTP_RESPONSE_DESC=		3rd party http_response module
HTTP_UPLOAD_DESC=		3rd party upload module
HTTP_UPLOAD_PROGRESS_DESC=	3rd party uploadprogress module
HTTP_UPSTREAM_FAIR_DESC=	3rd party upstream fair module
HTTP_VIDEO_THUMBEXTRACTOR_DESC=	3rd party video_thumbextractor module
HTTP_ZIP_DESC=			3rd party http_zip module
ARRAYVAR_DESC=			3rd party array_var module
DRIZZLE_DESC=			3rd party drizzlie module
ENCRYPTSESSION_DESC=		3rd party encrypted_session module
FORMINPUT_DESC=			3rd party form_input module
GRIDFS_DESC=			3rd party gridfs module
ICONV_DESC=			3rd party iconv module
LET_DESC=			3rd party let module
MEMC_DESC=			3rd party memc (memcached) module
MODSECURITY_DESC=		3rd party mod_security module
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
TCP_PROXY_DESC=			3rd party tcp_proxy module
XRID_HEADER_DESC=		3rd party x-rid header module
XSS_DESC=			3rd party xss module

.include <bsd.port.options.mk>

# FreeBSD 8 and earlier are unsupported
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900500
IGNORE=	is unsupported on FreeBSD 8 and earlier
.endif

NGINX_VARDIR?=	/var
NGINX_LOGDIR?=	${NGINX_VARDIR}/log
NGINX_RUNDIR?=	${NGINX_VARDIR}/run
NGINX_TMPDIR?=	${NGINX_VARDIR}/tmp/nginx
HTTP_PORT?=	80

NGINX_ACCESSLOG?=	${NGINX_LOGDIR}/nginx-access.log
NGINX_ERRORLOG?=	${NGINX_LOGDIR}/nginx-error.log

CONFLICTS?=	nginx-devel-[0-9].* nginx-[0-9].*

USE_RC_SUBR=	nginx
SUB_LIST+=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP} \
		NGINX_RUNDIR=${NGINX_RUNDIR} \
		NGINX_TMPDIR=${NGINX_TMPDIR}

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
STRIP=		# Avoid stripping if building tengine with debug information
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

.if ${PORT_OPTIONS:MHTTP}
CONFIGURE_ARGS+=--dso-path=${ETCDIR}/modules \
		--with-http_access_module=shared \
		--with-http_addition_module=shared \
		--with-http_autoindex_module=shared \
		--with-http_browser_module=shared \
		--with-http_charset_filter_module=shared \
		--with-http_concat_module=shared \
		--with-http_empty_gif_module=shared \
		--with-http_fastcgi_module=shared \
		--with-http_flv_module=shared \
		--with-http_footer_filter_module=shared \
		--with-http_geoip_module=shared \
		--with-http_image_filter_module=shared \
		--with-http_limit_conn_module=shared \
		--with-http_limit_req_module=shared \
		--with-http_lua_module=shared \
		--with-http_map_module=shared \
		--with-http_memcached_module=shared \
		--with-http_mp4_module=shared \
		--with-http_random_index_module=shared \
		--with-http_referer_module=shared \
		--with-http_scgi_module=shared \
		--with-http_secure_link_module=shared \
		--with-http_slice_module=shared \
		--with-http_split_clients_module=shared \
		--with-http_sub_module=shared \
		--with-http_sysguard_module=shared \
		--with-http_trim_filter_module=shared \
		--with-http_upstream_ip_hash_module=shared \
		--with-http_upstream_least_conn_module=shared \
		--with-http_upstream_session_sticky_module=shared \
		--with-http_user_agent_module=shared \
		--with-http_userid_filter_module=shared \
		--with-http_uwsgi_module=shared \
		--with-http_xslt_module=shared \
		--http-client-body-temp-path=${NGINX_TMPDIR}/client_body_temp \
		--http-fastcgi-temp-path=${NGINX_TMPDIR}/fastcgi_temp \
		--http-proxy-temp-path=${NGINX_TMPDIR}/proxy_temp \
		--http-scgi-temp-path=${NGINX_TMPDIR}/scgi_temp \
		--http-uwsgi-temp-path=${NGINX_TMPDIR}/uwsgi_temp \
		--http-log-path=${NGINX_ACCESSLOG}

.if ${PORT_OPTIONS:MHTTP_ACCEPT_LANGUAGE}
GIT_ACCEPT_LANGUAGE_VERSION=	2f69842
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

.if ${PORT_OPTIONS:MHTTP_AUTH_DIGEST}
GIT_AUTH_DIGEST_VERSION=	bd1c86a
MASTER_SITES+=	https://github.com/samizdatco/nginx-http-auth-digest/tarball/master/:auth_digest
DISTFILES+=	samizdatco-nginx-http-auth-digest-${GIT_AUTH_DIGEST_VERSION}.tar.gz:auth_digest
CONFIGURE_ARGS+=--add-module=${WRKDIR}/samizdatco-nginx-http-auth-digest-${GIT_AUTH_DIGEST_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_GZIP_STATIC}
CONFIGURE_ARGS+=--with-http_gzip_static_module
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_LDAP}
# WWW: https://github.com/kvspb/nginx-auth-ldap
GIT_HTTP_AUTH_LDAP_VERSION=	c4dc7c9153
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
NGINX_AUTH_REQ_VERSION=	0.2
MASTER_SITES+=	http://mdounin.ru/files/:auth_request
DISTFILES+=	ngx_http_auth_request_module-${NGINX_AUTH_REQ_VERSION}.tar.gz:auth_request
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_auth_request_module-${NGINX_AUTH_REQ_VERSION}
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

.if ${PORT_OPTIONS:MECHO}
NGINX_ECHO_VERSION=	0.50
GIT_ECHO_VERSION=	0-gf827a4f
MASTER_SITES+=	https://github.com/agentzh/echo-nginx-module/tarball/v${NGINX_ECHO_VERSION}/:echo
DISTFILES+=	agentzh-echo-nginx-module-v${NGINX_ECHO_VERSION}-${GIT_ECHO_VERSION}.tar.gz:echo
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-echo-nginx-module-${GIT_ECHO_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MHEADERS_MORE}
NGINX_HEADERS_MORE_VERSION=	0.24
GIT_HEADERS_MORE_VERSION=	0-g7a6fd11
MASTER_SITES+=	https://github.com/agentzh/headers-more-nginx-module/tarball/v${NGINX_HEADERS_MORE_VERSION}/:headers_more
DISTFILES+=	agentzh-headers-more-nginx-module-v${NGINX_HEADERS_MORE_VERSION}-${GIT_HEADERS_MORE_VERSION}.tar.gz:headers_more
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-headers-more-nginx-module-${GIT_HEADERS_MORE_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MHTTP_DAV}
CONFIGURE_ARGS+=--with-http_dav_module
.endif

.if ${PORT_OPTIONS:MHTTP_DAV_EXT}
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2
NGINX_DAV_EXT_VERSION=	0.0.2
GIT_DAV_EXT_VERSION=	0-g0e07a3e
MASTER_SITES+=	https://github.com/arut/nginx-dav-ext-module/tarball/v${NGINX_DAV_EXT_VERSION}/:dav_ext
DISTFILES+=	arut-nginx-dav-ext-module-v${NGINX_DAV_EXT_VERSION}-${GIT_DAV_EXT_VERSION}.tar.gz:dav_ext
CONFIGURE_ARGS+=--add-module=${WRKDIR}/arut-nginx-dav-ext-module-${GIT_DAV_EXT_VERSION:S/^0-g//} \
		--with-http_dav_module
.endif

.if ${PORT_OPTIONS:MHTTP_EVAL}
NGINX_EVAL_VERSION=	1.0.3
GIT_EVAL_VERSION=	0-g125fa2e
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

.if ${PORT_OPTIONS:MHTTP_GZIP_STATIC}
CONFIGURE_ARGS+=--with-http_gzip_static_module
.endif

.if ${PORT_OPTIONS:MHTTP_MOGILEFS}
NGINX_MOGILEFS_VERSION=	1.0.4
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:mogilefs
DISTFILES+=	nginx_mogilefs_module-${NGINX_MOGILEFS_VERSION}.tar.gz:mogilefs
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mogilefs_module-${NGINX_MOGILEFS_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_NOTICE}
GIT_NOTICE_VERSION=	0-g3c95966
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
MASTER_SITES+=	https://github.com/wandenberg/nginx-push-stream-module/tarball/${NGINX_PUSH_STREAM_VERSION}/:pushstream
DISTFILES+=	wandenberg-nginx-push-stream-module-${NGINX_PUSH_STREAM_VERSION}-${GIT_PUSH_STREAM_VERSION}.tar.gz:pushstream
CONFIGURE_ARGS+=--add-module=${WRKDIR}/wandenberg-nginx-push-stream-module-${GIT_PUSH_STREAM_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MHTTP_REALIP}
CONFIGURE_ARGS+=--with-http_realip_module
.endif

.if ${PORT_OPTIONS:MHTTP_REDIS}
NGINX_REDIS_VERSION=	0.3.7
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

.if ${PORT_OPTIONS:MHTTP_STATUS}
CONFIGURE_ARGS+=--with-http_stub_status_module
.endif

.if ${PORT_OPTIONS:MHTTP_UPLOAD}
NGINX_UPLOAD_VERSION=	2.2.0
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:upload
DISTFILES+=	nginx_upload_module-${NGINX_UPLOAD_VERSION}.tar.gz:upload
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upload_module-${NGINX_UPLOAD_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_UPLOAD_PROGRESS}
NGINX_UPLOADPROGRESS_VERSION=	0.9.0
GIT_UPLOADPROGRESS_VERSION=	0-ga788dea
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

.if ${PORT_OPTIONS:MHTTP_VIDEO_THUMBEXTRACTOR}
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
			libavformat.so:${PORTSDIR}/multimedia/ffmpeg \
			libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
			libavutil.so:${PORTSDIR}/multimedia/ffmpeg \
			libswscale.so:${PORTSDIR}/multimedia/ffmpeg \
			libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick
NGINX_VIDEO_THUMBEXTRACTOR_VERSION=	0.2.0
GIT_VIDEO_THUMBEXTRACTOR_VERSION=	0-g9406457
MASTER_SITES+=	https://github.com/wandenberg/nginx-video-thumbextractor-module/tarball/${NGINX_VIDEO_THUMBEXTRACTOR_VERSION}/:videothumbextractor
DISTFILES+=	wandenberg-nginx-video-thumbextractor-module-${NGINX_VIDEO_THUMBEXTRACTOR_VERSION}-${GIT_VIDEO_THUMBEXTRACTOR_VERSION}.tar.gz:videothumbextractor
CONFIGURE_ARGS+=--add-module=${WRKDIR}/wandenberg-nginx-video-thumbextractor-module-${GIT_VIDEO_THUMBEXTRACTOR_VERSION:S/^0-g//} \
			--with-cc-opt="-I ${LOCALBASE}/include -I ${LOCALBASE}/include/ImageMagick"
.endif

.if ${PORT_OPTIONS:MHTTP_ZIP}
NGINX_ZIP_VERSION=	1.1.6
MASTER_SITES+=	http://mod-zip.googlecode.com/files/:zip
DISTFILES+=	mod_zip-${NGINX_ZIP_VERSION}.tar.gz:zip
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mod_zip-${NGINX_ZIP_VERSION}
.endif

.if ${PORT_OPTIONS:MDRIZZLE}
LIB_DEPENDS+=	libdrizzle.so:${PORTSDIR}/databases/libdrizzle
NGINX_DRIZZLE_VERSION=	0.1.6
GIT_DRIZZLE_VERSION=	0-ge6937ba
MASTER_SITES+=	https://github.com/chaoslawful/drizzle-nginx-module/tarball/v${NGINX_DRIZZLE_VERSION}/:drizzle
DISTFILES+=	chaoslawful-drizzle-nginx-module-v${NGINX_DRIZZLE_VERSION}-${GIT_DRIZZLE_VERSION}.tar.gz:drizzle
CONFIGURE_ARGS+=--add-module=${WRKDIR}/chaoslawful-drizzle-nginx-module-${GIT_DRIZZLE_VERSION:S/^0-g//}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-chaoslawful-drizzle-nginx-module-config
.endif

.if ${PORT_OPTIONS:MARRAYVAR} || ${PORT_OPTIONS:MENCRYPTSESSION} || ${PORT_OPTIONS:MFORMINPUT} || ${PORT_OPTIONS:MICONV} || ${PORT_OPTIONS:MSET_MISC}
WITH_HTTP_REWRITE=	yes
NGINX_DEVEL_KIT_VERSION=	0.2.19
GIT_DEVEL_KIT_VERSION=	0-g8dd0df5
MASTER_SITES+=	https://github.com/simpl/ngx_devel_kit/tarball/v${NGINX_DEVEL_KIT_VERSION}/:devel_kit
DISTFILES+=	simpl-ngx_devel_kit-v${NGINX_DEVEL_KIT_VERSION}-${GIT_DEVEL_KIT_VERSION}.tar.gz:devel_kit
CONFIGURE_ARGS+=--add-module=${WRKDIR}/simpl-ngx_devel_kit-${GIT_DEVEL_KIT_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MENCRYPTSESSION}
NGINX_ENCRYPTSESSION_VERSION=	0.03
GIT_ENCRYPTSESSION_VERSION=	0-g49d741b
MASTER_SITES+=	https://github.com/agentzh/encrypted-session-nginx-module/tarball/v${NGINX_ENCRYPTSESSION_VERSION}/:encryptsession
DISTFILES+=	agentzh-encrypted-session-nginx-module-v${NGINX_ENCRYPTSESSION_VERSION}-${GIT_ENCRYPTSESSION_VERSION}.tar.gz:encryptsession
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-encrypted-session-nginx-module-${GIT_ENCRYPTSESSION_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MGRIDFS}
NGINX_GRIDFS_VERSION=	0.8
GIT_GRIDFS_VERSION=	0-gb5f8113
MONGO_C_DRIVER_VERSION=		0.3.1
GIT_MONGO_C_DRIVER_VERSION=	0-g9b4b232
MASTER_SITES+=	https://github.com/mdirolf/nginx-gridfs/tarball/v${NGINX_GRIDFS_VERSION}/:gridfs
MASTER_SITES+=	https://github.com/mongodb/mongo-c-driver/tarball/v${MONGO_C_DRIVER_VERSION}/:mongo_c
DISTFILES+=	mdirolf-nginx-gridfs-v${NGINX_GRIDFS_VERSION}-${GIT_GRIDFS_VERSION}.tar.gz:gridfs
DISTFILES+=	mongodb-mongo-c-driver-v${MONGO_C_DRIVER_VERSION}-${GIT_MONGO_C_DRIVER_VERSION}.tar.gz:mongo_c
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mdirolf-nginx-gridfs-${GIT_GRIDFS_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MLET}
NGINX_LET_VERSION=	0.0.4
GIT_LET_VERSION=	0-ga5e1dc5
MASTER_SITES+=	https://github.com/arut/nginx-let-module/tarball/v${NGINX_LET_VERSION}/:let
DISTFILES+=	arut-nginx-let-module-v${NGINX_LET_VERSION}-${GIT_LET_VERSION}.tar.gz:let
CONFIGURE_ARGS+=--add-module=${WRKDIR}/arut-nginx-let-module-${GIT_LET_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MMEMC}
NGINX_MEMC_VERSION=	0.14
GIT_MEMC_VERSION=	0-gde4cf86
MASTER_SITES+=	https://github.com/agentzh/memc-nginx-module/tarball/v${NGINX_MEMC_VERSION}/:memc
DISTFILES+=	agentzh-memc-nginx-module-v${NGINX_MEMC_VERSION}-${GIT_MEMC_VERSION}.tar.gz:memc
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-memc-nginx-module-${GIT_MEMC_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MMODSECURITY}
NGINX_MODSECURITY_VERSION=	2.7.5
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre \
	libcurl.so:${PORTSDIR}/ftp/curl \
	libapr-1.so:${PORTSDIR}/devel/apr1
USE_APACHE=	22+
MASTER_SITES+=	http://www.modsecurity.org/tarball/${NGINX_MODSECURITY_VERSION}/:modsecurity
DISTFILES+=	modsecurity-apache_${NGINX_MODSECURITY_VERSION}.tar.gz:modsecurity
CONFIGURE_ARGS+=--add-module=${WRKDIR}/modsecurity-apache_${NGINX_MODSECURITY_VERSION}/nginx/modsecurity
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-nginx-modsecurity-config
.endif

.if ${PORT_OPTIONS:MHTTP_REWRITE}
WITH_HTTP_REWRITE=	yes
.endif

.if ${PORT_OPTIONS:MPOSTGRES}
USES+=	pgsql
WITH_HTTP_REWRITE=	yes
NGINX_POSTGRES_VERSION=	0.9
MASTER_SITES+=	http://labs.frickle.com/files/:postgres
DISTFILES+=	ngx_postgres-${NGINX_POSTGRES_VERSION}.tar.gz:postgres
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_postgres-${NGINX_POSTGRES_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_postgres-config
.endif

.if ${PORT_OPTIONS:MRDS_CSV}
NGINX_RDS_CSV_VERSION=	0.05
GIT_RDS_CSV_VERSION=	0-g607e26b
MASTER_SITES+=	https://github.com/agentzh/rds-csv-nginx-module/tarball/v${NGINX_RDS_CSV_VERSION}/:rdscsv
DISTFILES+=	agentzh-rds-csv-nginx-module-v${NGINX_RDS_CSV_VERSION}-${GIT_RDS_CSV_VERSION}.tar.gz:rdscsv
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-rds-csv-nginx-module-${GIT_RDS_CSV_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MRDS_JSON}
NGINX_RDS_JSON_VERSION=	0.13
GIT_RDS_JSON_VERSION=	0-g8292070
MASTER_SITES+=	https://github.com/agentzh/rds-json-nginx-module/tarball/v${NGINX_RDS_JSON_VERSION}/:rdsjson
DISTFILES+=	agentzh-rds-json-nginx-module-v${NGINX_RDS_JSON_VERSION}-${GIT_RDS_JSON_VERSION}.tar.gz:rdsjson
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-rds-json-nginx-module-${GIT_RDS_JSON_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MREDIS2}
NGINX_REDIS2_VERSION=	0.10
GIT_REDIS2_VERSION=	0-g78a7622
MASTER_SITES+=	https://github.com/agentzh/redis2-nginx-module/tarball/v${NGINX_REDIS2_VERSION}/:redis2
DISTFILES+=	agentzh-redis2-nginx-module-v${NGINX_REDIS2_VERSION}-${GIT_REDIS2_VERSION}.tar.gz:redis2
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-redis2-nginx-module-${GIT_REDIS2_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MRTMP}
NGINX_RTMP_VERSION=	1.0.8
MASTER_SITES+=	https://github.com/arut/nginx-rtmp-module/archive/v${NGINX_RTMP_VERSION}/:rtmp
DISTFILES+=	rtmp-nginx-module-v${NGINX_RTMP_VERSION}.tar.gz:rtmp
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-rtmp-module-${NGINX_RTMP_VERSION}
.endif

.if ${PORT_OPTIONS:MSET_MISC}
NGINX_SET_MISC_VERSION=	0.23
GIT_SET_MISC_VERSION=	0-g6ce586e
MASTER_SITES+=	https://github.com/agentzh/set-misc-nginx-module/tarball/v${NGINX_SET_MISC_VERSION}/:setmisc
DISTFILES+=	agentzh-set-misc-nginx-module-v${NGINX_SET_MISC_VERSION}-${GIT_SET_MISC_VERSION}.tar.gz:setmisc
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-set-misc-nginx-module-${GIT_SET_MISC_VERSION:S/^0-g//}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-agentzh-set-misc-nginx-module-config
.endif

.if ${PORT_OPTIONS:MSFLOW}
NGINX_SFLOW_VERSION=	0.9.7
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
NGINX_SRCACHE_VERSION=	0.24
GIT_SRCACHE_VERSION=	0-g33f0f29
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

.if ${PORT_OPTIONS:MTCP_PROXY}
NGINX_TCP_PROXY_VERSION=	0.26
GIT_TCP_PROXY_VERSION=	0-gb83e5a6
MASTER_SITES+=	https://github.com/yaoweibin/nginx_tcp_proxy_module/tarball/v${NGINX_TCP_PROXY_VERSION}/:tcp_proxy
DISTFILES+=	yaoweibin-nginx_tcp_proxy_module-v${NGINX_TCP_PROXY_VERSION}-${GIT_TCP_PROXY_VERSION}.tar.gz:tcp_proxy
CONFIGURE_ARGS+=--add-module=${WRKDIR}/yaoweibin-nginx_tcp_proxy_module-${GIT_TCP_PROXY_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MXRID_HEADER}
GIT_XRID_VERSION=	0daa3cc
MASTER_SITES+=	https://github.com/gabor/nginx-x-rid-header/tarball/master/:xrid
DISTFILES+=	gabor-nginx-x-rid-header-${GIT_XRID_VERSION}.tar.gz:xrid
CONFIGURE_ARGS+=--add-module=${WRKDIR}/gabor-nginx-x-rid-header-${GIT_XRID_VERSION}
.endif

.if ${PORT_OPTIONS:MXSS}
NGINX_XSS_VERSION=	0.04
GIT_XSS_VERSION=	0-g7e37038
MASTER_SITES+=	https://github.com/agentzh/xss-nginx-module/tarball/v${NGINX_XSS_VERSION}/:xss
DISTFILES+=	agentzh-xss-nginx-module-v${NGINX_XSS_VERSION}-${GIT_XSS_VERSION}.tar.gz:xss
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-xss-nginx-module-${GIT_XSS_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MSPDY}
WITH_HTTP_SSL=  yes
CONFIGURE_ARGS+=--with-http_spdy_module
.endif

.if ${PORT_OPTIONS:MCPP_TEST}
CONFIGURE_ARGS+=--with-cpp_test_module
.endif

.if ${PORT_OPTIONS:MTFS}
LIB_DEPENDS+=	libyajl.so:${PORTSDIR}/devel/yajl
CONFIGURE_ARGS+=--with-http_tfs_module
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

.if ${PORT_OPTIONS:MARRAYVAR}
NGINX_ARRAYVAR_VERSION=	0.03
GIT_ARRAYVAR_VERSION=	0-g4676747
MASTER_SITES+=	https://github.com/agentzh/array-var-nginx-module/tarball/v${NGINX_ARRAYVAR_VERSION}/:arrayvar
DISTFILES+=	agentzh-array-var-nginx-module-v${NGINX_ARRAYVAR_VERSION}-${GIT_ARRAYVAR_VERSION}.tar.gz:arrayvar
CONFIGURE_ARGS+=--add-module=${WRKDIR}/agentzh-array-var-nginx-module-${GIT_ARRAYVAR_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MFORMINPUT}
NGINX_FORMINPUT_VERSION=	0.07
GIT_FORMINPUT_VERSION=		0-g78de845
MASTER_SITES+=	https://github.com/calio/form-input-nginx-module/tarball/v${NGINX_FORMINPUT_VERSION}/:forminput
DISTFILES+=	calio-form-input-nginx-module-v${NGINX_FORMINPUT_VERSION}-${GIT_FORMINPUT_VERSION}.tar.gz:forminput
CONFIGURE_ARGS+=--add-module=${WRKDIR}/calio-form-input-nginx-module-${GIT_FORMINPUT_VERSION:S/^0-g//}
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
NGINX_ICONV_VERSION=	0.10
GIT_ICONV_VERSION=	0-gb37efb5
MASTER_SITES+=	https://github.com/calio/iconv-nginx-module/tarball/v${NGINX_ICONV_VERSION}/:iconv
DISTFILES+=	calio-iconv-nginx-module-v${NGINX_ICONV_VERSION}-${GIT_ICONV_VERSION}.tar.gz:iconv
CONFIGURE_ARGS+=--add-module=${WRKDIR}/calio-iconv-nginx-module-${GIT_ICONV_VERSION:S/^0-g//}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-calio-iconv-nginx-module-config
.endif

PLIST_SUB+=	NGINX_TMPDIR=${NGINX_TMPDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

USERS?=	${WWWOWN}
GROUPS?=${WWWGRP}

.if defined(WITH_HTTP_REWRITE)
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-pcre
.else
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nopcre
CONFIGURE_ARGS+=--without-http_rewrite_module \
		--without-pcre
.endif

.if defined(NGINX_OPENSSL)
USE_OPENSSL=    yes
.if ${PORT_OPTIONS:MSPDY}
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000028
WITH_OPENSSL_PORT=      yes
.else
WITH_OPENSSL_BASE=      yes
.endif
.endif
.endif

.if defined(WITH_HTTP_SSL)
NGINX_OPENSSL=	yes
CONFIGURE_ARGS+=--with-http_ssl_module
.endif

.if ${PORT_OPTIONS:MHTTP_SSL}
WITH_HTTP_SSL=	yes
.endif

pre-everything::
.if ${PORT_OPTIONS:MHTTP_UPSTREAM_FAIR}
	@${ECHO_MSG} "Enable http_ssl module to build upstream_fair with SSL support"
.endif

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
# Linker error acquire if --std=c99 defined, add "static" to inline function
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
	${MKDIR}  ${STAGEDIR}${ETCDIR}/modules
	${MKDIR}  ${STAGEDIR}${ETCDIR}/include
	${MKDIR}  ${STAGEDIR}${NGINX_TMPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/objs/dso_tool ${STAGEDIR}${PREFIX}/sbin
.for i in koi-utf koi-win win-utf
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${STAGEDIR}${ETCDIR}
.endfor
.for i in *.so
	${INSTALL_PROGRAM} ${WRKSRC}/objs/modules/${i} ${STAGEDIR}${ETCDIR}/modules
.endfor
.for i in *.h
	${INSTALL_DATA} ${WRKSRC}/src/core/${i} ${STAGEDIR}${ETCDIR}/include
	${INSTALL_DATA} ${WRKSRC}/src/event/${i} ${STAGEDIR}${ETCDIR}/include
	${INSTALL_DATA} ${WRKSRC}/src/os/unix/${i} ${STAGEDIR}${ETCDIR}/include
	${INSTALL_DATA} ${WRKSRC}/src/http/${i} ${STAGEDIR}${ETCDIR}/include
	${INSTALL_DATA} ${WRKSRC}/src/http/modules/${i} ${STAGEDIR}${ETCDIR}/include
	${INSTALL_DATA} ${WRKSRC}/src/http/modules/lua/${i} ${STAGEDIR}${ETCDIR}/include
.endfor
	${INSTALL_DATA} ${WRKSRC}/objs/ngx_auto_headers.h ${WRKSRC}/objs/ngx_auto_config.h ${STAGEDIR}${ETCDIR}/include
.for i in fastcgi_params mime.types nginx.conf scgi_params uwsgi_params
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${STAGEDIR}${ETCDIR}/${i}-dist
.endfor
.if !empty(PORT_OPTIONS:MHTTP) && !empty(PORT_OPTIONS:MWWW)
	${MKDIR} ${STAGEDIR}${PREFIX}/www/nginx-dist
.for i in index.html 50x.html
	${INSTALL_DATA} ${WRKSRC}/html/${i} ${STAGEDIR}${PREFIX}/www/nginx-dist
.endfor
	${ECHO_CMD} "" >>${STAGEDIR}${PREFIX}/www/nginx-dist/EXAMPLE_DIRECTORY-DONT_ADD_OR_TOUCH_ANYTHING
.endif

.if !empty(PORT_OPTIONS:MHTTP) && !empty(PORT_OPTIONS:MHTTP_PERL)
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx
	${INSTALL_PROGRAM} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.so \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.bs \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/lib/nginx.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/
.endif

post-install:
.if !empty(PORT_OPTIONS:MHTTP) && !empty(PORT_OPTIONS:MHTTP_PERL)
	${ECHO_CMD} ${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx/nginx.so >> ${TMPPLIST}
	${ECHO_CMD} ${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx/nginx.bs >> ${TMPPLIST}
	${ECHO_CMD} ${SITE_PERL_REL}/${PERL_ARCH}/nginx.pm >> ${TMPPLIST}
	${ECHO_CMD} @dirrm ${SITE_PERL_REL}/${PERL_ARCH}/auto/nginx >> ${TMPPLIST}
.endif
	@${INSTALL_MAN} ${WRKSRC}/objs/nginx.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
