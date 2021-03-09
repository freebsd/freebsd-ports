# $FreeBSD$

PORTNAME=	rsocket-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.03.08.00
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ implementation of RSocket

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libfmt>0:devel/libfmt
LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		liblz4.so:archivers/liblz4 \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++14-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	rsocket
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_BENCHMARKS BUILD_EXAMPLES BUILD_TESTS BUILD_EXAMPLES

PORTSCOUT=	limit:^[0-9\.]*$$

post-install: # https://github.com/rsocket/rsocket-cpp/issues/890
	@cd ${STAGEDIR}${LOCALBASE} && ${RM} -r include/rsocket/examples include/rsocket/test include/yarpl/cmake include/yarpl/perf include/yarpl/test

.include <bsd.port.mk>
