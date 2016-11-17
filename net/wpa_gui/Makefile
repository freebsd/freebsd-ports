# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	wpa_gui
PORTVERSION=	2.6
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
LICENSE_FILE=	${WRKSRC}/../../COPYING

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC_SUBDIR=	wpa_supplicant/wpa_gui-qt4

PLIST_FILES=	"@(,,4555) sbin/wpa_gui" \
		share/applications/wpa_gui.desktop \
		share/icons/hicolor/16x16/apps/wpa_gui.png \
		share/icons/hicolor/scalable/apps/wpa_gui.svgz \
		man/man8/wpa_gui.8.gz

SUB_FILES=	pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE}

USE_QT4=	corelib gui moc_build rcc_build uic_build \
		imageformats_run
USES=		qmake
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DEBUG

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Exec/s|=.*|=${PREFIX}/sbin/wpa_gui|' \
		${WRKSRC}/wpa_gui.desktop

post-patch-DEBUG-on:
	@${REINPLACE_CMD} -e \
		's| release| debug|' \
		${WRKSRC}/wpa_gui.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/wpa_gui.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	${INSTALL_DATA} ${WRKDIR}/icons/hicolor/16x16/apps/wpa_gui.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${GZIP_CMD} < ${WRKSRC}/icons/wpa_gui.svg \
		> ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wpa_gui.svgz
	${GZIP_CMD} < ${WRKSRC}/../doc/docbook/wpa_gui.8 \
		> ${STAGEDIR}${PREFIX}/man/man8/wpa_gui.8.gz

.include <bsd.port.mk>
