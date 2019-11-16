# $FreeBSD$

PORTNAME=	transmission-remote-gui
PORTVERSION=	5.17.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

USE_GITHUB=	yes
GH_PROJECT=	transgui

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Remote GUI for transmission daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		desktop-file-utils fpc iconv lazarus:flavors
USE_FPC=	cairo chm fcl-base fcl-image fcl-json fcl-net fcl-xml pasjpeg \
		rtl-objpas rtl-extra x11

DESKTOP_ENTRIES="Transmission Remote GUI" \
                "Remote GUI for transmission daemon" \
                "transgui" \
                "${PREFIX}/bin/transgui" \
                "Application;Network;" \
                ${TRUE}

PLIST_FILES=	bin/transgui \
		share/icons/hicolor/48x48/apps/transgui.png
PORTDATA=	*
SUB_FILES=	pkg-message

LAZARUS_PROJECT_FILES=	transgui.lpi
LAZBUILD_ARGS=		-d
PROJECT_NAME=		transgui

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/restranslator.pas

do-install:
	@cd ${WRKSRC}/units && \
		${INSTALL_PROGRAM} transgui ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} lang ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${WRKSRC}/transgui.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/transgui.png

.include <bsd.port.mk>
