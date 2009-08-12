# New ports collection makefile for:	ffmpeg cvs
# Date created:		Sun May  1 20:46:59 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#      $Id: Makefile 77 2008-07-27 21:50:37Z buhnux $

PORTNAME=	ffmpeg
PORTVERSION=	0.5
PORTEPOCH=	1
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	http://ffmpeg.org/releases/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm

CONFLICTS=	ffmpeg-devel-20*

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	config.err
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
WANT_SDL=	yes

OPTIONS=	AMR_NB	"AMR Narrow Band encoder" off \
		AMR_WB	"AMR Wide Band encoder" off \
		DIRAC	"Dirac codec via libdirac" off \
		FAAC	"FAAC mp4/aac audio encoder" off \
		FAAD	"FAAD mp4/aac audio decoder" on \
		FFSERVER "Build and install ffserver" on \
		GSM	"GSM audio codec" off \
		IPV6	"IPV6 network support" on \
		LAME	"LAME MP3 encoder" off \
		OPENJPEG	"JPEG 2000 decoder" off \
		OPTIMIZED_CFLAGS "Additional optimizations" off \
		SCHROEDINGER	"Dirac codec via libschroedinger" on \
		SDL	"SDL support (build ffplay)" off \
		SPEEX	"Speex audio decoder" off \
		THEORA	"Theora encoder (implies OGG)" on \
		VHOOK	"Video hook support" off \
		VORBIS	"Vorbis encoder via libvorbis (implies OGG)" on \
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

CONFIGURE_ARGS+=--prefix="${PREFIX}" \
		--mandir="${PREFIX}/man" \
		--enable-shared \
		--enable-gpl \
		--enable-swscale \
		--enable-postproc \
		--enable-avfilter \
		--enable-avfilter-lavf \
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

DOC_FILES=	Changelog COPYING.GPL COPYING.LGPL \
		CREDITS INSTALL MAINTAINERS README
# under doc subdirectory
DOC_DOCFILES=	APIchanges avutil.txt faq.html ffmpeg-doc.html \
		ffmpeg_powerpc_performance_evaluation_howto.txt \
		ffplay-doc.html ffserver-doc.html general.html \
		issue_tracker.txt optimization.txt \
		snow.txt soc.txt swscale.txt TODO
PORTDOCS=	*

.ifndef(WITHOUT_FFSERVER)
USE_RC_SUBR=	ffserver
.endif

# sse hardware vector support
.if (defined(MACHINE_CPU) && ${MACHINE_CPU:Msse} == "sse")
WITH_BUILTIN_VECTOR=	yes
.else
CONFIGURE_ARGS+=	--disable-sse
.endif

# mmx support
.if ${MACHINE_CPU:Mmmx} == ""
CONFIGURE_ARGS+=	--disable-mmx
WITHOUT_BUILTIN_VECTOR=	yes
.endif

# builtin vector, requires mmx
.if !defined(WITHOUT_BUILTIN_VECTOR) && defined(WITH_BUILTIN_VECTOR)
FFMPEG_CFLAGS+=		-msse
.endif

# PORTDOCS
.ifndef(NOPORTDOCS)
BUILD_DEPENDS+=		texi2html:${PORTSDIR}/textproc/texi2html
MAN1+=		ffmpeg.1
. ifndef(WITHOUT_FFSERVER)
MAN1+=		ffserver.1
. endif
.endif

# optimizations
.ifdef(WITH_OPTIMIZED_CFLAGS)
CFLAGS:=	${CFLAGS:N-O*} -O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer
.else
CFLAGS:=	${CFLAGS:N-O0} -O2
DEBUG_FLAGS+=	-O2
.endif

# amr
.ifdef(WITH_AMR_NB)
LIB_DEPENDS+=	amrnb.3:${PORTSDIR}/audio/libamrnb
CONFIGURE_ARGS+=	--enable-libamr-nb --enable-nonfree
.else
CONFIGURE_ARGS+=	--disable-libamr-nb
.endif

.ifdef(WITH_AMR_WB)
LIB_DEPENDS+=	amrwb.3:${PORTSDIR}/audio/libamrwb
CONFIGURE_ARGS+=	--enable-libamr-wb --enable-nonfree
.else
CONFIGURE_ARGS+=	--disable-libamr-wb
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
CONFIGURE_ARGS+=	--enable-libfaac
.else
CONFIGURE_ARGS+=	--disable-libfaac
.endif

# faad
.ifndef(WITHOUT_FAAD)
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
CONFIGURE_ARGS+=	--enable-libfaad \
			--enable-libfaadbin
.else
CONFIGURE_ARGS+=	--disable-libfaad
.endif

# ffserver
.ifndef(WITHOUT_FFSERVER)
PLIST_SUB+=	FFSERVER=""
.else
PLIST_SUB+=	FFSERVER="@comment "
CONFIGURE_ARGS+=	--disable-ffserver
.endif

# gsm
.ifdef(WITH_GSM)
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm
CONFIGURE_ARGS+=	--enable-libgsm
.else
CONFIGURE_ARGS+=	--disable-libgsm
.endif

# vhook
.if defined(WITH_VHOOK)
USE_EFL=		imlib2
LIB_DEPENDS+=		freetype.9:${PORTSDIR}/print/freetype2
PLIST_SUB+=	VHOOK=""
.else
CONFIGURE_ARGS+=	--disable-vhook
PLIST_SUB+=	VHOOK="@comment "
.endif

# ipv6
.ifndef(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# mp3
.ifdef(WITH_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--enable-libmp3lame
.else
CONFIGURE_ARGS+=	--disable-libmp3lame
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
LIB_DEPENDS+=	schroedinger-1.0.2:${PORTSDIR}/multimedia/schroedinger
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

# vorbis
.ifndef(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbisenc.2:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-libvorbis
FFMPEG_CFLAGS+=		-I${LOCALBASE}/include/vorbis
.else
CONFIGURE_ARGS+=	--disable-libvorbis
.endif

# x264
.ifndef(WITHOUT_X264)
LIB_DEPENDS+=	x264.65:${PORTSDIR}/multimedia/x264
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
# faad compat
	@${REINPLACE_CMD} -e 's|faacD|NeAACD|' ${WRKSRC}/libavcodec/libfaad.c
# {C,LD}FLAGS safeness
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/subdir.mak
	@${REINPLACE_CMD} -e 's|/etc/ffserver.conf|${PREFIX}/etc/ffserver.conf|' \
		${WRKSRC}/ffserver.c
	@${REINPLACE_CMD} -E \
		-e "s|(EXTRALIBS[[:space:]]*=)|\1-L${LOCALBASE}/lib |g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|-pthread|${PTHREAD_LIBS}|g" \
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
