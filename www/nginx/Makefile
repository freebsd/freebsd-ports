# New ports collection makefile for:	nginx
# Date created:				11 Oct 2004
# Whom:					osa
#
# $FreeBSD$
#

PORTNAME=	nginx
PORTVERSION=	0.6.37
CATEGORIES=	www
MASTER_SITES=	http://sysoev.ru/nginx/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	osa
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Robust and small WWW server

OPTIONS=	DEBUG "Enable nginx debugging" off \
		GOOGLE_PERFTOOLS "Enable google perftools module" off \
		HTTP_MODULE "Enable HTTP module" on \
		HTTP_ACCESSKEY_MODULE "Enable http_accesskey module" off \
		HTTP_ADDITION_MODULE "Enable http_addition module" off \
		HTTP_DAV_MODULE "Enable http_webdav module" off \
		HTTP_FLV_MODULE "Enable http_flv module" off \
		HTTP_GZIP_STATIC_MODULE "Enable http_gzip_static module" off \
		HTTP_PERL_MODULE "Enable http_perl module" off \
		HTTP_REALIP_MODULE "Enable http_realip module" off \
		HTTP_REWRITE_MODULE "Enable http_rewrite module" on \
		HTTP_SSL_MODULE "Enable http_ssl module" off \
		HTTP_STATUS_MODULE "Enable http_stub_status module" on \
		HTTP_SUB_MODULE "Enable http_sub module" off \
		HTTP_UPSTREAM_FAIR "Enable upstream fair module" off \
		MAIL_MODULE "Enable IMAP4/POP3/SMTP proxy module" off \
		MAIL_IMAP_MODULE "Enable IMAP4 proxy module" off \
		MAIL_POP3_MODULE "Enable POP3 proxy module" off \
		MAIL_SMTP_MODULE "Enable SMTP proxy module" off \
		MAIL_SSL_MODULE "Enable mail_ssl module" off \
		WWW "Enable html sample files" on

MAKE_JOBS_SAFE=	yes

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

.if defined(WITH_HTTP_DAV_MODULE)
CONFIGURE_ARGS+=--with-http_dav_module
.endif

.if defined(WITH_HTTP_FLV_MODULE)
CONFIGURE_ARGS+=--with-http_flv_module
.endif

.if defined(WITH_HTTP_GZIP_STATIC_MODULE)
CONFIGURE_ARGS+=--with-http_gzip_static_module
.endif

.if defined(WITH_HTTP_PERL_MODULE)
CATEGORIES+=	perl5
CONFIGURE_ARGS+=--with-http_perl_module
USE_PERL5=	yes
.endif

.if defined(WITH_HTTP_REALIP_MODULE)
CONFIGURE_ARGS+=--with-http_realip_module
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

.if defined(WITH_HTTP_UPSTREAM_FAIR)
NGINX_UPSTREAM_FAIR_VERSION=	20081012
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:upstreamfair/}
MASTER_SITE_SUBDIR+=	osa/:upstreamfair
DISTFILES+=	nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}.tar.gz:upstreamfair
CONFIGURE_ARGS+=--add-module=${WRKDIR}/nginx_upstream_fair-${NGINX_UPSTREAM_FAIR_VERSION}
.endif

.if defined(WITHOUT_HTTP_REWRITE_MODULE) || defined(WITHOUT_PCRE)
PKGNAMESUFFIX+=	-nopcre
CONFIGURE_ARGS+=--without-http_rewrite_module \
		--without-pcre
.else
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
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

post-patch:
	@${REINPLACE_CMD} 's!%%HTTP_PORT%%!${HTTP_PORT}!; \
		s!%%PREFIX%%!${PREFIX}!' \
		${WRKSRC}/conf/nginx.conf
.if defined(WITH_HTTP_ACCESSKEY_MODULE)
	@${REINPLACE_CMD} \
		's!$$HTTP_ACCESSKEY_MODULE!ngx_http_accesskey_module!' \
		${WRKDIR}/nginx-accesskey-${NGINX_ACCESSKEY_MODULE_VERSION}/config
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
