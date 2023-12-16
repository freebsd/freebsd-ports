PORTNAME=	symengine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast symbolic manipulation library, written in C++
WWW=		https://symengine.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++14-lang llvm:min=15,max=15
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	WITH_SYMENGINE_THREAD_SAFE BUILD_SHARED_LIBS BUILD_FOR_DISTRIBUTION
CMAKE_OFF=	BUILD_BENCHMARKS WITH_COTIRE

OPTIONS_DEFINE=			ARB ECM LLVM MPC TCMALLOC ASSERT
OPTIONS_SINGLE=			INTCLASS
OPTIONS_SINGLE_INTCLASS=	GMP GMPXX BOOSTMP FLINT PIRANHA
OPTIONS_DEFAULT=		ARB ECM LLVM MPC FLINT # FLINT choice is based on best performance, TCMALLOC is broken due to memory corruption issues, see https://github.com/symengine/symengine.py/issues/412

INTCLASS_DESC=		Integer class, use integers from:

ARB_DESC=		Build with Arb (interval arithmetic library)
ARB_CMAKE_BOOL=		WITH_ARB
ARB_LIB_DEPENDS=	libarb.so:math/arb \
			libflint.so:math/flint2 \
			libmpfr.so:math/mpfr

ECM_DESC=		Build with ECM support (Elliptic Curve Method)
ECM_CMAKE_BOOL=		WITH_ECM
ECM_LIB_DEPENDS=	libecm.so:math/gmp-ecm

LLVM_DESC=		Build with LLVM
LLVM_CMAKE_BOOL=	WITH_LLVM
LLVM_CMAKE_ON=		-DLLVM_INCLUDE_DIRS:STRING=${LOCALBASE}/llvm${LLVM_VERSION}/include \
			-DFREEBSD_LLVM_VERSION=${LLVM_VERSION}
LLVM_BUILD_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}

MPC_DESC=		Build with MPC
MPC_CMAKE_BOOL=		WITH_MPC
MPC_LIB_DEPENDS=	libmpc.so:math/mpc

TCMALLOC_CMAKE_BOOL=	WITH_TCMALLOC
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools
TCMALLOC_BROKEN=	associated with a suspected memory corruption problem, see https://github.com/symengine/symengine.py/issues/412

ASSERT_CMAKE_BOOL=	WITH_SYMENGINE_ASSERT

GMP_DESC=		gmp (supports arbitrary fp precision)
GMP_CMAKE_ON=		-DINTEGER_CLASS:STRING=gmp
GMP_LIB_DEPENDS=	libgmp.so:math/gmp \
			libmpfr.so:math/mpfr

GMPXX_DESC=		gmpxx
GMPXX_CMAKE_ON=		-DINTEGER_CLASS:STRING=gmpxx
GMPXX_LIB_DEPENDS=	libgmp.so:math/gmp

BOOSTMP_DESC=		boostmp (no arbitrary fp precision)
BOOSTMP_CMAKE_ON=	-DINTEGER_CLASS:STRING=boostmp
BOOSTMP_BUILD_DEPENDS=	${LOCALBASE}/include/boost/multiprecision/cpp_int.hpp:devel/boost-libs

FLINT_DESC=		flint (supports arbitrary fp precision, best performance)
FLINT_CMAKE_ON=		-DINTEGER_CLASS:STRING=flint
FLINT_LIB_DEPENDS=	libflint.so:math/flint2 \
			libgmp.so:math/gmp \
			libmpfr.so:math/mpfr

PIRANHA_DESC=		piranha
PIRANHA_CMAKE_ON=	-DINTEGER_CLASS:STRING=piranha
PIRANHA_BUILD_DEPENDS=	piranha>0:math/piranha

do-test: # one test fails: https://github.com/symengine/symengine/issues/1697
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
