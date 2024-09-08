PORTNAME=	qmmp-plugin-pack
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/${PORTNAME}/${PORTVERSION:R}/ \
	SF/qmmp-dev/${PORTNAME}/${PORTVERSION:R}/
PKGNAMESUFFIX=	-qt5

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Additional plug-ins for QMMP (Qt5)
WWW=		https://qmmp.ylsoftware.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqmmpui-1.so:multimedia/qmmp-qt5
BUILD_DEPENDS=	qmmp-qt5>=1.5.0:multimedia/qmmp-qt5

CONFLICTS=	${PORTNAME}-qt6
PORTSCOUT=	limit:^1\..*

USES=		cmake pkgconfig qt:5 tar:bzip2
USE_QT=		core gui widgets \
		buildtools:build linguisttools:build qmake:build
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes

OPTIONS_MULTI=	PLUGINS
OPTIONS_MULTI_PLUGINS=	FFAP FFVIDEO GOOM MODPLUG SRCONV YTB
OPTIONS_DEFAULT=	FFAP FFVIDEO GOOM MODPLUG YTB
OPTIONS_DEFINE_i386=	FFAPASM GOOMASM
OPTIONS_DEFAULT_i386=	FFAPASM GOOMASM
OPTIONS_DEFINE_amd64=	FFAPASM GOOMASM
OPTIONS_DEFAULT_amd64=	FFAPASM GOOMASM

FFAP_DESC=		Support APE sound file
FFAP_LIB_DEPENDS=	libtag.so:audio/taglib
FFAP_CMAKE_BOOL=	USE_FFAP

FFAPASM_DESC=		Optimize FFap decoder using devel/yasm
FFAPASM_BUILD_DEPENDS=	yasm:devel/yasm
FFAPASM_CMAKE_BOOL=	USE_ASM

FFVIDEO_DESC=		FFmpeg video
FFVIDEO_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFVIDEO_CMAKE_BOOL=	USE_FFVIDEO

GOOM_DESC=		Goom spectacle
GOOM_CMAKE_BOOL=	USE_GOOM
GOOMASM_DESC=		Optimize Goom spectacle using devel/yasm
GOOMASM_BUILD_DEPENDS=	yasm:devel/yasm
GOOMASM_CMAKE_BOOL=	GOOM_ASM

MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CMAKE_BOOL=	USE_MODPLUG

SRCONV_DESC=		Support the sample rate converter
SRCONV_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SRCONV_CMAKE_BOOL=	USE_SRC

YTB_DESC=		YouTube plugin
YTB_USE=		QT=network
YTB_CMAKE_BOOL=		USE_YTB

PLIST_SUB+=		APP_SUFFIX=${PORTVERSION:R}

pre-configure:
	@${RM} ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.mk>
