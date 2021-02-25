# $FreeBSD$

PORTNAME=	libopenshot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5-517
DISTVERSIONSUFFIX=	-gdd2735e
CATEGORIES=	multimedia
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	OpenShot Video Library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig:devel/swig \
		unittest-cpp>=0:devel/unittest-cpp \
		${LOCALBASE}/include/zmq.hpp:net/cppzmq
LIB_DEPENDS=	libopenshot-audio.so:audio/libopenshot-audio \
		libjsoncpp.so:devel/jsoncpp \
		libavformat.so:multimedia/ffmpeg \
		libzmq.so:net/libzmq4

USES=		cmake compiler:c++11-lang pkgconfig python:3.5+ qt:5
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	OpenShot
USE_PYTHON=	flavors
USE_QT=		core gui network multimedia widgets qmake_build buildtools_build

CMAKE_ON=	USE_SYSTEM_JSONCPP DISABLE_BUNDLED_JSONCPP\
		CMAKE_DISABLE_FIND_PACKAGE_Doxygen\
		CMAKE_DISABLE_FIND_PACKAGE_Resvg\
		CMAKE_DISABLE_FIND_PACKAGE_Ruby
CMAKE_OFF=	ENABLE_COVERAGE\
		ENABLE_DOCS\
		ENABLE_TESTS
OPTIONS_DEFINE=	IMAGEMAGICK OPENCV
OPTIONS_DEFAULT=	IMAGEMAGICK
OPTIONS_SUB=	yes
IMAGEMAGICK_LIB_DEPENDS=	libMagick++-${IMAGEMAGICK_DEFAULT}.so:graphics/ImageMagick${IMAGEMAGICK_DEFAULT}
IMAGEMAGICK_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_ImageMagick
OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv \
			libprotobuf.so:devel/protobuf
OPENCV_CMAKE_ON=	-DOpenCV_DIR:STRING=${LOCALBASE:Q}/cmake/opencv4
OPENCV_CMAKE_BOOL=	ENABLE_OPENCV
OPENCV_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenCV\
			CMAKE_DISABLE_FIND_PACKAGE_Protobuf

.include <bsd.port.mk>
