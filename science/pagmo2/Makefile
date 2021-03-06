# $FreeBSD$

PORTNAME=	pagmo2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.17.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Platform to perform parallel computations of optimization tasks

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.gpl3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.lgpl3

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libipopt.so:math/ipopt \
		libnlopt.so:math/nlopt \
		libtbb.so:devel/tbb

USES=		cmake compiler:c++17-lang eigen:3,build,run
USE_GITHUB=	yes
GH_ACCOUNT=	esa
USE_LDCONFIG=	yes

CMAKE_ON=	PAGMO_WITH_EIGEN3 PAGMO_WITH_NLOPT PAGMO_WITH_IPOPT PAGMO_ENABLE_IPO

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DPAGMO_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
