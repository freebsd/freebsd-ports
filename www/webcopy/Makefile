# Created by: ache
# $FreeBSD$

PORTNAME=	webcopy
PORTVERSION=	0.98b7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A Web Mirroring Program

RESTRICTED=	This program cannot be distributed if modified in any way.  Don't sell for profit without written permission
ALL_TARGET=

USES=		perl5

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} webcopy ${STAGEDIR}${PREFIX}/bin
	${INSTALL} -d -m 755 ${STAGEDIR}${PREFIX}/share/doc/webcopy
	cd ${WRKSRC}; ${INSTALL_DATA} webcopy.html ${STAGEDIR}${PREFIX}/share/doc/webcopy

.include <bsd.port.mk>
