# New ports collection makefile for:	ffmpeg-devel
# Date created:		2009-08-12
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
DISTVERSION=	2012-04-25
PORTREVISION=	3
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mm/ffmpeg
PKGNAMESUFFIX=	-devel
DISTNAME=	ffmpeg-HEAD-${GIT_SUFFIX}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils

CONFLICTS=	ffmpeg-0.*

LATEST_LINK=	ffmpeg-devel

GIT_SNAPSHOT=	8f899545502c287653223ca27522c4abcd3a2e91
GIT_SUFFIX=	${GIT_SNAPSHOT:C/^(.......).*$/\1/g}

USE_XZ=		yes
HAS_CONFIGURE=	yes
CONFIGURE_LOG=	config.err
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
WANT_SDL=	yes

OPTIONS_DEFINE=	AACPLUS ALSA AMR_NB AMR_WB ASS CDIO CELT DEBUG FAAC \
		FFSERVER FREETYPE FREI0R GNUTLS GSM LAME MODPLUG OPENAL OPENCV \
		OPENJPEG OPENSSL OPTIMIZED_CFLAGS PULSEAUDIO RTMP SCHROEDINGER \
		SDL SPEEX THEORA VAAPI VDPAU VO_AACENC VO_AMRWBENC VORBIS VPX \
		X11GRAB X264 XVID
  
OPTIONS_DEFAULT=	FFSERVER FREETYPE FREI0R GNUTLS OPENCV SCHROEDINGER \
		THEORA VORBIS VPX X264 XVID

ASS_DESC=	Subtitles rendering via libass
CDIO_DESC=	Audio CD grabbing with libcdio
FFSERVER_DESC=	Build and install ffserver
MODPLUG_DESC=	Mod support via libmodplug
OPENAL_DESC=	OpenAL 1.1 capture support
X11GRAB_DESC=	Enable x11 grabbing

COMPAT_HEADERS=libavcodec/avcodec.h \
	libavcodec/vdpau.h \
	libavcodec/xvmc.h \
	libavdevice/avdevice.h \
	libavfilter/avfilter.h \
	libavformat/avformat.h \
	libavformat/avio.h \
	libavutil/adler32.h \
	libavutil/avstring.h \
	libavutil/avutil.h \
	libavutil/base64.h \
	libavutil/common.h \
	libavutil/crc.h \
	libavutil/fifo.h \
	libavutil/intfloat_readwrite.h \
	libavutil/log.h \
	libavutil/lzo.h \
	libavutil/mathematics.h \
	libavutil/md5.h \
	libavutil/mem.h \
	libavutil/pixfmt.h \
	libavutil/rational.h \
	libpostproc/postprocess.h \
	libswscale/swscale.h

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL} && empty(PORT_OPTIONS:MGNUTLS)
USE_OPENSSL=	yes
FFMPEG_NONFREE=	yes
.endif

.if ${PORT_OPTIONS:MX11GRAB}
USE_XORG=	x11 xext xfixes
CONFIGURE_ARGS+=	--enable-x11grab
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin

CONFIGURE_ARGS+=--prefix="${PREFIX}" \
		--mandir="${PREFIX}/man" \
		--enable-shared \
		--enable-gpl \
		--enable-postproc \
		--enable-avfilter \
		--enable-pthreads \
		--enable-memalign-hack \
		--cc="${CC}" \
		--extra-cflags="${FFMPEG_CFLAGS} -I${LOCALBASE}/include" \
		--extra-ldflags="-L${LOCALBASE}/lib ${FFMPEG_LDFLAGS}" \
		--extra-libs="${PTHREAD_LIBS}"
SHLIB_VER=	1
PLIST_SUB=	SHLIB_VER=${SHLIB_VER}
USE_LDCONFIG=	yes

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

# PORTDOCS
.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=		texi2html:${PORTSDIR}/textproc/texi2html
MAN1+=		ffmpeg.1 ffprobe.1
.endif

# optimizations
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer
.endif

#aacplus
.if ${PORT_OPTIONS:MAACPLUS}
FFMPEG_NONFREE=	yes
LIB_DEPENDS+=	aacplus.2:${PORTSDIR}/audio/libaacplus
CONFIGURE_ARGS+=	--enable-libaacplus
.else
CONFIGURE_ARGS+=	--disable-libaacplus
.endif

#alsa
.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.else
CONFIGURE_ARGS+=	--disable-indev=alsa \
			--disable-outdev=alsa
.endif

# Opencore AMR NB
.if ${PORT_OPTIONS:MAMR_NB}
FFMPEG_LICENSE_GPL3=	yes
LIB_DEPENDS+=	opencore-amrnb.0:${PORTSDIR}/audio/opencore-amr
CONFIGURE_ARGS+=	--enable-libopencore-amrnb
.else
CONFIGURE_ARGS+=	--disable-libopencore-amrnb
.endif

# Opencore AMR WB
.if ${PORT_OPTIONS:MAMR_WB}
FFMPEG_LICENSE_GPL3=	yes
LIB_DEPENDS+=	opencore-amrwb.0:${PORTSDIR}/audio/opencore-amr
CONFIGURE_ARGS+=	--enable-libopencore-amrwb
.else
CONFIGURE_ARGS+=	--disable-libopencore-amrwb
.endif

# ass
.if ${PORT_OPTIONS:MASS}
LIB_DEPENDS+=	ass.5:${PORTSDIR}/multimedia/libass
CONFIGURE_ARGS+=	--enable-libass
.else
CONFIGURE_ARGS+=	--disable-libass
.endif

# cdio
.if ${PORT_OPTIONS:MCDIO}
LIB_DEPENDS+=	cdio.13:${PORTSDIR}/sysutils/libcdio
CONFIGURE_ARGS+=	--enable-libcdio
.else
CONFIGURE_ARGS+=	--disable-libcdio
.endif

# celt
.if ${PORT_OPTIONS:MCELT}
LIB_DEPENDS+=	celt0.2:${PORTSDIR}/audio/celt
CONFIGURE_ARGS+=	--enable-libcelt
.else
CONFIGURE_ARGS+=	--disable-libcelt
.endif

# faac
.if ${PORT_OPTIONS:MFAAC}
FFMPEG_NONFREE=	yes
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
CONFIGURE_ARGS+=	--enable-libfaac
.else
CONFIGURE_ARGS+=	--disable-libfaac
.endif

# ffserver
.if ${PORT_OPTIONS:MFFSERVER}
PLIST_SUB+=	FFSERVER=""
.if ${PORT_OPTIONS:MDOCS}
MAN1+=		ffserver.1
DOC_DOCFILES+=	ffserver.html
. endif
.else
PLIST_SUB+=	FFSERVER="@comment "
CONFIGURE_ARGS+=	--disable-ffserver
.endif

# freetype
.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--enable-libfreetype
.else
CONFIGURE_ARGS+=	--disable-libfreetype
.endif

# frei0r
.if ${PORT_OPTIONS:MFREI0R}
BUILD_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
CONFIGURE_ARGS+=	--enable-frei0r
.else
CONFIGURE_ARGS+=	--disable-frei0r
.endif

# GnuTLS
.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

# gsm
.if ${PORT_OPTIONS:MGSM}
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm
CONFIGURE_ARGS+=	--enable-libgsm
.else
CONFIGURE_ARGS+=	--disable-libgsm
.endif

# mp3
.if ${PORT_OPTIONS:MLAME}
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--enable-libmp3lame
.else
CONFIGURE_ARGS+=	--disable-libmp3lame
.endif

# modplug
.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	 modplug.1:${PORTSDIR}/audio/libmodplug
CONFIGURE_ARGS+=	--enable-libmodplug
.else
CONFIGURE_ARGS+=	--disable-libmodplug
.endif

# OpenAL
.if ${PORT_OPTIONS:MOPENAL}
LIB_DEPENDS+=	openal.1:${PORTSDIR}/audio/openal-soft
CONFIGURE_ARGS+=	--enable-openal
.else
CONFIGURE_ARGS+=	--disable-openal
.endif

# opencv
.if ${PORT_OPTIONS:MOPENCV}
LIB_DEPENDS+=	opencv_imgproc.2:${PORTSDIR}/graphics/opencv
CONFIGURE_ARGS+=	--enable-libopencv
.else
CONFIGURE_ARGS+=	--disable-libopencv
.endif

# openjpeg
.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	openjpeg.2:${PORTSDIR}/graphics/openjpeg
CONFIGURE_ARGS+=	--enable-libopenjpeg
.else
CONFIGURE_ARGS+=	--disable-libopenjpeg
.endif

# PulseAudio
.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--enable-libpulse
.else
CONFIGURE_ARGS+=	--disable-libpulse
.endif

# rtmp
.if ${PORT_OPTIONS:MRTMP}
LIB_DEPENDS+=	rtmp.0:${PORTSDIR}/multimedia/rtmpdump
CONFIGURE_ARGS+=	--enable-librtmp
.else
CONFIGURE_ARGS+=	--disable-librtmp
.endif

# schroedinger
.if ${PORT_OPTIONS:MSCHROEDINGER}
LIB_DEPENDS+=	schroedinger-1.0.11:${PORTSDIR}/multimedia/schroedinger
CONFIGURE_ARGS+=	--enable-libschroedinger
.else
CONFIGURE_ARGS+=	--disable-libschroedinger
.endif

# sdl
.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl
PLIST_FILES+=	bin/ffplay
.if ${PORT_OPTIONS:MDOCS}
MAN1+=	ffplay.1
DOC_DOCFILES+=	ffplay.html
.endif
.else
CONFIGURE_ARGS+=	--disable-ffplay
.endif

# speex
.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=	--enable-libspeex
.else
CONFIGURE_ARGS+=	--disable-libspeex
.endif

# theora
.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=	--enable-libtheora
.else
CONFIGURE_ARGS+=	--disable-libtheora
.endif

# vaapi
.if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=	va.1:${PORTSDIR}/multimedia/libva
CONFIGURE_ARGS+=	--enable-vaapi
.else
CONFIGURE_ARGS+=	--disable-vaapi
.endif

# vdpau
.if ${PORT_OPTIONS:MVDPAU}
BUILD_DEPENDS+=	${LOCALBASE}/include/vdpau/vdpau.h:${PORTSDIR}/multimedia/libvdpau
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

# vo-aacenc
.if ${PORT_OPTIONS:MVO_AACENC}
FFMPEG_LICENSE_GPL3=	yes
LIB_DEPENDS+=	vo-aacenc.0:${PORTSDIR}/audio/vo-aacenc
CONFIGURE_ARGS+=	--enable-libvo-aacenc
.else
CONFIGURE_ARGS+=	--disable-libvo-aacenc
.endif

# vo-amrwbenc
.if ${PORT_OPTIONS:MVO_AMRWBENC}
FFMPEG_LICENSE_GPL3=	yes
LIB_DEPENDS+=	vo-amrwbenc.0:${PORTSDIR}/audio/vo-amrwbenc
CONFIGURE_ARGS+=	--enable-libvo-amrwbenc
.else
CONFIGURE_ARGS+=	--disable-libvo-amrwbenc
.endif

# vorbis
.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbisenc.2:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-libvorbis
FFMPEG_CFLAGS+=		-I${LOCALBASE}/include/vorbis
.else
CONFIGURE_ARGS+=	--disable-libvorbis
.endif

# vp8
.if ${PORT_OPTIONS:MVPX}
LIB_DEPENDS+=	vpx.1:${PORTSDIR}/multimedia/libvpx
CONFIGURE_ARGS+=	--enable-libvpx
.else
CONFIGURE_ARGS+=	--disable-libvpx
.endif

# x264
.if ${PORT_OPTIONS:MX264}
LIB_DEPENDS+=	x264.123:${PORTSDIR}/multimedia/x264
CONFIGURE_ARGS+=	--enable-libx264
.else
CONFIGURE_ARGS+=	--disable-libx264
.endif

# xvid
.if ${PORT_OPTIONS:MXVID}
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--enable-libxvid
.else
CONFIGURE_ARGS+=	--disable-libxvid
.endif

# License knobs
.if defined(FFMPEG_NONFREE)
RESTRICTED=	linking to libfaac or libaacplus restricts redistribution
CONFIGURE_ARGS+=	--enable-nonfree
. if defined(FFMPEG_LICENSE_GPL3)
CONFIGURE_ARGS+=	--enable-version3
. endif
.else
LICENSE_COMB=	multi
. if defined(FFMPEG_LICENSE_GPL3)
LICENSE=		GPLv3 LGPL3
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPLv3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPLv3
CONFIGURE_ARGS+=	--enable-version3
. else
LICENSE=		GPLv2 LGPL21
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPLv2
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPLv2.1
. endif
.endif

post-patch:
# {C,LD}FLAGS safeness
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/library.mak
	@${REINPLACE_CMD} -e 's|/etc/ffserver.conf|${PREFIX}/etc/ffserver.conf|' \
		${WRKSRC}/ffserver.c
	@${REINPLACE_CMD} -E \
		-e "s|(EXTRALIBS[[:space:]]*=)|\1-L${LOCALBASE}/lib |g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|-pthread|${PTHREAD_LIBS}|g; \
		s|gsm/gsm.h|gsm.h|g" \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-ldl||; s|$$(LIBMAJOR)|${SHLIB_VER}|g;' \
		-e 's|opencv opencv/cxcore.h|opencv-core opencv2/core/core_c.h|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
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
.if ${PORT_OPTIONS:MFFSERVER}
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf ${PREFIX}/etc/ffserver.conf-dist
	if [ ! -f ${PREFIX}/etc/ffserver.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf ${PREFIX}/etc; \
	fi
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for FILE in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.for FILE in ${DOC_DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${PREFIX}/include/ffmpeg
.for FILE in ${COMPAT_HEADERS}
	${CP} -f ${PREFIX}/include/${FILE} ${PREFIX}/include/ffmpeg/${FILE:C,^[^/]+/([^/]+).*,\1,}
.endfor
	${MKDIR} ${PREFIX}/include/postproc
	${CP} -f ${PREFIX}/include/libpostproc/postprocess.h \
		 ${PREFIX}/include/postproc/

.include <bsd.port.post.mk>
