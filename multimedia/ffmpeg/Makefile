PORTNAME=	ffmpeg
DISTVERSION=	8.0.1
PORTEPOCH=	1
CATEGORIES=	multimedia audio net
MASTER_SITES=	https://ffmpeg.org/releases/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server
WWW=		https://ffmpeg.org/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

EXTRA_PATCHES=	${FILESDIR}/0001-Add-av_stream_get_first_dts-for-Chromium.patch:-p1

FLAVORS=	default nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_aarch64=	as:devel/binutils
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_armv6=	as:devel/binutils
BUILD_DEPENDS_armv7=	as:devel/binutils
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		compiler:c17 cpe gmake localbase:ldflags perl5 \
		pkgconfig shebangfix tar:xz
USE_PERL5=	build
SHEBANG_FILES=	doc/texi2pod.pl
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	ffbuild/config.log
NOPRECIOUSMAKEVARS=	yes

CFLAGS_armv6=	-Wno-error=int-conversion
CFLAGS_armv7=	-Wno-error=int-conversion
CFLAGS_i386=	-Wno-error=int-conversion
CFLAGS_powerpc=	-Wno-error=int-conversion
LDFLAGS_aarch64=-Wl,-z,notext
LDFLAGS_armv6=	-Wl,-z,notext
LDFLAGS_armv7=	-Wl,-z,notext
LDFLAGS_i386=	-Wl,-z,notext

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

MAKE_ENV+=	V=1

HAS_SYMBOL_VERSION=	${PREFIX}/lib/libavcodec.so \
			${PREFIX}/lib/libavdevice.so \
			${PREFIX}/lib/libavfilter.so \
			${PREFIX}/lib/libavformat.so \
			${PREFIX}/lib/libavutil.so \
			${PREFIX}/lib/libswresample.so \
			${PREFIX}/lib/libswscale.so

INSTALL_TARGET=	install-progs install-doc install-data \
		install-libs install-headers install-examples

CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--mandir="${PREFIX}/share/man" \
		--datadir="${DATADIR}" \
		--docdir="${DOCSDIR}" \
		--pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--disable-static \
		--disable-libcelt \
		--disable-mbedtls \
		--enable-shared \
		--enable-pic \
		--enable-gpl \
		--cc="${CC}" \
		--cxx="${CXX}"

OPTIONS_DEFINE=	ALSA AMR_NB AMR_WB AOM ARIBB24 ASM ASS BS2B CACA CDIO CODEC2 \
		DAV1D DC1394 DEBUG DOCS DRM DVD FDK_AAC FLITE FONTCONFIG \
		FREETYPE FREI0R FRIBIDI GLSLANG GME GSM HARFBUZZ ICONV ILBC \
		JACK JXL KVAZAAR LADSPA LAME LCMS2 LENSFUN LIBBLURAY \
		LIBPLACEBO LIBRSVG2 LIBXML2 LTO LV2 MODPLUG MYSOFA NETWORK \
		NVENC OPENAL OPENCL OPENGL OPENH264 OPENJPEG OPENMPT \
		OPTIMIZED_CFLAGS OPUS POCKETSPHINX PULSEAUDIO RAV1E RABBITMQ \
		RIST RTCPU RUBBERBAND SDL SHADERC SMB SNAPPY SNDIO SOXR SPEEX \
		SRT SSH SVTAV1 TENSORFLOW TESSERACT THEORA \
		TWOLAME V4L VAAPI VAPOURSYNTH VDPAU VIDSTAB VMAF VO_AMRWBENC \
		VORBIS VPX VULKAN VVENC WEBP X264 X265 XCB XVID XVIDEO ZIMG \
		ZMQ ZVBI

.if ${FLAVOR} == nox11
COMMENT+=	(without x11)

OPTIONS_EXCLUDE=	CACA DRM JACK JXL LADSPA LENSFUN LIBPLACEBO LIBRSVG2 \
			LV2 MFX NVENC OPENAL OPENGL PULSEAUDIO SDL TESSERACT \
			V4L VAAPI VAPOURSYNTH VDPAU VIDSTAB VPL XCB XVIDEO \
			ZMQ ZVBI
.endif

# intel-media-sdk only for i386/amd64
OPTIONS_DEFINE_amd64=	MFX VPL
OPTIONS_DEFINE_i386=	MFX

OPTIONS_RADIO=	RTMP SSL
OPTIONS_RADIO_RTMP=	GCRYPT GMP
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_GROUP=	LICENSE
OPTIONS_GROUP_LICENSE=	GPL3 NONFREE

OPTIONS_DEFAULT=	AOM ASM ASS DAV1D DVD GMP GNUTLS HARFBUZZ ICONV LAME \
			LCMS2 LIBBLURAY LIBXML2 NETWORK OPTIMIZED_CFLAGS \
			OPUS RTCPU SRT SVTAV1 VORBIS VPX WEBP X264 X265
OPTIONS_DEFAULT_aarch64=LTO
OPTIONS_DEFAULT_amd64=	LTO
.if ${FLAVOR} == default
OPTIONS_DEFAULT+=	DRM FONTCONFIG FREETYPE FREI0R JXL LIBPLACEBO \
			LIBRSVG2 SHADERC V4L VAAPI VDPAU VMAF VULKAN XCB
OPTIONS_DEFAULT_amd64+=	NVENC
OPTIONS_DEFAULT_i386+=	NVENC
.endif
OPTIONS_SUB=	yes

ASS_DESC=	Subtitles rendering via libass
AOM_DESC=	AV1 video encoding/decoding via libaom
ARIBB24_DESC=	ARIB text and caption decoding via libaribb24
BS2B_DESC=	Bauer Stereophonic-to-Binaural filter
CHROMAPRINT_DESC=	Audio fingerprinting with chromaprint
CODEC2_DESC=	Codec 2 audio encoding/decoding via libcodec2
DAV1D_DESC=	AV1 video decoding via libdav1d
DC1394_DESC=	IIDC-1394 grabbing using libdc1394
DRM_DESC=	KMS grabbing using libdrm
DVD_DESC=	Support for DVD
FDK_AAC_DESC=	AAC audio encoding via Fraunhofer FDK
FLITE_DESC=	Voice synthesis support via libflite
GLSLANG_DESC=	GLSL->SPIRV compilation via libglslang
GME_DESC=	Game Music Emu demuxer
GPL3_DESC=	Allow (L)GPL version 3 code(cs)
HARFBUZZ_DESC=	Text shaping via HarfBuzz
ILBC_DESC=	Internet Low Bit Rate codec
KVAZAAR_DESC=	H.265 video codec support via Kvazaar
LICENSE_DESC=	Licensing options
LV2_DESC=	LV2 audio filtering
MFX_DESC=	Intel MediaSDK (aka Quick Sync Video)
MYSOFA_DESC=	SOFAlizer binaural filter
NETWORK_DESC=	Networking support
NONFREE_DESC=	Allow use of nonfree code
NVENC_DESC=	NVIDIA decoder/encoder with CUDA support
OPENMPT_DESC=	Decoding tracked files via libopenmpt
OPENH264_DESC=	H.264 video codec support via OpenH264
POCKETSPHINX_DESC=	Automatic Speech Recognition via PocketSphinx
RAV1E_DESC=	AV1 encoding via librav1e
RABBITMQ_DESC=	AMQP 0-9-1 protocol via RabbitMQ
RIST_DESC=	Reliable Internet Stream Transport protocol via librist
RUBBERBAND_DESC=Time-stretching and pitch-shifting with librubberband
RTCPU_DESC=	Detect CPU capabilities at runtime
RTMP_DESC=	RTMP(T)E protocol support
SHADERC_DESC=	GLSL->SPIRV compilation via libshaderc
SRT_DESC=	Haivision SRT protocol via libsrt
SVTAV1_DESC=	AV1 encoding via SVT-AV1
#SVTVP9_DESC=	VP9 encoding via SVT-VP9
LIBPLACEBO_DESC=GPU filters from libplacebo
TENSORFLOW_DESC=TensorFlow as a DNN module backend
TESSERACT_DESC=	Optical Character Recognition via Tesseract
THEORA_DESC=	Encoding support for theora via libtheora
VAPOURSYNTH_DESC=	VapourSynth demuxer
VIDSTAB_DESC=	Video stabilization filter
VMAF_DESC=	VMAF filter via libvmaf
VPL_DESC=	Intel oneVPL (aka Quick Sync Video)
VULKAN_DESC=	Vulkan filters
VVENC_DESC=	H.266/VVC encoding support via VVenC
XCB_DESC=	X11 grabbing using XCB
XVID_DESC=	Encoding support for MPEG-4 ASP via libxvid
ZIMG_DESC=	"z" library video scaling filter
ZMQ_DESC=	Message passing via libzmq${ZMQ_VERSION}
ZVBI_DESC=	Teletext support via libzvbi

###
### Not ported libraries / options
###
###  --enable-libiec61883	enable iec61883 via libiec61883
###  --enable-liblc3		enable LC3 de/encoding via liblc3
###  --enable-liblcevc-dec	enable LCEVC decoding via liblcevc-dec
###  --enable-liboapv		enable APV encoding via liboapv
###  --enable-libopencv		enable video filtering via libopencv
###  --enable-libqrencode	enable QR encode generation via libqrencode
###  --enable-libquirc		enable QR decoding via libquirc
###  --enable-libtls		enable LibreSSL (via libtls), needed for https support
###				if openssl, gnutls or mbedtls are not used
###  --enable-libtorch		enable Torch as one DNN backend
###  --enable-libxeve		enable EVC encoding via libxeve
###  --enable-libxevd		enable EVC decoding via libxevd
###  --enable-libxavs		enable AVS encoding via xavs
###  --enable-whisper		enable whisper filter
###  --enable-libaribcaption	ARIB STD-B24 Caption Decoder/Renderer
###  --enable-libdavs2		AVS2 decoding
###  --enable-libuavs3d		AVS3 decoding via libuavs3d
###  --enable-libxavs2		AVS2 encoding via libxavs2
###  --enable-libklvanc		Kernel Labs VANC processing
###  --enable-libopenvino	OpenVINO as a DNN module backend

# ALSA
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

# AOM AV1 codec
AOM_LIB_DEPENDS=	libaom.so:multimedia/aom
AOM_CONFIGURE_ENABLE=	libaom

# ARIB STD-B24, decoding JIS 8 bit characters and parsing MPEG-TS stream
ARIBB24_LIB_DEPENDS=	libaribb24.so:multimedia/aribb24
ARIBB24_CONFIGURE_ENABLE=	libaribb24

# Assembly support
ASM_CONFIGURE_ENABLE=	asm

# ASS/SSA (Advanced Substation Alpha/Substation Alpha) subtitle renderer
ASS_LIB_DEPENDS=	libass.so:multimedia/libass
ASS_CONFIGURE_ENABLE=	libass

# Bauer Stereophonic-to-Binaural filter via libbs2b
BS2B_LIB_DEPENDS=	libbs2b.so:audio/libbs2b
BS2B_CONFIGURE_ENABLE=	libbs2b

# Convert video into colour ASCII art via (lib)caca
CACA_LIB_DEPENDS=	libcaca.so:graphics/libcaca
CACA_CONFIGURE_ENABLE=	libcaca

# CD Audio support via (lib)cdio
CDIO_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia
CDIO_CONFIGURE_ENABLE=	libcdio

# chromaprint
#CHROMAPRINT_BROKEN=		Dependency loop
#CHROMAPRINT_LIB_DEPENDS=	libchromaprint.so:audio/chromaprint
#CHROMAPRINT_CONFIGURE_ENABLE=	chromaprint

# codec2 format support via (lib)codec2
CODEC2_LIB_DEPENDS=	libcodec2.so:audio/codec2
CODEC2_CONFIGURE_ENABLE=	libcodec2

# AV1 decoder
DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_CONFIGURE_ENABLE=	libdav1d

# IEEE 1394 camera control via (lib)dc1394
DC1394_LIB_DEPENDS=	libdc1394.so:multimedia/libdc1394
DC1394_CONFIGURE_ENABLE=	libdc1394

# Debugging
DEBUG_CONFIGURE_ON=	--disable-stripping
DEBUG_CONFIGURE_OFF=	--disable-debug

# Documentation
DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html
DOCS_CONFIGURE_ENABLE=	htmlpages
DOCS_BINARY_ALIAS=	makeinfo=${FALSE} # force texi2html

# DRM
DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_CONFIGURE_ENABLE=	libdrm

# DVD support
DVD_LIB_DEPENDS=	libdvdnav.so:multimedia/libdvdnav \
			libdvdread.so:multimedia/libdvdread
DVD_CONFIGURE_ENABLE=	libdvdnav \
			libdvdread

# Fraunhofer FDK AAC codec
FDK_AAC_LIB_DEPENDS=	libfdk-aac.so:audio/fdk-aac
FDK_AAC_CONFIGURE_ENABLE=	libfdk-aac
FDK_AAC_IMPLIES=	NONFREE

# Speech synthesis via (lib)flite
FLITE_LIB_DEPENDS=	libflite.so:audio/flite
FLITE_CONFIGURE_ENABLE=	libflite

# (lib)fontconfig
FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_ENABLE=	fontconfig

# (lib)freetype
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	libfreetype

# Video effects via (lib)Frei0r
FREI0R_BUILD_DEPENDS=	${LOCALBASE}/include/frei0r.h:graphics/frei0r
FREI0R_CONFIGURE_ENABLE=	frei0r

# (lib)FriBidi
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	libfribidi

# Libgcrypt
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CONFIGURE_ENABLE=	gcrypt

# OpenGL and OpenGL ES shader frontend
GLSLANG_BUILD_DEPENDS=	glslang>0:graphics/glslang \
			spirv-tools>0:graphics/spirv-tools
GLSLANG_CONFIGURE_ENABLE=	libglslang
GLSLANG_LDFLAGS=	-lm
GLSLANG_IMPLIES=	VULKAN

# GnuTLS
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ENABLE=	gnutls

# Game Music Emu via libgme
GME_LIB_DEPENDS=	libgme.so:audio/libgme
GME_CONFIGURE_ENABLE=	libgme

# GMP
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_ENABLE=	gmp
GMP_IMPLIES=		GPL3

# GSM de/encoding via libgsm
GSM_LIB_DEPENDS=	libgsm.so:audio/gsm
GSM_CONFIGURE_ENABLE=	libgsm

# (lib)harfbuzz
HARFBUZZ_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
HARFBUZZ_CONFIGURE_ENABLE=	libharfbuzz

# iconv
ICONV_USES=	iconv
ICONV_CONFIGURE_ENABLE=	iconv

# iLBC de/encoding via libilbc
ILBC_LIB_DEPENDS=	libilbc.so:net/libilbc
ILBC_CONFIGURE_ENABLE=	libilbc

# Support for JACK low-latency audio server
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	libjack

# JPEG XL de/encoding via libjxl
JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_CONFIGURE_ENABLE=	libjxl

# HEVC encoding via libkvazaar
KVAZAAR_LIB_DEPENDS=	libkvazaar.so:multimedia/kvazaar
KVAZAAR_CONFIGURE_ENABLE=	libkvazaar

# Support for Linux Audio Developer's Simple Plugin
LADSPA_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/lib/ladspa/amp.so:audio/ladspa
LADSPA_CONFIGURE_ENABLE=	ladspa

# MP3 encoding via LAME
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ENABLE=	libmp3lame

# lcms2
LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_CONFIGURE_ENABLE=	lcms2

# Lens geometry distortions correction filter via lib(lensfun)
LENSFUN_LIB_DEPENDS=	liblensfun.so:graphics/lensfun
LENSFUN_CONFIGURE_ENABLE=	liblensfun

# libbluray
LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray
LIBBLURAY_IMPLIES=	FONTCONFIG \
			FREETYPE

# GPU-accelerated video/image rendering via libplacebo
LIBPLACEBO_LIB_DEPENDS=	libplacebo.so:graphics/libplacebo
LIBPLACEBO_CONFIGURE_ENABLE=	libplacebo
LIBPLACEBO_IMPLIES=	VULKAN

# SVG format support via librsvg
LIBRSVG2_USES=	gnome
LIBRSVG2_USE=	GNOME=cairo,librsvg2
LIBRSVG2_CONFIGURE_ENABLE=	librsvg

# XML support via libxml2
LIBXML2_USES=	gnome
LIBXML2_USE=	GNOME=libxml2
LIBXML2_CONFIGURE_ENABLE=	libxml2

# lto
LTO_CONFIGURE_ON=	--enable-lto

# LV2 audio filtering
LV2_BUILD_DEPENDS=	lv2>0:audio/lv2
LV2_LIB_DEPENDS=	liblilv-0.so:audio/lilv
LV2_CONFIGURE_ENABLE=	lv2

# Intel MediaSDK support via libmfx
MFX_LIB_DEPENDS=	libmfx.so:multimedia/intel-media-sdk
MFX_CONFIGURE_ENABLE=	libmfx

# ModPlug via libmodplug
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	libmodplug

# mysofa
MYSOFA_LIB_DEPENDS=	libmysofa.so:audio/libmysofa
MYSOFA_CONFIGURE_ENABLE=	libmysofa

# network
NETWORK_CONFIGURE_ENABLE=	network

# Glue for Nvidia Codec SDK headers, hardware decoding/encoding
NVENC_BUILD_DEPENDS=	ffnvcodec-headers>=11.1.5.2:multimedia/ffnvcodec-headers
NVENC_CONFIGURE_ENABLE=	cuvid \
			nvdec \
			nvenc

# OpenAL 1.1 capture support
OPENAL_LIB_DEPENDS=	libopenal.so:audio/openal-soft
OPENAL_CONFIGURE_ENABLE=	openal

# OpenCL processing
OPENCL_BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_CONFIGURE_ENABLE=	opencl

# OpenGL rendering
OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_CONFIGURE_ENABLE=	opengl

# H.264 encoding via OpenH264
OPENH264_LIB_DEPENDS=	libopenh264.so:multimedia/openh264
OPENH264_CONFIGURE_ENABLE=	libopenh264

# JPEG 2000 encoding via OpenJPEG
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_CONFIGURE_ENABLE=	libopenjpeg

# Support for various mod files formats via (lib)openmpt
OPENMPT_LIB_DEPENDS=	libopenmpt.so:audio/libopenmpt
OPENMPT_CONFIGURE_ENABLE=	libopenmpt

# OpenSSL
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ENABLE=	openssl
OPENSSL_IMPLIES=	NONFREE

# Enable optimizations defined by upstream
OPTIMIZED_CFLAGS_CONFIGURE_ENABLE=	optimizations

# Opus de/encoding via libopus
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CONFIGURE_ENABLE=	libopus

# Speech recognition via (lib)PocketSphinx
POCKETSPHINX_LIB_DEPENDS=	libpocketsphinx.so:audio/pocketsphinx
POCKETSPHINX_CONFIGURE_ENABLE=	pocketsphinx
POCKETSPHINX_BROKEN=	pocketsphinx < 5prealpha is not supported

# Pulseaudio input via libpulse
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	libpulse

# AV1 encoding via librav1e
RAV1E_LIB_DEPENDS=	librav1e.so:multimedia/librav1e
RAV1E_CONFIGURE_ENABLE=	librav1e

# RabbitMQ
RABBITMQ_LIB_DEPENDS=	librabbitmq.so:net/rabbitmq-c
RABBITMQ_CONFIGURE_ENABLE=	librabbitmq

# RIST via librist
RIST_LIB_DEPENDS=	librist.so:multimedia/librist
RIST_CONFIGURE_ENABLE=	librist

# Real-time detection of CPU features
RTCPU_CONFIGURE_ENABLE=	runtime-cpudetect

# Time streching effect via (lib)Rubberband
RUBBERBAND_LIB_DEPENDS=	librubberband.so:audio/rubberband
RUBBERBAND_CONFIGURE_ENABLE=	librubberband

# SDL(2) video output support
SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CONFIGURE_ENABLE=	sdl2

# GLSL/HLSL to SPIR-V shader compiler
SHADERC_LIB_DEPENDS=	libshaderc_shared.so:graphics/shaderc
SHADERC_CONFIGURE_ENABLE=	libshaderc
SHADERC_IMPLIES=	VULKAN
SHADERC_PREVENTS=	GLSLANG

# Samba protocol support via libsmbclient
SMB_USES=		samba:lib
SMB_CONFIGURE_ENABLE=	libsmbclient
SMB_IMPLIES=		GPL3

# Snappy compression via libsnappy
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
SNAPPY_CONFIGURE_ENABLE=	libsnappy

# sndio
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio

# libsoxr resampling
SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SOXR_CONFIGURE_ENABLE=	libsoxr

# Speex de/encoding via libspeex
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_CONFIGURE_ENABLE=	libspeex

# Haivision SRT protocol via libsrt
SRT_LIB_DEPENDS=	libsrt.so:www/srt
SRT_CONFIGURE_ENABLE=	libsrt

# SFTP protocol support via libssh
SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CONFIGURE_ENABLE=	libssh

# AV1 encoding via SVT
SVTAV1_LIB_DEPENDS=	libSvtAv1Enc.so:multimedia/svt-av1
SVTAV1_CONFIGURE_ON=	--enable-libsvtav1

# VP9 encoding via SVT
#SVTVP9_LIB_DEPENDS=	libSvtVp9Enc.so:multimedia/svt-vp9
#SVTVP9_CONFIGURE_ON=	--enable-libsvtvp9
#SVTVP9_PATCH_SITES=	https://github.com/OpenVisualCloud/SVT-VP9/raw/v0.3.0-20-gbab25a6/ffmpeg_plugin/:svtvp9
#SVTVP9_PATCHFILES=	master-0001-Add-ability-for-ffmpeg-to-run-svt-vp9.patch:-p1:svtvp9
#.if make(makesum)
#.MAKEFLAGS:		WITH+=SVTVP9
#.endif

# TensorFlow
TENSORFLOW_LIB_DEPENDS=	libtensorflow.so:science/py-tensorflow
TENSORFLOW_CONFIGURE_ENABLE=	libtensorflow

# OCR support via Tesseract
TESSERACT_LIB_DEPENDS=	libtesseract.so:graphics/tesseract
TESSERACT_CONFIGURE_ENABLE=	libtesseract

# Theora encoding via libtheora
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CONFIGURE_ENABLE=	libtheora

# MP2 encoding via libtwolame
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame
TWOLAME_CONFIGURE_ENABLE=	libtwolame

# V4L
V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_ENABLE=	libv4l2
V4L_CONFIGURE_OFF=	--disable-indev=v4l2 \
			--disable-outdev=v4l2

# Video Acceleration API (VA-API)
VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CONFIGURE_ENABLE=	vaapi

# VapourSynth demuxer
VAPOURSYNTH_LIB_DEPENDS=	libvapoursynth-script.so:multimedia/vapoursynth
VAPOURSYNTH_CONFIGURE_ENABLE=	vapoursynth

# Nvidia Video Decode and Presentation API
VDPAU_USES=		xorg
VDPAU_USE=		XORG=x11
VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

# Video stabilization via (lib)VidStab
VIDSTAB_LIB_DEPENDS=	libvidstab.so:multimedia/vid.stab
VIDSTAB_CONFIGURE_ENABLE=	libvidstab

# Perceptual video quality assessment via libvmaf
VMAF_LIB_DEPENDS=	libvmaf.so:multimedia/vmaf
VMAF_CONFIGURE_ENABLE=	libvmaf

# VisualOn AMR-WB encoder
VO_AMRWBENC_LIB_DEPENDS=	libvo-amrwbenc.so:audio/vo-amrwbenc
VO_AMRWBENC_CONFIGURE_ENABLE=	libvo-amrwbenc
VO_AMRWBENC_IMPLIES=	GPL3

# Vorbis en/decoding via libvorbis
VORBIS_LIB_DEPENDS=	libvorbisenc.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	libvorbis

# Intel oneVPL
VPL_LIB_DEPENDS=	libvpl.so:multimedia/onevpl
VPL_CONFIGURE_ENABLE=	libvpl

# VP8 and VP9 de/encoding via libvpx
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_CONFIGURE_ENABLE=	libvpx

# Vulkan
VULKAN_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CONFIGURE_ENABLE=	vulkan

# H.266/VVC encoding via VVenC
VVENC_LIB_DEPENDS=	libvvenc.so:multimedia/vvenc
VVENC_CONFIGURE_ENABLE=	libvvenc

# WebP encoding via libwebp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_ENABLE=	libwebp

# H.264 encoding via (lib)x264
X264_LIB_DEPENDS=	libx264.so:multimedia/libx264
X264_CONFIGURE_ENABLE=	libx264

# HEVC encoding via (lib)x265
X265_LIB_DEPENDS=	libx265.so:multimedia/x265
X265_CONFIGURE_ENABLE=	libx265

# X11 grabbing using XCB
XCB_USES=		xorg
XCB_USE=		XORG=xcb,x11,xext,xv
XCB_CONFIGURE_ENABLE=	libxcb libxcb-shape libxcb-shm libxcb-xfixes xlib

# XviD support
XVID_LIB_DEPENDS=	libxvidcore.so:multimedia/xvid
XVID_CONFIGURE_ENABLE=	libxvid

# xv
XVIDEO_USES=		xorg
XVIDEO_USE=		XORG=x11,xext,xv
XVIDEO_CONFIGURE_OFF=	--disable-outdev=xv

# Scaling, colorspace conversion, and dithering via "z" library
ZIMG_LIB_DEPENDS=	libzimg.so:graphics/sekrit-twc-zimg
ZIMG_CONFIGURE_ENABLE=	libzimg

# Message passing via libzmq
ZMQ_LIB_DEPENDS=	libzmq.so:net/libzmq${ZMQ_VERSION}
ZMQ_CONFIGURE_ENABLE=	libzmq
ZMQ_VERSION?=		4

# Teletext support via libzvbi
ZVBI_LIB_DEPENDS=	libzvbi.so:devel/libzvbi
ZVBI_CONFIGURE_ENABLE=	libzvbi

# License knobs
GPL3_CONFIGURE_ENABLE=	version3
GPL3_VARS=		LICENSE="GPLv3+ LGPL3+"
#LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING.GPLv3
#LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LGPLv3

NONFREE_CONFIGURE_ENABLE=nonfree

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNONFREE}
LICENSE+=	NONFREE
LICENSE_COMB=	multi
LICENSE_NAME_NONFREE=	Non free code
LICENSE_TEXT_NONFREE=	enabling OpenSSL or fdk-aac restricts redistribution
LICENSE_PERMS_NONFREE=	auto-accept
.endif

.if !${PORT_OPTIONS:MVDPAU} || !${PORT_OPTIONS:MXCB} || !${PORT_OPTIONS:MXVIDEO}
CONFIGURE_ARGS+=	--disable-xlib
.endif

.include <bsd.port.mk>
