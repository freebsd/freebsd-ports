# $FreeBSD$

PORTNAME=	libav
PORTVERSION=	9.10
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	http://libav.org/releases/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Realtime audio/video conversion library

CONFLICTS=	ffmpeg-[0-9]*

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		texi2html:${PORTSDIR}/textproc/texi2html

USES=		pkgconfig:build gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
WANT_SDL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--prefix="${PREFIX}" \
			--mandir="${PREFIX}/man" \
			--datadir="${DATADIR}" \
			--enable-pthreads \
			--enable-shared \
			--enable-runtime-cpudetect \
			--disable-avserver

OPTIONS_DEFINE=	ALSA AMR_NB AMR_WB BZIP2 CDIO FAAC FDK_AAC FREETYPE FREI0R \
		GNUTLS GSM ILBC JACK LAME OPENCV OPENJPEG OPENSSL OPUS \
		PULSEAUDIO RTMP SCHROEDINGER SPEEX THEORA V4L2 VAAPI VDPAU \
		VO_AACENC VO_AMRWBENC VORBIS VPX X264 XVID ZLIB

OPTIONS_DEFAULT=	BZIP2 FREETYPE FREI0R GNUTLS OPENCV SCHROEDINGER \
			THEORA VPX X264 XVID

FDK_AAC_DESC=	AAC audio encoding via Fraunhofer FDK
ILBC_DESC=	iLBC en/decoding via libilbc
OPUS_DESC=	Opus decoding with libopus

ALSA_LIB_DEPENDS=		libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_ON=		--enable-indev=alsa --enable-outdev=alsa
ALSA_CONFIGURE_OFF=		--disable-indev=alsa --disable-outdev=alsa

AMR_NB_LIB_DEPENDS=		libopencore-amrnb.so:${PORTSDIR}/audio/opencore-amr
AMR_NB_CONFIGURE_ENABLE=	libopencore-amrnb

AMR_WB_LIB_DEPENDS=		libopencore-amrnb.so:${PORTSDIR}/audio/opencore-amr
AMR_WB_CONFIGURE_ENABLE=	libopencore-amrwb

BZIP2_CONFIGURE_ENABLE=		bzlib

CDIO_LIB_DEPENDS=		libcdio.so:${PORTSDIR}/sysutils/libcdio
CDIO_CONFIGURE_ENABLE=		libcdio

# --enable-libdc1394
# DC1394_LIB_DEPENDS=		libdc1394.so:${PORTSDIR}/multimedia/libdc1394
# DC1394_CONFIGURE_ENABLE=	libdc1394

FREI0R_BUILD_DEPENDS=		${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
FREI0R_CONFIGURE_ENABLE=	frei0r

FAAC_LIB_DEPENDS=		libfaac.so:${PORTSDIR}/audio/faac
FAAC_CONFIGURE_ENABLE=		libfaac

FDK_AAC_LIB_DEPENDS=		libfdk-aac.so:${PORTSDIR}/audio/fdk-aac
FDK_AAC_CONFIGURE_ENABLE=	libfdk-aac

FREETYPE_LIB_DEPENDS=		libfreetype.so:${PORTSDIR}/print/freetype2
FREETYPE_CONFIGURE_ENABLE=	libfreetype

GNUTLS_LIB_DEPENDS=		libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_ENABLE=	gnutls

GSM_LIB_DEPENDS=		libgsm.so:${PORTSDIR}/audio/gsm
GSM_CONFIGURE_ENABLE=		libgsm

ILBC_BUILD_DEPENDS=		${LOCALBASE}/include/ilbc.h:${PORTSDIR}/net/libilbc
ILBC_CONFIGURE_ENABLE=		libilbc

JACK_LIB_DEPENDS=		libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ENABLE=		indev=jack

LAME_LIB_DEPENDS=		libmp3lame.so:${PORTSDIR}/audio/lame
LAME_CONFIGURE_ENABLE=		libmp3lame

OPENCV_LIB_DEPENDS=		libopencv_imgproc.so:${PORTSDIR}/graphics/opencv-core \
				libopencv_gpu.so:${PORTSDIR}/graphics/opencv
OPENCV_CONFIGURE_ENABLE=	libopencv

OPENJPEG_LIB_DEPENDS=		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg
OPENJPEG_CONFIGURE_ENABLE=	libopenjpeg

OPENSSL_CONFIGURE_ENABLE=	openssl

OPUS_LIB_DEPENDS=		libopus.so:${PORTSDIR}/audio/opus
OPUS_CONFIGURE_ENABLE=		libopus

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	libpulse

RTMP_LIB_DEPENDS=		librtmp.so:${PORTSDIR}/multimedia/librtmp
RTMP_CONFIGURE_ENABLE=		librtmp

SCHROEDINGER_LIB_DEPENDS=	libschroedinger-1.0.so:${PORTSDIR}/multimedia/schroedinger
SCHROEDINGER_CONFIGURE_ENABLE=	libschroedinger

SPEEX_LIB_DEPENDS=		libspeex.so:${PORTSDIR}/audio/speex
SPEEX_CONFIGURE_ENABLE=		libspeex

THEORA_LIB_DEPENDS=		libtheora.so:${PORTSDIR}/multimedia/libtheora
THEORA_CONFIGURE_ENABLE=	libtheora

V4L2_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
V4L2_CONFIGURE_ENABLE=		indev=v4l2

VAAPI_LIB_DEPENDS=		libva.so:${PORTSDIR}/multimedia/libva
VAAPI_CONFIGURE_ENABLE=		vaapi

VDPAU_BUILD_DEPENDS=		${LOCALBASE}/include/vdpau/vdpau.h:${PORTSDIR}/multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=		vdpau

VO_AACENC_LIB_DEPENDS=		libvo-aacenc.so:${PORTSDIR}/audio/vo-aacenc
VO_AACENC_CONFIGURE_ENABLE=	libvo-aacenc

VO_AMRWBENC_LIB_DEPENDS=	libvo-amrwbenc.so:${PORTSDIR}/audio/vo-amrwbenc
VO_AMRWBENC_CONFIGURE_ENABLE=	libvo-amrwbenc

VORBIS_LIB_DEPENDS=		libvorbisenc.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	libvorbis

VPX_LIB_DEPENDS=		libvpx.so:${PORTSDIR}/multimedia/libvpx
VPX_CONFIGURE_ENABLE=		libvpx

X264_LIB_DEPENDS=		libx264.so:${PORTSDIR}/multimedia/x264
X264_CONFIGURE_ENABLE=		libx264

XVID_LIB_DEPENDS=		libxvidcore.so:${PORTSDIR}/multimedia/xvid
XVID_CONFIGURE_ENABLE=		libxvid

ZLIB_CONFIGURE_ENABLE=		zlib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_SDL:Msdl}
USE_SDL+=	sdl
MAN1+=		avplay.1
CONFIGURE_ARGS+=	--enable-avplay
PLIST_SUB+=	AVPLAY=""
.else
CONFIGURE_ARGS+=	--disable-avplay
PLIST_SUB+=	AVPLAY="@comment "
.endif

# License definitions

.if ${PORT_OPTIONS:MFAAC} || ${PORT_OPTIONS:MFDK_AAC} || ${PORT_OPTIONS:MOPENSSL}
RESTRICTED=	linking to libfaac or libaacplus or using OpenSSL support restricts redistribution
CONFIGURE_ARGS+=	--enable-nonfree
AV_NONFREE=		true
.endif

.if ${PORT_OPTIONS:MCDIO} || ${PORT_OPTIONS:MX264} || ${PORT_OPTIONS:MXVID} || ${PORT_OPTIONS:MX11GRAB}
CONFIGURE_ARGS+=	--enable-gpl
.if !defined(AV_NONFREE)
LICENSE=		GPLv2
AV_ISGPL=		true
.endif
.endif

.if ${PORT_OPTIONS:MAMR_NB} || ${PORT_OPTIONS:MAMR_WB} || ${PORT_OPTIONS:MVO_AACENC} || ${PORT_OPTIONS:MVO_AMRWBENC}
CONFIGURE_ARGS+=	--enable-version3
.if !defined(AV_NONFREE)
.if defined(AV_ISGPL)
LICENSE=	GPLv3
.else
LICENSE=	LGPL3
.endif
.endif
.endif

.if !defined(AV_NONFREE) && !defined(AV_ISGPL) && !defined(LICENSE)
LICENSE=	LGPL21
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gsm/gsm.h|gsm.h|' \
		${WRKSRC}/configure \
		${WRKSRC}/libavcodec/libgsm.c
	${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${STAGEDIR}${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/library.mak

.include <bsd.port.post.mk>
