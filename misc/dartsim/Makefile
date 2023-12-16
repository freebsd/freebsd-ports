PORTNAME=	dartsim
DISTVERSIONPREFIX=	v
DISTVERSION=	6.13.0
PORTREVISION=	4
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Animation and Robotics Toolkit
WWW=		https://dartsim.github.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	clang failure: https://bugs.llvm.org/show_bug.cgi?id=41757

BUILD_DEPENDS=	pagmo2>0:science/pagmo2 \
		pybind11>0:devel/pybind11
LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libBulletDynamics.so:devel/bullet \
		libboost_system.so:devel/boost-libs \
		libccd.so:math/libccd \
		libconsole_bridge.so:devel/ros-console_bridge \
		libfcl.so:math/fcl \
		libflann_cpp.so:math/flann \
		libfmt.so:devel/libfmt \
		libipopt.so:math/ipopt \
		liblz4.so:archivers/liblz4 \
		liboctomap.so:math/octomap \
		libode.so:devel/ode \
		libosg.so:graphics/osg34 \
		libnlopt.so:math/nlopt \
		libpagmo.so:science/pagmo2 \
		libtinyxml2.so:textproc/tinyxml2 \
		liburdfdom_world.so:devel/ros-urdfdom

USES=		cmake compiler:c++17-lang eigen:3,build,run gl localbase:ldflags \
		pkgconfig python xorg
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_CXXSTD=	c++17 # missing in the project, it uses std::void_t (through pagmo2) which is a c++17 feature
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_PROJECT=	dart

CXXFLAGS+=	-I${LOCALBASE}/include/coin # because of pagmo2 headers include <IpReturnCodes.hpp>

CMAKE_ON=	BUILD_SHARED_LIBS # DART_VERBOSE
CMAKE_ARGS=	-DODE_DIR=${LOCALBASE}

DATADIR=	share/dart
DOCSDIR=	${PREFIX}/share/doc/dart

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

.include <bsd.port.mk>
