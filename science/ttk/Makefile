PORTNAME=	ttk
DISTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Topology ToolKit: Topological data analysis and visualization
WWW=		https://topology-tool-kit.github.io \
		https://github.com/topology-tool-kit/ttk

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${LOCALBASE}/include/boost/functional/hash.hpp:devel/boost-libs \
		cli11>0:devel/cli11 \
		exprtk>0:math/exprtk \
		spectra>0:math/spectra \
		utf8cpp>0:devel/utf8cpp \
		websocketpp>0:devel/websocketpp \
		${PY_DEPENDS}
BUILD_DEPENDS+=	nlohmann-json>0:devel/nlohmann-json # is required by lib/cmake/paraview-5.11/vtk/VTK-vtk-module-find-packages.cmake:1167
BUILD_DEPENDS+=	fast_float>0:math/fast_float # attempt to fix build failures triggered by find_package(fastfloat) from paraview's vtk cmake scripts
LIB_DEPENDS=	libcgraph.so:graphics/graphviz \
		libembree3.so:graphics/embree3 \
		libfreetype.so:print/freetype2 \
		libjsoncpp.so:devel/jsoncpp \
		libqhull_r.so:math/qhull \
		libvtkRenderingCore-pv${PARAVIEW_VER}.so:science/paraview \
		libzfp.so:devel/zfp
RUN_DEPENDS=	${PY_DEPENDS}

USES=		cmake eigen:3 compiler:c++11-lang gl python sqlite xorg
USE_GL=		glew
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	topology-tool-kit

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	TTK_ENABLE_WEBSOCKETPP # fix build with boost-1.87+ until this is fixed

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/include/Python.h

.include <../../science/paraview/Makefile.version>
.include <bsd.port.mk>
