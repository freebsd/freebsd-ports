# $FreeBSD$

PORTNAME=	chatterino2
PORTVERSION=	g2020082701
CATEGORIES=	net-im

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Twitch chat client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libqt5keychain.so:security/qtkeychain

USES=		gl pkgconfig qmake qt:5 ssl
USE_QT=		concurrent core gui multimedia network svg widgets \
		buildtools_build qmake_build
USE_GL=		gl

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES=	"Chatterino" \
			"" \
			"chatterino" \
			"chatterino" \
			"Network;InstantMessaging;" \
			""

PLIST_FILES=	bin/chatterino \
		share/appdata/com.chatterino.chatterino.appdata.xml \
		share/icons/hicolor/256x256/apps/chatterino.png

USE_GITHUB=	yes
GH_ACCOUNT=	chatterino
GH_TAGNAME=	279a80b
GH_TUPLE=	Chatterino:libcommuni:f3e7f97:communi/lib/libcommuni \
		pajlada:humanize:1386737:humanize/lib/humanize \
		pajlada:serialize:86bfa5a:serialize/lib/serialize \
		pajlada:settings:4fe0ff9:settings/lib/settings \
		pajlada:signals:6665cca:signals/lib/signals \
		ziocleto:websocketpp:1e0138c:websocketpp/lib/websocketpp

QMAKE_ENV=	GIT_COMMIT=${GH_TAGNAME} \
		GIT_RELEASE=${DISTVERSIONPREFIX}${PORTVERSION}
QMAKE_ARGS=	INCLUDEPATH+=${LOCALBASE}/include/qt5keychain \
		LIBS+=-lqt5keychain PREFIX=${STAGEDIR}${PREFIX} \
		RAPIDJSON_SYSTEM=1

PORTDOCS=	README.md docs/Commands.md docs/ENV.md docs/IMAGEUPLOADER.md \
		docs/README.md docs/Regex.md

PORTSCOUT=	skipv:v2.1.7,v2.1.0,v2.0.4,v2.0.3,v2.0.2,v2.0.1,v2.0.0

post-extract:
	@${RM} ${WRKSRC}/lib/qtkeychain.pri

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chatterino ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/ ${STAGEDIR}${PREFIX}/share/appdata/
	${INSTALL_DATA} ${WRKSRC}/resources/icon.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/chatterino.png
	${INSTALL_DATA} ${WRKSRC}/resources/com.chatterino.chatterino.appdata.xml ${STAGEDIR}${PREFIX}/share/appdata/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
.for DOC in docs/Commands.md docs/ENV.md docs/IMAGEUPLOADER.md docs/README.md docs/Regex.md
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${STAGEDIR}${DOCSDIR}/docs
.endfor

.include <bsd.port.mk>
