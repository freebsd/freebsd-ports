PORTNAME=	faiss
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.1
PORTREVISION=	1
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ffc5c9a500b7a854c5ad6a3e77fabd31ec0a9300.patch:-p1 # Fix build for CPUTYPE=znver4: https://github.com/facebookresearch/faiss/pull/5752

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for efficient similarity search & clustering of dense vectors
WWW=		https://github.com/facebookresearch/faiss

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	openblas>0:math/openblas # faiss links with libopenblasp-rN.N.N.so (installed by default only on amd64,i386), so use non-filename-specific DEPENDS commands
RUN_DEPENDS=	openblas>0:math/openblas
TEST_DEPENDS=	benchmark>0:devel/benchmark \
		gflags>0:devel/gflags \
		googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang localbase:ldflags # tests fail to compile, see https://github.com/facebookresearch/faiss/issues/3913

USE_GITHUB=	yes
GH_ACCOUNT=	facebookresearch

CMAKE_ON=	BUILD_SHARED_LIBS FAISS_ENABLE_C_API
CMAKE_OFF=	BUILD_TESTING FAISS_ENABLE_GPU FAISS_ENABLE_PYTHON

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

# tests as of 1.13.1: 100% tests passed, 0 tests failed out of 138
# tests as of 1.15.1: 94% tests passed, 16 tests failed out of 283, all failures seem to be die to OpenBLAS mis-identifying the CPU architecture, see https://github.com/OpenMathLib/OpenBLAS/issues/6029

.include <bsd.port.mk>
