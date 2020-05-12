# $FreeBSD$

PORTNAME=	openvdb
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.0
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools for storage and manipulation of sparse volumetric data

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblosc.so:archivers/c-blosc \
		libboost_system.so:devel/boost-libs \
		libHalf.so:graphics/ilmbase \
		libtbb.so:devel/tbb

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCONCURRENT_MALLOC="Tbbmalloc"
CMAKE_OFF=	OPENVDB_CORE_STATIC

OPTIONS_DEFINE=		PYTHON TOOLS DOCS # TOOLS and PYTHON should be made into subpackages
OPTIONS_DEFAULT=	PYTHON TOOLS
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	OPENVDB_BUILD_PYTHON_MODULE
PYTHON_CMAKE_ON=	-DFREEBSD_PYTHON_VER:STRING=${PYTHON_VER} -DUSE_NUMPY:BOOL=ON
PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY}

TOOLS_DESC=		Build CLI tools
TOOLS_CMAKE_BOOL=	OPENVDB_BUILD_BINARIES OPENVDB_BUILD_VDB_LOD \
			OPENVDB_BUILD_VDB_RENDER OPENVDB_BUILD_VDB_VIEW
TOOLS_LIB_DEPENDS=	libglfw.so:graphics/glfw \
			libIlmImf.so:graphics/openexr
TOOLS_USES=		gl xorg
TOOLS_USE=		GL=gl,glu XORG=ice,sm,x11,xcursor,xext,xi,xinerama,xrandr,xxf86vm

DOCS_CMAKE_BOOL=	OPENVDB_BUILD_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

PORTDOCS=	*

.include <bsd.port.mk>
