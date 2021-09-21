PORTNAME=	libdatachannel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.4
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
		sctplab:usrsctp:b56b430:usrsctp/deps/usrsctp \
		paullouisageneau:libjuice:46a986e:libjuice/deps/libjuice \
		nlohmann:json:973c52d:json/deps/json \
		cisco:libsrtp:f379f48:libsrtp/deps/libsrtp

CMAKE_ON=	USE_SYSTEM_SRTP NO_EXAMPLES NO_TESTS

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_11=	OpenSSL is too old: use of undeclared identifier 'X509_getm_notBefore'
.endif

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DNO_TESTS:BOOL=OFF ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./tests-${DISTVERSION:C/-.*//}

.include <bsd.port.post.mk>
