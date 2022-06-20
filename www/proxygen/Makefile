PORTNAME=	proxygen
DISTVERSIONPREFIX=	v
DISTVERSION=	2022.06.20.00
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of C++ HTTP libraries including easy way to use HTTP server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/lib/libmvfst_server.a:net/mvfst \
		gperf>0:devel/gperf
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
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
		libwangle.so:net/wangle \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++14-lang cpe perl5 python:3.6+,build ssl
CPE_VENDOR=	facebook
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes

CXXFLAGS+=	-fPIC
LDFLAGS+=	-lexecinfo

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
