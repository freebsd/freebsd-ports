PORTNAME=	transmission-remote-gui
PORTVERSION=	5.18.0
PORTREVISION=	24
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

USE_GITHUB=	yes
GH_PROJECT=	transgui

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Remote GUI for transmission daemon
WWW=		https://github.com/transmission-remote-gui/transgui

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

ONLY_FOR_ARCHS=	i386 amd64

USES=		desktop-file-utils fpc gnome iconv lazarus:flavors xorg
USE_GNOME=	cairo
USE_XORG=	x11

DESKTOP_ENTRIES="Transmission Remote GUI" \
                "Remote GUI for transmission daemon" \
                "transgui" \
                "${PREFIX}/bin/transgui" \
                "Network;P2P;" \
                ${TRUE}

PLIST_FILES=	bin/transgui \
		share/icons/hicolor/48x48/apps/transgui.png
PORTDATA=	*
SUB_FILES=	pkg-message

LAZARUS_PROJECT_FILES=	transgui.lpi
LAZBUILD_ARGS=		-d
PROJECT_NAME=		transgui

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

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
