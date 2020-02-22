# $FreeBSD$

PORTNAME=	palisade
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PALISADE lattice cryptography library for Fully Homomorphic Encryption

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/License.md

BROKEN_i386=	fails to build: a declaration of 'Mul128' must be available
BROKEN_powerpc64=	fails to build: math/native_int/binint.h:510:11: error: Architecture not supported for MultD()

BUILD_DEPENDS=	autoconf:devel/autoconf # possibly a mistake in the project
LIB_DEPENDS=	libntl.so:math/ntl

USES=		cmake:noninja compiler:c++11-lang localbase
USE_GITLAB=	yes
USE_GITHUB=	nodefault
GL_PROJECT=	palisade-development # there's also palisade-release
GL_COMMIT=	e00817a14c1d58b064cb0584e23b703a083e4908
GH_TUPLE=	\
		JerryRyan:cereal:a384b101:cereal/third-party/cereal \
		google:benchmark:daff5fea:benchmark/third-party/google-benchmark \
		google:googletest:8b4817e3:google_test/third-party/google-test \
		gperftools:gperftools:c1d546d7:gperftools/third-party/gperftools
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_UNITTESTS
CMAKE_ARGS=	-DWITH_NTL=Y

LDFLAGS+=	${LOCALBASE}/lib/libntl.so # libntl is optional in palisade but is necessary in FreeBSD because is has an equivalent of quadmath.h that is missing in FreeBSD. -DWITH_NTL should be added by users to the compiler command lines.

CXXFLAGS+=	-I${WRKSRC}/third-party/google-test/googletest

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CMAKE_BOOL=	USE_OpenMP

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_UNITTESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} testall

.include <bsd.port.mk>
