# $FreeBSD$

PORTNAME=	visp
DISTVERSION=	3.2.0
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/latestfile/475/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular library for visual tracking and visual servoing

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libblas.so:math/blas \
		libboost_system.so:devel/boost-libs \
		libdmtx.so:graphics/libdmtx \
		libflann.so:math/flann \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack \
		libopencv_core.so:graphics/opencv-core \
		libopencv_videoio.so:graphics/opencv \
		libpcl_common.so:graphics/pcl-pointclouds \
		libqhull.so:math/qhull5 \
		libpng.so:graphics/png \
		libv4l2.so:multimedia/libv4l

USES=		cmake compiler:c++11-lang eigen:3 fortran gnome jpeg xorg
USE_GNOME=	libxml2
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_EXAMPLES BUILD_TUTORIALS BUILD_TESTS BUILD_DEMOS

OPTIONS_DEFINE=		OGRE

OGRE_DESC=		Include Ogre support
OGRE_CMAKE_BOOL=	USE_OGRE
OGRE_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libOgreMain.so:graphics/ogre3d19

.include <bsd.port.mk>
