PORTNAME=	gravity
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.20210512
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mathematical modeling for optimization and machine learning

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/adjacency_list.hpp:devel/boost-libs \
		gcc${GCC_DEFAULT}>0:lang/gcc${GCC_DEFAULT} # not sure why does it need gcc, maybe for libquadmath.so
LIB_DEPENDS=	libblas.so:math/blas \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libcoinasl.so:math/asl \
		libCoinUtils.so:math/coinutils \
		libipopt.so:math/ipopt \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas
RUN_DEPENDS=	gcc${GCC_DEFAULT}>0:lang/gcc${GCC_DEFAULT}

USES=		cmake compiler:c++11-lang eigen:3 localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Gravity
GH_TAGNAME=	da941e9

CMAKE_ARGS+=	-DIPOPT_ROOT_DIR=${LOCALBASE}
CMAKE_ON=	Boost Ipopt

LDFLAGS+=	-L${LOCALBASE}/lib/gcc${GCC_DEFAULT}

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_EXAMPLES:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${WRKSRC}/bin/Release/gravity_test

.include <bsd.port.mk>
