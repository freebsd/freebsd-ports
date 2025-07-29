PORTNAME=	fizz
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.07.28.00
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++14 implementation of the TLS-1.3 standard
WWW=		https://github.com/facebookincubator/fizz

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libbzip2.so:misc/vxl \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
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

USES=		cmake:testing compiler:c++14-lang ssl cpe
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	facebookincubator

CPE_VENDOR=	facebook

WRKSRC_SUBDIR=	${PORTNAME}

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS BUILD_EXAMPLES
CMAKE_TESTING_ON=	BUILD_TESTS
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT

post-install: # https://github.com/facebookincubator/fizz/issues/55
	cd ${STAGEDIR}${PREFIX} && ${RMDIR} include/fizz/tool/test include/fizz/util/test

.include <bsd.port.mk>
