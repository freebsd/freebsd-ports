PORTNAME=	mvfst
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.08.18.00
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of the QUIC transport protocol
WWW=		https://github.com/facebook/mvfst

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libicui18n.so:devel/icu \
		liblz4.so:archivers/liblz4 \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind \
		libbzip2.so:misc/vxl \
		libzstd.so:archivers/zstd

USES=		cmake:testing compiler:c++17-lang cpe ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

CPE_VENDOR=	facebook

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS # several tests fail, see https://github.com/facebookincubator/mvfst/issues/275

CXXFLAGS+=	-fPIC
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT

.include <bsd.port.mk>
