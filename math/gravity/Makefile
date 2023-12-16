PORTNAME=	gravity
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1-20220309
PORTREVISION=	3
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mathematical modeling for optimization and machine learning
WWW=		https://www.gravityopt.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/adjacency_list.hpp:devel/boost-libs
LIB_DEPENDS=	libblas.so:math/blas \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libcoinasl.so:math/asl \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas

USES=		cmake compiler:c++11-lang eigen:3 localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Gravity
GH_TAGNAME=	47ac86a

CMAKE_ARGS+=	-DIPOPT_ROOT_DIR=${LOCALBASE}
CMAKE_ON=	Boost
CMAKE_OFF=	MP
CMAKE_OFF+=	Ipopt CoinUtils # fails to find Ipopt and CoinUtils for some reason

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_EXAMPLES:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${WRKSRC}/bin/Release/gravity_test

.include <bsd.port.mk>
