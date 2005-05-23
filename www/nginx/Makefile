# New ports collection makefile for:	nginx
# Date created:				11 Oct 2004
# Whom:					osa
#
# $FreeBSD$
#

PORTNAME=	nginx
PORTVERSION=	0.1.33
CATEGORIES=	www
MASTER_SITES=	http://sysoev.ru/nginx/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Robust and small WWW server

VARDIR?=	${DESTDIR}/var
LOGDIR?=	${VARDIR}/log
RUNDIR?=	${VARDIR}/run
TMPDIR?=	${VARDIR}/tmp/nginx
HTTP_PORT?=	80

USE_REINPLACE=	yes
USE_RC_SUBR=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}/etc/nginx \
		--with-cc-opt="-I ${LOCALBASE}/include" \
		--with-ld-opt="-L ${LOCALBASE}/lib" \
		--conf-path=${PREFIX}/etc/nginx/nginx.conf \
		--sbin-path=${PREFIX}/sbin/nginx \
		--pid-path=${RUNDIR}/nginx.pid \
		--http-client-body-temp-path=${TMPDIR}/client_body_temp \
		--http-proxy-temp-path=${TMPDIR}/proxy_temp \
		--http-fastcgi-temp-path=${TMPDIR}/fastcgi_temp \
		--http-log-path=${LOGDIR}/nginx-access.log \
		--error-log-path=${LOGDIR}/nginx-error.log \
		--with-http_stub_status_module \
		--user=${WWWOWN} --group=${WWWGRP}

.if defined(WITHOUT_HTTP_REWRITE_MODULE) || defined(WITHOUT_PCRE)
PKGNAMESUFFIX=	-nopcre
CONFIGURE_ARGS+=--without-http_rewrite_module \
		--without-pcre
.else
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
.endif

.if defined(WITHOUT_WWW)
PLIST_SUB+=     WWWDATA="@comment "
.else
PLIST_SUB+=     WWWDATA=""
.endif

.if defined(STOP_BEFORE_REMOVE)
PLIST_SUB+=	STOP_BEFORE_REMOVE=""
.else
PLIST_SUB+=     STOP_BEFORE_REMOVE="@comment "
.endif

.if defined(START_AFTER_INSTALL)
PLIST_SUB+=	START_AFTER_INSTALL=""
.else
PLIST_SUB+=	START_AFTER_INSTALL="@comment "
.endif

PLIST_SUB+=	TMPDIR=${TMPDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

RC_SCRIPTS_SUB=PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/nginx.sh > ${WRKSRC}/nginx.sh

post-patch:
	@${REINPLACE_CMD} 's!%%HTTP_PORT%%!${HTTP_PORT}!; \
		s!%%PREFIX%%!${PREFIX}!' \
		${WRKSRC}/conf/nginx.conf

do-build:
	@cd ${WRKSRC} && ${MAKE}

do-install:
	${MKDIR} ${PREFIX}/etc/nginx ${TMPDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${TMPDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/nginx.sh ${PREFIX}/etc/rc.d
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

post-install:
.if defined(START_AFTER_INSTALL)
	${PREFIX}/etc/rc.d/nginx.sh start
.endif

.include <bsd.port.mk>
