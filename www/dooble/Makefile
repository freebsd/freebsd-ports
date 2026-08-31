PORTNAME=	dooble
DISTVERSION=	2026.08.21
CATEGORIES=	www

MAINTAINER=	eric@camachat.org
COMMENT=	Dooble Web Browser
WWW=		https://textbrowser.github.io/dooble/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgpgme.so:security/gpgme

USES=		compiler:c++17-lang gl gmake qmake qt:6 tar xorg
USE_GITHUB=	yes
GH_ACCOUNT=	textbrowser
GH_TUPLE=	textbrowser:dooble-dictionaries:0f1e715:dictionaries

USE_GL=		opengl
USE_QT=		base charts declarative positioning sqldriver-sqlite:run \
		webchannel webengine
USE_XORG=	xcb

QTWEBENGINE_DICTIONARIES=	${DATADIR}/qtwebengine_dictionaries
QMAKE_ENV+=		DOOBLE_DICTIONARIES_DIRECTORY=${WRKSRC_dictionaries}/Dictionaries \
			QTWEBENGINE_DICTIONARIES_PATH=${QTWEBENGINE_DICTIONARIES}
QMAKE_SOURCE_PATH=	dooble.pro

PLIST_SUB=		QTWEBENGINE_DICTIONARIES=${QTWEBENGINE_DICTIONARIES}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/dooble.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Dooble ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps ${STAGEDIR}${QTWEBENGINE_DICTIONARIES}
	${INSTALL_DATA} ${WRKSRC}/Icons/Logo/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/qtwebengine_dictionaries/*.bdic ${STAGEDIR}${QTWEBENGINE_DICTIONARIES}
	${INSTALL_DATA} ${WRKSRC}/Distributions/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
