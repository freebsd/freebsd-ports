# $FreeBSD$

PORTNAME=	nflib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-23
DISTVERSIONSUFFIX=	-g5cf40ed
PORTREVISION=	1
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NTT-based fast lattice cryptography library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT_LICENSE.txt

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	unconditionally includes amd64 assembler code

LIB_DEPENDS=	libmpfr.so:math/mpfr \
		libgmp.so:math/gmp

USES=		cmake compiler:c++11-lang localbase
USE_GITHUB=	yes
GH_ACCOUNT=	quarkslab
GH_PROJECT=	NFLlib
USE_LDCONFIG=	yes

CMAKE_ON=	NFL_OPTIMIZED

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
