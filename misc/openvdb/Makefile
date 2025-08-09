PORTNAME=	openvdb
DISTVERSIONPREFIX=	v
DISTVERSION=	12.0.1
PORTREVISION=	2
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
CMAKE_TESTING_ON=	OPENVDB_BUILD_UNITTESTS # one test fails: https://github.com/AcademySoftwareFoundation/openvdb/issues/1103

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

# 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
