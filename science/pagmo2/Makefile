# $FreeBSD$

PORTNAME=	pagmo2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10-161
DISTVERSIONSUFFIX=	-g0a589425
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Platform to perform parallel computations of optimization tasks

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.gpl3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.lgpl3

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		Ipopt>0:math/ipopt \
		nlopt>0:math/nlopt
RUN_DEPENDS=	boost-libs>0:devel/boost-libs \
		Ipopt>0:math/ipopt \
		nlopt>0:math/nlopt

USES=		cmake eigen:3,build,run
USE_GITHUB=	yes
GH_ACCOUNT=	esa

NO_BUILD=	yes
NO_ARCH=	yes

CMAKE_ON=	PAGMO_WITH_EIGEN3 PAGMO_WITH_NLOPT PAGMO_WITH_IPOPT

do-test: # tests fail to build: https://github.com/esa/pagmo2/issues/273
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DPAGMO_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
