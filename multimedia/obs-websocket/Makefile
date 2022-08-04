PORTNAME=	obs-websocket # will be included in obs-studio-28.x - port should be removed then
DISTVERSION=	5.0.1
CATEGORIES=	multimedia www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: WebSockets API

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	websocketpp>0:devel/websocketpp
LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake:insource compiler:c++17-lang localbase:ldflags qt:5 # insource because of https://github.com/obsproject/obs-websocket/issues/973
USE_QT=		core gui widgets buildtools_build concurrent_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	obsproject
GH_TUPLE=	chriskohlhoff:asio:b73dc1d2c0ecb9452a87c26544d7f71e24342df6:chriskohlhoff_asio/deps/asio \
		nlohmann:json:a34e011:json/deps/json \
		nayuki:QR-Code-generator:8518684:qr/deps/qr

PLIST_FILES=	lib/obs-plugins/obs-websocket.so \
		share/obs/obs-plugins/obs-websocket/locale/en-US.ini

.include <bsd.port.mk>
