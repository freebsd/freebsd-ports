# Created by: Kim Scarborough <user@unknown.nu>
# $FreeBSD$

PORTNAME=	micro_httpd
PORTVERSION=	2014.08.14
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/micro_httpd/
DISTNAME=	${PORTNAME}_14Aug2014

MAINTAINER=	user@unknown.nu
COMMENT=	Extremely small web server

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	sbin/micro_httpd man/man8/micro_httpd.8.gz

ALL_TARGET=	${PORTNAME}

post-patch:
	${REINPLACE_CMD} 's|-O|${CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micro_httpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/micro_httpd.8 ${STAGEDIR}${MAN1PREFIX}/man/man8

.include <bsd.port.mk>
