# New ports collection makefile for:	ffmpeg
# Date created:		Tue Sep 25 15:52:09 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
PORTVERSION=	0.4.8
PORTREVISION=	3
CATEGORIES=	multimedia audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ffmpeg

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Hyper fast realtime audio/video encoder/converter, streaming server

USE_GETOPT_LONG=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--cc="${CC}" --prefix="${PREFIX}" \
		--make="${GMAKE}" --enable-shared \
		--extra-ldflags="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		--extra-libs"-lm" \
		--disable-debug
MAKE_ENV+=	LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

PLIST_SUB=	SHLIB_VERSION=${SHLIB_VERSION}
INSTALLS_SHLIB=	yes

SHLIB_VERSION=	0
#
DOC_FILES=	COPYING Changelog README
# under subdir doc
DOC_DOCFILES=	TODO \
		faq.html faq.texi \
		ffmpeg-doc.html ffmpeg-doc.texi \
		ffserver-doc.html ffserver-doc.texi
HEADER_FILES=	libavcodec/avcodec.h libavcodec/common.h \
		libavcodec/dsputil.h
LIB_FILES=	libavcodec/libavcodec.a libavformat/libavformat.a
MAN1=		ffmpeg.1 ffplay.1 ffserver.1

.include <bsd.port.pre.mk>

##
## arch detection
##
.if ${ARCH} != "i386"
WITHOUT_MMX=	yes
.else
# only for i386
EXTRA_PATCHES+=	${FILESDIR}/extra-bktr-patch-libavformat::Makefile
.endif

## lib detection
##
##
## SDL
.if exists(${LOCALBASE}/lib/libSDL-1.1.so)
WITH_SDL=yes
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
.if exists(${LOCALBASE}/lib/libmp3lame.so.0)
WITH_MP3=yes
.endif
## vorbis
.if exists(${LOCALBASE}/lib/libvorbisenc.so.2)
WITH_VORBIS=yes
.endif

## support activation
##
## disable a52
.ifndef(WITHOUT_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52

CONFIGURE_ARGS+=	--enable-a52 \
			--enable-a52bin
.else
CONFIGURE_ARGS+=	--enable-a52 \
			--disable-a52bin
.endif
## enable freetype2
.if defined(WITH_FREETYPE2)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2

PLIST_SUB+=	DRAWTEXT=""
.else
PLIST_SUB+=	DRAWTEXT="@comment "
.endif
## enable imlib2
.if !defined(WITHOUT_VHOOK) && defined(WITH_IMLIB2)
LIB_DEPENDS+=	Imlib2.2:${PORTSDIR}/graphics/imlib2

PLIST_SUB+=	IMLIB2=""
.else
PLIST_SUB+=	IMLIB2="@comment "
.endif
## disable mmx
.ifdef(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx
.endif
## SDL
.ifdef(WITH_SDL)
USE_SDL=	yes

PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif
## mp3
.ifdef(WITH_MP3)
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame

CONFIGURE_ARGS+=	--enable-mp3lame
.endif
## optimization
.ifdef(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--extra-cflags="-fPIC -I${LOCALBASE}/include \
			-I${X11BASE}/include \
			-ffast-math -fomit-frame-pointer"
.else
CONFIGURE_ARGS+=	--extra-cflags="-fPIC -I${LOCALBASE}/include \
			-I${X11BASE}/include" \
			--disable-opts
.endif

## vhook
.ifndef(WITHOUT_VHOOK)
PLIST_SUB+=	VHOOK=""
.else
CONFIGURE_ARGS+=	-disable-vhook

PLIST_SUB+=	VHOOK="@comment "
.endif
## vorbis
.ifdef(WITH_VORBIS)
LIB_DEPENDS+=		vorbisenc.2:${PORTSDIR}/audio/libvorbis

CONFIGURE_ARGS+=	--enable-vorbis
.endif

pre-everything::
.ifndef(WITH_FREETYPE2)
	@${ECHO_MSG} 'Define WITH_FREETYPE2 to enable drawtext FREETYPE2 codec'
	@${ECHO_MSG}
.endif
.ifndef(WITHOUT_LIBA52)
	@${ECHO_MSG} "You can disable liba52 support by defining WITHOUT_LIBA52"
	@${ECHO_MSG}
.endif
.ifndef(WITHOUT_MMX)
	@${ECHO_MSG} "Define WITHOUT_MMX if your system does not support MMX"
	@${ECHO_MSG}
.endif
.ifndef(WITH_SDL)
	@${ECHO_MSG} 'Define WITH_SDL to enable ffplay SDL version'
	@${ECHO_MSG}
.endif
.ifndef(WITH_MP3)
	@${ECHO_MSG} 'Define WITH_MP3 to enable lame MP3 codec'
	@${ECHO_MSG}
.endif
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} 'You can enable additional compilation optimizations'
	@${ECHO_MSG} 'by defining WITH_OPTIMIZED_CFLAGS'
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
	@${REINPLACE_CMD} -e "s!/etc/ffserver.conf!${PREFIX}/etc/ffserver.conf!g" \
		${WRKSRC}/ffserver.c
.if ${ARCH} == "i386"
# we support "v4l" per default through Steve O'Hara-Smith's bktr(4)
# patch
	@${REINPLACE_CMD} -E -e \
		's|^(v4l).*$$|\1="yes"|' \
		${WRKSRC}/configure
.ifdef(WITH_BKTR_FORMAT)
	@${REINPLACE_CMD} -e \
		"s!VIDEO_FORMAT NTSC!VIDEO_FORMAT ${WITH_BKTR_FORMAT}!" \
		${WRKSRC}/libavformat/grab_bsdbktr.c
.endif
.ifdef(WITH_BKTR_DEV)
	@${REINPLACE_CMD} -e \
		"s!idev = 0!idev = ${WITH_BKTR_DEV}!" \
		${WRKSRC}/libavformat/grab_bsdbktr.c
.endif
.endif # ${ARCH} == i386
# malloc.h was deprecated in favor of stdlib.h
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib\.h|'
.ifndef(WITHOUT_LIBA52)
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/configure
.endif
.ifdef(WITH_SDL)
	@${REINPLACE_CMD} -E \
		-e 's|sdl-config|${SDL_CONFIG}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E \
		-e 's|#include <SDL|#include <SDL11/SDL|'
.endif

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
	@${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${PREFIX}/etc/ffserver.conf.sample
.for file in ${HEADER_FILES}
# fix header references prior to installation
	@${REINPLACE_CMD} -e 's|"common.h"|<ffmpeg/common.h>|; \
		s|"avcodec.h"|<ffmpeg/avcodec.h>|' \
		${WRKSRC}/${file}
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${PREFIX}/include/ffmpeg/${file:T}
.endfor
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/${file:T}
.endfor

.include <bsd.port.post.mk>
