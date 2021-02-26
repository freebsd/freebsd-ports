# Created by: Piotr Kubaj <pkubaj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openconnect-gui
PORTVERSION=	1.5.3
DISTVERSIONPREFIX=v
MASTER_SITES=	https://gitlab.com/openconnect/openconnect-gui/-/archive/v${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
CATEGORIES=	security net-vpn

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Graphical OpenConnect client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	openconnect:security/openconnect
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libspdlog.so:devel/spdlog \
		libfmt.so:devel/libfmt
RUN_DEPENDS=	openconnect:security/openconnect \
		vpnc-scripts>=0:sysutils/vpnc-scripts

USES=		cmake:insource compiler:c++11-lang pkgconfig qt:5
USE_GITHUB=	nodefault
GH_TUPLE=	qtproject:qt-solutions:a8dda66d:qtsolutions/external/src/qt-solutions-master
USE_QT=		buildtools_build concurrent core gui network qmake_build widgets
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
PLIST_FILES=	bin/openconnect-gui

do-install:
	${MV} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
