PORTNAME=	proxygen
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.08.18.00
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of C++ HTTP libraries including easy way to use HTTP server
WWW=		https://github.com/facebook/proxygen

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=283484

BUILD_DEPENDS=	bash:shells/bash \
		gperf>0:devel/gperf
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libbzip2.so:misc/vxl \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libicui18n.so:devel/icu \
		liblz4.so:archivers/liblz4 \
		libmvfst_server.so:net/mvfst \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind \
		libwangle.so:net/wangle \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++14-lang cpe perl5 python:build ssl
CPE_VENDOR=	facebook
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes

CXXFLAGS+=	-fPIC
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT
LDFLAGS+=	-lexecinfo

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
