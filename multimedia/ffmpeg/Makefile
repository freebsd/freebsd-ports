# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	4.2.2
PORTREVISION=	14
PORTEPOCH=	1
CATEGORIES=	multimedia audio net
MASTER_SITES=	https://ffmpeg.org/releases/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_aarch64=	as:devel/binutils
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_armv6=	as:devel/binutils
BUILD_DEPENDS_armv7=	as:devel/binutils
BUILD_DEPENDS_i386=	nasm:devel/nasm
BUILD_DEPENDS_powerpc64=as:devel/binutils
BUILD_DEPENDS_powerpc=	as:devel/binutils

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	ffbuild/config.log
USES=		compiler:c11 cpe gmake localbase:ldflags perl5 \
		pkgconfig shebangfix tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build
SHEBANG_FILES=	doc/texi2pod.pl
NOPRECIOUSMAKEVARS=	yes # ARCH

PORTSCOUT=	limit:^4\.

# Option CHROMAPRINT disabled, it cannot work and people are baffled.
OPTIONS_DEFINE=	ALSA AMR_NB AMR_WB AOM ARIBB24 ASS BS2B CACA CDIO CELT \
		CODEC2 DAV1D DAVS2 DC1394 DEBUG DOCS DRM FDK_AAC FLITE \
		FONTCONFIG FREETYPE FREI0R FRIBIDI GME GSM ICONV ILBC JACK \
		KLVANC KVAZAAR LADSPA LAME LENSFUN LIBBLURAY LIBRSVG2 LIBXML2 \
		LTO LV2 MFX MODPLUG MYSOFA OPENAL OPENCL OPENCV OPENGL OPENH264 \
		OPENJPEG OPENMPT OPTIMIZED_CFLAGS OPUS POCKETSPHINX PULSEAUDIO \
		RAV1E RTCPU RUBBERBAND SDL SMB SNAPPY SNDIO SOXR SPEEX SRT SSH \
		SVTAV1 SVTHEVC SVTVP9 TENSORFLOW TESSERACT THEORA TWOLAME V4L \
		VAAPI VAPOURSYNTH VDPAU VIDSTAB VMAF VO_AMRWBENC VORBIS VPX \
		WAVPACK WEBP X264 X265 XAVS2 XCB XVID XVIDEO ZIMG ZMQ ZVBI

OPTIONS_DEFAULT=	AOM ASS DAV1D FONTCONFIG FREETYPE FREI0R GMP GNUTLS ICONV \
			OPENCV OPTIMIZED_CFLAGS OPUS RTCPU THEORA V4L VAAPI VDPAU \
			VORBIS VPX X264 X265 XCB XVID

.if !exists(${.CURDIR:H:H}/multimedia/aribb24)
# https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/100bfac6d6ec
OPTIONS_EXCLUDE+=	ARIBB24
.endif

.if !exists(${.CURDIR:H:H}/multimedia/davs2)
# https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/5985a1bf7233
OPTIONS_EXCLUDE+=	DAVS2
.endif

.if !exists(${.CURDIR:H:H}/multimedia/xavs2)
# https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/85a921f4618
OPTIONS_EXCLUDE+=	XAVS2
.endif

.if !exists(${.CURDIR:H:H}/multimedia/klvanc)
# https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/8732dfa9954
OPTIONS_EXCLUDE+=	KLVANC
.endif

.if !exists(${.CURDIR:H:H}/net/srt)
# https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/a2fc8dbae853
OPTIONS_EXCLUDE+=	SRT
.endif

.if !exists(${.CURDIR:H:H}/science/tensorflow)
# https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/d8c0bbb0aa4
OPTIONS_EXCLUDE+=	TENSORFLOW
.endif

OPTIONS_RADIO=	RTMP SSL
OPTIONS_RADIO_RTMP=	GCRYPT GMP LIBRTMP
OPTIONS_RADIO_SSL=	GNUTLS MBEDTLS OPENSSL
OPTIONS_GROUP=	LICENSE
OPTIONS_GROUP_LICENSE=	GPL3 NONFREE

OPTIONS_DEFINE_amd64=	MMX SSE
OPTIONS_DEFINE_armv6=	VFP NEON
OPTIONS_DEFINE_i386=	MMX SSE
OPTIONS_DEFAULT_amd64=	MMX SSE
OPTIONS_DEFAULT_i386=	MMX SSE

ASS_DESC=	Subtitles rendering via libass
AOM_DESC=	AV1 video encoding/decoding via libaom
ARIBB24_DESC=	ARIB text and caption decoding via libaribb24
BS2B_DESC=	Bauer Stereophonic-to-Binaural filter
CHROMAPRINT_DESC=	Audio fingerprinting with chromaprint
CODEC2_DESC=	Codec 2 audio encoding/decoding via libcodec2
DAV1D_DESC=	AV1 video decoding via libdav1d
DAVS2_DESC=	AVS2 decoding via libdavs2
DC1394_DESC=	IIDC-1394 grabbing using libdc1394
DRM_DESC=	KMS grabbing using libdrm
FDK_AAC_DESC=	AAC audio encoding via Fraunhofer FDK
FLITE_DESC=	Voice synthesis support via libflite
GME_DESC=	Game Music Emu demuxer
GPL3_DESC=	Allow (L)GPL version 3 code(cs)
ILBC_DESC=	Internet Low Bit Rate codec
KLVANC_DESC=	Kernel Labs VANC processing
KVAZAAR_DESC=	H.265 video codec support via Kvazaar
LICENSE_DESC=	Licensing options
LTO_DESC=	Use Link-Time Optimization
LV2_DESC=	LV2 audio filtering
MFX_DESC=	Intel MediaSDK (aka Quick Sync Video)
MYSOFA_DESC=	SOFAlizer binaural filter
NEON_DESC=	Media Processing Engine instructions
NONFREE_DESC=	Allow use of nonfree code
OPENMPT_DESC=	Decoding tracked files via libopenmpt
OPENH264_DESC=	H.264 video codec support via OpenH264
POCKETSPHINX_DESC=	Automatic Speech Recognition via PocketSphinx
RAV1E_DESC=	AV1 encoding via librav1e
RUBBERBAND_DESC=Time-stretching and pitch-shifting with librubberband
RTCPU_DESC=	Detect CPU capabilities at runtime
RTMP_DESC=	RTMP(T)E protocol support
SRT_DESC=	Haivision SRT protocol via libsrt
SVTAV1_DESC=	AV1 encoding via SVT-AV1
SVTHEVC_DESC=	HEVC encoding via SVT-HEVC
SVTVP9_DESC=	VP9 encoding via SVT-VP9
LIBRTMP_DESC=	${RTMP_DESC} via librtmp
TENSORFLOW_DESC=TensorFlow as a DNN module backend for DNN based filters like sr
TESSERACT_DESC=	Optical Character Recognition via Tesseract
VAPOURSYNTH_DESC=	VapourSynth demuxer
VFP_DESC=	Vector Floating Point instructions
VIDSTAB_DESC=	Video stabilization filter
VMAF_DESC=	VMAF filter via libvmaf
XAVS2_DESC=	AVS2 encoding via libxavs2
XCB_DESC=	X11 grabbing using XCB
ZIMG_DESC=	"z" library video scaling filter
ZMQ_DESC=	Message passing via libzmq${ZMQ_VERSION}
ZVBI_DESC=	Teletext support via libzvbi

OPTIONS_SUB=	yes

# alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa

# Opencore AMR NB
AMR_NB_LIB_DEPENDS=	libopencore-amrnb.so:audio/opencore-amr
AMR_NB_CONFIGURE_ENABLE=	libopencore-amrnb
AMR_NB_IMPLIES=		GPL3

# Opencore AMR WB
AMR_WB_LIB_DEPENDS=	libopencore-amrwb.so:audio/opencore-amr
AMR_WB_CONFIGURE_ENABLE=	libopencore-amrwb
AMR_WB_IMPLIES=		GPL3

# aom
AOM_LIB_DEPENDS=	libaom.so:multimedia/aom
AOM_CONFIGURE_ENABLE=	libaom

# arib
ARIBB24_LIB_DEPENDS=	libaribb24.so:multimedia/aribb24
ARIBB24_CONFIGURE_ENABLE=	libaribb24

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

# chromaprint
CHROMAPRINT_BROKEN=		Dependency loop
CHROMAPRINT_LIB_DEPENDS=	libchromaprint.so:audio/chromaprint
CHROMAPRINT_CONFIGURE_ENABLE=	chromaprint

# codec2
CODEC2_LIB_DEPENDS=	libcodec2.so:audio/codec2
CODEC2_CONFIGURE_ENABLE=	libcodec2

# dav1d
DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_CONFIGURE_ENABLE=	libdav1d

# davs2
DAVS2_LIB_DEPENDS=	libdavs2.so:multimedia/davs2
DAVS2_CONFIGURE_ENABLE=	libdavs2

# dc1394
DC1394_LIB_DEPENDS=	libdc1394.so:multimedia/libdc1394
DC1394_CONFIGURE_ENABLE=	libdc1394

# debugging
DEBUG_CONFIGURE_ON=	--disable-stripping
DEBUG_CONFIGURE_OFF=	--disable-debug

# docs
DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html
DOCS_CONFIGURE_ENABLE=	htmlpages

# drm
DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_CONFIGURE_ENABLE=	libdrm

# fdk_aac
FDK_AAC_LIB_DEPENDS=	libfdk-aac.so:audio/fdk-aac
FDK_AAC_CONFIGURE_ENABLE=	libfdk-aac
FDK_AAC_IMPLIES=	NONFREE

# flite
FLITE_LIB_DEPENDS=	libflite.so:audio/flite
FLITE_CONFIGURE_ENABLE=	libflite
.if exists(/usr/bin/ld.lld) && (${/usr/bin/ld:L:tA} != /usr/bin/ld.lld)
FLITE_LDFLAGS=		-fuse-ld=lld
.endif

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

# gcrypt
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CONFIGURE_ENABLE=	gcrypt

# gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ENABLE=	gnutls

# gme
GME_LIB_DEPENDS=	libgme.so:audio/libgme
GME_CONFIGURE_ENABLE=	libgme

# gmp
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_ENABLE=	gmp
GMP_IMPLIES=		GPL3

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
JACK_CONFIGURE_ENABLE=	libjack

# klvanc
KLVANC_LIB_DEPENDS=	libklvanc.so:multimedia/libklvanc
KLVANC_CONFIGURE_ENABLE=	libklvanc

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

# lensfun
LENSFUN_LIB_DEPENDS=	liblensfun.so:graphics/lensfun
LENSFUN_CONFIGURE_ENABLE=	liblensfun

# libbluray
LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray

# librsvg
LIBRSVG2_USES=			gnome
LIBRSVG2_USE=			GNOME=librsvg2
LIBRSVG2_CONFIGURE_ENABLE=	librsvg

# libxml
LIBXML2_LIB_DEPENDS=	libxml2.so:textproc/libxml2
LIBXML2_CONFIGURE_ENABLE=	libxml2

# lto
LTO_CONFIGURE_ENABLE=	lto

# lv2
LV2_BUILD_DEPENDS=	lv2>0:audio/lv2
LV2_LIB_DEPENDS=	liblilv-0.so:audio/lilv
LV2_CONFIGURE_ENABLE=	lv2

# libv4l
V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_ENABLE=	libv4l2
V4L_CONFIGURE_OFF=		--disable-indev=v4l2 \
				--disable-outdev=v4l2

# mbedtls
MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
MBEDTLS_CONFIGURE_ENABLE=	mbedtls

# mfx
MFX_LIB_DEPENDS=	libmfx.so:multimedia/intel-media-sdk
MFX_CONFIGURE_ENABLE=	libmfx

# mmx support
MMX_CONFIGURE_ENABLE=	mmx

# modplug
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	libmodplug

# mysofa
MYSOFA_LIB_DEPENDS=	libmysofa.so:audio/libmysofa
MYSOFA_CONFIGURE_ENABLE=	libmysofa

# OpenAL
OPENAL_LIB_DEPENDS=	libopenal.so:audio/openal-soft
OPENAL_CONFIGURE_ENABLE=	openal

# opencl
OPENCL_BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_CONFIGURE_ENABLE=	opencl

# opencv
OPENCV_LIB_DEPENDS=	libopencv_imgproc.so:graphics/opencv-core
OPENCV_CONFIGURE_ENABLE=	libopencv

# opengl
OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_CONFIGURE_ENABLE=	opengl

# openh264
OPENH264_LIB_DEPENDS=	libopenh264.so:multimedia/openh264
OPENH264_CONFIGURE_ENABLE=	libopenh264

# openjpeg
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_CONFIGURE_ENABLE=	libopenjpeg

# openmpt
OPENMPT_LIB_DEPENDS=	libopenmpt.so:audio/libopenmpt
OPENMPT_CONFIGURE_ENABLE=	libopenmpt

# openssl/libtls
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ENABLE=	${"${SSL_DEFAULT:Mlibressl*}"!="":?libtls:openssl}
OPENSSL_IMPLIES=	NONFREE

# optimizations
OPTIMIZED_CFLAGS_CONFIGURE_ENABLE=	optimizations

# opus
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CONFIGURE_ENABLE=	libopus

# pocketsphinx
POCKETSPHINX_LIB_DEPENDS=	libpocketsphinx.so:audio/pocketsphinx
POCKETSPHINX_CONFIGURE_ENABLE=	pocketsphinx
POCKETSPHINX_BROKEN=	pocketsphinx < 5prealpha is not supported

# pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	libpulse

# rav1e
RAV1E_LIB_DEPENDS=	librav1e.so:multimedia/librav1e
RAV1E_CONFIGURE_ENABLE=	librav1e

# rubberband
RUBBERBAND_LIB_DEPENDS=	librubberband.so:audio/rubberband
RUBBERBAND_CONFIGURE_ENABLE=	librubberband

# rtcpu
RTCPU_CONFIGURE_ENABLE=	runtime-cpudetect

# rtmp
LIBRTMP_LIB_DEPENDS=	librtmp.so:multimedia/librtmp
LIBRTMP_CONFIGURE_ENABLE=	librtmp

# sdl
SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CONFIGURE_ENABLE=	sdl2

# smbclient
SMB_USES=		samba:lib
SMB_CONFIGURE_ENABLE=	libsmbclient
SMB_IMPLIES=		GPL3

# snappy
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
SNAPPY_CONFIGURE_ENABLE=	libsnappy

# sndio
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio

# soxr
SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SOXR_CONFIGURE_ENABLE=	libsoxr

# speex
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_CONFIGURE_ENABLE=	libspeex

# sse support
SSE_CONFIGURE_ENABLE=	sse
SSE_IMPLIES=		MMX

# ssh
SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CONFIGURE_ENABLE=	libssh

# srt
SRT_LIB_DEPENDS=	libsrt.so:net/srt
SRT_CONFIGURE_ENABLE=	libsrt

# svt-av1
SVTAV1_LIB_DEPENDS=	libSvtAv1Enc.so:multimedia/svt-av1
SVTAV1_CONFIGURE_ON=	--enable-libsvtav1
SVTAV1_PATCH_SITES=	https://github.com/OpenVisualCloud/SVT-AV1/raw/v0.8.3/ffmpeg_plugin/:svtav1
SVTAV1_PATCHFILES=	0001-Add-ability-for-ffmpeg-to-run-svt-av1.patch:-p1:svtav1
.if exists(/usr/bin/ld.lld) && (${/usr/bin/ld:L:tA} != /usr/bin/ld.lld)
# https://github.com/OpenVisualCloud/SVT-AV1/issues/691
SVTAV1_LDFLAGS=		-fuse-ld=lld
.endif
.if make(makesum)
.MAKEFLAGS:		WITH+=SVTAV1
.else
SVTAV1_PREVENTS=	SVTHEVC SVTVP9
SVTAV1_PREVENTS_MSG=	Only one SVT vendor patch can be applied at the same time
.endif

# svt-hevc
SVTHEVC_LIB_DEPENDS=	libSvtHevcEnc.so:multimedia/svt-hevc
SVTHEVC_CONFIGURE_ON=	--enable-libsvthevc
SVTHEVC_PATCH_SITES=	https://github.com/Intel/SVT-HEVC/raw/v1.4.3/ffmpeg_plugin/:svthevc
SVTHEVC_PATCHFILES=	0001-lavc-svt_hevc-add-libsvt-hevc-encoder-wrapper.patch:-p1:svthevc \
			0002-doc-Add-libsvt_hevc-encoder-docs.patch:-p1:svthevc
.if exists(/usr/bin/ld.lld) && (${/usr/bin/ld:L:tA} != /usr/bin/ld.lld)
SVTHEVC_LDFLAGS=	-fuse-ld=lld
.endif
.if make(makesum)
.MAKEFLAGS:		WITH+=SVTHEVC
.else
SVTHEVC_PREVENTS=	SVTAV1 SVTVP9
SVTHEVC_PREVENTS_MSG=	${SVTAV1_PREVENTS_MSG}
.endif

# svt-vp9
SVTVP9_LIB_DEPENDS=	libSvtVp9Enc.so:multimedia/svt-vp9
SVTVP9_CONFIGURE_ON=	--enable-libsvtvp9
SVTVP9_PATCH_SITES=	https://github.com/OpenVisualCloud/SVT-VP9/raw/v0.2.0/ffmpeg_plugin/:svtvp9
SVTVP9_PATCHFILES=	0001-Add-ability-for-ffmpeg-to-run-svt-vp9.patch:-p1:svtvp9
.if exists(/usr/bin/ld.lld) && (${/usr/bin/ld:L:tA} != /usr/bin/ld.lld)
SVTVP9_LDFLAGS=		-fuse-ld=lld
.endif
.if make(makesum)
.MAKEFLAGS:		WITH+=SVTVP9
.else
SVTVP9_PREVENTS=	SVTAV1 SVTHEVC
SVTVP9_PREVENTS_MSG=	${SVTAV1_PREVENTS_MSG}
.endif

# tensorflow
TENSORFLOW_LIB_DEPENDS=	libtensorflow.so:science/tensorflow
TENSORFLOW_CONFIGURE_ENABLE=	libtensorflow

# tesseract
TESSERACT_LIB_DEPENDS=	libtesseract.so:graphics/tesseract
TESSERACT_CONFIGURE_ENABLE=	libtesseract

# theora
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CONFIGURE_ENABLE=	libtheora

# twolame
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame
TWOLAME_CONFIGURE_ENABLE=	libtwolame

# vaapi
VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CONFIGURE_ENABLE=	vaapi

# vapoursynth
VAPOURSYNTH_LIB_DEPENDS=	libvapoursynth-script.so:multimedia/vapoursynth
VAPOURSYNTH_CONFIGURE_ENABLE=	vapoursynth

# vdpau
VDPAU_USES=		xorg
VDPAU_USE=		XORG=x11
VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

# vmaf
VMAF_LIB_DEPENDS=	libvmaf.so:multimedia/vmaf
VMAF_CONFIGURE_ENABLE=	libvmaf

# armv6/armv7
VFP_CONFIGURE_ENABLE=	vfp
NEON_CONFIGURE_ENABLE=	neon
.if ! ${CFLAGS:M-march*}
NEON_CONFIGURE_ON=	--cpu=armv7-a
.endif

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

# vp8
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_CONFIGURE_ENABLE=	libvpx

# wavpack
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_ENABLE=	libwavpack

# webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_ENABLE=	libwebp

# x264
X264_LIB_DEPENDS=	libx264.so:multimedia/libx264
X264_CONFIGURE_ENABLE=	libx264

# x265
X265_LIB_DEPENDS=	libx265.so:multimedia/x265
X265_CONFIGURE_ENABLE=	libx265

# xavs2
XAVS2_LIB_DEPENDS=	libxavs2.so:multimedia/xavs2
XAVS2_CONFIGURE_ENABLE=	libxavs2

# xcb
XCB_USES=		xorg
XCB_USE=		XORG=xcb
XCB_CONFIGURE_ENABLE=	libxcb

# xvid
XVID_LIB_DEPENDS=	libxvidcore.so:multimedia/xvid
XVID_CONFIGURE_ENABLE=	libxvid

# xv
XVIDEO_USES=		xorg
XVIDEO_USE=		XORG=x11,xext,xv
XVIDEO_CONFIGURE_OFF=	--disable-outdev=xv

# zimg
ZIMG_LIB_DEPENDS=	libzimg.so:graphics/sekrit-twc-zimg
ZIMG_CONFIGURE_ENABLE=	libzimg

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
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING.GPLv3
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LGPLv3

NONFREE_CONFIGURE_ENABLE=nonfree
NONFREE_VARS=		RESTRICTED="enabling OPENSSL or FDK_AAC restricts redistribution"

INSTALL_TARGET=	install-progs install-doc install-data \
		install-libs install-headers install-examples

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
MAKE_ENV+=	V=1
LDFLAGS_aarch64=-Wl,-z,notext
LDFLAGS_armv6=	-Wl,-z,notext
LDFLAGS_armv7=	-Wl,-z,notext
LDFLAGS_i386=	-Wl,-z,notext

CONFIGURE_ARGS+=--prefix="${PREFIX}" \
		--mandir="${PREFIX}/man" \
		--datadir="${DATADIR}" \
		--pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--enable-shared \
		--enable-pic \
		--enable-gpl \
		--enable-avresample \
		--cc="${CC}"

DOC_FILES=	Changelog CREDITS INSTALL.md LICENSE.md MAINTAINERS \
		README.md RELEASE_NOTES
# under doc subdirectory
DOC_DOCFILES=	APIchanges *.txt
PORTDOCS=	*

post-patch:
# {C,LD}FLAGS safeness
	@${REINPLACE_CMD} -E \
		-e 's|require_pkg_config opencv|require_pkg_config opencv-core|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${DOC_FILES}" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		"${DOC_DOCFILES}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
