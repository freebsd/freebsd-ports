# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	2.8.1
PORTEPOCH=	1
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	http://ffmpeg.org/releases/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	config.err
USES=		compiler cpe gmake perl5 pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_PERL5=	build

OPTIONS_DEFINE=	AACPLUS ALSA AMR_NB AMR_WB ASS CDIO CELT DEBUG DOCS FAAC \
		FDK_AAC FFSERVER FONTCONFIG FREETYPE FREI0R GSM ICONV \
		JACK LAME LIBBLURAY LIBV4L MODPLUG OPENAL OPENCV OPENH264 OPENJPEG \
		OPTIMIZED_CFLAGS OPUS PULSEAUDIO RTMP SCHROEDINGER SDL SMB SPEEX \
		THEORA VAAPI VDPAU VO_AACENC VO_AMRWBENC VORBIS VPX \
		X11GRAB X264 X265 XVID

OPTIONS_DEFAULT=	FFSERVER FONTCONFIG FREETYPE FREI0R GNUTLS ICONV \
			OPENCV SCHROEDINGER THEORA VORBIS VPX X264 XVID

OPTIONS_SINGLE=	SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_GROUP=	LICENSE
OPTIONS_GROUP_LICENSE=	GPL3 NONFREE

OPTIONS_DEFINE_amd64=	MMX SSE
OPTIONS_DEFINE_i386=	MMX SSE
OPTIONS_DEFAULT_amd64=	MMX SSE
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:MMMX} ${MACHINE_CPU:tu:MSSE}

ASS_DESC=	Subtitles rendering via libass
CDIO_DESC=	Audio CD grabbing with libcdio
FDK_AAC_DESC=	AAC audio encoding via Fraunhofer FDK
FFSERVER_DESC=	Build and install ffserver
GPL3_DESC=	Allow (L)GPL version 3 code(cs)
LIBV4L_DESC=	Video for Linux support
LICENSE_DESC=	Licensing options
NONFREE_DESC=	Allow use of nonfree code
OPENH264_DESC=	H.264 video codec support via OpenH264
X11GRAB_DESC=	Enable x11 grabbing

OPTIONS_SUB=	yes

# aacplus
AACPLUS_LIB_DEPENDS=	libaacplus.so:${PORTSDIR}/audio/libaacplus
AACPLUS_CONFIGURE_ENABLE=	libaacplus
AACPLUS_IMPLIES=	NONFREE

# alsa
ALSA_CONFIGURE_OFF=	--disable-indev=alsa \
			--disable-outdev=alsa
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib

# Opencore AMR NB
AMR_NB_LIB_DEPENDS=	libopencore-amrnb.so:${PORTSDIR}/audio/opencore-amr
AMR_NB_CONFIGURE_ENABLE=	libopencore-amrnb
AMR_NB_IMPLIES=		GPL3

# Opencore AMR WB
AMR_WB_LIB_DEPENDS=	libopencore-amrwb.so:${PORTSDIR}/audio/opencore-amr
AMR_WB_CONFIGURE_ENABLE=	libopencore-amrwb
AMR_WB_IMPLIES=		GPL3

# ass
ASS_LIB_DEPENDS=	libass.so:${PORTSDIR}/multimedia/libass
ASS_CONFIGURE_ENABLE=	libass

# cdio
CDIO_LIB_DEPENDS=	libcdio_paranoia.so:${PORTSDIR}/sysutils/libcdio-paranoia
CDIO_CONFIGURE_ENABLE=	libcdio

# celt
CELT_LIB_DEPENDS=	libcelt0.so:${PORTSDIR}/audio/celt
CELT_CONFIGURE_ENABLE=	libcelt

# debugging
DEBUG_CONFIGURE_ON=	--disable-stripping
DEBUG_CONFIGURE_OFF=	--disable-debug

# docs
DOCS_BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html
DOCS_CONFIGURE_ENABLE=	htmlpages

# faac
FAAC_LIB_DEPENDS=	libfaac.so:${PORTSDIR}/audio/faac
FAAC_CONFIGURE_ENABLE=	libfaac
FAAC_IMPLIES=		NONFREE

# fdk_aac
FDK_AAC_LIB_DEPENDS=	libfdk-aac.so:${PORTSDIR}/audio/fdk-aac
FDK_AAC_CONFIGURE_ENABLE=	libfdk-aac
FDK_AAC_IMPLIES=	NONFREE

# ffserver
FFSERVER_CONFIGURE_ENABLE=	ffserver
FFSERVER_VARS=		USE_RC_SUBR+=ffserver

# fontconfig
FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_ENABLE=	fontconfig

# freetype
FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
FREETYPE_CONFIGURE_ENABLE=	libfreetype

# frei0r
FREI0R_BUILD_DEPENDS=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
FREI0R_CONFIGURE_ENABLE=	frei0r

# gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_ENABLE=	gnutls

# gsm
GSM_LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm
GSM_CONFIGURE_ENABLE=	libgsm

# iconv
ICONV_USES=	iconv
ICONV_CONFIGURE_ENABLE=	iconv

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_OFF=	--disable-indev=jack

# lame
LAME_LIB_DEPENDS=	libmp3lame.so:${PORTSDIR}/audio/lame
LAME_CONFIGURE_ENABLE=	libmp3lame

# libbluray
LIBBLURAY_LIB_DEPENDS=	libbluray.so:${PORTSDIR}/multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray

# libv4l
LIBV4L_BUILD_DEPENDS=	v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat
LIBV4L_LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l
LIBV4L_CONFIGURE_ENABLE=	libv4l2
LIBV4L_CONFIGURE_OFF=		--disable-indev=v4l2 \
				--disable-outdev=v4l2

# mmx support
MMX_CONFIGURE_ENABLE=	mmx

# modplug
MODPLUG_LIB_DEPENDS=	libmodplug.so:${PORTSDIR}/audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	libmodplug

# OpenAL
OPENAL_LIB_DEPENDS=	libopenal.so:${PORTSDIR}/audio/openal-soft
OPENAL_CONFIGURE_ENABLE=	openal
OPENAL_CONFIGURE_OFF=		--disable-indev=openal

# opencv
OPENCV_LIB_DEPENDS=	libopencv_imgproc.so:${PORTSDIR}/graphics/opencv-core
OPENCV_CONFIGURE_ENABLE=	libopencv

# openh264
OPENH264_LIB_DEPENDS=	libopenh264.so:${PORTSDIR}/multimedia/openh264
OPENH264_CONFIGURE_ENABLE=	libopenh264

# openjpeg
OPENJPEG_LIB_DEPENDS=	libopenjpeg.so:${PORTSDIR}/graphics/openjpeg15
OPENJPEG_CONFIGURE_ENABLE=	libopenjpeg

# openssl
OPENSSL_USE=		OPENSSL=yes
OPENSSL_CONFIGURE_ENABLE=	openssl
OPENSSL_IMPLIES=	NONFREE

# optimizations
OPTIMIZED_CFLAGS_CFLAGS=-O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer

# opus
OPUS_LIB_DEPENDS=	libopus.so:${PORTSDIR}/audio/opus
OPUS_CONFIGURE_ENABLE=	libopus

# pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	libpulse
PULSEAUDIO_CONFIGURE_OFF=	--disable-indev=pulse \
				--disable-outdev=pulse

# rtmp
RTMP_LIB_DEPENDS=	librtmp.so:${PORTSDIR}/multimedia/librtmp
RTMP_CONFIGURE_ENABLE=	librtmp

# schroedinger
SCHROEDINGER_LIB_DEPENDS=	libschroedinger-1.0.so:${PORTSDIR}/multimedia/schroedinger
SCHROEDINGER_CONFIGURE_ENABLE=	libschroedinger

# sdl
SDL_USE=		SDL=sdl
SDL_CONFIGURE_ENABLE=	ffplay
SDL_CONFIGURE_OFF=	--disable-outdev=sdl

# smbclient
SMB_LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SMB_CONFIGURE_ENABLE=	libsmbclient
SMB_IMPLIES=		GPL3

# speex
SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_CONFIGURE_ENABLE=	libspeex

# sse support
SSE_CONFIGURE_ENABLE=	sse
SSE_VARS=		FFMPEG_CFLAGS+="-msse"
SSE_IMPLIES=		MMX

# theora
THEORA_LIB_DEPENDS=	libtheora.so:${PORTSDIR}/multimedia/libtheora
THEORA_CONFIGURE_ENABLE=	libtheora

# vaapi
VAAPI_LIB_DEPENDS=	libva.so:${PORTSDIR}/multimedia/libva
VAAPI_CONFIGURE_ENABLE=	vaapi

# vdpau
VDPAU_BUILD_DEPENDS=	${LOCALBASE}/include/vdpau/vdpau.h:${PORTSDIR}/multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

# vo-aacenc
VO_AACENC_LIB_DEPENDS=	libvo-aacenc.so:${PORTSDIR}/audio/vo-aacenc
VO_AACENC_CONFIGURE_ENABLE=	libvo-aacenc
VO_AACENC_IMPLIES=	GPL3

# vo-amrwbenc
VO_AMRWBENC_LIB_DEPENDS=	libvo-amrwbenc.so:${PORTSDIR}/audio/vo-amrwbenc
VO_AMRWBENC_CONFIGURE_ENABLE=	libvo-amrwbenc
VO_AMRWBENC_IMPLIES=	GPL3

# vorbis
VORBIS_LIB_DEPENDS=	libvorbisenc.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	libvorbis
VORBIS_VARS=		FFMPEG_CFLAGS+="-I${LOCALBASE}/include/vorbis"

# vp8
VPX_LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx
VPX_CONFIGURE_ENABLE=	libvpx

# x11grab
X11GRAB_USE=		XORG=x11,xext,xfixes
X11GRAB_CONFIGURE_ENABLE=	x11grab

# x264
X264_LIB_DEPENDS=	libx264.so:${PORTSDIR}/multimedia/libx264
X264_CONFIGURE_ENABLE=	libx264

# x265
X265_LIB_DEPENDS=	libx265.so:${PORTSDIR}/multimedia/x265
X265_CONFIGURE_ENABLE=	libx265

# xvid
XVID_LIB_DEPENDS=	libxvidcore.so:${PORTSDIR}/multimedia/xvid
XVID_CONFIGURE_ENABLE=	libxvid

# License knobs
GPL3_CONFIGURE_ENABLE=	version3
GPL3_VARS=		LICENSE="GPLv3 LGPL3"
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
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL5}|g' \
		${WRKSRC}/doc/texi2pod.pl

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
