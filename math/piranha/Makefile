# $FreeBSD$

PORTNAME=	piranha
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11
PORTREVISION=	7
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Piranha computer algebra system

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.gpl3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.lgpl3

# build only checks that boost, gmp, mpfr headers are installed, and in the runtime they are included, shared libs are never used directly
BUILD_DEPENDS=	${HEADER_DEPENDS}
RUN_DEPENDS=	${HEADER_DEPENDS}

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni
NO_BUILD=	yes
NO_ARCH=	yes

HEADER_DEPENDS=	${LOCALBASE}/include/boost/numeric/conversion/cast.hpp:devel/boost-libs \
		${LOCALBASE}/include/gmp.h:math/gmp \
		${LOCALBASE}/include/mpfr.h:math/mpfr

TEST_USES=	compiler:c++14-lang

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
