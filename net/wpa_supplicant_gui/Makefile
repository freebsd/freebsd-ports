# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	wpa_supplicant_gui
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://w1.fi/releases/ \
		http://partmedia.users.sourceforge.net/dist/:icons \
		LOCAL/jgh/net/${PORTNAME}/:icons
DISTNAME=	wpa_supplicant-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz \
		wpa-gui-icons.tar.gz:icons

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt-based frontend for wpa_supplicant

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		gmake qt:5
USE_QT=		qmake_build buildtools_build linguisttools_build core gui \
		widgets svg_run

ALL_TARGET=	wpa_gui-qt4
INSTALL_WRKSRC=	${WRKSRC}/wpa_gui-qt4
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
PLIST_FILES=	sbin/wpa_gui \
		share/applications/wpa_gui.desktop \
		share/icons/hicolor/16x16/apps/wpa_gui.png \
		share/icons/hicolor/scalable/apps/wpa_gui.svgz \
		man/man8/wpa_gui.8.gz
WRKSRC_SUBDIR=	wpa_supplicant
SUB_FILES=	pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE}

OPTIONS_DEFINE=	DEBUG NLS

NLS_PLIST_FILES=	${DATADIR_REL}/translations/wpa_gui_de.qm

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Exec/s|=.*|=${PREFIX}/sbin/wpa_gui|' \
		${INSTALL_WRKSRC}/wpa_gui.desktop
	@${REINPLACE_CMD} -e '/resourceDir = / \
		s|QLibraryInfo::location(QLibraryInfo::TranslationsPath)| \
		"${DATADIR}/translations"|' \
			${INSTALL_WRKSRC}/main.cpp

post-patch-DEBUG-on:
	@${REINPLACE_CMD} -e \
		's| release| debug|' \
		${INSTALL_WRKSRC}/wpa_gui.pro

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${INSTALL_WRKSRC}/wpa_gui.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	${INSTALL_DATA} ${WRKDIR}/icons/hicolor/16x16/apps/wpa_gui.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${GZIP_CMD} < ${INSTALL_WRKSRC}/icons/wpa_gui.svg \
		> ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wpa_gui.svgz
	${GZIP_CMD} < ${WRKSRC}/doc/docbook/wpa_gui.8 \
		> ${STAGEDIR}${PREFIX}/man/man8/wpa_gui.8.gz

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${INSTALL_WRKSRC}/lang/wpa_gui_de.qm \
		${STAGEDIR}${DATADIR}/translations

.include <bsd.port.mk>
