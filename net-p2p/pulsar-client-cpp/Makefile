PORTNAME=	pulsar-client-cpp # this port requres instruction sets crc32, pclmul above the default sse2
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Apache Pulsar C++ client library
WWW=		https://pulsar.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	i386 amd64 # due to requrement of instruction sets crc32, pclmul
BROKEN_i386=	compilation fails due to overflow, see https://github.com/apache/pulsar-client-cpp/issues/449

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:devel/boost-libs
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libprotobuf.so:devel/protobuf \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd

USES=		cmake:testing ssl

USE_GITHUB=	yes
GH_ACCOUNT=	apache

CMAKE_OFF=	BUILD_TESTS
CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17 \
		-DOPENSSL_ROOT_DIR=/usr

CXXFLAGS+=	-mcrc32 -mpclmul

.include <bsd.port.mk>
