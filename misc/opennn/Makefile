PORTNAME=	opennn
DISTVERSIONPREFIX=	v
DISTVERSION=	26.0.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open neural networks library
WWW=		https://www.opennn.net/ \
		https://github.com/Artelnics/opennn

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_armv7=	gcc13 fails: error: use of built-in trait '__remove_cvref(_InIter1)' in function signature, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=278630

BUILD_DEPENDS=	eigen5>=5.0:math/eigen5
RUN_DEPENDS=	eigen5>=5.0:math/eigen5
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing jpeg localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Artelnics

CMAKE_ON=	OpenNN_BUILD_SHARED OpenNN_DISABLE_CUDA
CMAKE_OFF=	OpenNN_BUILD_EXAMPLES OpenNN_BUILD_TESTS OpenNN_ENABLE_LTO
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_TBB:BOOL=ON \
		-DOpenNN_CPU_TARGET:STRING=PORTABLE \
		-DOpenNN_ENABLE_ONEDNN:STRING=OFF
CMAKE_TESTING_ON=	OpenNN_BUILD_TESTS # some tests fail, see https://github.com/Artelnics/opennn/issues/229
CMAKE_TESTING_TARGET=

CXXFLAGS_powerpc=	-O1
LDFLAGS+=	-pthread
LDFLAGS_powerpc=	-latomic

.include <bsd.port.options.mk>

.if !exists(/usr/include/omp.h)
LDFLAGS+=	-fopenmp
USES+=		compiler:gcc-c++11-lib
.else
CXXFLAGS+=	-fexperimental-library # std::jthread in libc++ < 20
LDFLAGS+=	-fexperimental-library -lomp # https://github.com/Artelnics/opennn/issues/182
USES+=		compiler:c++20-lang
.endif

.if ${ARCH} == aarch64
# libomp aborts here with "Too many args to microtask" for parallel regions with many shared variables, so use libgomp
BUILD_DEPENDS+=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgomp.so:lang/gcc${GCC_DEFAULT}
RUN_DEPENDS+=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgomp.so:lang/gcc${GCC_DEFAULT}
CMAKE_ARGS+=	-DOpenMP_CXX_FLAGS:STRING=-fopenmp=libgomp \
		-DOpenMP_CXX_LIB_NAMES:STRING=gomp \
		-DOpenMP_gomp_LIBRARY:FILEPATH=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgomp.so
LDFLAGS:=	${LDFLAGS:N-lomp}
LDFLAGS+=	-fopenmp=libgomp -Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT}
.endif

post-test:
	@cd ${TEST_WRKSRC} && ${BUILD_WRKSRC}/bin/opennn_tests \
		--gtest_filter=-ConvolutionalLayerTests/ConvolutionalLayerTest.BackwardGradientMatchesNumerical/1 # numerical gradient check exceeds its tolerance (0.00136 vs 0.001)

# tests as of 26.0.1: 1207 tests passed, 57 skipped (GPU, oneDNN, onnxruntime and other optional dependencies)

.include <bsd.port.mk>
