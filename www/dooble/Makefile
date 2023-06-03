PORTNAME=	dooble
DISTVERSION=	2023.05.31
CATEGORIES=	www
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	eric@camachat.org
COMMENT=	Dooble Web Browser
WWW=		https://textbrowser.github.io/dooble/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}
qt5_CONFLICTS_INSTALL=	qt6
qt6_CONFLICTS_INSTALL=	qt5

USES=		compiler:c++17-lang desktop-file-utils gl gmake qmake qt:${FLAVOR:S/qt//} ssl \
		tar xorg
USE_GITHUB=	yes
GH_ACCOUNT=	textbrowser
USE_GL=		gl
.if ${FLAVOR} == qt5
USE_QT=		concurrent core declarative gui location network printsupport \
		sql webchannel webengine widgets xml sql-sqlite3:run \
		buildtools:build qmake:build
. elif ${FLAVOR} == qt6
USE_QT=		base charts webchannel webengine
.endif
USE_XORG=	xcb

QMAKE_SOURCE_PATH=	${PORTNAME}.pro

PLIST_FILES=	${PREFIX}/share/applications/${PORTNAME}.desktop \
		${PREFIX}/share/pixmaps/${PORTNAME}.png \
		bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${FLAVOR:U} == qt5
QT5_VER_MINOR=	${QT5_VERSION:C/^[0-9]+\.//:C/\..+$//}
.if ${QT5_VER_MINOR} < 15
BROKEN=		Qt 5.15 or higher required, using 5.${QT5_VER_MINOR} now
.endif
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/Dooble ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
		${INSTALL_DATA} ${WRKSRC}/Icons/Logo/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
		desktop-file-edit --remove-category=Web --add-category=Network --add-category=WebBrowser ${WRKSRC}/${PORTNAME}.desktop
		desktop-file-edit --set-key=Exec --set-value="/usr/bin/env QTWEBENGINE_DICTIONARIES_PATH=${QT_DATADIR}/qtwebengine_dictionaries ${PREFIX}/bin/${PORTNAME}" ${WRKSRC}/${PORTNAME}.desktop
		desktop-file-edit --set-icon=${PREFIX}/share/pixmaps/${PORTNAME}.png ${WRKSRC}/${PORTNAME}.desktop
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

.include <bsd.port.post.mk>
