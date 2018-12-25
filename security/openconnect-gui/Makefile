# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openconnect-gui
PORTVERSION=	1.4.1
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	security

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Graphical OpenConnect client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	openconnect:security/openconnect
LIB_DEPENDS=	libgnutls.so:security/gnutls
RUN_DEPENDS=	openconnect:security/openconnect \
		vpnc-scripts>=0:sysutils/vpnc-scripts

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:C/-gui//}

USES=		cmake:insource pkgconfig qt:5
USE_QT=		buildtools_build concurrent core gui network qmake_build widgets
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
PLIST_FILES=	bin/openconnect-gui

do-install:
	${MV} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
