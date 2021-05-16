PORTNAME=	libdatachannel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebRTC Data Channels, WebRTC Media Transport, and WebSockets library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsrtp2.so:net/libsrtp2

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	paullouisageneau
GH_TUPLE=	\
		SergiusTheBest:plog:d8461e9:plog/deps/plog \
		sctplab:usrsctp:07f871b:usrsctp/deps/usrsctp \
		paullouisageneau:libjuice:4393345:libjuice/deps/libjuice \
		nlohmann:json:973c52d:json/deps/json

CMAKE_ON=	USE_SYSTEM_SRTP NO_EXAMPLES NO_TESTS

.include <bsd.port.mk>
