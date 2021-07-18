PORTNAME=	palisade
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.3
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PALISADE lattice cryptography library for Fully Homomorphic Encryption

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build: a declaration of 'Mul128' must be available
BROKEN_powerpc64=	fails to build: math/native_int/binint.h:510:11: error: Architecture not supported for MultD()

BUILD_DEPENDS=	autoconf:devel/autoconf # possibly a mistake in the project

USES=		cmake:noninja localbase # compiler:c++11-lang
USE_GITLAB=	yes
USE_GITHUB=	nodefault
GL_PROJECT=	palisade-release # there's also palisade-development
GL_COMMIT=	1a66eb80233b2adef8c67c71d9ca4652ea188f7d
GH_TUPLE=	\
		JerryRyan:cereal:a384b101:cereal/third-party/cereal \
		google:benchmark:d3ad0b9d:benchmark/third-party/google-benchmark \
		google:googletest:8b4817e3:google_test/third-party/google-test
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_UNITTESTS BUILD_EXAMPLES BUILD_BENCHMARKS
CMAKE_OFF+=	WITH_NTL # https://gitlab.com/palisade/palisade-development/-/issues/180
CMAKE_ARGS=	-DWITH_NTL=Y # libntl.so will be discontinued in 1.11, see https://gitlab.com/palisade/palisade-development/-/issues/180

CXXFLAGS+=	-I${WRKSRC}/third-party/google-test/googletest

BINARY_ALIAS=	git=false

# clang-8 fails: error: use of undeclared identifier '__builtin_FILE'
LLVM_VERSION=	10 # ${LLVM_DEFAULT}
BUILD_DEPENDS+=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
RUN_DEPENDS+=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}

LDFLAGS+=	-pthread # only for tests: see https://gitlab.com/palisade/palisade-release/-/issues/23

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CMAKE_BOOL=	USE_OpenMP

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_UNITTESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} testall

.include <bsd.port.mk>
