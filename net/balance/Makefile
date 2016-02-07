# Created by: Joseph Scott <joseph@randomnetworks.com>
# $FreeBSD$

PORTNAME=	balance
PORTVERSION=	3.57
CATEGORIES=	net
MASTER_SITES=	http://www.inlab.de/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Simple but powerful generic TCP proxy with round robin features

LICENSE=	GPLv2

ALL_TARGET=	balance
USE_RC_SUBR=	balance

pre-build:
	@${REINPLACE_CMD} -e 's|^CFLAGS|CFLAGS?|' \
	-e 's|^CC|CC?|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/balance ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/balance.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
