# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nginx
PORTVERSION=	1.11.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://nginx.org/download/
MASTER_SITES+=	LOCAL/osa
PKGNAMESUFFIX?=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	osa@FreeBSD.org
COMMENT?=	Robust and small WWW server

LICENSE=	BSD2CLAUSE

USES+=		cpe

CPE_VENDOR=	nginx
CPE_PRODUCT=	nginx
USE_GITHUB=	nodefault

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=	\
	DSO \
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
	HTTP_MP4 \
	HTTP_PERL \
	HTTP_RANDOM_INDEX \
	HTTP_REALIP \
	HTTP_REWRITE \
	HTTP_SECURE_LINK \
	HTTP_SLICE \
	HTTP_SSL \
	HTTP_STATUS \
	HTTP_SUB \
	HTTP_XSLT \
	MAIL \
	MAIL_IMAP \
	MAIL_POP3 \
	MAIL_SMTP \
	MAIL_SSL \
	HTTPV2 \
	NJS \
	STREAM \
	STREAM_SSL \
	STREAM_SSL_PREREAD \
	THREADS \
	WWW \
	AJP \
	AWS_AUTH \
	CACHE_PURGE \
	CLOJURE \
	CT \
	ECHO \
	FASTDFS \
	HEADERS_MORE \
	HTTP_ACCEPT_LANGUAGE \
	HTTP_ACCESSKEY \
	HTTP_AUTH_DIGEST \
	HTTP_AUTH_KRB5 \
	HTTP_AUTH_LDAP \
	HTTP_AUTH_PAM \
	HTTP_DAV_EXT \
	HTTP_EVAL \
	HTTP_FANCYINDEX \
	HTTP_FOOTER \
	HTTP_GEOIP2 \
	HTTP_JSON_STATUS \
	HTTP_MOGILEFS \
	HTTP_MP4_H264 \
	HTTP_NOTICE \
	HTTP_PUSH \
	HTTP_PUSH_STREAM \
	HTTP_REDIS \
	HTTP_RESPONSE \
	HTTP_SUBS_FILTER \
	HTTP_TARANTOOL \
	HTTP_UPLOAD \
	HTTP_UPLOAD_PROGRESS \
	HTTP_UPSTREAM_CHECK \
	HTTP_UPSTREAM_FAIR \
	HTTP_UPSTREAM_STICKY \
	HTTP_VIDEO_THUMBEXTRACTOR \
	HTTP_ZIP \
	ARRAYVAR \
	BROTLI \
	DRIZZLE \
	DYNAMIC_UPSTREAM \
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
	SHIBBOLETH \
	SLOWFS_CACHE \
	SMALL_LIGHT \
	SRCACHE \
	STATSD \
	UDPLOG \
	X11 \
	XRID_HEADER \
	XSS

OPTIONS_DEFAULT?=DSO FILE_AIO HTTP HTTP_ADDITION HTTP_AUTH_REQ HTTP_CACHE \
		HTTP_DAV HTTP_FLV HTTP_GZIP_STATIC HTTP_GUNZIP_FILTER \
		HTTP_MP4 HTTP_RANDOM_INDEX HTTP_REALIP HTTP_SECURE_LINK \
		HTTP_SLICE HTTP_REWRITE HTTP_SSL HTTP_STATUS HTTP_SUB \
		HTTPV2 MAIL MAIL_SSL STREAM STREAM_SSL STREAM_SSL_PREREAD \
		THREADS WWW

DSO_DESC=			Enable dynamic modules support
DEBUG_DESC=			Build with debugging support
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
HTTP_SLICE_DESC=		Enable http_slice module
HTTP_SSL_DESC=			Enable http_ssl module
HTTP_STATUS_DESC=		Enable http_stub_status module
HTTP_SUB_DESC=			Enable http_sub module
HTTP_XSLT_DESC=			Enable http_xslt module
MAIL_DESC=			Enable IMAP4/POP3/SMTP proxy module
MAIL_IMAP_DESC=			Enable IMAP4 proxy module
MAIL_POP3_DESC=			Enable POP3 proxy module
MAIL_SMTP_DESC=			Enable SMTP proxy module
MAIL_SSL_DESC=			Enable mail_ssl module
HTTPV2_DESC=			Enable HTTP/2 protocol support (SSL req.)
NJS_DESC=			Enable http_javascript module
STREAM_DESC=			Enable stream module
STREAM_SSL_DESC=		Enable stream_ssl module (SSL req.)
STREAM_SSL_PREREAD_DESC=	Enable stream_ssl_preread module (SSL req.)
THREADS_DESC=			Enable threads support
WWW_DESC=			Enable html sample files
AJP_DESC=			3rd party ajp module
AWS_AUTH_DESC=			3rd party aws auth module
CACHE_PURGE_DESC=		3rd party cache_purge module
CLOJURE_DESC=			3rd party clojure module
CT_DESC=			3rd party cert_transparency module (SSL req.)
ECHO_DESC=			3rd party echo module
FASTDFS_DESC=			3rd party fastdfs module
HEADERS_MORE_DESC=		3rd party headers_more module
HTTP_ACCEPT_LANGUAGE_DESC=	3rd party accept_language module
HTTP_ACCESSKEY_DESC=		3rd party http_accesskey module
HTTP_AUTH_DIGEST_DESC=		3rd party http_authdigest module
HTTP_AUTH_KRB5_DESC=		3rd party http_auth_gss module
HTTP_AUTH_LDAP_DESC=		3rd party http_auth_ldap module
HTTP_AUTH_PAM_DESC=		3rd party http_auth_pam module
HTTP_DAV_EXT_DESC=		3rd party webdav_ext module
HTTP_EVAL_DESC=			3rd party eval module
HTTP_FANCYINDEX_DESC=		3rd party http_fancyindex module
HTTP_FOOTER_DESC=		3rd party http_footer module
HTTP_GEOIP2_DESC=		3rd party geoip2 module
HTTP_JSON_STATUS_DESC=		3rd party http_json_status module
HTTP_MOGILEFS_DESC=		3rd party mogilefs module
HTTP_MP4_H264_DESC=		3rd party mp4/h264 module
HTTP_NOTICE_DESC=		3rd party notice module
HTTP_PUSH_DESC=			3rd party push module
HTTP_PUSH_STREAM_DESC=		3rd party push stream module
HTTP_REDIS_DESC=		3rd party http_redis module
HTTP_RESPONSE_DESC=		3rd party http_response module
HTTP_SUBS_FILTER_DESC=		3rd party subs filter module
HTTP_TARANTOOL_DESC=		3rd party tarantool upstream module
HTTP_UPLOAD_DESC=		3rd party upload module
HTTP_UPLOAD_PROGRESS_DESC=	3rd party uploadprogress module
HTTP_UPSTREAM_CHECK_DESC=	3rd party upstream check module
HTTP_UPSTREAM_FAIR_DESC=	3rd party upstream fair module
HTTP_UPSTREAM_STICKY_DESC=	3rd party upstream sticky module
HTTP_VIDEO_THUMBEXTRACTOR_DESC=	3rd party video_thumbextractor module
HTTP_ZIP_DESC=			3rd party http_zip module
ARRAYVAR_DESC=			3rd party array_var module
BROTLI_DESC=			3rd party brotli module
DRIZZLE_DESC=			3rd party drizzlie module
DYNAMIC_UPSTREAM_DESC=		3rd party dynamic_upstream module
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
POSTGRES_DESC=			3rd party postgres module
RDS_CSV_DESC=			3rd party rds_csv module
RDS_JSON_DESC=			3rd party rds_json module
REDIS2_DESC=			3rd party redis2 module
RTMP_DESC=			3rd party rtmp module
SET_MISC_DESC=			3rd party set_misc module
SFLOW_DESC=			3rd party sflow module
SHIBBOLETH_DESC=		3rd party shibboleth module
SLOWFS_CACHE_DESC=		3rd party slowfs_cache module
SMALL_LIGHT_DESC=		3rd party small_light module
SRCACHE_DESC=			3rd party srcache module
STATSD_DESC=			3rd party statsd module
UDPLOG_DESC=			3rd party udplog (syslog) module
X11_DESC=			graphics/ImageMagick[-nox11] dependency
XRID_HEADER_DESC=		3rd party x-rid header module
XSS_DESC=			3rd party xss module
VIDEO_DESC=			Video module support

WANT_GNOME=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
IMAGEMAGICK_LIB_DEPENDS= libMagickWand-6.so:graphics/ImageMagick
.else
IMAGEMAGICK_LIB_DEPENDS= libMagickWand-6.so:graphics/ImageMagick-nox11
.endif

.if ${PORT_OPTIONS:MPASSENGER}
CATEGORIES+=	ruby
USE_RUBY=	yes
BUILD_DEPENDS+=		${LOCALBASE}/bin/rake:devel/rubygem-rake
RAKE_BIN=	${LOCALBASE}/bin/rake
.endif

NGINX_VARDIR?=	/var
NGINX_LOGDIR?=	${NGINX_VARDIR}/log/nginx
NGINX_RUNDIR?=	${NGINX_VARDIR}/run
NGINX_TMPDIR?=	${NGINX_VARDIR}/tmp/nginx
HTTP_PORT?=	80

NGINX_ACCESSLOG?=	${NGINX_LOGDIR}/access.log
NGINX_ERRORLOG?=	${NGINX_LOGDIR}/error.log

CONFLICTS?=     nginx-1.* \
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

.if !empty(PORT_OPTIONS:MDSO)
MODULESDIR=	${PREFIX}/libexec/${PORTNAME}
CONFIGURE_ARGS+=--modules-path=${MODULESDIR}
.endif

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
LIB_DEPENDS+=	libprofiler.so:devel/google-perftools
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
IGNORE=	ACCESSKEY: a patch requires
.endif

.if ${PORT_OPTIONS:MHTTP_ADDITION}
CONFIGURE_ARGS+=--with-http_addition_module
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_DIGEST}
GIT_AUTH_DIGEST_VERSION=	cc61b4a
GH_ACCOUNT+=	atomx:auth_digest
GH_PROJECT+=	nginx-http-auth-digest:auth_digest
GH_TAGNAME+=	${GIT_AUTH_DIGEST_VERSION}:auth_digest
CONFIGURE_ARGS+=--add-module=${WRKSRC_auth_digest}
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_KRB5}
GIT_HTTP_AUTH_KRB5_VERSION=	c85a38c
GH_ACCOUNT+=	stnoonan:auth_krb5
GH_PROJECT+=	spnego-http-auth-nginx-module:auth_krb5
GH_TAGNAME+=	${GIT_HTTP_AUTH_KRB5_VERSION}:auth_krb5
CONFIGURE_ARGS+=--add-module=${WRKSRC_auth_krb5}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-spnego-http-auth-nginx-module-config
# TODO: Provide optional dependence on Kerberos implementations from ports
USES+=	gssapi:base,flags
.endif

.if ${PORT_OPTIONS:MHTTP_AUTH_LDAP}
# WWW: https://github.com/kvspb/nginx-auth-ldap
GIT_HTTP_AUTH_LDAP_VERSION=	dbcef31
GH_ACCOUNT+=	kvspb:http_auth_ldap
GH_PROJECT+=	nginx-auth-ldap:http_auth_ldap
GH_TAGNAME+=	${GIT_HTTP_AUTH_LDAP_VERSION}:http_auth_ldap
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_http_auth_ldap}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_http_auth_ldap}
.endif
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

.if ${PORT_OPTIONS:MAJP}
NGINX_AJP_VERSION=	bf6cd93
GH_ACCOUNT+=	yaoweibin:ajp
GH_PROJECT+=	nginx_ajp_module:ajp
GH_TAGNAME+=	${NGINX_AJP_VERSION}:ajp
CONFIGURE_ARGS+=--add-module=${WRKSRC_ajp}
.endif

.if ${PORT_OPTIONS:MAWS_AUTH}
NGINX_AWS_AUTH_VERSION=	1e62670
GH_ACCOUNT+=	anomalizer:aws_auth
GH_PROJECT+=	ngx_aws_auth:aws_auth
GH_TAGNAME+=	${NGINX_AWS_AUTH_VERSION}:aws_auth
CONFIGURE_ARGS+=--add-module=${WRKSRC_aws_auth}
.endif

.if ${PORT_OPTIONS:MCACHE_PURGE}
NGINX_CACHE_PURGE_VERSION=	2.3
MASTER_SITES+=	http://labs.frickle.com/files/:cache_purge
DISTFILES+=	ngx_cache_purge-${NGINX_CACHE_PURGE_VERSION}.tar.gz:cache_purge
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_cache_purge-${NGINX_CACHE_PURGE_VERSION}
.endif

.if ${PORT_OPTIONS:MCLOJURE}
CATEGORIES+=	java
USE_JAVA=	yes
JAVA_OS=	native
JAVA_VERSION=	1.8
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes
NGINX_CLOJURE_VERSION=	0.4.4
GH_ACCOUNT+=	nginx-clojure:clojure
GH_PROJECT+=	nginx-clojure:clojure
GH_TAGNAME+=	v${NGINX_CLOJURE_VERSION}:clojure
CONFIGURE_ENV+=	"JNI_INCS=-I${LOCALBASE}/openjdk8/include -I${LOCALBASE}/openjdk8/include/freebsd"
CONFIGURE_ARGS+=--add-module=${WRKSRC_clojure}/src/c
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src-c-ngx_http_clojure_socket.c
.endif

.if ${PORT_OPTIONS:MCT}
GIT_CT_VERSION=	f3cad5e
GH_ACCOUNT+=	grahamedgecombe:ct
GH_PROJECT+=	nginx-ct:ct
GH_TAGNAME+=	${GIT_CT_VERSION}:ct
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_ct}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_ct}
.endif
NGINX_OPENSSL=	yes
USE_HTTP_SSL=	yes
.endif

.if ${PORT_OPTIONS:MECHO}
NGINX_ECHO_VERSION=	46334b3
GH_ACCOUNT+=	openresty:echo
GH_PROJECT+=	echo-nginx-module:echo
GH_TAGNAME+=	${NGINX_ECHO_VERSION}:echo
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_echo}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_echo}
.endif
.endif

.if ${PORT_OPTIONS:MFASTDFS}
NGINX_FASTDFS_VERSION=     5a8110f
GH_ACCOUNT+=    happyfish100:fastdfs
GH_PROJECT+=    fastdfs-nginx-module:fastdfs
GH_TAGNAME+=    ${NGINX_FASTDFS_VERSION}:fastdfs
EXTRA_PATCHES+= ${PATCHDIR}/extra-patch-fastdfs-src-config
BUILD_DEPENDS+=	${LOCALBASE}/include/fastcommon/logger.h:devel/libfastcommon \
		${LOCALBASE}/include/fastdfs/fdfs_client.h:ftp/fastdfs
LIB_DEPENDS+=	libfastcommon.so:devel/libfastcommon \
		libfdfsclient.so:ftp/fastdfs
CONFIGURE_ARGS+=--add-module=${WRKSRC_fastdfs}/src \
		--with-cc-opt="-I ${LOCALBASE}/include/fastdfs \
		-I ${LOCALBASE}/include/fastcommon"
.endif

.if ${PORT_OPTIONS:MHEADERS_MORE}
NGINX_HEADERS_MORE_VERSION=	84241e4
GH_ACCOUNT+=	openresty:headers_more
GH_PROJECT+=	headers-more-nginx-module:headers_more
GH_TAGNAME+=	${NGINX_HEADERS_MORE_VERSION}:headers_more
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_headers_more}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_headers_more}
.endif
.endif

.if ${PORT_OPTIONS:MHTTP_DAV} || defined(USE_HTTP_DAV)
CONFIGURE_ARGS+=--with-http_dav_module
.endif

.if ${PORT_OPTIONS:MHTTP_DAV_EXT}
USE_HTTP_DAV=	yes
LIB_DEPENDS+=	libexpat.so:textproc/expat2
NGINX_DAV_EXT_VERSION=	0.0.3
GH_ACCOUNT+=	arut:dav_ext
GH_PROJECT+=	nginx-dav-ext-module:dav_ext
GH_TAGNAME+=	v${NGINX_DAV_EXT_VERSION}:dav_ext
CONFIGURE_ARGS+=--add-module=${WRKSRC_dav_ext}
.endif

.if ${PORT_OPTIONS:MHTTP_EVAL}
NGINX_EVAL_VERSION=	342c812
GH_ACCOUNT+=	openresty:eval
GH_PROJECT+=	nginx-eval-module:eval
GH_TAGNAME+=	${NGINX_EVAL_VERSION}:eval
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_eval}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_eval}
.endif
.endif

.if ${PORT_OPTIONS:MHTTP_FANCYINDEX}
NGINX_FANCYINDEX_VERSION=	0.3.6
GH_ACCOUNT+=	aperezdc:fancyindex
GH_PROJECT+=	ngx-fancyindex:fancyindex
GH_TAGNAME+=	v${NGINX_FANCYINDEX_VERSION}:fancyindex
CONFIGURE_ARGS+=--add-module=${WRKSRC_fancyindex}
.endif

.if ${PORT_OPTIONS:MHTTP_FOOTER}
NGINX_FOOTER_VERSION=	1.2.2
GH_ACCOUNT+=	alibaba:footer
GH_PROJECT+=	nginx-http-footer-filter:footer
GH_TAGNAME+=	${NGINX_FOOTER_VERSION}:footer
CONFIGURE_ARGS+=--add-module=${WRKSRC_footer}
.endif

.if ${PORT_OPTIONS:MHTTP_GEOIP2}
# WWW: https://github.com/leev/ngx_http_geoip2_module
NGINX_HTTP_GEOIP2_VERSION=	2.0
GH_ACCOUNT+=	leev:geoip2
GH_PROJECT+=	ngx_http_geoip2_module:geoip2
GH_TAGNAME+=	${NGINX_HTTP_GEOIP2_VERSION}:geoip2
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_geoip2}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_geoip2}
.endif
LIB_DEPENDS+=	libmaxminddb.so:net/libmaxminddb
.endif

.if ${PORT_OPTIONS:MHTTP_FLV}
CONFIGURE_ARGS+=--with-http_flv_module
.endif

.if ${PORT_OPTIONS:MHTTP_JSON_STATUS}
NGINX_JSON_STATUS_VERSION=	1d2f303
GH_ACCOUNT+=	nginx-modules:json_status
GH_PROJECT+=	ngx_http_json_status_module:json_status
GH_TAGNAME+=	${NGINX_JSON_STATUS_VERSION}:json_status
CONFIGURE_ARGS+=--add-module=${WRKSRC_json_status}
.endif

.if ${PORT_OPTIONS:MHTTP_GEOIP}
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--with-http_geoip_module=dynamic
.else
CONFIGURE_ARGS+=--with-http_geoip_module
.endif
LIB_DEPENDS+=	libGeoIP.so:net/GeoIP
.endif

.if ${PORT_OPTIONS:MHTTP_GZIP_STATIC}
CONFIGURE_ARGS+=--with-http_gzip_static_module
.endif

.if ${PORT_OPTIONS:MHTTP_GUNZIP_FILTER}
CONFIGURE_ARGS+=--with-http_gunzip_module
.endif

.if ${PORT_OPTIONS:MHTTP_IMAGE_FILTER}
LIB_DEPENDS+=	libgd.so:graphics/gd
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--with-http_image_filter_module=dynamic
.else
CONFIGURE_ARGS+=--with-http_image_filter_module
.endif
.endif

.if ${PORT_OPTIONS:MHTTP_MP4}
CONFIGURE_ARGS+=--with-http_mp4_module
.endif

.if ${PORT_OPTIONS:MHTTP_MOGILEFS}
NGINX_MOGILEFS_VERSION=	1.0.4
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:mogilefs
DISTFILES+=	nginx_mogilefs_module-${NGINX_MOGILEFS_VERSION}.tar.gz:mogilefs
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mogilefs_module-${NGINX_MOGILEFS_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_mogilefs_module.c
.endif

.if ${PORT_OPTIONS:MHTTP_MP4_H264}
NGINX_H264_VERSION=	2.2.7
MASTER_SITES+=	http://h264.code-shop.com/download/:mp4streaming
DISTFILES+=	nginx_mod_h264_streaming-${NGINX_H264_VERSION}.tar.gz:mp4streaming
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mod_h264_streaming-${NGINX_H264_VERSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_streaming_module.c
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
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--with-http_perl_module=dynamic
.else
CONFIGURE_ARGS+=--with-http_perl_module
.endif
USES+=		perl5
.endif

.if ${PORT_OPTIONS:MHTTP_PUSH}
GIT_PUSH_VERSION=	0.99.16
GH_ACCOUNT+=	slact:push
GH_PROJECT+=	nchan:push
GH_TAGNAME+=	v${GIT_PUSH_VERSION}:push
CONFIGURE_ARGS+=--add-module=${WRKSRC_push}
.endif

.if ${PORT_OPTIONS:MHTTP_PUSH_STREAM}
NGINX_PUSH_STREAM_VERSION=	0.5.1
GH_ACCOUNT+=	wandenberg:pushstream
GH_PROJECT+=	nginx-push-stream-module:pushstream
GH_TAGNAME+=	${NGINX_PUSH_STREAM_VERSION}:pushstream
CONFIGURE_ARGS+=--add-module=${WRKSRC_pushstream}
.endif

.if ${PORT_OPTIONS:MHTTP_RANDOM_INDEX}
CONFIGURE_ARGS+=--with-http_random_index_module
.endif

.if ${PORT_OPTIONS:MHTTP_REALIP}
CONFIGURE_ARGS+=--with-http_realip_module
.endif

.if ${PORT_OPTIONS:MHTTP_REDIS}
NGINX_REDIS_VERSION=	0.3.8
MASTER_SITES+=	LOCAL/osa:redis
DISTFILES+=	ngx_http_redis-${NGINX_REDIS_VERSION}.tar.gz:redis
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKDIR}/ngx_http_redis-${NGINX_REDIS_VERSION}
.else
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_redis-${NGINX_REDIS_VERSION}
.endif
.endif

.if ${PORT_OPTIONS:MHTTP_RESPONSE}
NGINX_RESPONSE_VERSION=	0.3
MASTER_SITES+=	http://catap.ru/downloads/nginx/:response
DISTFILES+=	ngx_http_response-${NGINX_RESPONSE_VERSION}.tar.gz:response
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_response-${NGINX_RESPONSE_VERSION}
.endif

.if ${PORT_OPTIONS:MHTTP_SUBS_FILTER}
NGINX_HTTP_SUBS_FILTER_VERSION=	0.6.4
GH_ACCOUNT+=	yaoweibin:subs_filter
GH_PROJECT+=	ngx_http_substitutions_filter_module:subs_filter
GH_TAGNAME+=	v${NGINX_HTTP_SUBS_FILTER_VERSION}:subs_filter
CONFIGURE_ARGS+=--add-module=${WRKSRC_subs_filter}
.endif

.if ${PORT_OPTIONS:MHTTP_TARANTOOL}
LIB_DEPENDS+=	libmsgpuck.so:devel/msgpuck \
		libyajl.so:devel/yajl
GH_ACCOUNT+=	tarantool:nginx_tarantool
GH_PROJECT+=	nginx_upstream_module:nginx_tarantool
GH_TAGNAME+=	1278ee5:nginx_tarantool
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_nginx_tarantool}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_nginx_tarantool}
.endif
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_tarantool-config
.endif

.if ${PORT_OPTIONS:MHTTP_SECURE_LINK}
CONFIGURE_ARGS+=--with-http_secure_link_module
.endif

.if ${PORT_OPTIONS:MHTTP_SLICE}
CONFIGURE_ARGS+=--with-http_slice_module
.endif

.if ${PORT_OPTIONS:MHTTP_STATUS}
CONFIGURE_ARGS+=--with-http_stub_status_module
.endif

.if ${PORT_OPTIONS:MHTTP_SUB}
CONFIGURE_ARGS+=--with-http_sub_module
.endif

.if ${PORT_OPTIONS:MHTTP_UPLOAD}
GIT_UPLOAD_VERSION=	aba1e3f34c
GH_ACCOUNT+=	vkholodkov:upload
GH_PROJECT+=	nginx-upload-module:upload
GH_TAGNAME+=	${GIT_UPLOAD_VERSION}:upload
CONFIGURE_ARGS+=--add-module=${WRKSRC_upload}
IGNORE=	HTTP_UPLOAD: a patch requires
.endif

.if ${PORT_OPTIONS:MHTTP_UPLOAD_PROGRESS}
NGINX_UPLOADPROGRESS_VERSION=	0.9.0
GH_ACCOUNT+=	masterzen:uploadprogress
GH_PROJECT+=	nginx-upload-progress-module:uploadprogress
GH_TAGNAME+=	v${NGINX_UPLOADPROGRESS_VERSION}:uploadprogress
CONFIGURE_ARGS+=--add-module=${WRKSRC_uploadprogress}
.endif

.if !empty(PORT_OPTIONS:MHTTP_UPSTREAM_CHECK)
# WWW: https://github.com/yaoweibin/nginx_upstream_check_module
NGINX_UPSTREAM_CHECK_VERSION=	10782ea
GH_ACCOUNT+=	yaoweibin:upstreamcheck
GH_PROJECT+=	nginx_upstream_check_module:upstreamcheck
GH_TAGNAME+=	${NGINX_UPSTREAM_CHECK_VERSION}:upstreamcheck
CONFIGURE_ARGS+=--add-module=${WRKSRC_upstreamcheck}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src-http-modules-ngx_http_upstream_hash_module.c \
		${PATCHDIR}/extra-patch-src-http-modules-ngx_http_upstream_ip_hash_module.c \
		${PATCHDIR}/extra-patch-src-http-modules-ngx_http_upstream_least_conn_module.c \
		${PATCHDIR}/extra-patch-src-http-ngx_http_upstream_round_robin.c \
		${PATCHDIR}/extra-patch-src-http-ngx_http_upstream_round_robin.h
.endif

.if !empty(PORT_OPTIONS:MHTTP_UPSTREAM_FAIR)
NGINX_UPSTREAM_FAIR_VERSION=	20090923
MASTER_SITES+=	LOCAL/osa:upstreamfair
DISTFILES+=	nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}.tar.gz:upstreamfair
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}
.if !empty(PORT_OPTIONS:MHTTP_UPSTREAM_CHECK)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_upstream_fair_module.c
IGNORE=	HTTP_UPSTREAM_FAIR: a patch requires
.endif
.endif

.if ${PORT_OPTIONS:MHTTP_UPSTREAM_STICKY}
USE_HTTP_SSL=	yes
NGINX_UPSTREAM_STICKY_VERSION=	08a395c66e42
MASTER_SITES+=	https://bitbucket.org/nginx-goodies/nginx-sticky-module-ng/get/:upstreamsticky
DISTFILES+=	${NGINX_UPSTREAM_STICKY_VERSION}.tar.gz:upstreamsticky
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-goodies-nginx-sticky-module-ng-${NGINX_UPSTREAM_STICKY_VERSION}/
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_sticky_misc.c
.endif

.if ${PORT_OPTIONS:MHTTP_VIDEO_THUMBEXTRACTOR}
NGINX_VIDEO_THUMBEXTRACTOR_VERSION=	0.7.0
LIB_DEPENDS+= 	libavformat.so:multimedia/ffmpeg \
		libavcodec.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg
USES+=		jpeg
GH_ACCOUNT+=	wandenberg:vte
GH_PROJECT+=	nginx-video-thumbextractor-module:vte
GH_TAGNAME+=	${NGINX_VIDEO_THUMBEXTRACTOR_VERSION}:vte
CONFIGURE_ARGS+=--add-module=${WRKSRC_vte}
.endif

.if ${PORT_OPTIONS:MHTTP_XSLT}
USE_GNOME+=	libxml2 libxslt
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--with-http_xslt_module=dynamic
.else
CONFIGURE_ARGS+=--with-http_xslt_module
.endif
.endif

.if ${PORT_OPTIONS:MHTTP_ZIP}
NGINX_ZIP_VERSION=	ca0b345
GH_ACCOUNT+=	evanmiller:mod_zip
GH_PROJECT+=	mod_zip:mod_zip
GH_TAGNAME+=	${NGINX_ZIP_VERSION}:mod_zip
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mod_zip-${NGINX_ZIP_VERSION}
.endif

.if ${PORT_OPTIONS:MDRIZZLE}
LIB_DEPENDS+=	libdrizzle.so:databases/libdrizzle
NGINX_DRIZZLE_VERSION=	0.1.9
GH_ACCOUNT+=	openresty:drizzle
GH_PROJECT+=	drizzle-nginx-module:drizzle
GH_TAGNAME+=	v${NGINX_DRIZZLE_VERSION}:drizzle
CONFIGURE_ARGS+=--add-module=${WRKSRC_drizzle}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-openresty-drizzle-nginx-module-config \
		${PATCHDIR}/extra-patch-ngx_http_drizzle_upstream.c
.endif

.if ${PORT_OPTIONS:MDYNAMIC_UPSTREAM}
NGINX_DYNAMIC_UPSTREAM_VERSION=	0.1.3
GH_ACCOUNT+=	cubicdaiya:dyn_upstream
GH_PROJECT+=	ngx_dynamic_upstream:dyn_upstream
GH_TAGNAME+=	v${NGINX_DYNAMIC_UPSTREAM_VERSION}:dyn_upstream
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_dyn_upstream}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_dyn_upstream}
.endif
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_inet_slab.c
.endif

.if ${PORT_OPTIONS:MARRAYVAR} || ${PORT_OPTIONS:MENCRYPTSESSION} || ${PORT_OPTIONS:MFORMINPUT} || ${PORT_OPTIONS:MICONV} || ${PORT_OPTIONS:MLUA} || ${PORT_OPTIONS:MSET_MISC}
NGINX_DEVEL_KIT_VERSION=	0.3.0
GH_ACCOUNT+=	simpl:devel_kit
GH_PROJECT+=	ngx_devel_kit:devel_kit
GH_TAGNAME+=	v${NGINX_DEVEL_KIT_VERSION}:devel_kit
CONFIGURE_ARGS+=--add-module=${WRKSRC_devel_kit}
.endif

.if ${PORT_OPTIONS:MENCRYPTSESSION}
NGINX_ENCRYPTSESSION_VERSION=	0.05
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

.if ${PORT_OPTIONS:MLUA}
LIB_DEPENDS+=	libluajit-5.1.so:lang/luajit
CONFIGURE_ENV+=	"LUAJIT_INC=${LOCALBASE}/include/luajit-2.0"
CONFIGURE_ENV+=	"LUAJIT_LIB=${LOCALBASE}/lib"
NGINX_LUA_VERSION=	0.10.6
GH_ACCOUNT+=	openresty:lua
GH_PROJECT+=	lua-nginx-module:lua
GH_TAGNAME+=	v${NGINX_LUA_VERSION}:lua
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_lua}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_lua}
.endif
.endif

.if ${PORT_OPTIONS:MMEMC}
NGINX_MEMC_VERSION=	0.17
GH_ACCOUNT+=	openresty:memc
GH_PROJECT+=	memc-nginx-module:memc
GH_TAGNAME+=	v${NGINX_MEMC_VERSION}:memc
CONFIGURE_ARGS+=--add-module=${WRKSRC_memc}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_memc_util.c
.endif

.if ${PORT_OPTIONS:MMODSECURITY}
NGINX_MODSECURITY_VERSION=	2.9.1
LIB_DEPENDS+=	libapr-1.so:devel/apr1 \
		libcurl.so:ftp/curl \
		libluajit-5.1.so:lang/luajit \
		libpcre.so:devel/pcre \
		libyajl.so:devel/yajl
USE_APACHE=	22+
USE_GNOME+=	libxml2
USES+=		pkgconfig shebangfix
MASTER_SITES+=	http://www.modsecurity.org/tarball/${NGINX_MODSECURITY_VERSION:S/RC/rc/}/:modsecurity
DISTFILES+=	modsecurity-${NGINX_MODSECURITY_VERSION}.tar.gz:modsecurity
CONFIGURE_ARGS+=--add-module=${WRKDIR}/modsecurity-${NGINX_MODSECURITY_VERSION}/nginx/modsecurity
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-nginx-modsecurity-configure
.endif

.if ${PORT_OPTIONS:MNAXSI}
NGINX_NAXSI_VERSION=	0.54
GH_ACCOUNT+=	nbs-system:naxsi
GH_PROJECT+=	naxsi:naxsi
GH_TAGNAME+=	${NGINX_NAXSI_VERSION}:naxsi
CONFIGURE_ARGS+=--add-module=${WRKDIR}/naxsi-${NGINX_NAXSI_VERSION}/naxsi_src
.endif

.if ${PORT_OPTIONS:MHTTP_REWRITE} || defined(USE_HTTP_REWRITE)
LIB_DEPENDS+=	libpcre.so:devel/pcre
CONFIGURE_ARGS+=--with-pcre
.else
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nopcre
CONFIGURE_ARGS+=--without-http_rewrite_module \
		--without-pcre
.endif

.if ${PORT_OPTIONS:MPASSENGER}
PASSENGER_VERSION=	5.0.30
MASTER_SITES+=	http://s3.amazonaws.com/phusion-passenger/releases/:passenger
DISTFILES+=	passenger-${PASSENGER_VERSION}.tar.gz:passenger
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKDIR}/passenger-${PASSENGER_VERSION}/src/nginx_module
.else
CONFIGURE_ARGS+=--add-module=${WRKDIR}/passenger-${PASSENGER_VERSION}/src/nginx_module
.endif
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-passenger-build-nginx.rb
.if empty(PORT_OPTIONS:MDEBUG)
CONFIGURE_ENV+=	OPTIMIZE="yes"
CFLAGS+=	-DNDEBUG
.endif
.endif

.if ${PORT_OPTIONS:MPOSTGRES}
USES+=	pgsql
NGINX_POSTGRES_VERSION=		1.0rc7
GH_ACCOUNT+=	FRiCKLE:postgres
GH_PROJECT+=	ngx_postgres:postgres
GH_TAGNAME+=	${NGINX_POSTGRES_VERSION}:postgres
CONFIGURE_ARGS+=--add-module=${WRKSRC_postgres}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_postgres-config \
		${PATCHDIR}/extra-patch-ngx_postgres_module.c
.endif

.if ${PORT_OPTIONS:MRDS_CSV}
NGINX_RDS_CSV_VERSION=	0.07
GH_ACCOUNT+=	openresty:rdscsv
GH_PROJECT+=	rds-csv-nginx-module:rdscsv
GH_TAGNAME+=	v${NGINX_RDS_CSV_VERSION}:rdscsv
CONFIGURE_ARGS+=--add-module=${WRKSRC_rdscsv}
.endif

.if ${PORT_OPTIONS:MRDS_JSON}
NGINX_RDS_JSON_VERSION=	0.14
GH_ACCOUNT+=	openresty:rdsjson
GH_PROJECT+=	rds-json-nginx-module:rdsjson
GH_TAGNAME+=	v${NGINX_RDS_JSON_VERSION}:rdsjson
CONFIGURE_ARGS+=--add-module=${WRKSRC_rdsjson}
.endif

.if ${PORT_OPTIONS:MREDIS2}
NGINX_REDIS2_VERSION=	0.12
GH_ACCOUNT+=	openresty:redis2
GH_PROJECT+=	redis2-nginx-module:redis2
GH_TAGNAME+=	v${NGINX_REDIS2_VERSION}:redis2
CONFIGURE_ARGS+=--add-module=${WRKSRC_redis2}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_redis2_util.c
.endif

.if ${PORT_OPTIONS:MRTMP}
NGINX_RTMP_VERSION=	1.1.8
GH_ACCOUNT+=	arut:rtmp
GH_PROJECT+=	nginx-rtmp-module:rtmp
GH_TAGNAME+=	v${NGINX_RTMP_VERSION}:rtmp
CONFIGURE_ARGS+=--add-module=${WRKSRC_rtmp}
.endif

.if ${PORT_OPTIONS:MSET_MISC}
NGINX_SET_MISC_VERSION=	f808ef4
GH_ACCOUNT+=	openresty:setmisc
GH_PROJECT+=	set-misc-nginx-module:setmisc
GH_TAGNAME+=	${NGINX_SET_MISC_VERSION}:setmisc
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_setmisc}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_setmisc}
.endif
.endif

.if ${PORT_OPTIONS:MSFLOW}
NGINX_SFLOW_VERSION=	543c72a
GH_ACCOUNT+=	sflow:sflow
GH_PROJECT+=	nginx-sflow-module:sflow
GH_TAGNAME+=	${NGINX_SFLOW_VERSION}:sflow
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ngx_http_sflow_config.c \
		${PATCHDIR}/extra-patch-ngx_http_sflow_config.h \
		${PATCHDIR}/extra-patch-ngx_http_sflow_module.c
.endif

.if ${PORT_OPTIONS:MSHIBBOLETH}
GIT_SHIBBOLETH_VERSION=	4f1119b
GH_ACCOUNT+=	nginx-shib:shib
GH_PROJECT+=	nginx-http-shibboleth:shib
GH_TAGNAME+=	${GIT_SHIBBOLETH_VERSION}:shib
CONFIGURE_ARGS+=--add-module=${WRKSRC_shib}
.endif

.if ${PORT_OPTIONS:MSLOWFS_CACHE}
NGINX_SLOWFS_CACHE_VERSION=	1.10
MASTER_SITES+=	http://labs.frickle.com/files/:slowfs_cache
DISTFILES+=	ngx_slowfs_cache-${NGINX_SLOWFS_CACHE_VERSION}.tar.gz:slowfs_cache
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_slowfs_cache-${NGINX_SLOWFS_CACHE_VERSION}
.endif

.if ${PORT_OPTIONS:MSMALL_LIGHT}
NGINX_SMALL_LIGHT_VERSION=	0.8.0
LIB_DEPENDS+=	${IMAGEMAGICK_LIB_DEPENDS} \
		libpcre.so:devel/pcre
GH_ACCOUNT+=	cubicdaiya:small_light
GH_PROJECT+=	ngx_small_light:small_light
GH_TAGNAME+=	v${NGINX_SMALL_LIGHT_VERSION}:small_light
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_small_light}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_small_light}
.endif
.endif

.if ${PORT_OPTIONS:MSRCACHE}
NGINX_SRCACHE_VERSION=	0.30
GH_ACCOUNT+=	openresty:srcache
GH_PROJECT+=	srcache-nginx-module:srcache
GH_TAGNAME+=	v${NGINX_SRCACHE_VERSION}:srcache
CONFIGURE_ARGS+=--add-module=${WRKSRC_srcache}
.endif

.if ${PORT_OPTIONS:MSTATSD}
NGINX_STATSD_VERSION=	b756a12
GH_ACCOUNT+=	zebrafishlabs:statsd
GH_PROJECT+=	nginx-statsd:statsd
GH_TAGNAME+=	${NGINX_STATSD_VERSION}:statsd
CONFIGURE_ARGS+=--add-module=${WRKSRC_statsd}
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
GH_ACCOUNT+=	gabor:xrid
GH_PROJECT+=	nginx-x-rid-header:xrid
GH_TAGNAME+=	${GIT_XRID_VERSION}:xrid
CONFIGURE_ARGS+=--add-module=${WRKSRC_xrid}
.endif

.if ${PORT_OPTIONS:MXSS}
NGINX_XSS_VERSION=	0.05
GH_ACCOUNT+=	openresty:xss
GH_PROJECT+=	xss-nginx-module:xss
GH_TAGNAME+=	v${NGINX_XSS_VERSION}:xss
CONFIGURE_ARGS+=--add-module=${WRKSRC_xss}
.endif

.if ${PORT_OPTIONS:MHTTPV2}
NGINX_OPENSSL=	yes
USE_HTTP_SSL=	yes
CONFIGURE_ARGS+=--with-http_v2_module
.endif

.if ${PORT_OPTIONS:MNJS}
GH_ACCOUNT+=	nginx:njs
GH_PROJECT+=	njs:njs
GH_TAGNAME+=	8c01042:njs
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_njs}/nginx
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_njs}/nginx
.endif
.endif

.if ${PORT_OPTIONS:MSTREAM}
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--with-stream=dynamic
.else
CONFIGURE_ARGS+=--with-stream
.endif
.if ${PORT_OPTIONS:MSTREAM_SSL}
NGINX_OPENSSL=	yes
USE_HTTP_SSL=	yes
CONFIGURE_ARGS+=--with-stream_ssl_module
.if ${PORT_OPTIONS:MSTREAM_SSL_PREREAD}
CONFIGURE_ARGS+=--with-stream_ssl_preread_module
.endif
.endif
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--with-threads
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
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--with-mail=dynamic
.else
CONFIGURE_ARGS+=--with-mail
.endif
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
NGINX_ARRAYVAR_VERSION=	0.05
GH_ACCOUNT+=	openresty:arrayvar
GH_PROJECT+=	array-var-nginx-module:arrayvar
GH_TAGNAME+=	v${NGINX_ARRAYVAR_VERSION}:arrayvar
CONFIGURE_ARGS+=--add-module=${WRKSRC_arrayvar}
.endif

.if ${PORT_OPTIONS:MBROTLI}
NGINX_BROTLI_VERSION=	ada972b
LIB_DEPENDS+=	libbrotlidec.so:devel/libbrotli \
		libbrotlienc.so:devel/libbrotli
GH_ACCOUNT+=	google:brotli
GH_PROJECT+=	ngx_brotli:brotli
GH_TAGNAME+=	${NGINX_BROTLI_VERSION}:brotli
.if !empty(PORT_OPTIONS:MDSO)
CONFIGURE_ARGS+=--add-dynamic-module=${WRKSRC_brotli}
.else
CONFIGURE_ARGS+=--add-module=${WRKSRC_brotli}
.endif
.endif

.if ${PORT_OPTIONS:MFORMINPUT}
NGINX_FORMINPUT_VERSION=	0.12
GH_ACCOUNT+=	calio:forminput
GH_PROJECT+=	form-input-nginx-module:forminput
GH_TAGNAME+=	v${NGINX_FORMINPUT_VERSION}:forminput
CONFIGURE_ARGS+=--add-module=${WRKSRC_forminput}
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
NGINX_ICONV_VERSION=	0.14
GH_ACCOUNT+=	calio:iconv
GH_PROJECT+=	iconv-nginx-module:iconv
GH_TAGNAME+=	v${NGINX_ICONV_VERSION}:iconv
CONFIGURE_ARGS+=--add-module=${WRKSRC_iconv}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-calio-iconv-nginx-module-config
.endif

PLIST_SUB+=	NGINX_TMPDIR=${NGINX_TMPDIR} NGINX_LOGDIR=${NGINX_LOGDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

USERS?=	${WWWOWN}
GROUPS?=${WWWGRP}

.if defined(NGINX_OPENSSL)
USE_OPENSSL=	yes
.if ${OSVERSION} < 1100000
WITH_OPENSSL_PORT=yes
.endif
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
	@${RMDIR} ${WRKSRC_gridfs}/mongo-c-driver/
	@${MV} ${WRKSRC_mongo_c} ${WRKSRC_gridfs}/mongo-c-driver
.endif

post-patch:
	@${REINPLACE_CMD} 's!%%HTTP_PORT%%!${HTTP_PORT}!; \
		s!%%PREFIX%%!${PREFIX}!; \
		s!%%NGINX_ERRORLOG%%!${NGINX_ERRORLOG}!' \
		${WRKSRC}/conf/nginx.conf
.if ${PORT_OPTIONS:MHTTP_ACCESSKEY}
	@${REINPLACE_CMD} \
		'128s!NGX_OK!NGX_DECLINED!' \
		${WRKDIR}/nginx-accesskey-${NGINX_ACCESSKEY_VERSION}/ngx_http_accesskey_module.c
.endif
.if ${PORT_OPTIONS:MHTTP_AUTH_KRB5}
	@${REINPLACE_CMD} \
		's!%%GSSAPILIBS%%!${GSSAPILIBS}!' \
		${WRKSRC_auth_krb5}/config
.endif
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
		${WRKSRC_drizzle}/config
.endif
.if ${PORT_OPTIONS:MFASTDFS}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${PREFIX}!g; \
		s!%%LOCALBASE%%!${LOCALBASE}!g' \
		${WRKSRC_fastdfs}/src/config
.endif
# Respect CFLAGS by remove needless --std=c99 flag
.if ${PORT_OPTIONS:MGRIDFS}
	@${REINPLACE_CMD} \
		's!--std=c99!-DMONGO_HAVE_STDINT!' \
		${WRKSRC_gridfs}/config
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
.endif
.if ${PORT_OPTIONS:MPOSTGRES}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKSRC_postgres}/config
.endif
.if ${PORT_OPTIONS:MSFLOW}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKDIR}/nginx-sflow-module-${NGINX_SFLOW_VERSION}/ngx_http_sflow_config.h
.endif
.if ${PORT_OPTIONS:MSTATSD}
	@${REINPLACE_CMD} \
		's!ngx_udp_connection_t!ngx_resolver_connection_t!g; \
		s!uc->connection!uc->udp!g; \
		s!e->udp_connection->connection!e->udp_connection->udp!g' \
		${WRKSRC_statsd}/ngx_http_statsd.c
.endif
.if ${PORT_OPTIONS:MUDPLOG}
	@${REINPLACE_CMD} \
		's!ngx_udp_connection_t!ngx_resolver_connection_t!g; \
		s!uc->connection!uc->udp!g; \
		s!e->udp_connection->connection!e->udp_connection->udp!g' \
		${WRKDIR}/nginx_udplog_module-${NGINX_UDPLOG_VERSION}/ngx_http_udplog_module.c
.endif
.if ${PORT_OPTIONS:MICONV}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKSRC_iconv}/config
.endif
.if ${PORT_OPTIONS:MMODSECURITY}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKDIR}/modsecurity-${NGINX_MODSECURITY_VERSION}/configure
.endif
.if ${PORT_OPTIONS:MHTTP_TARANTOOL}
	@${REINPLACE_CMD} \
		's!%%PREFIX%%!${LOCALBASE}!g' \
		${WRKSRC_nginx_tarantool}/config
.endif

pre-configure:
.if ${PORT_OPTIONS:MMODSECURITY}
	( cd ${WRKDIR}/modsecurity-${NGINX_MODSECURITY_VERSION} && \
		CC="${CC}" ${CONFIGURE_CMD} --enable-standalone-module \
		--with-pcre=${LOCALBASE} --with-yajl=${LOCALBASE} \
		--with-curl=${LOCALBASE} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} )
.endif
.if ${PORT_OPTIONS:MSMALL_LIGHT}
	( cd ${WRKSRC_small_light} && ./setup )
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
.if !empty(PORT_OPTIONS:MDSO)
	${MKDIR} ${STAGEDIR}${MODULESDIR}
.endif
	${MKDIR} ${STAGEDIR}${NGINX_TMPDIR}
	${MKDIR} ${STAGEDIR}${NGINX_LOGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${STAGEDIR}${PREFIX}/sbin
.for i in koi-utf koi-win win-utf
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${STAGEDIR}${ETCDIR}
.endfor
.for i in fastcgi_params mime.types scgi_params uwsgi_params
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

.if ${PORT_OPTIONS:MFASTDFS}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fdfs
	${INSTALL_DATA} ${WRKSRC_fastdfs}/src/mod_fastdfs.conf ${STAGEDIR}${PREFIX}/etc/fdfs/mod_fastdfs.conf.sample
.endif

# Install dynamic modules
.if !empty(PORT_OPTIONS:MDSO)
	(cd ${WRKSRC}/objs/ && ${FIND} . -name '*.so' -maxdepth 1 -type f \
		-exec ${INSTALL_PROGRAM} {} ${STAGEDIR}${MODULESDIR} \;)
.endif

.if ${PORT_OPTIONS:MNAXSI}
	${INSTALL_DATA} \
	${WRKDIR}/naxsi-${NGINX_NAXSI_VERSION}/naxsi_config/naxsi_core.rules \
	${STAGEDIR}${ETCDIR}
.endif

post-install:
.if !empty(PORT_OPTIONS:MHTTP) && !empty(PORT_OPTIONS:MHTTP_PERL)
	${ECHO_CMD} ${SITE_ARCH_REL}/auto/nginx/nginx.so >> ${TMPPLIST}
	${ECHO_CMD} ${SITE_ARCH_REL}/nginx.pm >> ${TMPPLIST}
.endif
	${INSTALL_MAN} ${WRKSRC}/objs/nginx.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.if ${PORT_OPTIONS:MNAXSI}
	${ECHO_CMD} etc/nginx/naxsi_core.rules >> ${TMPPLIST}
.endif

.if ${PORT_OPTIONS:MFASTDFS}
	${ECHO_CMD} @sample etc/fdfs/mod_fastdfs.conf.sample >> ${TMPPLIST}
.endif

# Add dynamic modules to the plist
.if !empty(PORT_OPTIONS:MDSO)
	(cd ${STAGEDIR}${PREFIX} && ${FIND} ${MODULESDIR:S|${PREFIX}/||} \
		! -type d >>${TMPPLIST})
# Update nginx.conf-dist with a list of staged dynamic modules
	(cd ${STAGEDIR} && \
		${FIND} ${MODULESDIR:S|^/||} -type f -name '*.so' \
			-exec ${ECHO_CMD} "load_module /{};" \; \
			>>${STAGEDIR}${ETCDIR}/nginx.conf-dist)
.endif
	${CAT} ${WRKSRC}/conf/nginx.conf \
		>>${STAGEDIR}${ETCDIR}/nginx.conf-dist

.include <bsd.port.mk>
