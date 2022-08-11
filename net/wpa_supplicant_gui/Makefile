PORTNAME=	wpa_supplicant_gui
DISTVERSION=	2.10
CATEGORIES=	net
MASTER_SITES=	https://w1.fi/releases/ \
		LOCAL/yuri/net/wpa_supplicant_gui/:icons
DISTNAME=	wpa_supplicant-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz \
		wpa-gui-icons.tar.gz:icons

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt-based frontend for wpa_supplicant

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		gl gmake qt:5 xorg
USE_QT=		qmake_build buildtools_build linguisttools_build core gui \
		widgets svg_run
USE_GL=		gl

ALL_TARGET=	wpa_gui-qt4

INSTALL_WRKSRC=	${WRKSRC}/wpa_gui-qt4
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}

PLIST_FILES=	sbin/wpa_gui \
		share/applications/wpa_gui.desktop \
		share/icons/hicolor/16x16/apps/wpa_gui.png \
		share/icons/hicolor/scalable/apps/wpa_gui.svgz \
		man/man8/wpa_gui.8.gz
WRKSRC_SUBDIR=	wpa_supplicant

OPTIONS_DEFINE=	DEBUG NLS

NLS_PLIST_FILES=	${DATADIR_REL}/translations/wpa_gui_de.qm

# The makefile directly calls 'qmake', give it such.
BINARY_ALIAS=	qmake=${QMAKE} \
		lrelease=${LRELEASE}

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
	# executable
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/wpa_gui \
		${STAGEDIR}${PREFIX}/sbin
	# desktop file
	${INSTALL_DATA} ${INSTALL_WRKSRC}/wpa_gui.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	# icons
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	${INSTALL_DATA} ${WRKDIR}/icons/hicolor/16x16/apps/wpa_gui.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${GZIP_CMD} < ${INSTALL_WRKSRC}/icons/wpa_gui.svg \
		> ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wpa_gui.svgz
	# manpage
	${GZIP_CMD} < ${WRKSRC}/doc/docbook/wpa_gui.8 \
		> ${STAGEDIR}${PREFIX}/man/man8/wpa_gui.8.gz

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${INSTALL_WRKSRC}/lang/wpa_gui_de.qm \
		${STAGEDIR}${DATADIR}/translations

.include <bsd.port.mk>
