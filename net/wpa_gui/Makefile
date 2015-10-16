# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	wpa_gui
PORTVERSION=	2.5
CATEGORIES=	net
MASTER_SITES=	http://w1.fi/releases/ \
		http://partmedia.users.sourceforge.net/dist/:icons \
		LOCAL/jgh/net/${PORTNAME}/:icons
DISTNAME=	wpa_supplicant-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz \
		wpa-gui-icons.tar.gz:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based frontend for wpa_supplicant

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	wpa_supplicant/wpa_gui-qt4

PLIST_FILES=	sbin/wpa_gui \
		share/applications/wpa_gui.desktop \
		share/icons/hicolor/16x16/apps/wpa_gui.png \
		share/icons/hicolor/scalable/apps/wpa_gui.svg

USE_QT4=	gui moc_build rcc_build uic_build
USES=		qmake

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Exec/s|=.*|=${PREFIX}/sbin/wpa_gui|' \
		${WRKSRC}/wpa_gui.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/wpa_gui.desktop ${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	${INSTALL_DATA} ${WRKDIR}/icons/hicolor/16x16/apps/wpa_gui.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/wpa_gui.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
