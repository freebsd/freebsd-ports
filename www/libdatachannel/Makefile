PORTNAME=	libdatachannel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebRTC Data Channels, WebRTC Media Transport, and WebSockets library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsrtp2.so:net/libsrtp2

USES=		cmake compiler:c++17-lang ssl

USE_GITHUB=	yes
GH_ACCOUNT=	paullouisageneau
GH_TUPLE=	\
		SergiusTheBest:plog:d8461e9:plog/deps/plog \
		sctplab:usrsctp:07f871b:usrsctp/deps/usrsctp \
		paullouisageneau:libjuice:7a6efb7:libjuice/deps/libjuice \
		nlohmann:json:973c52d:json/deps/json

CMAKE_ON=	USE_SYSTEM_SRTP NO_EXAMPLES NO_TESTS

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DNO_TESTS:BOOL=OFF ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./tests-${DISTVERSION:C/-.*//}

.include <bsd.port.mk>
