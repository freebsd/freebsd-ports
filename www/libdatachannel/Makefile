PORTNAME=	libdatachannel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.4
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebRTC Data Channels, WebRTC Media Transport, and WebSockets library
WWW=		https://github.com/paullouisageneau/libdatachannel

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsrtp2.so:net/libsrtp2

USES=		cmake compiler:c++17-lang ssl

USE_GITHUB=	yes
GH_ACCOUNT=	paullouisageneau
GH_TUPLE=	SergiusTheBest:plog:e21baec:SergiusTheBest_plog/deps/plog \
		sctplab:usrsctp:5ca29ac:sctplab_usrsctp/deps/usrsctp \
		paullouisageneau:libjuice:5f753ca:paullouisageneau_libjuice/deps/libjuice \
		nlohmann:json:bc889af:nlohmann_json/deps/json \
		cisco:libsrtp:a566a9cfcd619e8327784aa7cff4a1276dc1e895:cisco_libsrtp/deps/libsrtp

CMAKE_ON=	USE_SYSTEM_SRTP NO_EXAMPLES NO_TESTS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=unused-but-set-variable \
			   -Wno-error=strict-prototypes
.endif

do-test: # tests require dual stack to be enabled with 'sysctl net.inet6.ip6.v6only=0', at least one test is known to fail
	# tests fail (intermittently?): https://github.com/paullouisageneau/libdatachannel/issues/682
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DNO_TESTS:BOOL=OFF ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./tests-${DISTVERSION:C/-.*//}

.include <bsd.port.post.mk>
