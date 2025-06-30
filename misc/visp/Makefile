PORTNAME=	visp
DISTVERSION=	3.6.0
PORTREVISION=	12
CATEGORIES=	misc
MASTER_SITES=	https://visp-doc.inria.fr/download/releases/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular library for visual tracking and visual servoing
WWW=		https://visp.inria.fr/ \
		https://github.com/lagadic/visp

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	doxygen:devel/doxygen \
		latex:print/tex-formats \
		nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libblas.so:math/blas \
		libboost_system.so:devel/boost-libs \
		libdmtx.so:graphics/libdmtx \
		libflann.so:math/flann \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas \
		libopencv_core.so:graphics/opencv \
		libopencv_videoio.so:graphics/opencv \
		libpcap.so:net/libpcap \
		libpng.so:graphics/png \
		libv4l2.so:multimedia/libv4l \
		libdc1394.so:multimedia/libdc1394

USES=		cmake compiler:c++14-lang eigen:3 fortran gl gnome jpeg python:build qt:5 xorg zip
USE_QT=		opengl widgets
USE_GNOME=	libxml2
USE_XORG=	ice sm x11 xext
USE_GL=		gl glu opengl
USE_LDCONFIG=	yes

CMAKE_OFF=	WITH_QBDEVICE BUILD_EXAMPLES BUILD_TUTORIALS BUILD_TESTS BUILD_DEMOS

CXXFLAGS+=	-I${LOCALBASE}/include/vtk-${VTK_VER} # https://github.com/lagadic/visp/issues/1707

OPTIONS_DEFINE=		COIN OGRE PCL ZBAR
OPTIONS_DEFAULT=	COIN OGRE PCL ZBAR

COIN_DESC=		Use Coin3D for simulation or augmented reality capabilities
COIN_CMAKE_BOOL=	USE_COIN3D
COIN_LIB_DEPENDS=	libCoin.so:graphics/Coin

OGRE_DESC=		Include Ogre support for 3D Rendering
OGRE_CMAKE_BOOL=	USE_OGRE
OGRE_LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d19

PCL_DESC=		Include Point Cloud Library support
PCL_CMAKE_BOOL=		USE_PCL
PCL_LIB_DEPENDS=	libpcl_common.so:graphics/pcl-pointclouds \
			libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R} # vtk9 is incurred by pcl-pointclouds

ZBAR_DESC=		Use ZBAR to read bar codes and QR codes
ZBAR_CMAKE_BOOL=	USE_ZBAR
ZBAR_LIB_DEPENDS=	libzbar.so:graphics/zbar

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
