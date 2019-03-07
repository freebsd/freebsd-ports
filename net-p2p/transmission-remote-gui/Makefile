# $FreeBSD$

PORTNAME=	transmission-remote-gui
PORTVERSION=	5.16.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	transmission-remote-gui
GH_PROJECT=	transgui

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Remote GUI for transmission daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		fpc iconv lazarus:flavors
USE_FPC=	cairo chm fcl-base fcl-image fcl-json fcl-net fcl-xml pasjpeg \
		rtl-objpas rtl-extra x11

WRKSRC=		${WRKDIR}/transgui-${PORTVERSION}
PLIST_FILES=	bin/transgui
SUB_FILES=	pkg-message
LLD_UNSAFE=	yes

LAZARUS_PROJECT_FILES=	transgui.lpi
LAZBUILD_ARGS=		-d
PROJECT_NAME=		transgui

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt4 ${PORTNAME}-qt5
qt4_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt4

do-install:
	@cd ${WRKSRC}/units && \
		${INSTALL_PROGRAM} transgui ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
