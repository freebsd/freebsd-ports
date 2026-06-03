PORTNAME=	raja
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.09.1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for performance portability on HPC systems
WWW=		https://raja.readthedocs.io/en/develop/ \
		https://github.com/LLNL/RAJA

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: undefined reference: RAJA::TypedIndexSet<RAJA::TypedRangeSegment<int, int>, RAJA::TypedListSegment<int>>::T0_TypeId, see https://github.com/LLNL/RAJA/issues/1936

LIB_DEPENDS=	libcamp.so:devel/camp

USES=		cmake:testing pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	RAJA
GH_TUPLE=	LLNL:blt:e783e30:blt/blt

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_TESTS
CMAKE_TESTING_ON=	ENABLE_TESTS

# tests as of 2025.09.1: 100% tests passed, 0 tests failed out of 459

.include <bsd.port.mk>
