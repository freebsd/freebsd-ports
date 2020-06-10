# $FreeBSD$

PORTNAME=	flint2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast library for number theory

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake compiler:c++11-lang
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
