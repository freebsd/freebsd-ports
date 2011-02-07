# New ports collection makefile for:	ffmpeg-devel
# Date created:		2009-08-12
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
DISTVERSION=	2011-02-07
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	http://git.ffmpeg.org/?p=ffmpeg.git;sf=tgz;a=snapshot;h=${GIT_SNAPSHOT};
DISTNAME=	ffmpeg-${GIT_SUFFIX}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm

CONFLICTS=	ffmpeg-0.*

LATEST_LINK=	ffmpeg-devel

GIT_SNAPSHOT=	5bea615dc383cf3617c5057db4fbc6832fc64137

GIT_SUFFIX=	${GIT_SNAPSHOT:C/^(.......).*$/\1/g}
FETCH_BEFORE_ARGS+=	-o ffmpeg-${GIT_SUFFIX}${EXTRACT_SUFX}

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	config.err
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
WANT_SDL=	yes

OPTIONS=	ALSA	"Enable alsa input/output device" off \
		AMR_NB	"AMR Narrow Band encoder (opencore)" on \
		AMR_WB	"AMR Wide Band decoder (opencore)" on \
		CPUDETECT "Enable runtime CPU detection" on \
		DIRAC	"Dirac codec via libdirac" off \
		FAAC	"FAAC mp4/aac audio encoder" off \
		FFSERVER "Build and install ffserver" on \
		FREI0R	"Frei0r wrapper filter" off \
		GSM	"GSM audio codec" off \
		LAME	"LAME MP3 encoder" off \
		OPENCV	"OpenCV video filtering support" off \
		OPENJPEG	"JPEG 2000 decoder" off \
		OPTIMIZED_CFLAGS "Additional optimizations" off \
		SCHROEDINGER	"Dirac codec via libschroedinger" on \
		SDL	"SDL support (build ffplay)" off \
		SPEEX	"Speex audio decoder" off \
		SSSE3	"SSSE3 support" on \
		THEORA	"Theora encoder (implies OGG)" on \
		VDPAU "NVidia vdpau support" off \
		VORBIS	"Vorbis encoder via libvorbis (implies OGG)" on \
		VP8	"VP8 codec via libvpx" on \
		X264	"H.264 encoder" on \
		XVID	"Xvid encoder via xvidcore" on

COMPAT_HEADERS=libavcodec/avcodec.h \
	libavcodec/opt.h \
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
	libavutil/sha1.h \
	libpostproc/postprocess.h \
	libswscale/swscale.h

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

CONFIGURE_ARGS+=--prefix="${PREFIX}" \
		--mandir="${PREFIX}/man" \
		--enable-shared \
		--enable-gpl \
		--enable-postproc \
		--enable-avfilter \
		--enable-pthreads \
		--enable-x11grab \
		--enable-memalign-hack \
		--cc="${CC}" \
		--extra-cflags="${FFMPEG_CFLAGS} -I${LOCALBASE}/include" \
		--extra-ldflags="-L${LOCALBASE}/lib ${FFMPEG_LDFLAGS}" \
		--extra-libs="${PTHREAD_LIBS}" \
		--disable-debug
SHLIB_VER=	1
PLIST_SUB=	SHLIB_VER=${SHLIB_VER}
USE_LDCONFIG=	yes

DOC_FILES=	Changelog COPYING.GPLv2 COPYING.GPLv3 COPYING.LGPLv2.1 \
		COPYING.LGPLv3 CREDITS INSTALL LICENSE MAINTAINERS README
# under doc subdirectory
DOC_DOCFILES=	APIchanges TODO avutil.txt developer.html faq.html \
		ffmpeg.html ffplay.html ffprobe.html \
		ffserver.html general.html issue_tracker.txt \
		libavfilter.html optimization.txt rate_distortion.txt \
		snow.txt soc.txt swscale.txt tablegen.txt viterbi.txt
PORTDOCS=	*

.if !defined(WITHOUT_CPUDETECT)
CONFIGURE_ARGS+=	--enable-runtime-cpudetect
.endif

.if !defined(WITHOUT_SSSE3)
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.ifndef(WITHOUT_FFSERVER)
USE_RC_SUBR=	ffserver
.endif

# sse hardware vector support
.if defined(MACHINE_CPU) && (${MACHINE_CPU:Msse} == "sse" || ${MACHINE_CPU:Mamd64} == "amd64")
WITH_BUILTIN_VECTOR=	yes
.else
CONFIGURE_ARGS+=	--disable-sse
.endif

# mmx support
.if defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx} == "" && ${MACHINE_CPU:Mamd64} == ""
CONFIGURE_ARGS+=	--disable-mmx
WITHOUT_BUILTIN_VECTOR=	yes
.endif

# builtin vector, requires mmx and sse
.if !defined(WITHOUT_BUILTIN_VECTOR) && defined(WITH_BUILTIN_VECTOR)
FFMPEG_CFLAGS+=		-msse
.endif

# PORTDOCS
.ifndef(NOPORTDOCS)
BUILD_DEPENDS+=		texi2html:${PORTSDIR}/textproc/texi2html
MAN1+=		ffmpeg.1 ffprobe.1
. ifndef(WITHOUT_FFSERVER)
MAN1+=		ffserver.1
. endif
.endif

# optimizations
.ifdef(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer
.endif

#alsa
.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.else
CONFIGURE_ARGS+=	--disable-indev=alsa \
			--disable-outdev=alsa
.endif

# amr
.if defined(WITH_AMR_NB) || defined (WITH_AMR_WB)
LIB_DEPENDS+=	opencore-amrnb.0:${PORTSDIR}/audio/opencore-amr
.endif

.ifdef(WITH_AMR_NB)
CONFIGURE_ARGS+=        --enable-libopencore-amrnb --enable-version3
.else
CONFIGURE_ARGS+=        --disable-libopencore-amrnb
.endif

.ifdef(WITH_AMR_WB)
CONFIGURE_ARGS+=        --enable-libopencore-amrwb --enable-version3
.else
CONFIGURE_ARGS+=        --disable-libopencore-amrwb
.endif

# dirac
.ifdef(WITH_DIRAC)
LIB_DEPENDS+=	dirac_encoder.1:${PORTSDIR}/multimedia/dirac
CONFIGURE_ARGS+=	--enable-libdirac
.else
CONFIGURE_ARGS+=	--disable-libdirac
.endif

# faac
.ifdef(WITH_FAAC)
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
CONFIGURE_ARGS+=	--enable-libfaac --enable-nonfree
.else
CONFIGURE_ARGS+=	--disable-libfaac
.endif

# ffserver
.ifndef(WITHOUT_FFSERVER)
PLIST_SUB+=	FFSERVER=""
.else
PLIST_SUB+=	FFSERVER="@comment "
CONFIGURE_ARGS+=	--disable-ffserver
.endif

# frei0r
.ifdef(WITH_FREI0R)
BUILD_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
CONFIGURE_ARGS+=	--enable-frei0r
.else
CONFIGURE_ARGS+=	--disable-frei0r
.endif

# gsm
.ifdef(WITH_GSM)
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm
CONFIGURE_ARGS+=	--enable-libgsm
.else
CONFIGURE_ARGS+=	--disable-libgsm
.endif

# mp3
.ifdef(WITH_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--enable-libmp3lame
.else
CONFIGURE_ARGS+=	--disable-libmp3lame
.endif

# opencv
.ifdef(WITH_OPENCV)
LIB_DEPENDS+=	cv.2:${PORTSDIR}/graphics/opencv
CONFIGURE_ARGS+=	--enable-libopencv
.else
CONFIGURE_ARGS+=	--disable-libopencv
.endif

# openjpeg
.ifdef(WITH_OPENJPEG)
LIB_DEPENDS+=	openjpeg.2:${PORTSDIR}/graphics/openjpeg
CONFIGURE_ARGS+=	--enable-libopenjpeg
.else
CONFIGURE_ARGS+=	--disable-libopenjpeg
.endif

# schroedinger
.ifndef(WITHOUT_SCHROEDINGER)
LIB_DEPENDS+=	schroedinger-1.0.10:${PORTSDIR}/multimedia/schroedinger
CONFIGURE_ARGS+=	--enable-libschroedinger
.else
CONFIGURE_ARGS+=	--disable-libschroedinger
.endif

# sdl
.ifdef(WITH_SDL)
USE_SDL+=	sdl
PLIST_FILES+=	bin/ffplay
.if !defined(NOPORTDOCS)
MAN1+=	ffplay.1
.endif
.else
CONFIGURE_ARGS+=	--disable-ffplay
.endif

# speex
.ifdef(WITH_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=	--enable-libspeex
.else
CONFIGURE_ARGS+=	--disable-libspeex
.endif

# theora
.ifndef(WITHOUT_THEORA)
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=	--enable-libtheora
.else
CONFIGURE_ARGS+=	--disable-libtheora
.endif

# vdpau
.ifndef(WITHOUT_VDPAU)
LIB_DEPENDS+=   vdpau.1:${PORTSDIR}/multimedia/libvdpau
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

# vorbis
.ifndef(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbisenc.2:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-libvorbis
FFMPEG_CFLAGS+=		-I${LOCALBASE}/include/vorbis
.else
CONFIGURE_ARGS+=	--disable-libvorbis
.endif

# vp8
.ifndef(WITHOUT_VP8)
LIB_DEPENDS+=	vpx.0:${PORTSDIR}/multimedia/libvpx
CONFIGURE_ARGS+=	--enable-libvpx
.else
CONFIGURE_ARGS+=	--disable-libvpx
.endif

# x264
.ifdef(WITH_X264)
LIB_DEPENDS+=	x264.110:${PORTSDIR}/multimedia/x264
CONFIGURE_ARGS+=	--enable-libx264
.else
CONFIGURE_ARGS+=	--disable-libx264
.endif

# xvid
.ifndef(WITHOUT_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--enable-libxvid
.else
CONFIGURE_ARGS+=	--disable-libxvid
.endif

pre-configure:
.if defined(WITHOUT_OGG) && (!defined(WITHOUT_VORBIS) || !defined(WITHOUT_THEORA))
	@${ECHO_MSG}	WITH_VORBIS or WITH_THEORA defined, libogg will be built
.endif

post-patch:
# {C,LD}FLAGS safeness
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/subdir.mak
	@${REINPLACE_CMD} -e 's|/etc/ffserver.conf|${PREFIX}/etc/ffserver.conf|' \
		${WRKSRC}/ffserver.c
	@${REINPLACE_CMD} -E \
		-e "s|(EXTRALIBS[[:space:]]*=)|\1-L${LOCALBASE}/lib |g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|-pthread|${PTHREAD_LIBS}|g; \
		s|gsm/gsm.h|gsm.h|g" \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-ldl||; s|$$(LIBMAJOR)|${SHLIB_VER}|g;' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.ifdef(WITH_SDL)
	@${REINPLACE_CMD} -E \
		-e 's|sdl-config|${SDL_CONFIG}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E \
		-e 's|#include <SDL|#include <SDL/SDL|'
.endif

post-configure:
.ifdef(WITHOUT_THEORA)
	@${REINPLACE_CMD} -E \
		-e 's|^(CONFIG_LIBTHEORA).*$$|\1=no|' \
		${WRKSRC}/config.mak
.endif

post-install:
.ifndef(WITHOUT_FFSERVER)
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf ${PREFIX}/etc/ffserver.conf-dist
	if [ ! -f ${PREFIX}/etc/ffserver.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf ${PREFIX}/etc; \
	fi
.endif
.ifndef(NOPORTDOCS)
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
