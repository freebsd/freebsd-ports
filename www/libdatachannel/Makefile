PORTNAME=	libdatachannel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.4
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
		sctplab:usrsctp:7c31bd3:usrsctp/deps/usrsctp \
		paullouisageneau:libjuice:3795466:libjuice/deps/libjuice \
		nlohmann:json:fec56a1:json/deps/json \
		cisco:libsrtp:90d05bf:libsrtp/deps/libsrtp

CMAKE_ON=	USE_SYSTEM_SRTP NO_EXAMPLES NO_TESTS

do-test: # tests require dual stack to be enabled with 'sysctl net.inet6.ip6.v6only=0', at least one test is known to fail
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DNO_TESTS:BOOL=OFF ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./tests-${DISTVERSION:C/-.*//}

.include <bsd.port.mk>
