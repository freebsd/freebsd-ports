# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	2.8.8
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	http://ffmpeg.org/releases/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	yasm:devel/yasm \
		${LOCALBASE}/bin/as:devel/binutils

HAS_CONFIGURE=	yes
USES=		compiler:c11 cpe gmake perl5 pkgconfig tar:bzip2 shebangfix
USE_LDCONFIG=	yes
USE_PERL5=	build
SHEBANG_FILES=	doc/texi2pod.pl

PORTSCOUT=	limit:^2\.

OPTIONS_DEFINE= AACPLUS ALSA AMR_NB AMR_WB ASS BS2B CACA CDIO CELT DC1394 \
		DEBUG DOCS FAAC FDK_AAC FFSERVER FLITE FONTCONFIG \
		FREETYPE FREI0R FRIBIDI GME GSM ICONV ILBC JACK KVAZAAR LADSPA \
		LAME LIBBLURAY MODPLUG OPENAL OPENCL OPENCV OPENGL \
		OPENH264 OPENJPEG OPTIMIZED_CFLAGS OPUS PULSEAUDIO QUVI \
		RTCPU RTMP SCHROEDINGER SDL SMB SNAPPY SPEEX SSH \
		THEORA TWOLAME V4L VAAPI VDPAU VIDSTAB VORBIS VO_AACENC \
		VO_AMRWBENC VPX WAVPACK WEBP X11GRAB X264 X265 XCB XVID \
		XVIDEO ZMQ ZVBI

OPTIONS_DEFAULT=	FFSERVER FONTCONFIG FREETYPE FREI0R GNUTLS ICONV \
			OPENCV RTCPU SCHROEDINGER THEORA V4L VAAPI VDPAU \
			VORBIS VPX X264 XVID

OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_GROUP=	LICENSE
OPTIONS_GROUP_LICENSE=	GPL3 NONFREE

OPTIONS_DEFINE_amd64=	MMX SSE
OPTIONS_DEFINE_armv6=	VFP NEON
OPTIONS_DEFINE_armv6hf=	VFP NEON
OPTIONS_DEFINE_i386=	MMX SSE
OPTIONS_DEFAULT_amd64=	MMX SSE
OPTIONS_DEFAULT_i386=	MMX SSE

ASS_DESC=	Subtitles rendering via libass
BS2B_DESC=	Bauer Stereophonic-to-Binaural filter
CDIO_DESC=	Audio CD grabbing with libcdio
DC1394_DESC=	IIDC-1394 grabbing using libdc1394
FDK_AAC_DESC=	AAC audio encoding via Fraunhofer FDK
FFSERVER_DESC=	Build and install ffserver
FLITE_DESC=	Voice synthesis support via libflite
GME_DESC=	Game Music Emu demuxer
GPL3_DESC=	Allow (L)GPL version 3 code(cs)
ILBC_DESC=	Internet Low Bit Rate codec
KVAZAAR_DESC=	H.265 video codec support via Kvazaar
LICENSE_DESC=	Licensing options
NEON_DESC=	Enable Media Processing Engine instructions
NONFREE_DESC=	Allow use of nonfree code
OPENH264_DESC=	H.264 video codec support via OpenH264
QUVI_DESC=	Flash media stream URLs
RTCPU_DESC=	Detect CPU capabilities at runtime
VFP_DESC=	Enable Vector Floating Point instructions
VIDSTAB_DESC=	Video stabilization filter
X11GRAB_DESC=	X11 grabbing (legacy)
XCB_DESC=	X11 grabbing using XCB
ZMQ_DESC=	Message passing via libzmq${ZMQ_VERSION}
ZVBI_DESC=	Teletext support via libzvbi

OPTIONS_SUB=	yes

# aacplus
AACPLUS_LIB_DEPENDS=	libaacplus.so:audio/libaacplus
AACPLUS_CONFIGURE_ENABLE=	libaacplus
AACPLUS_IMPLIES=	NONFREE

# alsa
ALSA_CONFIGURE_OFF=	--disable-indev=alsa \
			--disable-outdev=alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

# Opencore AMR NB
AMR_NB_LIB_DEPENDS=	libopencore-amrnb.so:audio/opencore-amr
AMR_NB_CONFIGURE_ENABLE=	libopencore-amrnb
AMR_NB_IMPLIES=		GPL3

# Opencore AMR WB
AMR_WB_LIB_DEPENDS=	libopencore-amrwb.so:audio/opencore-amr
AMR_WB_CONFIGURE_ENABLE=	libopencore-amrwb
AMR_WB_IMPLIES=		GPL3

# ass
ASS_LIB_DEPENDS=	libass.so:multimedia/libass
ASS_CONFIGURE_ENABLE=	libass

# bs2b
BS2B_LIB_DEPENDS=	libbs2b.so:audio/libbs2b
BS2B_CONFIGURE_ENABLE=	libbs2b

# caca
CACA_LIB_DEPENDS=	libcaca.so:graphics/libcaca
CACA_CONFIGURE_ENABLE=	libcaca

# cdio
CDIO_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia
CDIO_CONFIGURE_ENABLE=	libcdio

# celt
CELT_LIB_DEPENDS=	libcelt0.so:audio/celt
CELT_CONFIGURE_ENABLE=	libcelt

# dc1394
DC1394_LIB_DEPENDS=	libdc1394.so:multimedia/libdc1394
DC1394_CONFIGURE_ENABLE=	libdc1394

# debugging
DEBUG_CONFIGURE_ON=	--disable-stripping
DEBUG_CONFIGURE_OFF=	--disable-debug

# docs
DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html
DOCS_CONFIGURE_ENABLE=	htmlpages

# faac
FAAC_LIB_DEPENDS=	libfaac.so:audio/faac
FAAC_CONFIGURE_ENABLE=	libfaac
FAAC_IMPLIES=		NONFREE

# fdk_aac
FDK_AAC_LIB_DEPENDS=	libfdk-aac.so:audio/fdk-aac
FDK_AAC_CONFIGURE_ENABLE=	libfdk-aac
FDK_AAC_IMPLIES=	NONFREE

# ffserver
FFSERVER_CONFIGURE_ENABLE=	ffserver
FFSERVER_VARS=		USE_RC_SUBR+=ffserver

# flite
FLITE_LIB_DEPENDS=	libflite.so:audio/flite
FLITE_CONFIGURE_ENABLE=	libflite

# fontconfig
FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_ENABLE=	fontconfig

# freetype
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	libfreetype

# frei0r
FREI0R_BUILD_DEPENDS=	${LOCALBASE}/include/frei0r.h:graphics/frei0r
FREI0R_CONFIGURE_ENABLE=	frei0r

# fribidi
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	libfribidi

# gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ENABLE=	gnutls

# gme
GME_LIB_DEPENDS=	libgme.so:audio/libgme
GME_CONFIGURE_ENABLE=	libgme

# gsm
GSM_LIB_DEPENDS=	libgsm.so:audio/gsm
GSM_CONFIGURE_ENABLE=	libgsm

# iconv
ICONV_USES=	iconv
ICONV_CONFIGURE_ENABLE=	iconv

# ilbc
ILBC_LIB_DEPENDS=	libilbc.so:net/libilbc
ILBC_CONFIGURE_ENABLE=	libilbc

# jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--disable-indev=jack

# kvazaar
KVAZAAR_LIB_DEPENDS=	libkvazaar.so:multimedia/kvazaar
KVAZAAR_CONFIGURE_ENABLE=	libkvazaar

# ladspa
LADSPA_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/lib/ladspa/amp.so:audio/ladspa
LADSPA_CONFIGURE_ENABLE=	ladspa

# lame
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ENABLE=	libmp3lame

# libbluray
LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray

# libv4l
V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_ENABLE=	libv4l2
V4L_CONFIGURE_OFF=		--disable-indev=v4l2 \
				--disable-outdev=v4l2

# mmx support
MMX_CONFIGURE_ENABLE=	mmx

# modplug
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	libmodplug

# OpenAL
OPENAL_LIB_DEPENDS=	libopenal.so:audio/openal-soft
OPENAL_CONFIGURE_ENABLE=	openal
OPENAL_CONFIGURE_OFF=		--disable-indev=openal

# opencl
OPENCL_BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_CONFIGURE_ENABLE=	opencl

# opencv
OPENCV_LIB_DEPENDS=	libopencv_imgproc.so:graphics/opencv2-core
OPENCV_CONFIGURE_ENABLE=	libopencv

# opengl
OPENGL_USE=		GL=gl
OPENGL_CONFIGURE_ENABLE=	opengl

# openh264
OPENH264_LIB_DEPENDS=	libopenh264.so:multimedia/openh264
OPENH264_CONFIGURE_ENABLE=	libopenh264

# openjpeg
OPENJPEG_LIB_DEPENDS=	libopenjpeg.so:graphics/openjpeg15
OPENJPEG_CONFIGURE_ENABLE=	libopenjpeg

# openssl
OPENSSL_USE=		OPENSSL=yes
OPENSSL_CONFIGURE_ENABLE=	openssl
OPENSSL_IMPLIES=	NONFREE

# optimizations
OPTIMIZED_CFLAGS_CFLAGS=-O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer

# opus
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CONFIGURE_ENABLE=	libopus

# pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	libpulse
PULSEAUDIO_CONFIGURE_OFF=	--disable-indev=pulse \
				--disable-outdev=pulse

# quvi
QUVI_LIB_DEPENDS=	libquvi.so:multimedia/libquvi
QUVI_CONFIGURE_ENABLE=	libquvi

# rtcpu
RTCPU_CONFIGURE_ENABLE=	runtime-cpudetect

# rtmp
RTMP_LIB_DEPENDS=	librtmp.so:multimedia/librtmp
RTMP_CONFIGURE_ENABLE=	librtmp

# schroedinger
SCHROEDINGER_LIB_DEPENDS=	libschroedinger-1.0.so:multimedia/schroedinger
SCHROEDINGER_CONFIGURE_ENABLE=	libschroedinger

# sdl
SDL_USE=		SDL=sdl
SDL_CONFIGURE_ENABLE=	ffplay
SDL_CONFIGURE_OFF=	--disable-outdev=sdl

# smbclient
SMB_LIB_DEPENDS=	libsmbclient.so:net/samba-libsmbclient
SMB_CONFIGURE_ENABLE=	libsmbclient
SMB_IMPLIES=		GPL3

# snappy
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
SNAPPY_CONFIGURE_ENABLE=	libsnappy

# speex
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_CONFIGURE_ENABLE=	libspeex

# sse support
SSE_CONFIGURE_ENABLE=	sse
SSE_IMPLIES=		MMX

# ssh
SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CONFIGURE_ENABLE=	libssh

# theora
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CONFIGURE_ENABLE=	libtheora

# twolame
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame
TWOLAME_CONFIGURE_ENABLE=	libtwolame

# vaapi
VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CONFIGURE_ENABLE=	vaapi

# vdpau
VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

# armv6
VFP_CONFIGURE_ENABLE=	vfp
NEON_CONFIGURE_ENABLE=	neon
NEON_CONFIGURE_ON=	--cpu=armv7-a

# vo-aacenc
VO_AACENC_LIB_DEPENDS=	libvo-aacenc.so:audio/vo-aacenc
VO_AACENC_CONFIGURE_ENABLE=	libvo-aacenc
VO_AACENC_IMPLIES=	GPL3

# vo-amrwbenc
VO_AMRWBENC_LIB_DEPENDS=	libvo-amrwbenc.so:audio/vo-amrwbenc
VO_AMRWBENC_CONFIGURE_ENABLE=	libvo-amrwbenc
VO_AMRWBENC_IMPLIES=	GPL3

# vid.stab
VIDSTAB_LIB_DEPENDS=	libvidstab.so:multimedia/vid.stab
VIDSTAB_CONFIGURE_ENABLE=	libvidstab

# vorbis
VORBIS_LIB_DEPENDS=	libvorbisenc.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	libvorbis
VORBIS_VARS=		FFMPEG_CFLAGS+="-I${LOCALBASE}/include/vorbis"

# vp8
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_CONFIGURE_ENABLE=	libvpx

# wavpack
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_ENABLE=	libwavpack

# webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_ENABLE=	libwebp

# x11grab
X11GRAB_USE=		XORG=x11,xext,xfixes
X11GRAB_CONFIGURE_ENABLE=	x11grab

# x264
X264_LIB_DEPENDS=	libx264.so:multimedia/libx264
X264_CONFIGURE_ENABLE=	libx264

# x265
X265_LIB_DEPENDS=	libx265.so:multimedia/x265
X265_CONFIGURE_ENABLE=	libx265

# xcb
XCB_USE=		XORG=xcb
XCB_CONFIGURE_ENABLE=	libxcb

# xvid
XVID_LIB_DEPENDS=	libxvidcore.so:multimedia/xvid
XVID_CONFIGURE_ENABLE=	libxvid

# xv
XVIDEO_USE=		XORG=xv
XVIDEO_CONFIGURE_OFF=	--disable-outdev=xv

# zmq
ZMQ_LIB_DEPENDS=	libzmq.so:net/libzmq${ZMQ_VERSION}
ZMQ_CONFIGURE_ENABLE=	libzmq
ZMQ_VERSION?=		4

# zvbi
ZVBI_LIB_DEPENDS=	libzvbi.so:devel/libzvbi
ZVBI_CONFIGURE_ENABLE=	libzvbi

# License knobs
GPL3_CONFIGURE_ENABLE=	version3
GPL3_VARS=		LICENSE="GPLv3+ LGPL3+"
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPLv3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPLv3

NONFREE_CONFIGURE_ENABLE=nonfree
NONFREE_VARS=		RESTRICTED="linking to libfaac or libaacplus restricts redistribution"

INSTALL_TARGET=	install-progs install-doc install-data \
		install-libs install-headers

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin

CONFIGURE_ARGS+=--prefix="${PREFIX}" \
		--mandir="${PREFIX}/man" \
		--datadir="${DATADIR}" \
		--pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--enable-shared \
		--enable-gpl \
		--enable-postproc \
		--enable-avfilter \
		--enable-avresample \
		--enable-pthreads \
		--disable-libstagefright-h264 \
		--disable-libutvideo \
		--disable-libsoxr \
		--cc="${CC}" \
		--extra-cflags="${FFMPEG_CFLAGS} -I${LOCALBASE}/include" \
		--extra-ldflags="-L${LOCALBASE}/lib ${FFMPEG_LDFLAGS}" \
		--extra-libs="-lpthread"

CONFIGURE_ENV_armv6_clang=	ASFLAGS=-no-integrated-as
CONFIGURE_ARGS_armv6=		--disable-fast-unaligned
CONFIGURE_ARGS_FreeBSD_9=	--enable-memalign-hack

DOC_FILES=	Changelog CREDITS INSTALL.md LICENSE.md MAINTAINERS \
		README.md RELEASE_NOTES
# under doc subdirectory
DOC_DOCFILES=	APIchanges *.txt
PORTDOCS=	*

# Custom helpers. FOO_${ARCH} style from bsd.port.mk
CONFIGURE_ENV+=	${CONFIGURE_ENV_${ARCH}_${CHOSEN_COMPILER_TYPE}}
CONFIGURE_ARGS+=${CONFIGURE_ARGS_${OPSYS}_${OSREL:R}}
CONFIGURE_ARGS+=${CONFIGURE_ARGS_${ARCH}}

post-patch:
# {C,LD}FLAGS safeness
	@${REINPLACE_CMD} -e 's|/etc/ffserver.conf|${PREFIX}/etc/ffserver.conf|' \
		${WRKSRC}/ffserver.c
	@${REINPLACE_CMD} -E \
		-e "s|(EXTRALIBS[[:space:]]*=)|\1-L${LOCALBASE}/lib |g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|gsm/gsm.h|gsm.h|g" \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-ldl||' \
		-e 's|opencv opencv/cxcore.h|opencv-core opencv2/core/core_c.h|g' \
		-e 's|freetype/freetype.h|freetype.h|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-patch-SDL-on:
	@${REINPLACE_CMD} -E \
		-e 's|sdl-config|${SDL_CONFIG}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E \
		-e 's|#include <SDL|#include <SDL/SDL|'

post-configure-THEORA-off:
	@${REINPLACE_CMD} -E \
		-e 's|^(CONFIG_LIBTHEORA).*$$|\1=no|' \
		${WRKSRC}/config.mak

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${DOC_FILES}" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		"${DOC_DOCFILES}" ${STAGEDIR}${DOCSDIR})

post-install-FFSERVER-on:
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${STAGEDIR}${PREFIX}/etc/ffserver.conf.sample

.include <bsd.port.mk>
