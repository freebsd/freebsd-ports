# New ports collection makefile for:	mplayerxp
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#

PORTNAME=	mplayerxp
PORTVERSION=	0.1.9
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Multi-threaded branch of the well known mplayer media player

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		mp3lame.0:${PORTSDIR}/audio/lame \
		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/mplayer/fonts:${PORTSDIR}/multimedia/mplayer-fonts

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_XLIB=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
HAS_CONFIGURE=	yes

MAN1=	mplayerxp.1

SDL_CONFIG?=	"${LOCALBASE}/bin/sdl11-config"
WIN32_CODEC_PREFIX=	${LOCALBASE}/lib/win32

# dirs to create before installation
DIRS_TO_CREATE= etc/mplayerxp \
		lib/mplayerxp/codecs \
		lib/mplayerxp/wine

.include <bsd.port.pre.mk>

# add this after <bsd.port.pre.mk> so that we inherit /etc/make.conf
CONFIGURE_ARGS+= --with-extralibdir=${LOCALBASE}/lib \
		--with-extraincdir=${LOCALBASE}/include \
		--with-x11incdir=${X11BASE}/include \
		--with-x11libdir=${X11BASE}/lib \
		--cc=${CC} \
		--prefix=${PREFIX} \
		--confdir=${PREFIX}/etc/${PORTNAME} \
		--datadir=${LOCALBASE}/share/mplayer \
		--disable-fbdev \
		--disable-lirc \
		--disable-rtc \
		--disable-tv-v4l
# insure CC,LD safeness
MAKE_ARGS+=	CC="${CC}" LD="${LD}"

##
## Feature detection
##

# KDE aRts
.if exists(${LOCALBASE}/lib/libartsc.so)
WITH_ARTS=yes
.endif
# xine libdvdnav
.if exists(${LOCALBASE}/lib/libdvdnav.so)
WITH_DVD=yes
WITH_LIBDVDNAV=yes
.endif
# cdparanoia (cdda support)
.if exists(${LOCALBASE}/lib/libcdda_paranoia.so)
WITH_CDPARANOIA=yes
.endif
# ogle's libdvdread (dvd support)
.if exists(${LOCALBASE}/lib/libdvdread.a)
WITH_DVD=yes
.endif
# sdl
.if exists(${LOCALBASE}/lib/libSDL-1.1.a)
WITH_SDL=yes
.endif
# sdl_image
.if exists(${LOCALBASE}/lib/libSDL_image.a)
WITH_SDL_IMAGE=yes
.endif
# xvid
.if exists(${LOCALBASE}/lib/libxvidcore.so)
WITH_XVID=yes
.endif

##
## Feature activation and Library Dependencies
##

# libdvdnav does not currently work
.undef WITH_LIBDVDNAV
WITHOUT_LIBDVDNAV=yes

# compilation optimizations
.ifdef(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif
# 3dnow optimizations
.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
CONFIGURE_ARGS+=	--enable-3dnow --enable-3dnowex
.endif
# sse optimizations
.if !defined(WITHOUT_SSE) && ${OSVERSION} >= 400021
CONFIGURE_ARGS+=	--enable-sse --enable-sse2
.endif
# KDE aRts
.ifdef(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
.endif
# cdda support
.ifdef(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
.else
CONFIGURE_ARGS+=	--disable-cdparanoia
.endif
# dvd support
.ifdef(WITH_DVD)
LIB_DEPENDS+=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

CONFIGURE_ARGS+=	--with-csslibdir=${LOCALBASE}/lib
PLIST_SUB+=	DVD=''
.else
PLIST_SUB+=	DVD='@comment '
.endif
# xine libdvdnav
.if defined(WITH_LIBDVDNAV) && !defined(WITHOUT_LIBDVDNAV)
LIB_DEPENDS+=	dvdnav.1:${PORTSDIR}/multimedia/libdvdnav

CONFIGURE_ARGS+=	--with-libdvdnav=${LOCALBASE}
.endif
# sdl
.ifdef(WITH_SDL)
LIB_DEPENDS+=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

CONFIGURE_ARGS+=	--enable-sdl
CONFIGURE_ENV+=	SDL_CONFIG=${SDL_CONFIG}
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif
# sdl_image
.ifdef(WITH_SDL_IMAGE)
LIB_DEPENDS+=	SDL_image.10:${PORTSDIR}/graphics/sdl_image

CONFIGURE_ARGS+=	--enable-sdl-image
.else
CONFIGURE_ARGS+=	--disable-sdl-image
.endif
# xvid
.ifdef(WITH_XVID)
LIB_DEPENDS+=	xvidcore.2:${PORTSDIR}/multimedia/xvid

CONFIGURE_ARGS+=	--enable-xvid \
			--with-xvidcore=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-xvid
.endif
# termcap key support
# mplayerxp does not clean up after itself yet
.ifdef(WITH_TERMCAP)
CONFIGURE_ARGS+=	--enable-termcap
.else
CONFIGURE_ARGS+=	--disable-termcap
.endif
# win32 binary dll codecs
.if !defined(WITHOUT_WIN32_CODECS)
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.endif

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable additional compilation optimizations'
	@${ECHO_MSG} '		by defining WITH_OPTIMIZED_CFLAGS.'
.endif
.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can disable 3DNow! optimized routines by defining WITHOUT_3DNOW.'
.endif
.if !defined(WITHOUT_SSE) && ${OSVERSION} >= 400021
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can disable SSE optimized routines by defining WITHOUT_SSE.'
.endif
.ifndef(WITH_ARTS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable KDE ARTS support by defining WITH_ARTS.'
.endif
.ifndef(WITH_CDPARANOIA)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable cdda support by defining WITH_CDPARANOIA.'
.endif
.ifndef(WITH_DVD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable DVD support by defining WITH_DVD.'
.endif
.ifndef(WITH_LIBDVDNAV)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable LIBDVDNAV support by defining WITH_LIBDVDNAV.'
.endif
.ifndef(WITH_SDL)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable SDL support by defining WITH_SDL.'
.endif
.ifndef(WITH_SDL_IMAGE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable SDL_image support by defining WITH_SDL_IMAGE.'
.endif
.ifndef(WITH_TERMCAP)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable termcap key database support by defining WITH_TERMCAP.'
.endif
.ifndef(WITH_XVID)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable XVID support by defining WITH_XVID.'
.endif
.ifndef(WITHOUT_WIN32_CODECS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can disable support for Win32 codecs by defining WITHOUT_WIN32_CODECS'
.endif
	@${ECHO_MSG} '===>'

post-patch:
# fix detection of libdvdnav
.ifdef(WITH_LIBDVDNAV)
	@${REINPLACE_CMD} -E -e  \
		's|(-I\$$_dvdnavdir)|\1/include/dvdnav|; \
		s|(-L\$$_dvdnavdir)/.libs|\1/lib|; \
		s|(-ldvdnav)|\1 ${PTHREAD_LIBS}|' \
		${WRKSRC}/mplayerxp/configure
.endif
# linux/ioctl.h -> sys/ioctl.h
.for file in mplayerxp/libdha/kernelhelper/dhahelper.h \
	mplayerxp/vidix/drivers/radeon_vid.c
	@${REINPLACE_CMD} -e 's|linux/ioctl.h|sys/ioctl.h|' \
		${WRKSRC}/${file}
.endfor
# correct SDL prefix installation
# -lpthread -> ${PHREAD_LIBS}
# win32 codec location
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -x -n 10 ${REINPLACE_CMD} -E -e \
		's|SDL/|SDL11/|; \
		s|-lpthread|${PTHREAD_LIBS}|; \
		s|/usr/local/lib/win32|${WIN32_CODEC_PREFIX}|'
# win32 codec location
	@${REINPLACE_CMD} -E -e \
		's|WIN32_PATH|"${WIN32_CODEC_PREFIX}"|' \
		${WRKSRC}/loader/win32.c
# FreeBSD's install utility does not support -D flag
	@${FIND} ${WRKSRC} -name Makefile | \
		${XARGS} -x -n 10 ${REINPLACE_CMD} -E -e \
		's,(\$$\(INSTALL\)|install)(.*)-D,${INSTALL}\2,'
# PTHREAD_{CFLAGS,LIBS}
# location of xine libdvdnav header files
	@${REINPLACE_CMD} -E -e  \
		's|-pthread|${PTHREAD_LIBS}|; \
		s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|' \
		${WRKSRC}/mplayerxp/configure
# FreeBSD does not have -ldl
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/mplayerxp/vidix/Makefile
# ffmpeg currently is not compatible with mplayerxp
.for file in ad_ffmp3.c vd_ffmpeg.c
	@${REINPLACE_CMD} -e 's|libavcodec.so|libNOTavcodec.so|' \
		${WRKSRC}/mplayerxp/libmpcodecs/${file}
.endfor
# native libdivxdecore is not compatible with mplayerxp
.for file in vd_divx4.c vd_xvid.c
	@${REINPLACE_CMD} -e 's|libdivxdecore|libNOTdivxdecore|' \
		${WRKSRC}/mplayerxp/libmpcodecs/${file}
.endfor

pre-install:
# create dirs before installation since the port uses a install
# utility option not available in FreeBSD
.for dir in ${DIRS_TO_CREATE}
	@${MKDIR} ${PREFIX}/${dir}
.endfor

.include <bsd.port.post.mk>
