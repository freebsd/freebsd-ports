# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mediastreamer
PORTVERSION=	2.16.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.linphone.org/releases/sources/mediastreamer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time audio and video streaming and processing

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libortp.so:net/ortp \
		libspeexdsp.so:audio/speexdsp \
		libsrtp2.so:net/libsrtp2 \
		libbzrtp.so:security/bzrtp

USES=		cmake compiler python:build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_ALSA=NO -DENABLE_BV16=NO -DENABLE_DOC=NO \
		-DENABLE_JPEG=NO -DENABLE_OSS=YES -DENABLE_PULSEAUDIO=NO \
		-DENABLE_STATIC=NO -DENABLE_STRICT=NO -DENABLE_TOOLS=NO \
		-DENABLE_UNIT_TESTS=NO

OPTIONS_DEFINE=		MATROSKA VIDEO
OPTIONS_GROUP=		AUDIOOPT VIDEOOPT
OPTIONS_GROUP_AUDIOOPT=	G726 G729 GSM OPUS SPEEX
OPTIONS_GROUP_VIDEOOPT=	FFMPEG GLX THEORA V4L VPX XVIDEO
OPTIONS_DEFAULT=	MATROSKA VIDEO \
			G729 GSM OPUS SPEEX \
			FFMPEG GLX THEORA V4L VPX XVIDEO
OPTIONS_SUB=		yes

AUDIOOPT_DESC=		Audio options

FFMPEG_IMPLIES=		VIDEO
FFMPEG_CMAKE_BOOL=	ENABLE_FFMPEG
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

G726_CMAKE_BOOL=	ENABLE_G726
G726_DESC=		G.726 codec support
G726_LIB_DEPENDS=	libspandsp.so:comms/spandsp

G729_CMAKE_BOOL=	ENABLE_G729
G729_DESC=		G.729 codec support
G729_LIB_DEPENDS=	libbcg729.so:audio/bcg729

GLX_IMPLIES=		VIDEO
GLX_CMAKE_BOOL=		ENABLE_GL ENABLE_GLX
GLX_USE=		GL=glew

GSM_CMAKE_BOOL=		ENABLE_GSM
GSM_LIB_DEPENDS=	libgsm.so:audio/gsm

MATROSKA_CMAKE_BOOL=	ENABLE_MKV
MATROSKA_LIB_DEPENDS=	libbcmatroska2.so:multimedia/bcmatroska2

OPUS_CMAKE_BOOL=	ENABLE_OPUS
OPUS_LIB_DEPENDS=	libopus.so:audio/opus

SPEEX_CMAKE_BOOL=	ENABLE_SPEEX_CODEC
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex

THEORA_IMPLIES=		VIDEO
THEORA_CMAKE_BOOL=	ENABLE_THEORA
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora

V4L_IMPLIES=		VIDEO
V4L_CMAKE_BOOL=		ENABLE_V4L
V4L_BUILD_DEPENDS=	v4l_compat>=1.0.20120501:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

VIDEOOPT_DESC=		Video options

VIDEO_CMAKE_BOOL=	ENABLE_VIDEO

VPX_IMPLIES=		VIDEO
VPX_CMAKE_BOOL=		ENABLE_VPX
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx

XVIDEO_IMPLIES=		VIDEO
XVIDEO_CMAKE_BOOL=	ENABLE_X11 ENABLE_XV
XVIDEO_USE=		XORG=xorgproto,x11,xv

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's,gsm/gsm\.h,gsm.h,' \
		${WRKSRC}/cmake/FindGSM.cmake ${WRKSRC}/src/audiofilters/gsm.c
.if ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} '/-Wno-format-truncation/d' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
