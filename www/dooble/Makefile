PORTNAME=	dooble
DISTVERSION=	2023.11.30
CATEGORIES=	www

MAINTAINER=	eric@camachat.org
COMMENT=	Dooble Web Browser
WWW=		https://textbrowser.github.io/dooble/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang desktop-file-utils gl gmake qmake qt:6 ssl \
		tar xorg
USE_GITHUB=	yes
GH_ACCOUNT=	textbrowser
USE_GL=		gl
USE_QT=		base charts declarative positioning webchannel webengine \
		sqldriver-sqlite:run
USE_XORG=	xcb

QMAKE_SOURCE_PATH=	dooble.pro

QTWEBENGINE_DICTIONARIES=	${QT_DATADIR}/qtwebengine_dictionaries
PLIST_SUB=	QTWEBENGINE_DICTIONARIES=${QTWEBENGINE_DICTIONARIES}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/Dooble ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
		${INSTALL_DATA} ${WRKSRC}/Icons/Logo/dooble.png ${STAGEDIR}${PREFIX}/share/pixmaps/dooble.png
		${MKDIR} ${STAGEDIR}${QTWEBENGINE_DICTIONARIES}
		${INSTALL_DATA} ${WRKSRC}/qtwebengine_dictionaries/*.bdic ${STAGEDIR}${QTWEBENGINE_DICTIONARIES}
		desktop-file-edit --remove-category=Web --add-category=Network --add-category=WebBrowser ${WRKSRC}/Distributions/dooble.desktop
		desktop-file-edit --set-key=Exec --set-value="/usr/bin/env QTWEBENGINE_DICTIONARIES_PATH=${QTWEBENGINE_DICTIONARIES} ${PREFIX}/bin/${PORTNAME}" ${WRKSRC}/Distributions/dooble.desktop
		desktop-file-edit --set-icon=${PREFIX}/share/pixmaps/dooble.png ${WRKSRC}/Distributions/dooble.desktop
		${INSTALL_DATA} ${WRKSRC}/Distributions/dooble.desktop ${STAGEDIR}${PREFIX}/share/applications/dooble.desktop

.include <bsd.port.mk>
