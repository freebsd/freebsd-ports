PORTNAME=	dartsim
DISTVERSIONPREFIX=	v
DISTVERSION=	6.15.0
PORTREVISION=	8
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Animation and Robotics Toolkit
WWW=		https://dartsim.github.io/ \
		https://github.com/dartsim/dart

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
		libosg.so:graphics/osg \
		libnlopt.so:math/nlopt \
		libpagmo.so:science/pagmo2 \
		libtinyxml2.so:textproc/tinyxml2 \
		liburdfdom_world.so:devel/ros-urdfdom
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang eigen:3,build,run gl localbase:ldflags \
		pkgconfig python xorg
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_CXXSTD=	c++17 # missing in the project, it uses std::void_t (through pagmo2) which is a c++17 feature
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_PROJECT=	dart

CXXFLAGS+=	-I${LOCALBASE}/include/coin # because of pagmo2 headers include <IpReturnCodes.hpp>

CMAKE_ON=	BUILD_SHARED_LIBS DART_USE_SYSTEM_GOOGLETEST # DART_VERBOSE
CMAKE_OFF=	BUILD_TESTING
CMAKE_OFF+=	DART_TREAT_WARNINGS_AS_ERRORS # workaround for https://github.com/dartsim/dart/issues/1799
CMAKE_ARGS=	-DODE_DIR=${LOCALBASE} \
		-DFREEBSD_PYTHON_VER=${PYTHON_VER}
CMAKE_TESTING_TARGET=	tests # only builds test

DATADIR=	share/dart
DOCSDIR=	${PREFIX}/share/doc/dart

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

post-test: # run tests: 8 tests fail, see https://github.com/dartsim/dart/issues/1797#issuecomment-2191988407
	@cd ${BUILD_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
