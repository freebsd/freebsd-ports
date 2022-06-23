PORTNAME=	obs-websocket
DISTVERSION=	4.8.0
CATEGORIES=	multimedia www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: WebSockets API

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		does not build: src/rpc/../obs-websocket.h:36:7: error: type alias redefinition with different types, see https://github.com/obsproject/obs-websocket/issues/954

BUILD_DEPENDS=	websocketpp>0:devel/websocketpp
LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake compiler:c++17-lang localbase:ldflags qt:5
USE_QT=		core gui widgets buildtools_build concurrent_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	obsproject
GH_TUPLE=	chriskohlhoff:asio:b73dc1d2c0ecb9452a87c26544d7f71e24342df6:chriskohlhoff_asio/deps/asio

OPTIONS_DEFINE=		IPV4 # with devel/websocketpp it's either IPv4 or IPv6, but not both
OPTIONS_DEFAULT=	IPV4 # project defaults to IPv6 but the port defaults to IPv4 because IPv4 is currently more common

post-patch-IPV4-on:
	@${REINPLACE_CMD} -e 's|ip::tcp::v6|ip::tcp::v4|g' ${WRKSRC}/deps/asio/asio/src/tests/unit/ip/tcp.cpp
	@${REINPLACE_CMD} -e 's|_server.listen(|_server.listen(asio::ip::tcp::v4(), |g' ${WRKSRC}/src/WSServer.cpp

post-install: # see https://github.com/Palakis/obs-websocket/issues/457
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/amd64-linux-gnu

.include <bsd.port.mk>
