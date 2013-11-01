# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	2.1
PORTEPOCH=	1
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	http://ffmpeg.org/releases/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server

LICENSE=		GPLv2 LGPL21
LICENSE_COMB=		multi

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils \
		texi2html:${PORTSDIR}/textproc/texi2html

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	config.err
USES=		gmake pkgconfig perl5
USE_PERL5=	build
USE_BZIP2=	yes
WANT_SDL=	yes

OPTIONS_DEFINE=	AACPLUS ALSA AMR_NB AMR_WB ASS CDIO CELT DEBUG FAAC \
		FDK_AAC FFSERVER FONTCONFIG FREETYPE FREI0R GNUTLS GSM ICONV \
		JACK LAME LIBBLURAY LIBV4L MODPLUG OPENAL OPENCV OPENJPEG OPENSSL \
		OPTIMIZED_CFLAGS OPUS PULSEAUDIO RTMP SCHROEDINGER SDL SPEEX \
		THEORA VAAPI VDPAU VO_AACENC VO_AMRWBENC VORBIS VPX \
		X11GRAB X264 XVID

OPTIONS_DEFAULT=	FFSERVER FONTCONFIG FREETYPE FREI0R GNUTLS ICONV \
			OPENCV SCHROEDINGER THEORA VORBIS VPX X264 XVID

ASS_DESC=	Subtitles rendering via libass
CDIO_DESC=	Audio CD grabbing with libcdio
FDK_AAC_DESC=	AAC audio encoding via Fraunhofer FDK
FFSERVER_DESC=	Build and install ffserver
LIBV4L_DESC=	Video for Linux support
OPUS_DESC=	Opus decoding with libopus
X11GRAB_DESC=	Enable x11 grabbing

# aacplus
AACPLUS_LIB_DEPENDS=	libaacplus.so:${PORTSDIR}/audio/libaacplus
AACPLUS_CONFIGURE_ENABLE=	libaacplus

# alsa
ALSA_CONFIGURE_OFF=	--disable-indev=alsa \
			--disable-outdev=alsa
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib

# Opencore AMR NB
AMR_NB_LIB_DEPENDS=	libopencore-amrnb.so:${PORTSDIR}/audio/opencore-amr
AMR_NB_CONFIGURE_ENABLE=	libopencore-amrnb

# Opencore AMR WB
AMR_WB_LIB_DEPENDS=	libopencore-amrwb.so:${PORTSDIR}/audio/opencore-amr
AMR_WB_CONFIGURE_ENABLE=	libopencore-amrwb

# ass
ASS_LIB_DEPENDS=	libass.so:${PORTSDIR}/multimedia/libass
ASS_CONFIGURE_ENABLE=	libass

# cdio
CDIO_LIB_DEPENDS=	libcdio.so:${PORTSDIR}/sysutils/libcdio
CDIO_CONFIGURE_ENABLE=	libcdio

# celt
CELT_LIB_DEPENDS=	libcelt0.so:${PORTSDIR}/audio/celt
CELT_CONFIGURE_ENABLE=	libcelt

# faac
FAAC_LIB_DEPENDS=	libfaac.so:${PORTSDIR}/audio/faac
FAAC_CONFIGURE_ENABLE=	libfaac

# fdk_aac
FDK_AAC_LIB_DEPENDS=	libfdk-aac.so:${PORTSDIR}/audio/fdk-aac
FDK_AAC_CONFIGURE_ENABLE=	libfdk-aac

# ffserver
FFSERVER_CONFIGURE_ENABLE=	ffserver

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
LIBV4L_LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l
LIBV4L_CONFIGURE_ENABLE=	libv4l2
LIBV4L_CONFIGURE_OFF=		--disable-indev=v4l2 \
				--disable-outdev=v4l2

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

# openjpeg
OPENJPEG_LIB_DEPENDS=	libopenjpeg.so:${PORTSDIR}/graphics/openjpeg
OPENJPEG_CONFIGURE_ENABLE=	libopenjpeg

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

# speex
SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_CONFIGURE_ENABLE=	libspeex

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

# vo-amrwbenc
VO_AMRWBENC_LIB_DEPENDS=	libvo-amrwbenc.so:${PORTSDIR}/audio/vo-amrwbenc
VO_AMRWBENC_CONFIGURE_ENABLE=	libvo-amrwbenc

# vorbis
VORBIS_LIB_DEPENDS=	libvorbisenc.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	libvorbis

# vp8
VPX_LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx
VPX_CONFIGURE_ENABLE=	libvpx

# x264
X264_LIB_DEPENDS=	libx264.so:${PORTSDIR}/multimedia/x264
X264_CONFIGURE_ENABLE=	libx264

# xvid
XVID_LIB_DEPENDS=	libxvidcore.so:${PORTSDIR}/multimedia/xvid
XVID_CONFIGURE_ENABLE=	libxvid

FFPROGS=	ffmpeg ffprobe
INSTALL_TARGET=	install-progs install-data install-libs install-headers
#FFMPEG_SUFFIX=	2
#PLIST_SUB+=	SUFF="${FFMPEG_SUFFIX}"

#USE_LDCONFIG=	${PREFIX}/lib/ffmpeg${FFMPEG_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.options.mk>

# ssl
.if ${PORT_OPTIONS:MOPENSSL} && empty(PORT_OPTIONS:MGNUTLS)
USE_OPENSSL=	yes
FFMPEG_NONFREE=	yes
.endif

.if ${PORT_OPTIONS:MAACPLUS} || ${PORT_OPTIONS:MFAAC} || ${PORT_OPTIONS:MFDK_AAC}
FFMPEG_NONFREE=	yes
.endif

.if ${PORT_OPTIONS:MAMR_NB} || ${PORT_OPTIONS:MAMR_WB} || \
${PORT_OPTIONS:MVO_AACENC} || ${PORT_OPTIONS:MVO_AMRWBENC}
FFMPEG_LICENSE_GPL3=	yes
.endif

# x11grab
.if ${PORT_OPTIONS:MX11GRAB}
USE_XORG=	x11 xext xfixes
CONFIGURE_ARGS+=	--enable-x11grab
.endif

.include <bsd.port.pre.mk>

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin

CONFIGURE_ARGS+=--prefix="${PREFIX}" \
		--mandir="${PREFIX}/man" \
		--datadir="${DATADIR}" \
		--enable-shared \
		--enable-gpl \
		--enable-postproc \
		--enable-avfilter \
		--enable-avresample \
		--enable-pthreads \
		--enable-memalign-hack \
		--disable-libstagefright-h264 \
		--disable-libutvideo \
		--disable-libsoxr \
		--cc="${CC}" \
		--extra-cflags="${FFMPEG_CFLAGS} -I${LOCALBASE}/include" \
		--extra-ldflags="-L${LOCALBASE}/lib ${FFMPEG_LDFLAGS}" \
		--extra-libs="${PTHREAD_LIBS}"

DOC_FILES=	Changelog CREDITS INSTALL LICENSE MAINTAINERS README
# under doc subdirectory
DOC_DOCFILES=	APIchanges RELEASE_NOTES *.txt *.html
PORTDOCS=	*

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--disable-stripping
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${PORT_OPTIONS:MFFSERVER}
USE_RC_SUBR=	ffserver
.endif

# sse hardware vector support
.if defined(MACHINE_CPU) && (${MACHINE_CPU:Msse} == "sse" || ${MACHINE_CPU:Mamd64} == "amd64")
_BUILTIN_VECTOR=	yes
.else
CONFIGURE_ARGS+=	--disable-sse
.endif

# mmx support
.if defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx} == "" && ${MACHINE_CPU:Mamd64} == ""
CONFIGURE_ARGS+=	--disable-mmx
_NO_BUILTIN_VECTOR=	yes
.endif

# builtin vector, requires mmx and sse
.if !defined(_NO_BUILTIN_VECTOR) && defined(_BUILTIN_VECTOR)
FFMPEG_CFLAGS+=		-msse
.endif

# optimizations
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer
.endif

# ffserver
.if ${PORT_OPTIONS:MFFSERVER}
PLIST_SUB+=	FFSERVER=""
PLIST_FILES+=	man/man1/ffserver.1.gz
FFPROGS+=	ffserver
. if ${PORT_OPTIONS:MDOCS}
DOC_DOCFILES+=	ffserver.html
. endif
.else
PLIST_SUB+=	FFSERVER="@comment "
.endif

# sdl
.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl
PLIST_FILES+=	bin/ffplay man/man1/ffplay.1.gz
FFPROGS+=	ffplay
.if ${PORT_OPTIONS:MDOCS}
DOC_DOCFILES+=	ffplay.html
.endif
.else
CONFIGURE_ARGS+=	--disable-ffplay --disable-outdev=sdl
.endif

# vorbis
.if ${PORT_OPTIONS:MVORBIS}
FFMPEG_CFLAGS+=		-I${LOCALBASE}/include/vorbis
.endif

# License knobs
.if defined(FFMPEG_NONFREE)
RESTRICTED=	linking to libfaac or libaacplus restricts redistribution
CONFIGURE_ARGS+=	--enable-nonfree
.endif

.if defined(FFMPEG_LICENSE_GPL3)
CONFIGURE_ARGS+=	--enable-version3
LICENSE=		GPLv3 LGPL3
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPLv3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPLv3
.endif

post-patch:
# {C,LD}FLAGS safeness
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|$$(DESTDIR)$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/library.mak
	@${REINPLACE_CMD} -e 's|/etc/ffserver.conf|${PREFIX}/etc/ffserver.conf|' \
		${WRKSRC}/ffserver.c
	@${REINPLACE_CMD} -E \
		-e "s|(EXTRALIBS[[:space:]]*=)|\1-L${LOCALBASE}/lib |g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|-pthread|${PTHREAD_LIBS}|g; \
		s|gsm/gsm.h|gsm.h|g" \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-ldl||' \
		-e 's|opencv opencv/cxcore.h|opencv-core opencv2/core/core_c.h|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL5}|g' \
		${WRKSRC}/doc/texi2pod.pl
.if ${PORT_OPTIONS:MSDL}
	@${REINPLACE_CMD} -E \
		-e 's|sdl-config|${SDL_CONFIG}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E \
		-e 's|#include <SDL|#include <SDL/SDL|'
.endif

post-configure:
.if empty(PORT_OPTIONS:MTHEORA)
	@${REINPLACE_CMD} -E \
		-e 's|^(CONFIG_LIBTHEORA).*$$|\1=no|' \
		${WRKSRC}/config.mak
.endif

post-install:
.for PROG in ${FFPROGS}
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/${PROG}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/${PROG}.1
.endfor
.if ${PORT_OPTIONS:MFFSERVER}
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${STAGEDIR}${PREFIX}/etc/ffserver.conf-dist
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in ${DOC_DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
