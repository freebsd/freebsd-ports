# $FreeBSD$

PORTNAME=	ccextractor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.85
PORTREVISION=	5
CATEGORIES=	multimedia

MAINTAINER=	oz@nixil.net
COMMENT=	Closed caption extractor for MPEG and H264 files

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libgnutls.so:security/gnutls \
		libogg.so:audio/libogg \
		libopencv_core.so:graphics/opencv-core \
		libpng.so:graphics/png \
		libschroedinger-1.0.so:multimedia/schroedinger \
		libtheoraenc.so:multimedia/libtheora \
		libv4l2.so:multimedia/libv4l \
		libva-x11.so:multimedia/libva \
		libvdpau.so:multimedia/libvdpau \
		libvorbisenc.so:audio/libvorbis \
		libvpx.so:multimedia/libvpx \
		libx264.so:multimedia/libx264 \
		libx265.so:multimedia/x265 \
		libxvidcore.so:multimedia/xvid

USES=		cmake:outsource iconv localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	CCExtractor
USE_XORG=	x11
USE_LDCONFIG=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DWITH_OCR:BOOL=OFF # fails: CFLAGS get semicolon-separated for some reason
CMAKE_ARGS+=	-DWITH_SHARING:BOOL=OFF # enable when net/nanomsg is available

OPTIONS_DEFINE=		FFMPEG
OPTIONS_DEFAULT=	FFMPEG

FFMPEG_BROKEN=		fails to build with ffmpeg 4.0
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

.include <bsd.port.mk>
