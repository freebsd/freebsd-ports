# $FreeBSD$

PORTNAME=	chatterino2
PORTVERSION=	g2020090101
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Twitch chat client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libqt5keychain.so:security/qtkeychain

USES=		compiler:c++17-lang gl pkgconfig qmake qt:5 ssl
USE_QT=		concurrent core gui multimedia network svg widgets \
		buildtools_build qmake_build
USE_GL=		gl

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/chatterino \
		share/appdata/com.chatterino.chatterino.appdata.xml \
		share/applications/com.chatterino.chatterino.desktop \
		share/icons/hicolor/256x256/apps/chatterino.png

USE_GITHUB=	yes
GH_ACCOUNT=	chatterino
COMMIT_ID=	cbcd5f3863b6edf22b6d6ffb625bd338f3ea112d
GH_TAGNAME=	${COMMIT_ID:C|(.......).*|\1|}
GH_TUPLE=	Chatterino:libcommuni:f3e7f97:communi/lib/libcommuni \
		pajlada:humanize:4e00a03:humanize/lib/humanize \
		pajlada:serialize:130ffc3:serialize/lib/serialize \
		pajlada:settings:6de3a27:settings/lib/settings \
		pajlada:signals:6665cca:signals/lib/signals \
		ziocleto:websocketpp:1e0138c:websocketpp/lib/websocketpp

QMAKE_ENV=	GIT_COMMIT=${COMMIT_ID} \
		GIT_RELEASE=${DISTVERSIONPREFIX}${PORTVERSION}
QMAKE_ARGS=	INCLUDEPATH+=${LOCALBASE}/include/qt5keychain \
		LIBS+=-lqt5keychain \
		RAPIDJSON_SYSTEM=1

PORTDOCS=	README.md docs/Commands.md docs/ENV.md docs/IMAGEUPLOADER.md \
		docs/README.md docs/Regex.md

PORTSCOUT=	skipv:v2.2.2,v2.2.1,v2.2.0,v2.1.7,v2.1.6,v2.1.5,v2.1.4,v2.1.3,v2.1.2,v2.1.0,v2.0.4,v2.0.3,v2.0.2,v2.0.1,v2.0.0

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
.for DOC in docs/Commands.md docs/ENV.md docs/IMAGEUPLOADER.md docs/README.md docs/Regex.md
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${STAGEDIR}${DOCSDIR}/docs
.endfor

.include <bsd.port.mk>
