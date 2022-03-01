PORTNAME=	darkhttpd
DISTVERSION=	1.13
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	henrichartzer@tuta.io
COMMENT=	Simple, static web server

LICENSE=	ISCL

USE_GITHUB=	yes
GH_ACCOUNT=	emikulic

NO_INSTALL=	yes

PLIST_FILES=	bin/darkhttpd

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
