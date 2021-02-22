# $FreeBSD$

PORTNAME=	proxygen
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.02.22.00
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
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libfolly.so:devel/folly \
		libwangle.so:net/wangle \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++14-lang perl5 python:3.6+,build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes

CXXFLAGS+=	-fPIC
LDFLAGS+=	-lexecinfo

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
