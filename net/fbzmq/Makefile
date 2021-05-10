PORTNAME=	fbzmq
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.05.10.00
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for writing services in C++ while leveraging libzmq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libepoll-shim>0:devel/libepoll-shim
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		liblz4.so:archivers/liblz4 \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libthriftcpp2.so:devel/fbthrift \
		libunwind.so:devel/libunwind \
		libwangle.so:net/wangle \
		libzmq.so:net/libzmq4 \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS

CXXFLAGS+=	-I${LOCALBASE}/include/libepoll-shim -fPIC

.include <bsd.port.mk>
