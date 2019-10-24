# $FreeBSD$

PORTNAME=	darknet
PORTVERSION=	g20180914
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source neural networks in C

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake
USE_GITHUB=	yes
GH_ACCOUNT=	pjreddie
GH_TAGNAME=	61c9d02
USE_LDCONFIG=	yes

MAKE_ARGS=	OPTS=-O3 CC=${CC} CPP=${CXX}

PLIST_FILES=	bin/darknet \
		include/darknet.h \
		lib/libdarknet.a \
		lib/libdarknet.so

OPTIONS_DEFINE=		OPENCV OPENMP
OPTIONS_DEFAULT=	OPENCV OPENMP
# Many secondary functions in DarkNet depend on OpenCV which is a large dependency.
# Build with OPENCV=off for a self-contained executable which would support
# core NN computations but would not support many visualization, training and
# other features.

OPENCV_USES=	pkgconfig
OPENCV_MAKE_ARGS=	OPENCV=1
OPENCV_LIB_DEPENDS=	libopencv_video.so:graphics/opencv \
			libopencv_core.so:graphics/opencv-core

OPENMP_MAKE_ARGS=	OPENMP=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darknet ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}
	${INSTALL_DATA} ${WRKSRC}/libdarknet.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libdarknet.a ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdarknet.so

.include <bsd.port.mk>
