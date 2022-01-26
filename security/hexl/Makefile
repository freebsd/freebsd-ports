PORTNAME=	hexl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel homomorphic encryption acceleration library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: __int128 is not supported on this target

LIB_DEPENDS=	libcpu_features.so:devel/cpu_features

USES=		cmake:testing compiler:c++11-lang localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	intel

CMAKE_ON=		HEXL_SHARED_LIB
CMAKE_OFF=		HEXL_BENCHMARK HEXL_TESTING
CMAKE_TESTING_ON=	HEXL_TESTING
CMAKE_TESTING_TARGET=	unittest

CXXFLAGS+=	-I${LOCALBASE}/include/cpu_features

.include <bsd.port.mk>
