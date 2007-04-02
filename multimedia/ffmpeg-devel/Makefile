# New ports collection makefile for:	ffmpeg cvs
# Date created:		Sun May  1 20:46:59 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
DISTVERSION=	2007-03-31
PORTREVISION=	1
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze
PKGNAMESUFFIX=	-devel

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Hyper fast realtime audio/video encoder/converter, streaming server

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_SDL=	yes
CONFIGURE_ARGS=	--cc="${CC}" --prefix="${PREFIX}" \
		--make="${GMAKE}" \
		--disable-debug \
		--enable-memalign-hack \
		--enable-shared \
		--enable-pp \
		--extra-cflags="-fPIC ${CFLAGS} -I${LOCALBASE}/include" \
		--extra-ldflags="-L${LOCALBASE}/lib" \
		--extra-libs="${PTHREAD_LIBS}" \
		--disable-bktr \
		--enable-gpl
MAKE_ENV=	INSTALL="${INSTALL}"
SHLIB_VER=	1
PLIST_SUB=	SHLIB_VER=${SHLIB_VER}
USE_LDCONFIG=	yes

CONFLICTS=	ffmpeg-[0-9]*-*

MAN1=		ffmpeg.1

##
DOC_FILES=	COPYING Changelog README
# under subdir doc
DOC_DOCFILES=	TODO faq.html ffmpeg-doc.html \
		ffplay-doc.html ffserver-doc.html \
		hooks.html optimization.txt
PORTDOCS=	*

.include <bsd.port.pre.mk>

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
.endif

.ifdef(WITH_OPTIMIZED_CFLAGS)
FFMPEG_CFLAGS+=		-O3 -ffast-math -fomit-frame-pointer
.endif

## a52
.if !defined(WITHOUT_LIBA52) && !defined(WITHOUT_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52

CONFIGURE_ARGS+=	--enable-liba52 \
			--enable-liba52bin
FFMPEG_LDFLAGS+=		-la52
.else
CONFIGURE_ARGS+=	--enable-liba52
.endif
## dts
.ifdef(WITH_DTS) || exists(${LOCALBASE}/lib/libdts.a)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libdts.a:${PORTSDIR}/multimedia/libdts

CONFIGURE_ARGS+=	--enable-libdts
.endif
## faac
.ifdef(WITH_FAAC) || exists(${LOCALBASE}/lib/libfaac.so)
LIB_DEPENDS+=		faac.0:${PORTSDIR}/audio/faac

CONFIGURE_ARGS+=	--enable-libfaac
.endif
## faad
.ifdef(WITH_FAAD) || exists(${LOCALBASE}/lib/libfaad.so)
LIB_DEPENDS+=		faad.0:${PORTSDIR}/audio/faad

CONFIGURE_ARGS+=	--enable-libfaad \
			--enable-libfaadbin
.endif
USE_RC_SUBR=		ffserver
MAN1+=			ffserver.1

#### BROKEN LIST #####
WITHOUT_THEORA=	yes

.if ${MACHINE_CPU:Mmmx}==""
CONFIGURE_ARGS+=	--disable-mmx

WITHOUT_BUILTIN_VECTOR=	yes
.endif
## gsm
.ifdef(WITH_GSM) || exists(${LOCALBASE}/lib/libgsm.so)
LIB_DEPENDS+=		gsm.1:${PORTSDIR}/audio/gsm

CONFIGURE_ARGS+=	--enable-libgsm
.endif
## mp3
.ifdef(WITH_LAME) || exists(${LOCALBASE}/lib/libmp3lame.so) || defined(WITH_MP3)
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame

CONFIGURE_ARGS+=	--enable-libmp3lame
.endif
## ogg
.ifdef(WITH_OGG) || exists(${LOCALBASE}/lib/libogg.so)
LIB_DEPENDS+=		ogg.5:${PORTSDIR}/audio/libogg

CONFIGURE_ARGS+=	--enable-libogg
.endif

## SDL
.ifdef(WITH_SDL) || ${HAVE_SDL:Msdl}
USE_SDL+=	sdl

MAN1+=		ffplay.1

PLIST_FILES+=	bin/ffplay
.else
CONFIGURE_ARGS+=	--disable-ffplay
.endif
## theora
.if !defined(WITHOUT_THEORA)
WITH_OGG=	yes
LIB_DEPENDS+=		theora.2:${PORTSDIR}/multimedia/libtheora

CONFIGURE_ARGS+=	--enable-libtheora
.endif
## vorbis
.if !defined(WITHOUT_VORBIS)
WITH_OGG=	yes
LIB_DEPENDS+=		vorbisenc.2:${PORTSDIR}/audio/libvorbis

CONFIGURE_ARGS+=	--enable-libvorbis
FFMPEG_CFLAGS+=		-I${LOCALBASE}/include/vorbis
.endif
# x264
.ifdef(WITH_X264) || exists(${LOCALBASE}/lib/libx264.so)
LIB_DEPENDS+=		x264.50:${PORTSDIR}/multimedia/x264

CONFIGURE_ARGS+=	--enable-x264
.endif
## builtin vector, requires mmx
.if !defined(WITHOUT_BUILTIN_VECTOR) && defined(WITH_BUILTIN_VECTOR)
FFMPEG_CFLAGS+=		-msse
.endif
. ifdef(WITH_FREETYPE2) || exists(${LOCALBASE}/lib/libfreetype.so)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2

PLIST_FILES+=	lib/vhook/drawtext.so
. endif # freetype2
. ifdef(WITH_IMLIB2) || exists(${LOCALBASE}/lib/libImlib2.so)
LIB_DEPENDS+=	Imlib2.4:${PORTSDIR}/graphics/imlib2

PLIST_FILES+=	lib/vhook/imlib2.so
. else
WITHOUT_IMLIB2=	yes
. endif # imlib2

## xvid
.ifdef(WITH_XVID) || exists(${LOCALBASE}/lib/libxvidcore.so)
LIB_DEPENDS+=		xvidcore.4:${PORTSDIR}/multimedia/xvid

CONFIGURE_ARGS+=	--enable-xvid
.endif

pre-everything::
.ifndef(WITHOUT_A52)
	@${ECHO_MSG} 'You can disable liba52 support by defining WITHOUT_LIBA52'
	@${ECHO_MSG}
.endif
.ifndef(WITH_DTS)
	@${ECHO_MSG} 'Define WITH_DTS to enable DTS codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_FAAC)
	@${ECHO_MSG} 'Define WITH_FAAC to enable FAAC codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_FAAD)
	@${ECHO_MSG} 'Define WITH_FAAD to enable FAAD codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_FREETYPE2)
	@${ECHO_MSG} 'Define WITH_FREETYPE2 to enable VHOOK drawtext FREETYPE2 codec'
	@${ECHO_MSG}
.endif
.ifndef(WITHOUT_IPV6)
	@${ECHO_MSG} 'Define WITHOUT_IPV6 to disable IPV6 network support'
	@${ECHO_MSG}
.endif
.ifndef(WITH_LAME)
	@${ECHO_MSG} 'Define WITH_LAME to enable lame MP3 codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_OGG)
	@${ECHO_MSG} 'Define WITH_OGG to enable OGG codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} 'You can enable additional compilation optimizations'
	@${ECHO_MSG} 'by defining WITH_OPTIMIZED_CFLAGS'
	@${ECHO_MSG}
.endif
.ifndef(WITH_VORBIS)
	@${ECHO_MSG} 'Define WITH_VORBIS to enable libvorbisenc VORBIS codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_X264)
	@${ECHO_MSG} 'Define WITH_X264 to enable X264 codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_XVID)
	@${ECHO_MSG} 'Define WITH_XVID to enable XVID codec'
	@${ECHO_MSG}
.endif

post-patch:
# Faad compat
	@${REINPLACE_CMD} -e 's|faacD|NeAACD|' ${WRKSRC}/libavcodec/faad.c
# {C,LD}FLAGS safeness
# fix x264 math, use correct log base 2 from math(3)
.if ${OSVERSION} <= 601000
	@${REINPLACE_CMD} -E \
		-e 's| log2| log|' \
		${WRKSRC}/libavcodec/x264.c
.endif
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/common.mak
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
	@${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 -n 5 -x ${REINPLACE_CMD} -E \
		-e 's|malloc\.h|stdlib\.h|' \
		-e 's|^.*please_use_av_log.*$$||'
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(WITH_IMLIB2) && !defined(WITHOUT_IMLIB2)
	@${REINPLACE_CMD} -E \
		-e 's|^(imlib2).*$$|\1=yes|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -E \
		-e 's|(-lImlib2)|-L ${LOCALBASE}/lib \1|' \
		${WRKSRC}/vhook/Makefile
.endif
.if defined(WITH_IPV6)
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

post-configure:
.ifdef(WITH_DTS)
	@${REINPLACE_CMD} -E \
		-e 's|-ldts|${LOCALBASE}/lib/libdts_pic.a|' \
		-e 's|(-lx264)|-L${LOCALBASE}/lib \1|' \
			${WRKSRC}/config.mak \
			${WRKSRC}/libavcodec/Makefile
.endif
.ifndef(WITH_THEORA)
	@${REINPLACE_CMD} -E \
		-e 's|^(CONFIG_LIBTHEORA).*$$|\1=no|' \
		${WRKSRC}/config.mak
.endif
# shared libraries PIC
	@${REINPLACE_CMD} -E \
		-e 's|^(PIC[[:space:]]*=.*)$$|\1 -fpic -fPIC -DPIC|' \
		${WRKSRC}/config.mak
post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${DOC_DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
