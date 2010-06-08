# New ports collection makefile for:	nginx
# Date created:				11 Oct 2004
# Whom:					osa
#
# $FreeBSD$
#

PORTNAME=	nginx
PORTVERSION=	0.8.40
CATEGORIES=	www
MASTER_SITES=	http://sysoev.ru/nginx/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	osa
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Robust and small WWW server

LICENSE=	BSD

OPTIONS=	DEBUG			"Enable nginx debugging" off \
		DEBUGLOG		"Enable debug log (--with-debug)" off \
		FILE_AIO		"Enable file aio" off \
		IPV6			"Enable IPv6" off \
		GOOGLE_PERFTOOLS	"Enable google perftools module" off \
		HTTP_MODULE		"Enable HTTP module" on \
		HTTP_ADDITION_MODULE	"Enable http_addition module" off \
		HTTP_CACHE_MODULE	"Enable http_cache module" on \
		HTTP_DAV_MODULE		"Enable http_webdav module" off \
		HTTP_FLV_MODULE		"Enable http_flv module" off \
		HTTP_GEOIP_MODULE	"Enable http_geoip module" off \
		HTTP_GZIP_STATIC_MODULE "Enable http_gzip_static module" off \
		HTTP_IMAGE_FILTER_MODULE "Enable http_image_filter module" off \
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
		HTTP_UPLOAD_MODULE	"3rd party upload module" off \
		HTTP_UPLOAD_PROGRESS	"3rd party uploadprogress module" off \
		HTTP_UPSTREAM_FAIR	"3rd party upstream fair module" off \
		HTTP_UPSTREAM_HASH	"3rd party upstream hash module" off \
		HTTP_UPSTREAM_KEEPALIVE "3rd party upstream keepalive module" off \
		HTTP_ZIP_MODULE		"3rd party http_zip module" off \
		MEMC_MODULE		"3rd party memc (memcached) module" off \
		PASSENGER_MODULE	"3rd party passenger module" off \
		SLOWFS_CACHE_MODULE	"3rd party slowfs_cache module" off \
		SUPERVISORD_MODULE	"3rd party supervisord module" off \
		UDPLOG_MODULE		"3rd party udplog (syslog) module" off

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

CONFLICTS?=	nginx-0.7.*
USE_RC_SUBR=	nginx.sh
SUB_LIST+=	WWWOWN=${WWWOWN}

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

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=--with-ipv6
CATEGORIES+=	ipv6
.endif

.if defined(WITH_GOOGLE_PERFTOOLS)
LIB_DEPENDS+=	profiler.0:${PORTSDIR}/devel/google-perftools
CONFIGURE_ARGS+=--with-google_perftools_module
.endif

.if defined(WITH_HTTP_MODULE)
CONFIGURE_ARGS+=--http-client-body-temp-path=${NGINX_TMPDIR}/client_body_temp \
		--http-proxy-temp-path=${NGINX_TMPDIR}/proxy_temp \
		--http-fastcgi-temp-path=${NGINX_TMPDIR}/fastcgi_temp \
		--http-log-path=${NGINX_ACCESSLOG}

.if defined(WITH_HTTP_ACCEPT_LANGUAGE)
MASTER_SITES+=	ftp://inside01.p8.ru/nginx/:accept_language
DISTFILES+=	nginx_accept_language_module.tar.gz:accept_language
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_accept_language_module
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
NGINX_AUTH_PAM_MODULE_VERSION=	1.1
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
NGINX_CACHE_PURGE_MODULE_VERSION=	1.1
MASTER_SITES+=	http://labs.frickle.com/files/:cache_purge
DISTFILES+=	ngx_cache_purge-${NGINX_CACHE_PURGE_MODULE_VERSION}.tar.gz:cache_purge
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_cache_purge-${NGINX_CACHE_PURGE_MODULE_VERSION}
.endif

.if defined(WITH_ECHO_MODULE)
NGINX_ECHO_MODULE_VERSION=	0.30
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:echo/}
MASTER_SITE_SUBDIR+=	osa/:echo
DISTFILES+=	ngx_echo_module-${NGINX_ECHO_MODULE_VERSION}.tar.gz:echo
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_echo_module-${NGINX_ECHO_MODULE_VERSION}
.endif

.if defined(WITH_HEADERS_MORE_MODULE)
NGINX_HEADERS_MORE_MODULE_VERSION=	0.10
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:headers_more/}
MASTER_SITE_SUBDIR+=	osa/:headers_more
DISTFILES+=	ngx_headers_more_module-${NGINX_HEADERS_MORE_MODULE_VERSION}.tar.gz:headers_more
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_headers_more_module-${NGINX_HEADERS_MORE_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_DAV_MODULE)
CONFIGURE_ARGS+=--with-http_dav_module
.endif

.if defined(WITH_HTTP_EVAL_MODULE)
NGINX_EVAL_MODULE_VERSION=	1.0.1
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:eval
DISTFILES+=	nginx_eval_module-${NGINX_EVAL_MODULE_VERSION}.tar.gz:eval
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_eval_module-${NGINX_EVAL_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_FANCYINDEX_MODULE)
NGINX_FANCYINDEX_MODULE_VERSION=	0.2.2
MASTER_SITES+=	http://connectical.com/attachments/download/26/:fancyindex
DISTFILES+=	ngx-fancyindex-${NGINX_FANCYINDEX_MODULE_VERSION}.tar.bz2:fancyindex
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx-fancyindex-${NGINX_FANCYINDEX_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_GUNZIP_FILTER)
NGINX_GUNZIP_FILTER_MODULE_VERSION=	0.3
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

.if defined(WITH_HTTP_MOGILEFS_MODULE)
NGINX_MOGILEFS_MODULE_VERSION=	1.0.3
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:mogilefs
DISTFILES+=	nginx_mogilefs_module-${NGINX_MOGILEFS_MODULE_VERSION}.tar.gz:mogilefs
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mogilefs_module-${NGINX_MOGILEFS_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_MP4_H264_MODULE)
NGINX_H264_MODULE_VERSION=	2.2.7
MASTER_SITES+=	http://h264.code-shop.com/download/:mp4streaming
DISTFILES+=	nginx_mod_h264_streaming-${NGINX_H264_MODULE_VERSION}.tar.gz:mp4streaming
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mod_h264_streaming-${NGINX_H264_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_NOTICE_MODULE)
MASTER_SITES+=	http://xph.us/dist/nginx-notice/:notice2
DISTFILES+=	nginx-notice-2.tar.gz:notice2
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-notice-2
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
NGINX_REDIS_MODULE_VERSION=	0.3.1
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
NGINX_UPLOAD_MODULE_VERSION=	2.0.12
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:upload
DISTFILES+=	nginx_upload_module-${NGINX_UPLOAD_MODULE_VERSION}.tar.gz:upload
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upload_module-${NGINX_UPLOAD_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_UPLOAD_PROGRESS)
NGINX_UPLOADPROGRESS_MODULE_VERSION=	0.8
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
.endif

.if defined(WITH_HTTP_UPSTREAM_KEEPALIVE)
NGINX_UPSTREAM_KEEPALIVE_VERSION=	0.2
MASTER_SITES+=	http://mdounin.ru/files/:upstream
DISTFILES+=	ngx_http_upstream_keepalive-${NGINX_UPSTREAM_KEEPALIVE_VERSION}.tar.gz:upstream
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_upstream_keepalive-${NGINX_UPSTREAM_KEEPALIVE_VERSION}
.endif

.if defined(WITH_HTTP_XSLT_MODULE)
USE_GNOME=	libxml2 libxslt
CONFIGURE_ARGS+=--with-http_xslt_module
.endif

.if defined(WITH_HTTP_ZIP_MODULE)
NGINX_ZIP_MODULE_VERSION=	1.1.5
MASTER_SITES+=	${MASTER_SITE_GOOGLE_CODE}:zip
PROJECTHOST=	mod-zip
DISTFILES+=	mod_zip-${NGINX_ZIP_MODULE_VERSION}.tar.gz:zip
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mod_zip-${NGINX_ZIP_MODULE_VERSION}
.endif

.if defined(WITH_MEMC_MODULE)
NGINX_MEMC_MODULE_VERSION=	0.08
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:memc/}
MASTER_SITE_SUBDIR+=	osa/:memc
DISTFILES+=	ngx_http_memc_module-${NGINX_MEMC_MODULE_VERSION}.tar.gz:memc
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_memc_module-${NGINX_MEMC_MODULE_VERSION}
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
PASSENGER_VERSION=	2.2.14
MASTER_SITES+=	RF/passenger/:passenger
DISTFILES+=	passenger-${PASSENGER_VERSION}.tar.gz:passenger
CONFIGURE_ARGS+=--add-module=${WRKDIR}/passenger-${PASSENGER_VERSION}/ext/nginx
.endif

.if defined(WITH_SLOWFS_CACHE_MODULE)
NGINX_SLOWFS_CACHE_MODULE_VERSION=	1.5
MASTER_SITES+=	http://labs.frickle.com/files/:slowfs_cache
DISTFILES+=	ngx_slowfs_cache-${NGINX_SLOWFS_CACHE_MODULE_VERSION}.tar.gz:slowfs_cache
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_slowfs_cache-${NGINX_SLOWFS_CACHE_MODULE_VERSION}
.endif

.if defined(WITH_SUPERVISORD_MODULE)
NGINX_SUPERVISORD_MODULE_VERSION=	1.4
MASTER_SITES+=	http://labs.frickle.com/files/:supervisord
DISTFILES+=	ngx_supervisord-${NGINX_SUPERVISORD_MODULE_VERSION}.tar.gz:supervisord
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_MODULE_VERSION}
.endif

.if defined(WITH_UDPLOG_MODULE)
NGINX_UDPLOG_MODULE_VERSION=	1.0.0
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:udplog
DISTFILES+=	nginx_udplog_module-${NGINX_UDPLOG_MODULE_VERSION}.tar.gz:udplog
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_udplog_module-${NGINX_UDPLOG_MODULE_VERSION}
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

post-patch:
	@${REINPLACE_CMD} 's!%%HTTP_PORT%%!${HTTP_PORT}!; \
		s!%%PREFIX%%!${PREFIX}!' \
		${WRKSRC}/conf/nginx.conf
.if defined(WITH_HTTP_ACCESSKEY_MODULE)
	@${REINPLACE_CMD} \
		's!$$HTTP_ACCESSKEY_MODULE!ngx_http_accesskey_module!' \
		${WRKDIR}/nginx-accesskey-${NGINX_ACCESSKEY_MODULE_VERSION}/config
.endif
.if defined(WITH_HTTP_FANCYINDEX_MODULE)
	@${PATCH} ${PATCH_ARGS} < \
		${PATCHDIR}/extra-patch-ngx_http_fancyindex_module.c
.endif
.if defined(WITH_HTTP_MP4_H264_MODULE)
	@${PATCH} ${PATCH_ARGS} < \
		${PATCHDIR}/extra-patch-ngx_http_streaming_module.c
.endif
.if defined(WITH_HTTP_NOTICE_MODULE)
	@${PATCH} ${PATCH_ARGS} < \
		${PATCHDIR}/extra-patch-ngx_http_notice_module.c
.endif
.if defined(WITH_PASSENGER_MODULE)
	@${REINPLACE_CMD} 's!g++!${CXX}!' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/Rakefile
	@${REINPLACE_CMD} '377s!-g!${CXXFLAGS}!; \
		s!-lpthread!${PTHREAD_LIBS}!g' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/lib/phusion_passenger/platform_info.rb
.endif
.if defined(WITH_HTTP_UPSTREAM_HASH)
	@${PATCH} ${PATCH_ARGS} < \
		${PATCHDIR}/extra-patch-ngx_http_upstream.h
.endif
.if defined(WITH_SUPERVISORD_MODULE)
	( cd ${WRKDIR}/nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION} && \
		${PATCH} -p0 < \
			${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_MODULE_VERSION}/patches/ngx_http_upstream_fair_module.patch )
	( cd ${WRKSRC} && \
		${PATCH} -p0 < \
			${WRKDIR}/ngx_supervisord-${NGINX_SUPERVISORD_MODULE_VERSION}/patches/ngx_http_upstream_init_busy-0.8.17.patch )
.endif
.if defined(WITH_UDPLOG_MODULE)
	@${PATCH} ${PATCH_ARGS} < \
		${PATCHDIR}/extra-patch-ngx_http_udplog_module.c
.endif

do-build:
	@cd ${WRKSRC} && ${MAKE}

do-install:
	${MKDIR} ${ETCDIR} ${NGINX_TMPDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${NGINX_TMPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${PREFIX}/sbin
.for i in koi-win koi-utf win-utf fastcgi_params
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${ETCDIR}
.endfor
.for i in mime.types nginx.conf
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

.include <bsd.port.post.mk>
