PORTNAME=	chatterino2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.2
CATEGORIES=	net-im

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Twitch chat client
WWW=		https://chatterino.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build with Boost>=1.87

BUILD_DEPENDS=	${LOCALBASE}/include/magic_enum/magic_enum.hpp:devel/magic_enum \
		miniaudio>0:audio/miniaudio \
		rapidjson>0:devel/rapidjson \
		websocketpp>=0:devel/websocketpp
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++17-lang desktop-file-utils gl pkgconfig \
		qt:6 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	chatterino
GH_TUPLE=	Chatterino:libcommuni:030710a:communi/lib/libcommuni \
		martinmoene:expected-lite:5b5caad:expectedlite/lib/expected-lite \
		arsenm:sanitizers-cmake:0573e2e:sanitizers/cmake/sanitizers-cmake \
		pajlada:serialize:17946d6:serialize/lib/serialize \
		pajlada:settings:9e9c2f6:settings/lib/settings \
		pajlada:signals:d067706:signals/lib/signals
USE_GL=	gl
#USE_QT=multimedia svg
USE_QT=	5compat

CMAKE_ARGS=	-DUSE_SYSTEM_QTKEYCHAIN=on

CXXFLAGS+=	-I${LOCALBASE}/include/miniaudio

PLIST_FILES=	bin/chatterino \
		share/applications/com.chatterino.chatterino.desktop \
		share/icons/hicolor/256x256/apps/com.chatterino.chatterino.png

.include <bsd.port.mk>
