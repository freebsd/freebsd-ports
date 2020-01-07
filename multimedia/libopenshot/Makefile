# $FreeBSD$

PORTNAME=	libopenshot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3-595
DISTVERSIONSUFFIX=	-ga1158ee
CATEGORIES=	multimedia

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	OpenShot Video Library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig3.0:devel/swig30 \
		unittest-cpp>=0:devel/unittest-cpp \
		${LOCALBASE}/include/zmq.hpp:net/cppzmq
LIB_DEPENDS=	libopenshot-audio.so:audio/libopenshot-audio \
		libjsoncpp.so:devel/jsoncpp \
		libzmq.so:net/libzmq4

USES=		cmake compiler:c++11-lang pkgconfig python:3.5+ qt:5
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	OpenShot
USE_PYTHON=	noflavors
USE_QT=		core gui network multimedia widgets qmake_build buildtools_build

CMAKE_ON=	USE_SYSTEM_JSONCPP DISABLE_BUNDLED_JSONCPP\
		DISABLE_TESTS\
		CMAKE_DISABLE_FIND_PACKAGE_Doxygen\
		CMAKE_DISABLE_FIND_PACKAGE_RESVG\
		CMAKE_DISABLE_FIND_PACKAGE_Ruby
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_ImageMagick:BOOL=ON
OPTIONS_DEFAULT=	FFMPEG
OPTIONS_RADIO=	IMAGEMAGICK
OPTIONS_RADIO_IMAGEMAGICK=	IMAGEMAGICK6 IMAGEMAGICK7
OPTIONS_SINGLE=	LIBAVCODEC
OPTIONS_SINGLE_LIBAVCODEC=	FFMPEG LIBAV
FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
IMAGEMAGICK6_DESC=	with ImageMagick6
IMAGEMAGICK6_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick6
IMAGEMAGICK6_CMAKE_ON=	-DCMAKE_DISABLE_FIND_PACKAGE_ImageMagick:BOOL=NO
IMAGEMAGICK7_DESC=	with ImageMagick7
IMAGEMAGICK7_LIB_DEPENDS=	libMagick++-7.so:graphics/ImageMagick7
IMAGEMAGICK7_CMAKE_ON=	-DCMAKE_DISABLE_FIND_PACKAGE_ImageMagick:BOOL=NO
LIBAV_LIB_DEPENDS=	libavformat.so:multimedia/libav

.if !exists(/usr/lib/libomp.so)
LIB_DEPENDS+=	libomp.so:devel/openmp
.endif

.include <bsd.port.mk>
