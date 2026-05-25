PORTNAME=	ompl
DISTVERSION=	2.0.0
CATEGORIES=	misc comms

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Motion Planning Library
WWW=		https://ompl.kavrakilab.org/ \
		https://github.com/ompl/ompl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:testing compiler:c++17-lang eigen:3 pkgconfig python:run shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/ompl_benchmark_statistics.py

CMAKE_OFF=	OMPL_BUILD_TESTS OMPL_BUILD_VAMP OMPL_VERSIONED_INSTALL
CMAKE_TESTING_ON=	OMPL_BUILD_TESTS

OPTIONS_DEFINE=		DEMOS FLANN PLANNERARENA SPOT TRIANGLE
OPTIONS_DEFAULT=	FLANN TRIANGLE
OPTIONS_SUB=		yes

DEMOS_DESC=		Build and install demo programs
DEMOS_CMAKE_ON=		OMPL_BUILD_DEMOS

FLANN_DESC=		Use FLANN for nearest neighbor queries
FLANN_LIB_DEPENDS=	libflann.so:math/flann

SPOT_DESC=		Use 'Spot' for creating finite automata from LTL formulae
SPOT_USES=		compiler:c++14-lang
SPOT_LIB_DEPENDS=	libspot.so:math/spot

TRIANGLE_DESC=		Create triangular decompositions of 2D polygons
TRIANGLE_LIB_DEPENDS=	libtriangle.so:math/triangle

.for o in ${OPTIONS_DEFINE:NDEMOS}
post-patch-${o}-off:
	@${REINPLACE_CMD} 's|find_package(${o}|#&|i' ${WRKSRC}/CMakeModules/OMPLDependencies.cmake
.endfor

post-patch-DEMOS-on:
	@${REINPLACE_CMD} 's|#add_subdirectory(demos)|add_subdirectory(demos)|' ${WRKSRC}/CMakeLists.txt

post-patch-PLANNERARENA-off:
	@${REINPLACE_CMD} 's|find_program(R_EXEC|#&|' ${WRKSRC}/CMakeModules/OMPLDependencies.cmake

.include <bsd.port.mk>
