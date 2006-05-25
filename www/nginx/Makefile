# New ports collection makefile for:	nginx
# Date created:				11 Oct 2004
# Whom:					osa
#
# $FreeBSD$
#

PORTNAME=	nginx
PORTVERSION=	0.3.47
CATEGORIES=	www
MASTER_SITES=	http://sysoev.ru/nginx/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	osa

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Robust and small WWW server

NGINX_VARDIR?=	${DESTDIR}/var
NGINX_LOGDIR?=	${NGINX_VARDIR}/log
NGINX_RUNDIR?=	${NGINX_VARDIR}/run
NGINX_TMPDIR?=	${NGINX_VARDIR}/tmp/nginx
HTTP_PORT?=	80

USE_RC_SUBR=	nginx.sh
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}/etc/nginx \
		--with-cc-opt="-I ${LOCALBASE}/include" \
		--with-ld-opt="-L ${LOCALBASE}/lib" \
		--conf-path=${PREFIX}/etc/nginx/nginx.conf \
		--sbin-path=${PREFIX}/sbin/nginx \
		--pid-path=${NGINX_RUNDIR}/nginx.pid \
		--http-client-body-temp-path=${NGINX_TMPDIR}/client_body_temp \
		--http-proxy-temp-path=${NGINX_TMPDIR}/proxy_temp \
		--http-fastcgi-temp-path=${NGINX_TMPDIR}/fastcgi_temp \
		--http-log-path=${NGINX_LOGDIR}/nginx-access.log \
		--error-log-path=${NGINX_LOGDIR}/nginx-error.log \
		--with-http_stub_status_module \
		--user=${WWWOWN} --group=${WWWGRP}

.if defined(WITH_DEBUG)
CFLAGS+=	-g
CONFIGURE_ARGS+=--with-debug
STRIP=		#do not strip if nginx with debug information
.endif

.if defined(WITH_OPENSSL_MODULE)
NGINX_OPENSSL=	yes
CONFIGURE_ARGS+=--with-http_ssl_module
.endif

.if defined(WITH_IMAP_MODULE)
NGINX_OPENSSL=	yes
CONFIGURE_ARGS+=--with-imap --with-imap_ssl_module
.endif

.if defined(NGINX_OPENSSL)
USE_OPENSSL=	yes
.endif

.if defined(WITHOUT_HTTP_REWRITE_MODULE) || defined(WITHOUT_PCRE)
PKGNAMESUFFIX+=	-nopcre
CONFIGURE_ARGS+=--without-http_rewrite_module \
		--without-pcre
.else
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
.endif

.if defined(WITHOUT_WWW)
PLIST_SUB+=	WWWDATA="@comment "
.else
PLIST_SUB+=	WWWDATA=""
.endif

PLIST_SUB+=	NGINX_TMPDIR=${NGINX_TMPDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-patch:
	@${REINPLACE_CMD} 's!%%HTTP_PORT%%!${HTTP_PORT}!; \
		s!%%PREFIX%%!${PREFIX}!' \
		${WRKSRC}/conf/nginx.conf

do-build:
	@cd ${WRKSRC} && ${MAKE}

do-install:
	${MKDIR} ${PREFIX}/etc/nginx ${NGINX_TMPDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${NGINX_TMPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/conf/koi-win ${PREFIX}/etc/nginx
.for i in mime.types nginx.conf
	[ -f ${PREFIX}/etc/nginx/${i} ] || \
		${INSTALL_DATA} ${WRKSRC}/conf/${i} ${PREFIX}/etc/nginx
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${PREFIX}/etc/nginx/${i}-dist
.endfor
.if !defined(WITHOUT_WWW)
	${MKDIR} ${PREFIX}/www/nginx-dist
	${INSTALL_DATA} ${WRKSRC}/html/index.html ${PREFIX}/www/nginx-dist
	${ECHO_CMD} "" >>${PREFIX}/www/nginx-dist/EXAMPLE_DIRECTORY-DONT_ADD_OR_TOUCH_ANYTHING
	[ -e ${PREFIX}/www/nginx ] || \
		${LN} -sf ${PREFIX}/www/nginx-dist ${PREFIX}/www/nginx
.endif

.include <bsd.port.mk>
