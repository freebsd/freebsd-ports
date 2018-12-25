# $FreeBSD$

PORTNAME=	simint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
CATEGORIES=	science
MASTER_SITES=	http://www.bennyp.org/research/simint/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Obara-Saika (OS) method of calculating electron repulsion integrals

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake tar:bz2
USE_LDCONFIG=	yes

OPTIONS_SINGLE=		VECTOR
OPTIONS_SINGLE_VECTOR=	SCALAR ${ARCH:C/(amd64|i386)/SSE3 AVX AVXFMA MICAVX512/:C/^[a-z].*//}
OPTIONS_DEFAULT=	${ARCH:C/(amd64|i386)/SSE3/:C/^[a-z].*/SCALAR/}
VECTOR_DESC=		Vector SIMD optimization
SCALAR_DESC=		Unvectorized: no SIMD acceleration
SSE3_DESC=		Intel CPUs with SSSE3 support
AVX_DESC=		Intel CPUs with AVX support (Sandy/Ivy Bridge, Haswell)
AVXFMA_DESC=		Intel CPUs with AVX and FMA support (Haswell)
MICAVX512_DESC=		Intel KNL (experimental)

# Need https://reviews.freebsd.org/D13078 approved
#CMAKE_ARGS=	-DSIMINT_VECTOR:STRING=${OPTIONS_SINGLE_VECTOR_SELECTED:S/3//:tl}

# Temporary replacement
SCALAR_CMAKE_ON=	-DSIMINT_VECTOR:STRING=scalar
SSE3_CMAKE_ON=		-DSIMINT_VECTOR:STRING=sse
AVX_CMAKE_ON=		-DSIMINT_VECTOR:STRING=avx
AVXFMA_CMAKE_ON=	-DSIMINT_VECTOR:STRING=avxfma
MICAVX512_CMAKE_ON=	-DSIMINT_VECTOR:STRING=micavx512

CMAKE_ON=	BUILD_SHARED_LIBS \
		SIMINT_STANDALONE
CMAKE_OFF=	ENABLE_TESTS

.for opt in ${OPTIONS_SINGLE_VECTOR}
${opt}_VARS=    SIMINT_VECTOR=${opt}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/simint/cpp_restrict.hpp ${STAGEDIR}${PREFIX}/include/simint

do-test: # unfirtunately  it rebuilds
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENABLE_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}
.for tst in test_eri test_eri_deriv1 benchmark_eri screentest # from test/CMakeLists.txt
	#@cd ${WRKSRC} && (${FIND} test/dat -name "*.mol" | ${XARGS} ${BUILD_WRKSRC}/test/${tst})
	@cd ${WRKSRC} && (${FIND} test/dat -name "*.mol" | ${XARGS} printf "%s")
.endfor

.include <bsd.port.mk>
