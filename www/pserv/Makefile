# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	pserv
PORTVERSION=	3.4
CATEGORIES=	www
MASTER_SITES=	SF
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Portable and small webserver written in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

CONFLICTS=	popular-[0-9]*

OPTIONS_DEFINE=	LOG PHP
OPTIONS_DEFAULT=	LOG PHP
LOG_DESC=	Enable loggin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHP}
USE_PHP=	yes
WANT_PHP_CGI=	yes
.endif

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g;s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/defaults/pserv.conf ${WRKSRC}/sources/main.h
.if ! ${PORT_OPTIONS:MLOG}
	@${REINPLACE_CMD} "s|define LOG|undef LOG|" \
		${WRKSRC}/sources/main.h
.endif
.if ! ${PORT_OPTIONS:MPHP}
	@${REINPLACE_CMD} "s|define PHP|undef PHP|" \
		${WRKSRC}/sources/main.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sources/pserv ${STAGEDIR}${PREFIX}/sbin/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pserv
	${INSTALL_DATA} ${WRKSRC}/defaults/mime_types.dat ${STAGEDIR}${PREFIX}/etc/pserv/mime.types
	${INSTALL_DATA} ${WRKSRC}/defaults/pserv.conf ${STAGEDIR}${PREFIX}/etc/pserv/pserv.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pserv.sh ${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
