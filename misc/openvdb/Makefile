PORTNAME=	openvdb
DISTVERSIONPREFIX=	v
DISTVERSION=	13.1.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools for storage and manipulation of sparse volumetric data
WWW=		https://www.openvdb.org/ \
		https://github.com/AcademySoftwareFoundation/openvdb

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblosc.so:archivers/c-blosc \
		libboost_iostreams.so:devel/boost-libs \
		libImath.so:math/Imath \
		libtbb.so:devel/onetbb
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation

CMAKE_ARGS=		-DCONCURRENT_MALLOC="Tbbmalloc" -DTbb_INCLUDE_DIR=${LOCALBASE}/include
CMAKE_OFF=		OPENVDB_CORE_STATIC
CMAKE_TESTING_ON=	OPENVDB_BUILD_UNITTESTS

TEST_ENV=		${MAKE_ENV} TMPDIR=${WRKDIR}/tmp GTEST_FILTER=-TestStreamCompression.testPagedStreams

pre-test:
	@${MKDIR} ${WRKDIR}/tmp

OPTIONS_DEFINE=		TOOLS #DOCS # TOOLS should be made into a subpackage
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes

TOOLS_DESC=		Build CLI tools
TOOLS_CMAKE_BOOL=	OPENVDB_BUILD_BINARIES OPENVDB_BUILD_VDB_LOD \
			OPENVDB_BUILD_VDB_RENDER OPENVDB_BUILD_VDB_VIEW
TOOLS_LIB_DEPENDS=	libglfw.so:graphics/glfw \
			libOpenEXR.so:graphics/openexr
TOOLS_USES=		gl xorg
TOOLS_USE=		GL=gl,glu XORG=ice,sm,x11,xcursor,xext,xi,xinerama,xrandr,xxf86vm

# DOCS is broken: https://github.com/AcademySoftwareFoundation/openvdb/issues/899
#DOCS_CMAKE_BOOL=	OPENVDB_BUILD_DOCS
#DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

#PORTDOCS=	*

# tests as of 13.1.0:
# [==========] 769 tests from 148 test suites ran. (42610 ms total)
# [  PASSED  ] 769 tests.
# TestStreamCompression.testPagedStreams is excluded (flaky; upstream issue #2133).

.include <bsd.port.mk>
