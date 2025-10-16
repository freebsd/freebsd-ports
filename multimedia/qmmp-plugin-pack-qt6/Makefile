PORTNAME=	qmmp-plugin-pack
PORTVERSION=	2.3.0
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/${PORTNAME}/${PORTVERSION:R}/ \
	SF/qmmp-dev/${PORTNAME}/${PORTVERSION:R}/
PKGNAMESUFFIX=	-qt6

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Additional plug-ins for QMMP (Qt6)
WWW=		https://qmmp.ylsoftware.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqmmpui.so:multimedia/qmmp-qt6
BUILD_DEPENDS=	qmmp-qt6>=2.3:multimedia/qmmp-qt6

CONFLICTS=	${PORTNAME}-qt5
PORTSCOUT=	limit:^1\..*

USES=		cmake pkgconfig qt:6 tar:bzip2
USE_QT=		base tools:build
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes

OPTIONS_MULTI=	PLUGINS
OPTIONS_MULTI_PLUGINS=	FFAP FFVIDEO GOOM MODPLUG SRCONV YTB
OPTIONS_DEFAULT=	FFAP FFVIDEO GOOM MODPLUG YTB
OPTIONS_DEFINE_i386=	FFAPASM GOOMASM
OPTIONS_DEFAULT_i386=	FFAPASM GOOMASM
OPTIONS_DEFINE_amd64=	FFAPASM GOOMASM
OPTIONS_DEFAULT_amd64=	FFAPASM GOOMASM

CMAKE_OFF=	USE_MMS \
		USE_MPLAYER

FFAP_DESC=		Support APE sound file
FFAP_LIB_DEPENDS=	libtag.so:audio/taglib
FAAP_USES=		iconv
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
YTB_CMAKE_BOOL=		USE_YTB

PLIST_SUB+=		APP_SUFFIX=${PORTVERSION:R}

pre-configure:
	@${RM} ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.mk>
