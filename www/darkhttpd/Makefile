PORTNAME=	darkhttpd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13
CATEGORIES=	www

MAINTAINER=	henrichartzer@tuta.io
COMMENT=	Simple, static web server

LICENSE=	ISCL

USES=		cpe

CPE_VENDOR=	darkhttpd_project

USE_GITHUB=	yes
GH_ACCOUNT=	emikulic

PLIST_FILES=	bin/darkhttpd

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
