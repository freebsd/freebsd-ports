# $FreeBSD$

PORTNAME=	ompl
DISTVERSION=	1.4.1
DISTVERSIONSUFFIX=	-Source
PORTREVISION=	3
CATEGORIES=	misc comms
MASTER_SITES=	http://cdn.bitbucket.org/${PORTNAME}/${PORTNAME}/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Motion Planning Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake eigen:3 pkgconfig zip
USE_LDCONFIG=	yes

CMAKE_OFF=	OMPL_REGISTRATION OMPL_BUILD_TESTS OMPL_BUILD_DEMOS

OPTIONS_DEFINE=		FLANN MORSE OPENDE SPOT TRIANGLE PLANNERARENA
OPTIONS_DEFAULT=	FLANN MORSE OPENDE TRIANGLE
OPTIONS_SUB=		yes

FLANN_DESC=		Use FLANN for nearest neighbor queries
FLANN_LIB_DEPENDS=	libflann.so:math/flann

MORSE_DESC=		Include a plugin for the MORSE Robot Simulation engine
MORSE_BUILD_DEPENDS=	morse-robotics>0:misc/morse
MORSE_RUN_DEPENDS=	morse-robotics>0:misc/morse

OPENDE_DESC=		Use Open Dynamics Engine for kinodynamic planning
OPENDE_LIB_DEPENDS=	libode.so:devel/ode

SPOT_DESC=		Use 'Spot' for creating finite automata from LTL formulae
SPOT_BROKEN=		https://bitbucket.org/ompl/ompl/issues/442
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

post-patch-SPOT-on:
	@${REINPLACE_CMD} 's|-std=c++11|-std=c++14|' ${WRKSRC}/CMakeModules/CompilerSettings.cmake

post-configure:
	@${REINPLACE_CMD} 's|/usr/bin/morse|${LOCALBASE}/bin/morse|' ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.mk>
