# $FreeBSD$

PORTNAME=	libopenshot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3-490
DISTVERSIONSUFFIX=	-gc271352
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
		libomp.so:devel/openmp \
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
		CMAKE_DISABLE_FIND_PACKAGE_ImageMagick\
		CMAKE_DISABLE_FIND_PACKAGE_RESVG\
		CMAKE_DISABLE_FIND_PACKAGE_Ruby
OPTIONS_DEFAULT=	FFMPEG
OPTIONS_SINGLE=	LIBAVCODEC
OPTIONS_SINGLE_LIBAVCODEC=	FFMPEG LIBAV
FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
LIBAV_LIB_DEPENDS=	libavformat.so:multimedia/libav

.include <bsd.port.mk>
