# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	zxing-cpp
DISTVERSION=	0.20190320
PORTREVISION=	4
CATEGORIES=	textproc

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	9e5dfa57f3b998bc3049bfa893b20e81dea656df.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ZXing C++ Library for QR code recognition

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang iconv
USE_GITHUB=	yes
GH_ACCOUNT=	glassechidna
GH_TAGNAME=	e0e40dd
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		OPENCV # only one .cpp module in the project depends on OpenCV
OPTIONS_SUB=		yes

OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv-core \
			libopencv_photo.so:graphics/opencv

post-patch-OPENCV-off:
	@${REINPLACE_CMD} 's|find_package(OpenCV)|#&|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
