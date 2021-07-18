# Created by: ache

PORTNAME=	webcopy
PORTVERSION=	0.98b7
CATEGORIES=	www
MASTER_SITES=	LOCAL/cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Web Mirroring Program

# Converted from RESTRICTED
LICENSE=	webcopy
LICENSE_NAME=	webcopy
LICENSE_TEXT=	This program cannot be distributed if modified in any way.  Don't sell for profit without written permission
LICENSE_PERMS=	auto-accept

ALL_TARGET=

USES=		perl5

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} webcopy ${STAGEDIR}${PREFIX}/bin
	${INSTALL} -d -m 755 ${STAGEDIR}${PREFIX}/share/doc/webcopy
	cd ${WRKSRC}; ${INSTALL_DATA} webcopy.html ${STAGEDIR}${PREFIX}/share/doc/webcopy

.include <bsd.port.mk>
