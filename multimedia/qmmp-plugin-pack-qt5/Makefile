# $FreeBSD$

PORTNAME=	qmmp-plugin-pack
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/plugins/ \
	SF/qmmp-dev/${PORTNAME}/
PKGNAMESUFFIX=	-qt5

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Additional plug-ins for QMMP (Qt5)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqmmpui.so:multimedia/qmmp-qt5
BUILD_DEPENDS=	qmmp-qt5>=1.2.0:multimedia/qmmp-qt5

CONFLICTS=	${PORTNAME}-0.*
PORTSCOUT=	limit:^1\..*

USES=		cmake:outsource pkgconfig tar:bzip2
USE_QT5=	core gui widgets \
		buildtools_build linguisttools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes

OPTIONS_MULTI=	PLUGINS
OPTIONS_MULTI_PLUGINS=	FFAP FFVIDEO GOOM HISTORY MPG123 SRCONV XMP
OPTIONS_DEFAULT=	FFAP FFVIDEO GOOM HISTORY MPG123 XMP
OPTIONS_DEFINE_i386=	FFAPASM GOOMASM
OPTIONS_DEFAULT_i386=	FFAPASM GOOMASM
OPTIONS_DEFINE_amd64=	FFAPASM GOOMASM
OPTIONS_DEFAULT_amd64=	FFAPASM GOOMASM

FFAP_DESC=		Support APE sound file
FFAP_LIB_DEPENDS=	libtag.so:audio/taglib
FFAP_CMAKE_BOOL=	USE_FFAP
FFAPASM_DESC=	Optimize FFap decoder using devel/yasm
FFAPASM_BUILD_DEPENDS=	yasm:devel/yasm
FFAPASM_CMAKE_BOOL=	USE_ASM

FFVIDEO_DESC=	FFmpeg video
FFVIDEO_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFVIDEO_CMAKE_BOOL=	USE_FFVIDEO

GOOM_DESC=	Goom spectacle
GOOM_CMAKE_BOOL=	USE_GOOM
GOOMASM_DESC=	Optimize Goom spectacle using devel/yasm
GOOMASM_BUILD_DEPENDS=	yasm:devel/yasm
GOOMASM_CMAKE_BOOL=	GOOM_ASM

HISTORY_DESC=	Information about listened tracks
HISTORY_USE=	QT5=sql
HISTORY_CMAKE_BOOL=	USE_HISTORY

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123 \
		libtag.so:audio/taglib
MPG123_CMAKE_BOOL=	USE_MPG123

SRCONV_DESC=	Support the sample rate converter
SRCONV_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SRCONV_CMAKE_BOOL=	USE_SRC

XMP_DESC=		Support various module formats using libxmp
XMP_LIB_DEPENDS=	libxmp.so:audio/libxmp
XMP_CMAKE_BOOL=	USE_XMP

pre-configure:
	@${RM} ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.mk>
