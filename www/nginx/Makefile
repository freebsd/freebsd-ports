# New ports collection makefile for:	nginx
# Date created:				11 Oct 2004
# Whom:					osa
#
# $FreeBSD$
#

PORTNAME=	nginx
PORTVERSION=	0.7.61
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://sysoev.ru/nginx/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	osa
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Robust and small WWW server

OPTIONS=	DEBUG			"Enable nginx debugging" off \
		IPV6			"Enable IPv6" off \
		GOOGLE_PERFTOOLS	"Enable google perftools module" off \
		HTTP_MODULE		"Enable HTTP module" on \
		HTTP_ADDITION_MODULE	"Enable http_addition module" off \
		HTTP_CACHE_MODULE	"Enable http_cache module" on \
		HTTP_DAV_MODULE		"Enable http_webdav module" off \
		HTTP_FLV_MODULE		"Enable http_flv module" off \
		HTTP_GZIP_STATIC_MODULE "Enable http_gzip_static module" off \
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
		HTTP_ACCESSKEY_MODULE	"3rd party http_accesskey module" off \
		HTTP_EVAL_MODULE	"3rd party eval module" off \
		HTTP_FANCYINDEX_MODULE	"3rd party http_fancyindex module" off \
		HTTP_MOGILEFS_MODULE	"3rd party mogilefs module" off \
		HTTP_RESPONSE_MODULE	"3rd party http_response module" off \
		HTTP_UPLOAD_MODULE	"3rd party upload module" off \
		HTTP_UPLOAD_PROGRESS	"3rd party upload_progress module" off \
		HTTP_UPSTREAM_FAIR	"3rd party upstream fair module" off \
		HTTP_UPSTREAM_KEEPALIVE "3rd party upstream keepalive module" off \
		HTTP_ZIP_MODULE		"3rd party http_zip module" off \
		PASSENGER_MODULE	"3rd party passenger module" off

WANT_GNOME=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if defined(WITH_PASSENGER_MODULE)
USE_RUBY=	yes
USE_RAKE=	yes
.endif

.include <bsd.port.pre.mk>

NGINX_VARDIR?=	/var
NGINX_LOGDIR?=	${NGINX_VARDIR}/log
NGINX_RUNDIR?=	${NGINX_VARDIR}/run
NGINX_TMPDIR?=	${NGINX_VARDIR}/tmp/nginx
HTTP_PORT?=	80

CONFLICTS?=	nginx-devel-0.*
USE_RC_SUBR=	nginx.sh
SUB_LIST+=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX} WWWOWN=${WWWOWN}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${ETCDIR} \
		--with-cc-opt="-I ${LOCALBASE}/include" \
		--with-ld-opt="-L ${LOCALBASE}/lib" \
		--conf-path=${ETCDIR}/nginx.conf \
		--sbin-path=${PREFIX}/sbin/nginx \
		--pid-path=${NGINX_RUNDIR}/nginx.pid \
		--error-log-path=${NGINX_LOGDIR}/nginx-error.log \
		--user=${WWWOWN} --group=${WWWGRP}

.if defined(WITHOUT_HTTP_MODULE) && defined(WITHOUT_MAIL_MODULE)
IGNORE=		requires at least HTTP_MODULE or MAIL_MODULE to \
		be defined.  Please 'make config' again
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-g -DNGX_DEBUG_MALLOC
CONFIGURE_ARGS+=--with-debug
STRIP=		#do not strip if nginx with debug information
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
		--http-log-path=${NGINX_LOGDIR}/nginx-access.log

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

.if defined(WITHOUT_HTTP_CACHE_MODULE)
CONFIGURE_ARGS+=--without-http-cache
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
NGINX_FANCYINDEX_MODULE_VERSION=	0.1b5
MASTER_SITES+=	http://furi-ku.org/nginx/fancyindex/:fancyindex
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:fancyindex/}
MASTER_SITE_SUBDIR+=	osa/:fancyindex
DISTFILES+=	nginx-fancyindex-${NGINX_FANCYINDEX_MODULE_VERSION:S/b/_beta/}.tar.bz2:fancyindex
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx-fancyindex-${NGINX_FANCYINDEX_MODULE_VERSION:S/b/_beta/}
.endif

.if defined(WITH_HTTP_FLV_MODULE)
CONFIGURE_ARGS+=--with-http_flv_module
.endif

.if defined(WITH_HTTP_GZIP_STATIC_MODULE)
CONFIGURE_ARGS+=--with-http_gzip_static_module
.endif

.if defined(WITH_HTTP_MOGILEFS_MODULE)
NGINX_MOGILEFS_MODULE_VERSION=	1.0.1
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:mogilefs
DISTFILES+=	nginx_mogilefs_module-${NGINX_MOGILEFS_MODULE_VERSION}.tar.gz:mogilefs
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_mogilefs_module-${NGINX_MOGILEFS_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_PERL_MODULE)
CATEGORIES+=	perl5
CONFIGURE_ARGS+=--with-http_perl_module
USE_PERL5=	yes
.endif

.if defined(WITH_HTTP_RANDOM_INDEX_MODULE)
CONFIGURE_ARGS+=--with-http_random_index_module
.endif

.if defined(WITH_HTTP_REALIP_MODULE)
CONFIGURE_ARGS+=--with-http_realip_module
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
NGINX_UPLOAD_MODULE_VERSION=	2.0.9
MASTER_SITES+=	http://www.grid.net.ru/nginx/download/:upload
DISTFILES+=	nginx_upload_module-${NGINX_UPLOAD_MODULE_VERSION}.tar.gz:upload
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upload_module-${NGINX_UPLOAD_MODULE_VERSION}
.endif

.if defined(WITH_HTTP_UPLOAD_PROGRESS)
NGINX_UPLOAD_PROGRESS_MODULE_VERSION=	0.5
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:uploadprogress/}
MASTER_SITE_SUBDIR+=	osa/:uploadprogress
DISTFILES+=	nginx_uploadprogress_module-${NGINX_UPLOAD_PROGRESS_MODULE_VERSION}.tar.gz:uploadprogress
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_uploadprogress_module
.endif

.if defined(WITH_HTTP_UPSTREAM_FAIR)
NGINX_UPSTREAM_FAIR_VERSION=	20081012
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:upstreamfair/}
MASTER_SITE_SUBDIR+=	osa/:upstreamfair
DISTFILES+=	nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}.tar.gz:upstreamfair
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}
.endif

.if defined(WITH_HTTP_UPSTREAM_KEEPALIVE)
NGINX_UPSTREAM_KEEPALIVE_VERSION=	0.1
MASTER_SITES+=	http://mdounin.ru/files/:upstream
DISTFILES+=	ngx_http_upstream_keepalive-${NGINX_UPSTREAM_KEEPALIVE_VERSION}.tar.gz:upstream
CONFIGURE_ARGS+=--add-module=${WRKDIR}/ngx_http_upstream_keepalive-${NGINX_UPSTREAM_KEEPALIVE_VERSION}
.endif

.if defined(WITH_HTTP_XSLT_MODULE)
USE_GNOME=	libxml2 libxslt
CONFIGURE_ARGS+=--with-http_xslt_module
.endif

.if defined(WITH_HTTP_ZIP_MODULE)
NGINX_ZIP_MODULE_VERSION=	1.1.4
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:zip/}
MASTER_SITE_SUBDIR+=	osa/:zip
DISTFILES+=	nginx_mod_zip-${NGINX_ZIP_MODULE_VERSION}.tar.gz:zip
CONFIGURE_ARGS+=--add-module=${WRKDIR}/mod_zip-${NGINX_ZIP_MODULE_VERSION}
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
PASSENGER_VERSION=	2.2.4
MASTER_SITES+=	RF/passenger/:passenger
DISTFILES+=	passenger-${PASSENGER_VERSION}.tar.gz:passenger
CONFIGURE_ARGS+=--add-module=${WRKDIR}/passenger-${PASSENGER_VERSION}/ext/nginx
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
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

PLIST_SUB+=	NGINX_TMPDIR=${NGINX_TMPDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

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
.if defined(WITH_HTTP_UPLOAD_PROGRESS)
	@${PATCH} ${PATCH_ARGS} < \
		${PATCHDIR}/extra-patch-ngx_http_uploadprogress_module.c
.endif
.if defined(WITH_PASSENGER_MODULE)
	@${REINPLACE_CMD} 's!g++!${CXX}!' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/Rakefile
	@${REINPLACE_CMD} '377s!-g!${CXXFLAGS}!; \
		s!-lpthread!${PTHREAD_LIBS}!g' \
		${WRKDIR}/passenger-${PASSENGER_VERSION}/lib/phusion_passenger/platform_info.rb
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
