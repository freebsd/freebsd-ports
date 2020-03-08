# $FreeBSD$

PORTNAME=	libopenshot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5-4
DISTVERSIONSUFFIX=	-gf1e5c9c
CATEGORIES=	multimedia
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

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
USE_PYTHON=	flavors
USE_QT=		core gui network multimedia widgets qmake_build buildtools_build

CMAKE_ON=	USE_SYSTEM_JSONCPP DISABLE_BUNDLED_JSONCPP\
		CMAKE_DISABLE_FIND_PACKAGE_Doxygen\
		CMAKE_DISABLE_FIND_PACKAGE_RESVG\
		CMAKE_DISABLE_FIND_PACKAGE_Ruby
CMAKE_OFF=	ENABLE_COVERAGE\
		ENABLE_DOCS\
		ENABLE_TESTS
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
LIBAV_DESC=		${FFMPEG_DESC:S/FFmpeg/Libav/}
LIBAV_LIB_DEPENDS=	libavformat.so:multimedia/libav

.include <bsd.port.mk>
