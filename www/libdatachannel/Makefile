PORTNAME=	libdatachannel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.8
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebRTC Data Channels, WebRTC Media Transport, and WebSockets library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsrtp2.so:net/libsrtp2

USES=		cmake compiler:c++17-lang ssl

USE_GITHUB=	yes
GH_ACCOUNT=	paullouisageneau
GH_TUPLE=	SergiusTheBest:plog:d8461e9d473e59fbcc1f79eee021550dcf81e618:SergiusTheBest_plog/deps/plog \
		sctplab:usrsctp:7c31bd35c79ba67084ce029511193a19ceb97447:sctplab_usrsctp/deps/usrsctp \
		paullouisageneau:libjuice:4c3c85f536fb480e328e5de5e8f27fccc1a9690d:paullouisageneau_libjuice/deps/libjuice \
		nlohmann:json:4f8fba14066156b73f1189a2b8bd568bde5284c5:nlohmann_json/deps/json \
		cisco:libsrtp:90d05bf8980d16e4ac3f16c19b77e296c4bc207b:cisco_libsrtp/deps/libsrtp

CMAKE_ON=	USE_SYSTEM_SRTP NO_EXAMPLES NO_TESTS

do-test: # tests require dual stack to be enabled with 'sysctl net.inet6.ip6.v6only=0', at least one test is known to fail
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DNO_TESTS:BOOL=OFF ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./tests-${DISTVERSION:C/-.*//}

.include <bsd.port.mk>
