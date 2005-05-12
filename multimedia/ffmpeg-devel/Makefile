# New ports collection makefile for:	ffmpeg cvs
# Date created:		Sun May  1 20:46:59 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
DISTVERSION=	0.4.9.cvs.${RELEASE_DATE}
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	http://mplayerhq.hu/MPlayer/cvs/
DISTNAME=	FFMpeg-${RELEASE_DATE}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Hyper fast realtime audio/video encoder/converter, streaming server

HAS_CONFIGURE=	yes
USE_LINUX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
WANT_SDL=	yes
CONFIGURE_ARGS=	--cc="${CC}" --prefix="${PREFIX}" \
		--make="${GMAKE}" \
		--disable-debug \
		--enable-memalign-hack \
		--enable-shared \
		--source-path=${WRKSRC}

FFMPEG_CFLAGS=	${CFLAGS} \
		-I${WRKSRC}/libavcodec \
		-I${WRKSRC}/libavcodec/i386 \
		-I${WRKSRC}/libavformat \
		-I${LOCALBASE}/include \
		-I${X11BASE}/include \
		-I. -I.. \
		-L${LOCALBASE}/lib \
		-L${X11BASE}/lib
FFMPEG_LDFLAGS=	${LDFLAGS} \
		-L${WRKSRC}/libavcodec/libpostproc \
		-L${LOCALBASE}/lib \
		-L${X11BASE}/lib \
		-lm \
		-fpie \
		-fPIE

PLIST_SUB=	SHLIB_VERSION=${SHLIB_VERSION}
INSTALLS_SHLIB=	yes

NO_LATEST_LINK=	yes
CONFLICTS=      ffmpeg-[0-9]*-*

RELEASE_DATE=	20050512
SHLIB_VERSION=	1

MAN1=		ffmpeg.1

##
DOC_FILES=	COPYING Changelog README
# under subdir doc
DOC_DOCFILES=	TODO faq.html ffmpeg-doc.html \
		ffplay-doc.html ffserver-doc.html \
		hooks.html optimization.txt
#
PORTDOCS=	*

## headers
HEADER_FILES=	libavcodec/avcodec.h libavcodec/common.h \
		libavcodec/dsputil.h
#
# libraries
LIB_FILES=	libavcodec/libavcodec.a libavformat/libavformat.a

.include <bsd.port.pre.mk>

.if (exists(${LOCALBASE}/lib/libavformat.so))
BROKEN=		'Please remove previous version of ${PORTNAME} to continue build'
.endif

##
## default options
##
GPLLIBS=yes
WITHOUT_LIBA52=yes
# video captuure is not working as of yet
WITH_VIDEO_CAPTURE=no
CONFIGURE_ARGS+=--disable-v4l

##
## support detection
##
.if !defined(WITHOUT_IPV6) && ${OSVERSION} >= 400014
WITH_IPV6=	yes
.endif

##
## arch detection
##
.if ${ARCH} != "i386"
WITHOUT_MMX=	yes
.endif

##
## lib detection
##
## dts
.if exists(${LOCALBASE}/lib/libdts.a)
WITH_DTS=yes
.endif
## faac
.if exists(${LOCALBASE}/lib/libfaac.so)
WITH_FAAC=yes
.endif
## faad
.if exists(${LOCALBASE}/lib/libfaad.so)
WITH_FAAD=yes
.endif
## freetype2
.if exists(${LOCALBASE}/lib/libfreetype.so)
WITH_FREETYPE2=yes
.endif
## imlib2
.if exists(${X11BASE}/lib/libImlib2.so)
WITH_IMLIB2=yes
.endif
## lame mp3
.if exists(${LOCALBASE}/lib/libmp3lame.so)
WITH_MP3=yes
.endif
## ogg
.if exists(${LOCALBASE}/lib/libogg.so)
WITH_OGG=yes
.endif
## sdl
.if ${HAVE_SDL:Msdl}
WITH_SDL=yes
.endif
## theora
.if exists(${LOCALBASE}/lib/libtheora.so)
## XXX theora does not work for the time being
WITH_THEORA=yes
.endif
## vorbis
.if exists(${LOCALBASE}/lib/libvorbisenc.so)
WITH_VORBIS=yes
.endif
# x264
.if exists(${LOCALBASE}/lib/libx264.so)
WITH_X264=yes
.endif
# xvid
.if exists(${LOCALBASE}/lib/libxvidcore.so)
WITH_XVID=yes
.endif

##
## support activation
##
## PORTDOCS
.ifndef(NOPORTDOCS)
BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.endif
## optimization
# breaks ffmpeg build if defined
FFMPEG_CFLAGS+=		-fno-force-addr

.ifdef(WITH_OPTIMIZED_CFLAGS)
FFMPEG_CFLAGS+=		-O3 -ffast-math -fomit-frame-pointer
. if ${OSVERSION} > 502124
FFMPEG_CFLAGS+=		-fno-unit-at-a-time
. endif
.endif

## a52
.ifndef(WITHOUT_LIBA52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52

CONFIGURE_ARGS+=	--enable-a52 \
			--enable-a52bin

# libavcodec needs it
FFMPEG_LDFLAGS+=		-la52
.else
CONFIGURE_ARGS+=	--enable-a52 \
			--disable-a52bin
.endif
## dts
.ifdef(WITH_DTS)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libdts.a:${PORTSDIR}/multimedia/libdts

CONFIGURE_ARGS+=	--enable-dts
.endif
## faac
.ifdef(WITH_FAAC)
LIB_DEPENDS+=		faac.0:${PORTSDIR}/audio/faac

CONFIGURE_ARGS+=	--enable-faac
.endif
## faad
.ifdef(WITH_FAAD)
LIB_DEPENDS+=		faad.0:${PORTSDIR}/audio/faad

CONFIGURE_ARGS+=	--enable-faad \
			--enable-faadbin
.endif
## ffserver
.ifdef(WITHOUT_FFMPEG_FFSERVER)
CONFIGURE_ARGS+=	--disable-ffserver
.else
USE_RC_SUBR=		yes

MAN1+=			ffserver.1

PLIST_FILES+=		bin/ffserver \
			etc/ffserver.conf.sample \
			etc/rc.d/ffserver.sh
.endif
## gpl libs
.ifdef(GPLLIBS)
CONFIGURE_ARGS+=	--enable-gpl
.endif
## disable mmx
.ifdef(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx

WITHOUT_BUILTIN_VECTOR=	yes
.endif
## mp3
.ifdef(WITH_MP3)
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame

CONFIGURE_ARGS+=	--enable-mp3lame
.endif
## ogg
.ifdef(WITH_OGG)
LIB_DEPENDS+=		ogg.5:${PORTSDIR}/audio/libogg

CONFIGURE_ARGS+=	--enable-libogg
.endif
## post processing
.ifndef(WITHOUT_POSTPROCESS)
CONFIGURE_ARGS+=	--enable-pp \
			--enable-shared-pp

LIB_FILES+=		libavcodec/libpostproc/libpostproc.a
PLIST_DIRS+=		include/ffmpeg/postproc \
			include/ffmpeg
PLIST_FILES+=		include/ffmpeg/postproc/postprocess.h
.endif
## pthreads
.ifndef(WITHOUT_PTHREADS)
CONFIGURE_ARGS+=		--enable-pthreads
.endif
## SDL
.ifdef(WITH_SDL)
USE_SDL=	sdl

MAN1+=		ffplay.1

PLIST_FILES+=	bin/ffplay
.else
CONFIGURE_ARGS+=	--disable-ffplay
.endif
## theora
.undef WITH_THEORA
.ifdef(WITH_THEORA)
LIB_DEPENDS+=		theora.1:${PORTSDIR}/multimedia/libtheora

CONFIGURE_ARGS+=	--enable-theora
.endif
## vorbis
.ifdef(WITH_VORBIS)
LIB_DEPENDS+=		vorbisenc.2:${PORTSDIR}/audio/libvorbis

CONFIGURE_ARGS+=	--enable-vorbis
FFMPEG_CFLAGS+=		-I${LOCALBASE}/include/vorbis
.endif
# x264
.ifdef(WITH_X264)
LIB_DEPENDS+=		x264.1:${PORTSDIR}/multimedia/x264

CONFIGURE_ARGS+=	--enable-x264
.endif
## builtin vector, requires mmx
.if !defined(WITHOUT_BUILTIN_VECTOR) && defined(WITH_BUILTIN_VECTOR)
FFMPEG_CFLAGS+=		-msse
.endif
## vhook
.ifndef(WITHOUT_VHOOK)
PLIST_DIRS+=	lib/vhook
PLIST_FILES+=	\
		lib/vhook/fish.so \
		lib/vhook/null.so \
		lib/vhook/ppm.so \
		lib/vhook/watermark.so

# enable freetype2
. ifdef(WITH_FREETYPE2)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2

PLIST_FILES+=	lib/vhook/drawtext.so
. endif # freetype2

# enable imlib2
. ifdef(WITH_IMLIB2)
LIB_DEPENDS+=	Imlib2.3:${PORTSDIR}/graphics/imlib2

PLIST_FILES+=	lib/vhook/imlib2.so
. else
WITHOUT_IMLIB2=	yes
. endif # imlib2

.else
CONFIGURE_ARGS+=	-disable-vhook
.endif ## WITHOUT_VHOOK
## xvid
.ifdef(WITH_XVID)
LIB_DEPENDS+=		xvidcore.4:${PORTSDIR}/multimedia/xvid

CONFIGURE_ARGS+=	--enable-xvid
.endif

pre-everything::
.ifndef(WITHOUT_LIBA52)
	@${ECHO_MSG} 'You can disable liba52 support by defining WITHOUT_LIBA52'
	@${ECHO_MSG}
.endif
.ifndef(WITH_BUILTIN_VECTOR)
	@${ECHO_MSG} 'Define WITH_BUILTIN_VECTOR if your system supports SSE"
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
.ifndef(WITHOUT_FFMPEG_FFSERVER)
	@${ECHO_MSG} 'Define WITHOUT_FFMPEG_FFSERVER to disable ffserver build'
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
.ifndef(WITHOUT_MMX)
	@${ECHO_MSG} 'Define WITHOUT_MMX if your system does not support MMX'
	@${ECHO_MSG}
.endif
.ifndef(WITH_MP3)
	@${ECHO_MSG} 'Define WITH_MP3 to enable lame MP3 codec'
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
.ifndef(WITHOUT_PTHREADS)
	@${ECHO_MSG} 'Define WITHOUT_PTHREADS to disable threading support'
	@${ECHO_MSG}
.endif
.ifndef(WITHOUT_POSTPROCESS)
	@${ECHO_MSG} 'You can disable post process support by defining'
	@${ECHO_MSG} 'WITHOUT_POSTPROCESS'
	@${ECHO_MSG} 'Beware that this might break some ports that require it'
	@${ECHO_MSG}
.endif
.ifndef(WITH_SDL)
	@${ECHO_MSG} 'Define WITH_SDL to enable ffplay SDL version'
	@${ECHO_MSG}
.endif
.ifndef(WITH_THEORA)
	@${ECHO_MSG} 'Define WITH_THEORA to enable THEORA codec'
	@${ECHO_MSG}
.endif
.ifndef(WITHOUT_VHOOK)
	@${ECHO_MSG} 'You can disable vhook support by defining WITHOUT_VHOOK'
	@${ECHO_MSG}
.endif
.ifndef(WITH_VORBIS)
	@${ECHO_MSG} 'Define WITH_VORBIS to enable libvorbisenc VORBIS codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_X264)
	@${ECHO_MSG} 'Define WITH_VORBIS to enable X264 codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_XVID)
	@${ECHO_MSG} 'Define WITH_VORBIS to enable XVID codec'
	@${ECHO_MSG}
.endif
.if ${ARCH} == "i386"
.if !(defined(WITH_BKTR_FORMAT) && defined(WITH_BKTR_DEV))
	@${ECHO_MSG}
	@${ECHO_MSG} 'If you want to capture from a bktr(4) supported card'
	@${ECHO_MSG} 'you will probably need to set the input device and format'
	@${ECHO_MSG} 'You can set WITH_BKTR_FORMAT to NTSC or PAL and you can set'
	@${ECHO_MSG} 'WITH_BKTR_DEV to 0, 1, 2 or 3 (1 is usually the tuner)'
	@${ECHO_MSG} 'so for a PAL tuner make WITH_BKTR_FORMAT=PAL WITH_BKTR_DEV=1'
	@${ECHO_MSG}
	@${ECHO_MSG} 'Warning: invalid settings will probably dump cores'
	@${ECHO_MSG}
.endif
.endif # ${ARCH} == i386

post-extract:
.if ${ARCH} == "i386"
# install booktree extension
	@${CP} ${FILESDIR}/grab_bsdbktr.c ${WRKSRC}/libavformat/
.endif # ${ARCH} == i386

post-patch:
# {C,LD}FLAGS safeness
	@${FIND} ${WRKDIR} -type f -name "Makefile" -print0 | \
		${XARGS} -0 -n 5 -x \
			${REINPLACE_CMD} -E \
			-e 's@^(CFLAGS.+)$$@\1 ${FFMPEG_CFLAGS}@' \
			-e 's@^(FFLIBS|LDFLAGS)(.+)$$@\1\2 ${FFMPEG_LDFLAGS}@' \
# fix x264 math, use correct log base 2 from math(3)
	@${REINPLACE_CMD} -E \
		-e 's| log2| log|' \
		${WRKSRC}/libavcodec/x264.c
# force detection of texi2html
.ifndef(NOPORTDOCS)
	@${REINPLACE_CMD} -E \
		-e 's|^(texi2html=)no|\1yes|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.if ${ARCH} == "i386"
.ifdef(WITH_VIDEO_CAPTURE)
# we support "v4l" per default through Steve O'Hara-Smith's bktr(4)
# patch
	@${REINPLACE_CMD} -E \
		-e 's|^(v4l).*$$|\1="yes"|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# set proper audio device
.ifdef(WITH_AUDIO_DEV)
	@${REINPLACE_CMD} -E \
		-e 's!/dev/dsp!${WITH_AUDIO_DEV:Q}!' \
		${WRKSRC}/libavformat/audio.c
.endif
.ifdef(WITH_BKTR_DEV)
	@${REINPLACE_CMD} -E \
		-e "s!idev = 0!idev = ${WITH_BKTR_DEV}!" \
		${WRKSRC}/libavformat/grab_bsdbktr.c
.endif
.ifdef(WITH_BKTR_FORMAT)
	@${REINPLACE_CMD} -E \
		-e "s!VIDEO_FORMAT NTSC!VIDEO_FORMAT ${WITH_BKTR_FORMAT}!" \
		${WRKSRC}/libavformat/grab_bsdbktr.c
.endif
.endif # WITH_VIDEO_CAPTURE
.endif # ${ARCH} == i386
# malloc.h was deprecated in favor of stdlib.h
# do not shadow fprintf(3) with bogus statement
	@${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 -n 5 -x ${REINPLACE_CMD} -E \
		-e 's|malloc\.h|stdlib\.h|' \
		-e 's|^.*please_use_av_log.*$$||'
.ifndef(WITHOUT_LIBA52)
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -E \
		-e 's|../(avcodec.h)|\1|' \
		${WRKSRC}/libavcodec/liba52/a52.h
.endif
.ifndef(WITHOUT_FFMPEG_FFSERVER)
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|; s|%%RC_SUBR%%|${RC_SUBR}|' \
		${FILESDIR}/ffserver.sh >${WRKDIR}/ffserver.sh
	@${REINPLACE_CMD} -e "s!/etc/ffserver.conf!${PREFIX}/etc/ffserver.conf!g" \
		${WRKSRC}/ffserver.c ${WRKSRC}/doc/ffserver-doc.texi
	@${REINPLACE_CMD} -e 's!NoDaemon!# NoDaemon!g' \
		${WRKSRC}/doc/ffserver.conf
.endif
.if defined(WITH_IMLIB2) && !defined(WITHOUT_IMLIB2)
	@${REINPLACE_CMD} -E \
		-e 's|^(imlib2).*$$|\1=yes|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -E \
		-e 's|(-lImlib2)|-L ${X11BASE}/lib \1|' \
		${WRKSRC}/vhook/Makefile
.endif
.if defined(WITH_IPV6) && ${OSVERSION} >= 400014
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
		-e 's|#include <SDL|#include <SDL11/SDL|'
.endif
.ifndef(WITHOUT_POSTPROCESS)
	@${REINPLACE_CMD} -E \
		-e 's|^(SPPVERSION).*$$|\1=${SHLIB_VERSION}|' \
		-e 's|\$$[(]SPPLIB[)].0|$$(SPPLIB).${SHLIB_VERSION}|' \
		${WRKSRC}/libavcodec/libpostproc/Makefile
# XXX - libavcodec.so needs libpostproc.so but looks for libpostproc.so.0
# exists
	@${LN} -sf libpostproc.so \
		${WRKSRC}/libavcodec/libpostproc/libpostproc.so.${SHLIB_VERSION}
.endif
.ifndef(WITHOUT_BUILTIN_VECTOR)
	@${REINPLACE_CMD} -E \
		-e 's|^(builtin_vector).*$$|\1=yes|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif

post-configure:
.ifdef(WITH_DTS)
	@${REINPLACE_CMD} -E \
		-e 's|-ldts|${LOCALBASE}/lib/libdts.a|' \
		-e 's|(-lx264)|-L${LOCALBASE}/lib \1|' \
			${WRKSRC}/config.mak \
			${WRKSRC}/libavcodec/Makefile
.endif
.ifdef(WITH_X264)
	@${REINPLACE_CMD} -E \
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
.ifndef(WITHOUT_FFMPEG_FFSERVER)
	@${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${PREFIX}/etc/ffserver.conf.sample
	@${INSTALL_SCRIPT} ${WRKDIR}/ffserver.sh ${PREFIX}/etc/rc.d
.endif
.for file in ${HEADER_FILES}
# fix header references prior to installation
	@${REINPLACE_CMD} -e 's|"common.h"|<ffmpeg/common.h>|; \
		s|"avcodec.h"|<ffmpeg/avcodec.h>|' \
		${WRKSRC}/${file}
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${PREFIX}/include/ffmpeg/${file:T}
# change headers back so reinstall target works
	@${REINPLACE_CMD} -e 's|<ffmpeg/common.h>|"common.h"|; \
		s|<ffmpeg/avcodec.h>|"avcodec.h"|' \
		${WRKSRC}/${file}
.endfor
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/${file:T}
.endfor
.ifndef(WITHOUT_POSTPROCESS)
	@${MKDIR} ${PREFIX}/include/ffmpeg/postproc
	@${INSTALL_DATA} ${WRKSRC}/libavcodec/libpostproc/postprocess.h \
		${PREFIX}/include/ffmpeg/postproc/postprocess.h
.endif

.include <bsd.port.post.mk>
