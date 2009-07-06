# New ports collection makefile for:	ffmpeg cvs
# Date created:		Sun May  1 20:46:59 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#      $Id: Makefile 77 2008-07-27 21:50:37Z buhnux $

PORTNAME=	ffmpeg
DISTVERSION=	2008-07-27
PORTREVISION=	11
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Hyper fast realtime audio/video encoder/converter, streaming server

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	config.err
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
WANT_SDL=	yes

OPTIONS=	AMR_NB	"AMR narrowband encoder" off \
		AMR_WB	"AMR wideband encoder" off \
		FAAC	"FAAC mp4/aac audio encoder" off \
		FAAD	"FAAD mp4/aac audio decoder" on \
		GSM	"gsm audio codec" off \
		IPV6	"IPV6 network support" on \
		LAME	"lame MP3 codec" off \
		LIBA52	"liba52 support"	on \
		OPTIMIZED_CFLAGS "Additional optimizations" off \
		SDL	"SDL support (build ffplay)" off \
		THEORA	"libtheora support (implies OGG)" on \
		VORBIS	"libvorbisenc support (implies OGG)" on \
		X264	"X.264 codec" on \
		XVID	"XVID codec" off

COMPAT_HEADERS=	libavcodec/avcodec.h \
	libavcodec/opt.h \
	libavdevice/avdevice.h \
	libavformat/avformat.h \
	libavformat/avio.h \
	libavformat/rtsp.h \
	libavformat/rtspcodes.h \
	libavutil/adler32.h  \
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
	libavutil/random.h \
	libavutil/rational.h \
	libavutil/sha1.h \
	libpostproc/postprocess.h \
	libswscale/rgb2rgb.h \
	libswscale/swscale.h

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--cc="${CC}" --prefix="${PREFIX}" \
		--disable-debug \
		--enable-memalign-hack \
		--enable-shared \
		--enable-postproc \
		--extra-cflags="${FFMPEG_CFLAGS} -I${LOCALBASE}/include" \
		--extra-ldflags="-L${LOCALBASE}/lib ${FFMPEG_LDFLAGS}" \
		--extra-libs="${PTHREAD_LIBS}" \
		--enable-gpl \
		--enable-pthreads \
		--enable-swscale \
		--mandir=${PREFIX}/man
CONFIGURE_ENV+=	LANG=C
MAKE_ENV+=	INSTALL="${INSTALL}"
SHLIB_VER=	1
PLIST_SUB=	SHLIB_VER=${SHLIB_VER}
USE_LDCONFIG=	yes

##
DOC_FILES=	Changelog README
# under subdir doc
DOC_DOCFILES=	TODO faq.html ffmpeg-doc.html \
		ffplay-doc.html ffserver-doc.html \
		hooks.html optimization.txt
PORTDOCS=	*

## sse hardware vector support
.if (defined(MACHINE_CPU) && ${MACHINE_CPU:Msse} == "sse")
WITH_BUILTIN_VECTOR=	yes
.endif

##
## support activation
##
## PORTDOCS
.ifndef(NOPORTDOCS)
BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
MAN1+=	ffmpeg.1 ffserver.1
.endif

.ifdef(WITH_OPTIMIZED_CFLAGS)
CFLAGS:=		${CFLAGS:N-O*} -O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer
.else
CFLAGS:=		${CFLAGS:N-O0} -O2
DEBUG_FLAGS+=		 -O2
.endif

## a52
.if !defined(WITHOUT_LIBA52) && !defined(WITHOUT_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52

CONFIGURE_ARGS+=	--enable-liba52 \
			--enable-liba52bin
FFMPEG_LDFLAGS+=	-la52
.else
CONFIGURE_ARGS+=	--disable-liba52
.endif

.ifdef(WITH_FAAC)
LIB_DEPENDS+=		faac.0:${PORTSDIR}/audio/faac
CONFIGURE_ARGS+=	--enable-libfaac
.else
CONFIGURE_ARGS+=	--disable-libfaac
.endif

## faad
.ifndef(WITHOUT_FAAD)
LIB_DEPENDS+=		faad.2:${PORTSDIR}/audio/faad
CONFIGURE_ARGS+=	--enable-libfaad \
			--enable-libfaadbin
.else
CONFIGURE_ARGS+=	--disable-libfaad
.endif

## amr
.ifdef(WITH_AMR_NB)
LIB_DEPENDS+=		amrnb.3:${PORTSDIR}/audio/libamrnb
CONFIGURE_ARGS+=	--enable-libamr-nb --enable-nonfree
.else
CONFIGURE_ARGS+=	--disable-libamr-nb
.endif

.ifdef(WITH_AMR_WB)
LIB_DEPENDS+=		amrwb.3:${PORTSDIR}/audio/libamrwb
CONFIGURE_ARGS+=	--enable-libamr-wb --enable-nonfree
.else
CONFIGURE_ARGS+=	--disable-libamr-wb
.endif

USE_RC_SUBR=		ffserver

.if ${MACHINE_CPU:Mmmx}==""
CONFIGURE_ARGS+=	--disable-mmx

WITHOUT_BUILTIN_VECTOR=	yes
.endif
## gsm
.ifdef(WITH_GSM)
LIB_DEPENDS+=		gsm.1:${PORTSDIR}/audio/gsm

CONFIGURE_ARGS+=	--enable-libgsm
.else
CONFIGURE_ARGS+=	--disable-libgsm
.endif
## mp3
.ifdef(WITH_LAME)
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--enable-libmp3lame
.else
CONFIGURE_ARGS+=	--disable-libmp3lame
.endif

## SDL
.ifdef(WITH_SDL)
USE_SDL+=	sdl
PLIST_FILES+=	bin/ffplay
.if !defined(NOPORTDOCS)
MAN1+=	ffplay.1
.endif
.else
CONFIGURE_ARGS+=	--disable-ffplay
.endif

## theora
.if !defined(WITHOUT_THEORA)
LIB_DEPENDS+=		theora.0:${PORTSDIR}/multimedia/libtheora

CONFIGURE_ARGS+=	--enable-libtheora
.else
CONFIGURE_ARGS+=	--disable-libtheora
.endif

## vorbis
.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=		vorbisenc.2:${PORTSDIR}/audio/libvorbis

CONFIGURE_ARGS+=	--enable-libvorbis
FFMPEG_CFLAGS+=		-I${LOCALBASE}/include/vorbis
.else
CONFIGURE_ARGS+=	--disable-libvorbis
.endif

# x264
.ifndef(WITHOUT_X264)
LIB_DEPENDS+=		x264.65:${PORTSDIR}/multimedia/x264

CONFIGURE_ARGS+=	--enable-libx264
.else
CONFIGURE_ARGS+=	--disable-libx264
.endif
## builtin vector, requires mmx
.if !defined(WITHOUT_BUILTIN_VECTOR) && defined(WITH_BUILTIN_VECTOR)
FFMPEG_CFLAGS+=		-msse
.endif

## xvid
.ifdef(WITH_XVID)
LIB_DEPENDS+=		xvidcore.4:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--enable-libxvid
.else
CONFIGURE_ARGS+=	--disable-libxvid
.endif

pre-configure:
.if defined(WITHOUT_OGG) && (!defined(WITHOUT_VORBIS) || !defined(WITHOUT_THEORA))
	@${ECHO_MSG}	WITH_VORBIS or WITH_THEORA defined, libogg will be built
.endif
.if defined(WITHOUT_VHOOK) && (defined(WITH_VHOOK_FREETYPE2) || defined(WITH_VHOOK_IMLIB2))
	@${ECHO_MSG}	WITH_VHOOK_FREETYPE2 or WITH_VHOOK_IMLIB2 defined, video hooks will be built
.endif

post-patch:
# Faad compat
	@${REINPLACE_CMD} -e 's|faacD|NeAACD|' ${WRKSRC}/libavcodec/libfaad.c
# {C,LD}FLAGS safeness
# fix x264 math, use correct log base 2 from math(3)
.if ${OSVERSION} <= 601000
	@${REINPLACE_CMD} -E \
		-e 's| log2| log|' \
		${WRKSRC}/libavcodec/libx264.c
.endif
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/common.mak
	@${REINPLACE_CMD} -e 's|/etc/ffserver.conf|${PREFIX}/etc/ffserver.conf|' \
		${WRKSRC}/ffserver.c
	@${REINPLACE_CMD} -E \
		-e "s|(EXTRALIBS[[:space:]]*=)|\1-L${LOCALBASE}/lib |g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; s|%%SHLIB_VER%%|${SHLIB_VER}|g; \
		s|-pthread|${PTHREAD_LIBS}|g" \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# force detection of texi2html
.ifndef(NOPORTDOCS)
	@${REINPLACE_CMD} -E \
		-e 's|^(texi2html=)no|\1yes|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(WITH_IMLIB2) && !defined(WITHOUT_IMLIB2)
	@${REINPLACE_CMD} -E \
		-e 's|^(imlib2).*$$|\1=yes|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.if !defined(WITHOUT_IPV6)
	@${REINPLACE_CMD} -E \
		-e 's|^(ipv6).*$$|\1=yes|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.ifdef(WITH_SDL)
	@${REINPLACE_CMD} -E \
		-e 's|sdl-config|${SDL_CONFIG}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E \
		-e 's|#include <SDL|#include <SDL/SDL|'
.endif
.if !defined(WITHOUT_BUILTIN_VECTOR) && defined(WITH_BUILTIN_VECTOR)
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]+builtin_vector).*$$|\1=yes|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.else
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]+builtin_vector).*$$|\1=no|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/common.mak

post-configure:
.ifdef(WITHOUT_THEORA)
	@${REINPLACE_CMD} -E \
		-e 's|^(CONFIG_LIBTHEORA).*$$|\1=no|' \
		${WRKSRC}/config.mak
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf ${PREFIX}/etc/ffserver.conf-dist
	if [ ! -f ${PREFIX}/etc/ffserver.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf ${PREFIX}/etc; \
	fi
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
