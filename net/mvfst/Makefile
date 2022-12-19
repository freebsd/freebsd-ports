PORTNAME=	mvfst
DISTVERSION=	g20220926
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of the QUIC transport protocol
WWW=		https://github.com/facebookincubator/mvfst

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
		libzstd.so:archivers/zstd

USES=		cmake:testing compiler:c++17-lang cpe
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	facebookincubator
GH_TAGNAME=	1e9db60a905b00618c857abcc8a27931f6baa154

CPE_VENDOR=	facebook

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS # several tests fail, see https://github.com/facebookincubator/mvfst/issues/275

CXXFLAGS+=	-fPIC

.include <bsd.port.mk>
