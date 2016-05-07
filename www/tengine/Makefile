# Created by: Jim Ohlstein <jim@ohlste.in>
# $FreeBSD$

PORTNAME=	tengine
PORTVERSION=	2.0.3
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	7
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robust and small WWW server forked from Nginx

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

WANT_GNOME=	yes
USE_GNOME=	libxml2 libxslt
USE_GITHUB=	yes
GH_ACCOUNT=	alibaba

LIB_DEPENDS+=	libluajit-5.1.so:lang/luajit \
		libeio.so:devel/libeio \
		libev.so:devel/libev \
		libgd.so:graphics/gd \
		libGeoIP.so:net/GeoIP

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
GH_ACCOUNT+=	giom:accept_language
GH_PROJECT+=	nginx_accept_language_module:accept_language
GH_TAGNAME+=	${GIT_ACCEPT_LANGUAGE_VERSION}:accept_language
CONFIGURE_ARGS+=--add-module=${WRKSRC_accept_language}
.endif

.if ${PORT_OPTIONS:MHTTP_ACCESSKEY}
NGINX_ACCESSKEY_VERSION=	2.0.3
MASTER_SITES+=	LOCAL/osa:accesskey
DISTFILES+=	nginx-accesskey-${NGINX_ACCESSKEY_VERSION}.tar.gz:accesskey
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-accesskey-${NGINX_ACCESSKEY_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_DIGEST}
GIT_AUTH_DIGEST_VERSION=	bd1c86a
GH_ACCOUNT+=	samizdatco:auth_digest
GH_PROJECT+=	nginx-http-auth-digest:auth_digest
GH_TAGNAME+=	${GIT_AUTH_DIGEST_VERSION}:auth_digest
CONFIGURE_ARGS+=--add-module=${WRKSRC_auth_digest}
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
GH_ACCOUNT+=	openresty:echo
GH_PROJECT+=	echo-nginx-module:echo
GH_TAGNAME+=	v${NGINX_ECHO_VERSION}:echo
CONFIGURE_ARGS+=--add-module=${WRKSRC_echo}
.endif

.if ${PORT_OPTIONS:MHEADERS_MORE}
NGINX_HEADERS_MORE_VERSION=	0.24
GH_ACCOUNT+=	openresty:headers_more
GH_PROJECT+=	headers-more-nginx-module:headers_more
GH_TAGNAME+=	v${NGINX_HEADERS_MORE_VERSION}:headers_more
CONFIGURE_ARGS+=--add-module=${WRKSRC_headers_more}
.endif

.if ${PORT_OPTIONS:MHTTP_DAV}
CONFIGURE_ARGS+=--with-http_dav_module
.endif

.if ${PORT_OPTIONS:MHTTP_DAV_EXT}
LIB_DEPENDS+=	libexpat.so:textproc/expat2
NGINX_DAV_EXT_VERSION=	0.0.2
GH_ACCOUNT+=	arut:dav_ext
GH_PROJECT+=	nginx-dav-ext-module:dav_ext
GH_TAGNAME+=	v${NGINX_DAV_EXT_VERSION}:dav_ext
CONFIGURE_ARGS+=--add-module=${WRKSRC_dav_ext} \
		--with-http_dav_module
.endif

.if ${PORT_OPTIONS:MHTTP_EVAL}
NGINX_EVAL_VERSION=	1.0.3
GH_ACCOUNT+=	vkholodkov:eval
GH_PROJECT+=	nginx-eval-module:eval
GH_TAGNAME+=	${NGINX_EVAL_VERSION}:eval
CONFIGURE_ARGS+=--add-module=${WRKSRC_eval}
.endif

.if ${PORT_OPTIONS:MHTTP_FANCYINDEX}
NGINX_FANCYINDEX_VERSION=	0.3.1
MASTER_SITES+=	LOCAL/osa:fancyindex
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
GIT_NOTICE_VERSION=	3c95966
GH_ACCOUNT+=	kr:notice
GH_PROJECT+=	nginx-notice:notice
GH_TAGNAME+=	${GIT_NOTICE_VERSION}:notice
CONFIGURE_ARGS+=--add-module=${WRKSRC_notice}
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
GH_ACCOUNT+=	wandenberg:pushstream
GH_PROJECT+=	nginx-push-stream-module:pushstream
GH_TAGNAME+=	${NGINX_PUSH_STREAM_VERSION}:pushstream
CONFIGURE_ARGS+=--add-module=${WRKSRC_pushstream}
.endif

.if ${PORT_OPTIONS:MHTTP_REALIP}
CONFIGURE_ARGS+=--with-http_realip_module
.endif

.if ${PORT_OPTIONS:MHTTP_REDIS}
NGINX_REDIS_VERSION=	0.3.7
MASTER_SITES+=	LOCAL/osa:redis
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
GH_ACCOUNT+=	masterzen:uploadprogress
GH_PROJECT+=	nginx-upload-progress-module:uploadprogress
GH_TAGNAME+=	v${NGINX_UPLOADPROGRESS_VERSION}:uploadprogress
CONFIGURE_ARGS+=--add-module=${WRKSRC_uploadprogress}
.endif

.if !empty(PORT_OPTIONS:MHTTP_UPSTREAM_FAIR) || !empty(PORT_OPTIONS:MSUPERVISORD)
NGINX_UPSTREAM_FAIR_VERSION=	20090923
MASTER_SITES+=	LOCAL/osa:upstreamfair
DISTFILES+=	nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}.tar.gz:upstreamfair
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_VIDEO_THUMBEXTRACTOR}
LIB_DEPENDS+=	libavformat.so:multimedia/ffmpeg \
			libavcodec.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg \
			libswscale.so:multimedia/ffmpeg \
			libMagickWand-6.so:graphics/ImageMagick
USES+=		jpeg
NGINX_VIDEO_THUMBEXTRACTOR_VERSION=	0.2.0
GH_ACCOUNT+=	wandenberg:videothumbextractor
GH_PROJECT+=	nginx-video-thumbextractor-module:videothumbextractor
GH_TAGNAME+=	${NGINX_VIDEO_THUMBEXTRACTOR_VERSION}:videothumbextractor
CONFIGURE_ARGS+=--add-module=${WRKSRC_videothumbextractor} \
			--with-cc-opt="-I ${LOCALBASE}/include -I ${LOCALBASE}/include/ImageMagick"
.endif

.if ${PORT_OPTIONS:MHTTP_ZIP}
NGINX_ZIP_VERSION=	1.1.6
MASTER_SITES+=	http://mod-zip.googlecode.com/files/:zip
DISTFILES+=	mod_zip-${NGINX_ZIP_VERSION}.tar.gz:zip
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mod_zip-${NGINX_ZIP_VERSION}
.endif

.if ${PORT_OPTIONS:MDRIZZLE}
LIB_DEPENDS+=	libdrizzle.so:databases/libdrizzle
NGINX_DRIZZLE_VERSION=	0.1.6
GH_ACCOUNT+=	chaoslawful:drizzle
GH_PROJECT+=	drizzle-nginx-module:drizzle
GH_TAGNAME+=	v${NGINX_DRIZZLE_VERSION}:drizzle
CONFIGURE_ARGS+=--add-module=${WRKSRC_drizzle}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-chaoslawful-drizzle-nginx-module-config
.endif

.if ${PORT_OPTIONS:MARRAYVAR} || ${PORT_OPTIONS:MENCRYPTSESSION} || ${PORT_OPTIONS:MFORMINPUT} || ${PORT_OPTIONS:MICONV} || ${PORT_OPTIONS:MSET_MISC}
WITH_HTTP_REWRITE=	yes
NGINX_DEVEL_KIT_VERSION=	0.2.19
GH_ACCOUNT+=	simpl:devel_kit
GH_PROJECT+=	ngx_devel_kit:devel_kit
GH_TAGNAME+=	v${NGINX_DEVEL_KIT_VERSION}:devel_kit
CONFIGURE_ARGS+=--add-module=${WRKSRC_devel_kit}
.endif

.if ${PORT_OPTIONS:MENCRYPTSESSION}
NGINX_ENCRYPTSESSION_VERSION=	0.03
GH_ACCOUNT+=	openresty:encryptsession
GH_PROJECT+=	encrypted-session-nginx-module:encryptsession
GH_TAGNAME+=	v${NGINX_ENCRYPTSESSION_VERSION}:encryptsession
CONFIGURE_ARGS+=--add-module=${WRKSRC_encryptsession}
.endif

.if ${PORT_OPTIONS:MGRIDFS}
NGINX_GRIDFS_VERSION=	0.8
MONGO_C_DRIVER_VERSION=		0.3.1
GH_ACCOUNT+=	mdirolf:gridfs mongodb:mongo_c
GH_PROJECT+=	nginx-gridfs:gridfs mongo-c-driver:mongo_c
GH_TAGNAME+=	v${NGINX_GRIDFS_VERSION}:gridfs v${MONGO_C_DRIVER_VERSION}:mongo_c
CONFIGURE_ARGS+=--add-module=${WRKSRC_gridfs}
.endif

.if ${PORT_OPTIONS:MLET}
NGINX_LET_VERSION=	0.0.4
GH_ACCOUNT+=	arut:let
GH_PROJECT+=	nginx-let-module:let
GH_TAGNAME+=	v${NGINX_LET_VERSION}:let
CONFIGURE_ARGS+=--add-module=${WRKSRC_let}
.endif

.if ${PORT_OPTIONS:MMEMC}
NGINX_MEMC_VERSION=	0.14
GH_ACCOUNT+=	openresty:memc
GH_PROJECT+=	memc-nginx-module:memc
GH_TAGNAME+=	v${NGINX_MEMC_VERSION}:memc
CONFIGURE_ARGS+=--add-module=${WRKSRC_memc}
.endif

.if ${PORT_OPTIONS:MMODSECURITY}
NGINX_MODSECURITY_VERSION=	2.7.5
LIB_DEPENDS+=	libpcre.so:devel/pcre \
	libcurl.so:ftp/curl \
	libapr-1.so:devel/apr1
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
GH_ACCOUNT+=	openresty:rdscsv
GH_PROJECT+=	rds-csv-nginx-module:rdscsv
GH_TAGNAME+=	v${NGINX_RDS_CSV_VERSION}:rdscsv
CONFIGURE_ARGS+=--add-module=${WRKSRC_rdscsv}
.endif

.if ${PORT_OPTIONS:MRDS_JSON}
NGINX_RDS_JSON_VERSION=	0.13
GH_ACCOUNT+=	openresty:rdsjson
GH_PROJECT+=	rds-json-nginx-module:rdsjson
GH_TAGNAME+=	v${NGINX_RDS_JSON_VERSION}:rdsjson
CONFIGURE_ARGS+=--add-module=${WRKSRC_rdsjson}
.endif

.if ${PORT_OPTIONS:MREDIS2}
NGINX_REDIS2_VERSION=	0.10
GH_ACCOUNT+=	openresty:redis2
GH_PROJECT+=	redis2-nginx-module:redis2
GH_TAGNAME+=	v${NGINX_REDIS2_VERSION}:redis2
CONFIGURE_ARGS+=--add-module=${WRKSRC_redis2}
.endif

.if ${PORT_OPTIONS:MRTMP}
NGINX_RTMP_VERSION=	1.0.8
GH_ACCOUNT+=	arut:rtmp
GH_PROJECT+=	nginx-rtmp-module:rtmp
GH_TAGNAME+=	v${NGINX_RTMP_VERSION}:rtmp
CONFIGURE_ARGS+=--add-module=${WRKSRC_rtmp}
.endif

.if ${PORT_OPTIONS:MSET_MISC}
NGINX_SET_MISC_VERSION=	0.23
GH_ACCOUNT+=	openresty:setmisc
GH_PROJECT+=	set-misc-nginx-module:setmisc
GH_TAGNAME+=	v${NGINX_SET_MISC_VERSION}:setmisc
CONFIGURE_ARGS+=--add-module=${WRKSRC_setmisc}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-openresty-set-misc-nginx-module-config
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
GH_ACCOUNT+=	openresty:srcache
GH_PROJECT+=	srcache-nginx-module:srcache
GH_TAGNAME+=	v${NGINX_SRCACHE_VERSION}:srcache
CONFIGURE_ARGS+=--add-module=${WRKSRC_srcache}
.endif

.if ${PORT_OPTIONS:MSUPERVISORD}
NGINX_SUPERVISORD_VERSION=	1.4
MASTER_SITES+=	http://labs.frickle.com/files/:supervisord
DISTFILES+=	ngx_supervisord-${NGINX_SUPERVISORD_VERSION}.tar.gz:supervisord
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_VERSION}
.endif

.if ${PORT_OPTIONS:MTCP_PROXY}
NGINX_TCP_PROXY_VERSION=	0.26
GH_ACCOUNT+=	yaoweibin:tcp_proxy
GH_PROJECT+=	nginx_tcp_proxy_module:tcp_proxy
GH_TAGNAME+=	v${NGINX_TCP_PROXY_VERSION}:tcp_proxy
CONFIGURE_ARGS+=--add-module=${WRKSRC_tcp_proxy}
.endif

.if ${PORT_OPTIONS:MXRID_HEADER}
GIT_XRID_VERSION=	0daa3cc
GH_ACCOUNT+=	gabor:xrid
GH_PROJECT+=	nginx-x-rid-header:xrid
GH_TAGNAME+=	master:xrid
CONFIGURE_ARGS+=--add-module=${WRKSRC_xrid}
.endif

.if ${PORT_OPTIONS:MXSS}
NGINX_XSS_VERSION=	0.04
GH_ACCOUNT+=	openresty:xss
GH_PROJECT+=	xss-nginx-module:xss
GH_TAGNAME+=	v${NGINX_XSS_VERSION}:xss
CONFIGURE_ARGS+=--add-module=${WRKSRC_xss}
.endif

.if ${PORT_OPTIONS:MSPDY}
WITH_HTTP_SSL=	yes
CONFIGURE_ARGS+=--with-http_spdy_module
.endif

.if ${PORT_OPTIONS:MCPP_TEST}
CONFIGURE_ARGS+=--with-cpp_test_module
.endif

.if ${PORT_OPTIONS:MTFS}
LIB_DEPENDS+=	libyajl.so:devel/yajl
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
GH_ACCOUNT+=	openresty:arrayvar
GH_PROJECT+=	array-var-nginx-module:arrayvar
GH_TAGNAME+=	v${NGINX_ARRAYVAR_VERSION}:arrayvar
CONFIGURE_ARGS+=--add-module=${WRKSRC_arrayvar}
.endif

.if ${PORT_OPTIONS:MFORMINPUT}
NGINX_FORMINPUT_VERSION=	0.07
GH_ACCOUNT+=	calio:forminput
GH_PROJECT+=	form-input-nginx-module:forminput
GH_TAGNAME+=	v${NGINX_FORMINPUT_VERSION}:forminput
CONFIGURE_ARGS+=--add-module=${WRKSRC_forminput}
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
NGINX_ICONV_VERSION=	0.10
GH_ACCOUNT+=	calio:iconv
GH_PROJECT+=	iconv-nginx-module:iconv
GH_TAGNAME+=	v${NGINX_ICONV_VERSION}:iconv
CONFIGURE_ARGS+=--add-module=${WRKSRC_iconv}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-calio-iconv-nginx-module-config
.endif

PLIST_SUB+=	NGINX_TMPDIR=${NGINX_TMPDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

USERS?=	${WWWOWN}
GROUPS?=${WWWGRP}

.if defined(WITH_HTTP_REWRITE)
LIB_DEPENDS+=	libpcre.so:devel/pcre
CONFIGURE_ARGS+=--with-pcre
.else
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nopcre
CONFIGURE_ARGS+=--without-http_rewrite_module \
		--without-pcre
.endif

.if defined(NGINX_OPENSSL)
USE_OPENSSL=	yes
.if ${PORT_OPTIONS:MSPDY}
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000028
WITH_OPENSSL_PORT=	yes
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
	@${RMDIR} ${WRKSRC_gridfs}/mongo-c-driver/
	@${MV} ${WRKSRC_mongo_c} ${WRKSRC_gridfs}/mongo-c-driver/
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
		${WRKSRC_drizzle}/config
.endif
# Respect CFLAGS by remove needless --std=c99 flag
.if ${PORT_OPTIONS:MGRIDFS}
	@${REINPLACE_CMD} \
		's!--std=c99!-DMONGO_HAVE_STDINT!' \
		${WRKSRC_gridfs}/config
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
		${WRKSRC_drizzle}/src/ngx_http_drizzle_util.c
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
			${WRKSRC_tcp_proxy}/tcp.patch )
.endif
.if ${PORT_OPTIONS:MICONV}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKSRC_iconv}/config
.endif
.if ${PORT_OPTIONS:MMODSECURITY}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKDIR}/modsecurity-apache_${NGINX_MODSECURITY_VERSION}/nginx/modsecurity/config
.endif

pre-configure:
.if ${PORT_OPTIONS:MMODSECURITY}
	( cd ${WRKDIR}/modsecurity-apache_${NGINX_MODSECURITY_VERSION} && \
		CC="${CC}" ${CONFIGURE_CMD} --enable-standalone-module && \
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
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/nginx
	${INSTALL_PROGRAM} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.so \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/lib/nginx.pm \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/
.endif

post-install:
.if !empty(PORT_OPTIONS:MHTTP) && !empty(PORT_OPTIONS:MHTTP_PERL)
	${ECHO_CMD} ${SITE_ARCH_REL}/auto/nginx/nginx.so >> ${TMPPLIST}
	${ECHO_CMD} ${SITE_ARCH_REL}/nginx.pm >> ${TMPPLIST}
.endif
	${INSTALL_MAN} ${WRKSRC}/objs/nginx.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
