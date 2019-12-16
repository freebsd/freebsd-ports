# $FreeBSD$

PORTNAME=	darknet
DISTVERSIONPREFIX=	darknet_yolo_v
DISTVERSION=	3-446
DISTVERSIONSUFFIX=	-gf2fc239
PORTEPOCH=	1
CATEGORIES=	math # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source neural networks in C

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libomp.so:devel/openmp

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	AlexeyAB
USE_LDCONFIG=	yes

CMAKE_OFF=	ENABLE_CUDA ENABLE_CUDNN ENABLE_CUDNN_HALF ENABLE_VCPKG_INTEGRATION

PLIST_FILES=	bin/darknet \
		include/darknet.h \
		include/yolo_v2_class.hpp \
		lib/libdark.so

OPTIONS_DEFINE=		OPENCV
OPTIONS_DEFAULT=	OPENCV
# Many secondary functions in DarkNet depend on OpenCV which is a large dependency.
# Build with OPENCV=off for a self-contained executable which would support
# core NN computations but would not support many visualization, training and
# other features.

OPENCV_USES=		pkgconfig
OPENCV_CMAKE_BOOL=	ENABLE_OPENCV
OPENCV_LIB_DEPENDS=	libopencv_video.so:graphics/opencv \
			libopencv_core.so:graphics/opencv-core

do-install: # https://github.com/AlexeyAB/darknet/issues/4527
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darknet ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}
	${INSTALL_DATA} ${BUILD_WRKSRC}/libdark.so ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdark.so

.include <bsd.port.mk>
