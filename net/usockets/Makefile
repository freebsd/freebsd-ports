PORTNAME=	usockets
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.8
PORTREVISION=	2
CATEGORIES=	net devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minuscule eventing, networking, and crypto for async applications
WWW=		https://github.com/uNetworking/uSockets

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	uNetworking
GH_PROJECT=	uSockets

USE_CSTD=	c11
USE_CXXSTD=	c++17

CFLAGS+=	-fPIC

SUB_FILES=	libusockets.pc
SUB_LIST+=	VERSION=${DISTVERSION}

PLIST_FILES=	include/libusockets.h \
		lib/libuSockets.so.0 \
		lib/libuSockets.so \
		libdata/pkgconfig/libusockets.pc

do-build:
	@cd ${WRKSRC} && \
		${SETENVI} ${MAKE_ENV} ${CC} ${CFLAGS} -DLIBUS_USE_OPENSSL -Isrc -c src/*.c src/eventing/*.c src/crypto/*.c src/io_uring/*.c && \
		${SETENVI} ${MAKE_ENV} ${CXX} ${CXXFLAGS} -c src/crypto/*.cpp && \
		${SETENVI} ${MAKE_ENV} ${CXX} ${CXXFLAGS} -shared -o libuSockets.so.0 -Wl,-soname=libuSockets.so.0 *.o -lssl

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libusockets.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libuSockets.so.0 ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libuSockets.so.0 ${STAGEDIR}${PREFIX}/lib/libuSockets.so
	${INSTALL_DATA} ${WRKDIR}/libusockets.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

do-test: # tests fail to compile: https://github.com/uNetworking/uSockets/issues/213
	@cd ${WRKSRC} && \
		${CC} ${CFLAGS} -o test tests/sni_test.c ${STAGEDIR}${PREFIX}/lib/libuSockets.so && \
		./test

.include <bsd.port.mk>
