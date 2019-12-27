# $FreeBSD$

PORTNAME=	palisade
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.c.20191227
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PALISADE lattice cryptography library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/License.md

BROKEN_i386=	fails to build: a declaration of 'Mul128' must be available

BUILD_DEPENDS=	autoconf:devel/autoconf # possibly a mistake in the project

USES=		cmake:noninja localbase
USE_GITLAB=	yes
USE_GITHUB=	nodefault
GL_PROJECT=	palisade-development
GL_COMMIT=	5d4f7a3ff66006966bf16c67f3da2e4e6936e39f
GH_TUPLE=	\
		JerryRyan:cereal:181fbcd3:cereal/third-party/cereal \
		google:benchmark:c50ac68c:benchmark/third-party/google-benchmark \
		google:googletest:78fdd6c0:google_test/third-party/google-test \
		gperftools:gperftools:c1d546d7:gperftools/third-party/gperftools
USE_GCC=	any # clang fails: fatal error: 'quadmath.h' file not found
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_UNITTESTS

CXXFLAGS+=	-I${WRKSRC}/third-party/google-test/googletest

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_UNITTESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} testall

.include <bsd.port.mk>
