PORTNAME=	g2o
DISTVERSION=	20230806
PORTREVISION=	16
DISTVERSIONSUFFIX=	_git
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General framework for graph optimization
WWW=		https://openslam-org.github.io/g2o.html \
		https://github.com/RainerKuemmerle/g2o

LICENSE=	LGPL3 GPLv3
LICENSE_COMB=	dual

BROKEN_FreeBSD_15=	compilation error: static assertion failed due to requirement 'is_unsigned<int>::value', see https://github.com/RainerKuemmerle/g2o/issues/838

LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libcamd.so:math/suitesparse-camd \
		libccolamd.so:math/suitesparse-ccolamd \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libcxsparse.so:math/suitesparse-cxsparse \
		libQGLViewer.so:graphics/libQGLViewer \
		libmetis.so:math/metis \
		libopenblas.so:math/openblas \
		libsuitesparseconfig.so:math/suitesparse-config
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++14-lang gl eigen:3 blaslapack:netlib localbase qt:5
USE_GL=		gl glu
USE_QT=		core gui opengl xml widgets buildtools:build qmake:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	RainerKuemmerle

CMAKE_OFF=	DO_SSE_AUTODETECT
CMAKE_TESTING_ON=	BUILD_UNITTESTS

OPTIONS_DEFINE=			FAST_MATH
OPTIONS_SINGLE=			SIMD_${ARCH:tu}
OPTIONS_SINGLE_SIMD_AMD64=	NOSSE SSE2 SSE3 SSE41 SSE42 SSE4A
OPTIONS_SINGLE_SIMD_I386=	${OPTIONS_SINGLE_SIMD_AMD64}
OPTIONS_DEFAULT_amd64=		SSE2
OPTIONS_DEFAULT_i386=		SSE2

SIMD_AMD64_DESC=	Use SSE SIMD optimizations
SIMD_I386_DESC=		${SIMD_AMD64_DESC}
FAST_MATH_DESC=		Enable fast math operations
NOSSE_DESC=		Do not use SIMD optimization
SSE2_DESC=		SSE2 optimization
SSE3_DESC=		SSE3 optimization
SSE41_DESC=		SSE41 optimization
SSE42_DESC=		SSE42 optimization
SSE4A_DESC=		SSE4a optimization

FAST_MATH_CMAKE_BOOL=	G2O_FAST_MATH
NOSSE_CMAKE_ON=		-DDISABLE_SSE2:BOOL=ON -DDISABLE_SSE3:BOOL=ON -DDISABLE_SSE4_1:BOOL=ON -DDISABLE_SSE4_2:BOOL=ON -DDISABLE_SSE4_A:BOOL=ON
SSE2_CMAKE_ON=		-DDISABLE_SSE3:BOOL=ON -DDISABLE_SSE4_1:BOOL=ON -DDISABLE_SSE4_2:BOOL=ON -DDISABLE_SSE4_A:BOOL=ON
SSE3_CMAKE_ON=		-DDISABLE_SSE4_1:BOOL=ON -DDISABLE_SSE4_2:BOOL=ON -DDISABLE_SSE4_A:BOOL=ON
SSE41_CMAKE_ON=		-DDISABLE_SSE4_2:BOOL=ON -DDISABLE_SSE4_A:BOOL=ON
SSE42_CMAKE_ON=		-DDISABLE_SSE4_A:BOOL=ON
SSE4A_CMAKE_ON=		# empty to make portlint happy

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DDISABLE_SSE2:BOOL=ON -DDISABLE_SSE3:BOOL=ON -DDISABLE_SSE4_1:BOOL=ON -DDISABLE_SSE4_2:BOOL=ON -DDISABLE_SSE4_A:BOOL=ON
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/cmake_modules/*.cmake

# tests fail to compile, see https://github.com/RainerKuemmerle/g2o/issues/711

.include <bsd.port.mk>
