PORTNAME=	faiss
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for efficient similarity search & clustering of dense vectors
WWW=		https://github.com/facebookresearch/faiss

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	openblas>0:math/openblas # faiss links with libopenblasp-rN.N.N.so (installed by default only on amd64,i386), so use non-filename-specific DEPENDS commands
RUN_DEPENDS=	openblas>0:math/openblas
TEST_DEPENDS=	benchmark>0:devel/benchmark \
		gflags>0:devel/gflags \
		googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang localbase:ldflags # tests fail to compile, see https://github.com/facebookresearch/faiss/issues/3913

USE_GITHUB=	yes
GH_ACCOUNT=	facebookresearch

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING FAISS_ENABLE_GPU FAISS_ENABLE_PYTHON

# tests as of 1.12.0: 100% tests passed

.include <bsd.port.mk>
