PORTNAME=	libopenshot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.7
PORTREVISION=	2
CATEGORIES=	multimedia
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	OpenShot Video Library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig:devel/swig \
		${LOCALBASE}/include/zmq.hpp:net/cppzmq
LIB_DEPENDS=	libopenshot-audio.so:audio/libopenshot-audio \
		libjsoncpp.so:devel/jsoncpp \
		libavformat.so:multimedia/ffmpeg \
		libzmq.so:net/libzmq4

USES=		cmake pkgconfig python:3.6+ qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	OpenShot
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		core gui network multimedia widgets qmake_build buildtools_build
CMAKE_ON=	USE_SYSTEM_JSONCPP DISABLE_BUNDLED_JSONCPP\
		USE_HW_ACCEL ENABLE_PYTHON\
		CMAKE_DISABLE_FIND_PACKAGE_Catch2\
		CMAKE_DISABLE_FIND_PACKAGE_Resvg\
		CMAKE_DISABLE_FIND_PACKAGE_Ruby
CMAKE_OFF=	ENABLE_COVERAGE BUILD_TESTING ENABLE_TESTS\
		ENABLE_RUBY

OPTIONS_DEFINE=	DOCS IMAGEMAGICK OPENCV
OPTIONS_DEFAULT=	IMAGEMAGICK
OPTIONS_SUB=	yes
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_BOOL=	ENABLE_DOCS
DOCS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen
DOCS_CMAKE_ON=	-DCMAKE_INSTALL_DOCDIR:PATH=${DOCSDIR_REL:Q}
DOCS_PORTDOCS=	*
IMAGEMAGICK_USES=	magick
IMAGEMAGICK_CMAKE_BOOL=	ENABLE_MAGICK
IMAGEMAGICK_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_ImageMagick
OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv \
			libprotobuf.so:devel/protobuf
OPENCV_CMAKE_BOOL=	ENABLE_OPENCV
OPENCV_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenCV\
			CMAKE_DISABLE_FIND_PACKAGE_Protobuf
OPENCV_CMAKE_ON=	-DOpenCV_DIR:STRING=${LOCALBASE:Q}/cmake/opencv4

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

do-build-DOCS-on:
	@(cd ${BUILD_WRKSRC}; if ! ${DO_MAKE_BUILD} doc; then \
		(${ECHO_CMD} "===> ${.TARGET} failed unexpectedly.") | ${FMT_80} ; \
		${FALSE}; \
		fi)

.include <bsd.port.mk>
