PORTNAME=	dooble
DISTVERSION=	2023.08.30
PORTREVISION=	1
CATEGORIES=	www

PATCH_SITES=	https://github.com/textbrowser/dooble/commit/
PATCHFILES+=	95c0d3277d714ea1dba658ff4433bde3eb29ef76.patch:-p1 # Fix build with Qt 6.6.0

MAINTAINER=	eric@camachat.org
COMMENT=	Dooble Web Browser
WWW=		https://textbrowser.github.io/dooble/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	qt6 qt5
FLAVOR?=	${FLAVORS:[1]}
qt5_CONFLICTS_INSTALL=	qt6
qt6_CONFLICTS_INSTALL=	qt5

USES=		compiler:c++17-lang desktop-file-utils gl gmake qmake qt:${FLAVOR:S/qt//} ssl \
		tar xorg
USE_GITHUB=	yes
GH_ACCOUNT=	textbrowser
USE_GL=		gl
.if ${FLAVOR} == qt5
PKGNAMESUFFIX=	-${FLAVOR}
USE_QT=		charts concurrent core declarative gui location network \
		printsupport sql webchannel webengine widgets xml \
		sql-sqlite3:run \
		buildtools:build qmake:build
. elif ${FLAVOR} == qt6
USE_QT=		base charts declarative positioning webchannel webengine \
		sqldriver-sqlite:run
.endif
USE_XORG=	xcb

QMAKE_SOURCE_PATH=	${PORTNAME}.pro

PLIST_FILES=	${PREFIX}/share/applications/${PORTNAME}.desktop \
		${PREFIX}/share/pixmaps/${PORTNAME}.png \
		bin/${PORTNAME}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/Dooble ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
		${INSTALL_DATA} ${WRKSRC}/Icons/Logo/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
		desktop-file-edit --remove-category=Web --add-category=Network --add-category=WebBrowser ${WRKSRC}/${PORTNAME}.desktop
		desktop-file-edit --set-key=Exec --set-value="/usr/bin/env QTWEBENGINE_DICTIONARIES_PATH=${QT_DATADIR}/qtwebengine_dictionaries ${PREFIX}/bin/${PORTNAME}" ${WRKSRC}/${PORTNAME}.desktop
		desktop-file-edit --set-icon=${PREFIX}/share/pixmaps/${PORTNAME}.png ${WRKSRC}/${PORTNAME}.desktop
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

.include <bsd.port.mk>
