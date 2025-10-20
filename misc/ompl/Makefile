PORTNAME=	ompl
DISTVERSION=	1.6.0
PORTREVISION=	7
CATEGORIES=	misc comms

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Motion Planning Library
WWW=		https://ompl.kavrakilab.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:testing compiler:c++17-lang eigen:3 pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	OMPL_REGISTRATION OMPL_BUILD_TESTS OMPL_BUILD_DEMOS OMPL_VERSIONED_INSTALL
CMAKE_TESTING_ON=	OMPL_BUILD_TESTS

OPTIONS_DEFINE=		FLANN OPENDE SPOT TRIANGLE PLANNERARENA
OPTIONS_DEFAULT=	FLANN OPENDE TRIANGLE
OPTIONS_SUB=		yes

FLANN_DESC=		Use FLANN for nearest neighbor queries
FLANN_LIB_DEPENDS=	libflann.so:math/flann

OPENDE_DESC=		Use Open Dynamics Engine for kinodynamic planning
OPENDE_LIB_DEPENDS=	libode.so:devel/ode

SPOT_DESC=		Use 'Spot' for creating finite automata from LTL formulae
SPOT_USES=		compiler:c++14-lang
SPOT_LIB_DEPENDS=	libspot.so:math/spot

TRIANGLE_DESC=		Create triangular decompositions of 2D polygons
TRIANGLE_LIB_DEPENDS=	libtriangle.so:math/triangle

PLANNERARENA_DESC=	Install plannerarena (depends on R)
PLANNERARENA_BUILD_DEPENDS=	Rscript:math/R
PLANNERARENA_RUN_DEPENDS=	Rscript:math/R

.for o in ${OPTIONS_DEFINE:NPLANNERARENA}
post-patch-${o}-off:
	@${REINPLACE_CMD} 's|find_package(${o}|#&|i' ${WRKSRC}/CMakeLists.txt
.endfor

post-patch-PLANNERARENA-off:
	@${REINPLACE_CMD} 's|find_program(R_EXEC|#&|' ${WRKSRC}/CMakeLists.txt

post-configure:
	@${REINPLACE_CMD} 's|/usr/bin/morse|${LOCALBASE}/bin/morse|' ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.mk>
