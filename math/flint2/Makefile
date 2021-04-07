PORTNAME=	flint2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1	# See note #1
CATEGORIES=	math
# Note #1: FLINT is known to change its API. When upgrading please check that
#	it does not break its consumers (e.g. math/e-antic)

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast library for number theory

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libopenblas.so:math/openblas

USES=		cmake compiler:c++11-lang python:build
USE_GITHUB=	yes
GH_ACCOUNT=	wbhart
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		NTL
OPTIONS_DEFAULT=	NTL

NTL_DESC=		Victor Shoup's Number Theory Library
NTL_CMAKE_BOOL=		WITH_NTL
NTL_LIB_DEPENDS=	libntl.so:math/ntl

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
