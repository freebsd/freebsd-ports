PORTNAME=	chatterino2
PORTVERSION=	2.3.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Twitch chat client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson \
		websocketpp>=0:devel/websocketpp
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libqt5keychain.so:security/qtkeychain

USES=		compiler:c++17-lang gl pkgconfig qmake qt:5 ssl
USE_QT=		concurrent core gui multimedia network svg widgets \
		buildtools_build qmake_build
USE_GL=		gl

PLIST_FILES=	bin/chatterino \
		share/appdata/com.chatterino.chatterino.appdata.xml \
		share/applications/com.chatterino.chatterino.desktop \
		share/icons/hicolor/256x256/apps/chatterino.png

USE_GITHUB=	yes
GH_ACCOUNT=	chatterino
GH_TUPLE=	Chatterino:libcommuni:c613600e:communi/lib/libcommuni \
		pajlada:serialize:7d37cbf:serialize/lib/serialize \
		pajlada:settings:7cf8431d:settings/lib/settings \
		pajlada:signals:baf5bb0:signals/lib/signals

QMAKE_ENV=	GIT_COMMIT=${COMMIT_ID} \
		GIT_RELEASE=${DISTVERSIONPREFIX}${PORTVERSION}
QMAKE_ARGS=	INCLUDEPATH+=${LOCALBASE}/include/qt5keychain \
		LIBS+=-lqt5keychain \
		WEBSOCKETPP_SYSTEM=1 \
		RAPIDJSON_SYSTEM=1

.include <bsd.port.mk>
