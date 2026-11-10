PORTNAME=	clad
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic differentiation for C/C++
WWW=		https://github.com/vgvassilev/clad

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake:testing llvm:build,run localbase
USE_LDCONFIG=	yes

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	vgvassilev

CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Kokkos:BOOL=ON \
		-DClang_DIR=${LLVM_PREFIX}/lib/cmake/clang \
		-DLLVM_DIR=${LLVM_PREFIX}/lib/cmake/llvm \
		-DLLVM_EXTERNAL_LIT=${LLVM_PREFIX}/bin/llvm-lit
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	FREEBSD_BUILD_TESTS FREEBSD_BUILD_DEMOS
CMAKE_TESTING_TARGET=	CladUnitTests

#CXXFLAGS+=	-D_OPENMP
CXXFLAGS+=	-fopenmp

post-test: # lit tests (check-clad) cannot run because lit.llvm is not packaged with llvm, so run the unit test binaries directly
	@cd ${BUILD_WRKSRC}/unittests && ./Basic/DifferentiatorHTests && ./Misc/MiscTests

# tests as of 2.5: 5 tests passed (1 DifferentiatorHTests, 4 MiscTests); Kokkos tests crash clang (https://github.com/vgvassilev/clad/issues/993), lit tests cannot run

.include <bsd.port.mk>
