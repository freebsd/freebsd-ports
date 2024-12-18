PORTNAME=	dlib
DISTVERSIONPREFIX=v
DISTVERSION=	19.24.6
PORTREVISION=	1
CATEGORIES=	science devel math
PKGNAMESUFFIX=	-cpp

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Machine learning framework written in C++
WWW=		http://dlib.net

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/dlib/LICENSE.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libgif.so:graphics/giflib

USES=			cmake compiler:c++11-lang pkgconfig sqlite tar:bzip2 xorg
USE_LDCONFIG=		yes
USE_XORG=		ice sm x11 xext

USE_GITHUB=		yes
GH_ACCOUNT=		davisking

CMAKE_ON=		BUILD_SHARED_LIBS

OPTIONS_DEFINE=		BLASLAPACK FFMPEG

BLASLAPACK_DESC=	Use OpenBLAS for matrix operations
FFMPEG_DESC=		Build with the FFMPEG wrappers

BLASLAPACK_USES=	blaslapack:openblas
BLASLAPACK_CMAKE_OFF=	-DDLIB_USE_BLAS=0 -DDLIB_USE_LAPACK=0
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

.include <bsd.port.mk>
