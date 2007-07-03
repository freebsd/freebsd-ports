# New ports collection makefile for:	mplayerxp
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#

PORTNAME=	mplayerxp
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-threaded branch of the well known mplayer media player

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		vcdinfo.2:${PORTSDIR}/multimedia/vcdimager
RUN_DEPENDS=	${LOCALBASE}/share/mplayer/fonts:${PORTSDIR}/multimedia/mplayer-fonts

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
#USE_GNOME=	gtk12
USE_GCC=	3.4+
USE_ICONV=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
WANT_SDL=	yes
USE_LDCONFIG=	yes

MAN1=	mplayerxp.1

WIN32_CODEC_PREFIX=	${LOCALBASE}/lib/win32

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

# add this after <bsd.port.pre.mk> so that we inherit /etc/make.conf
CONFIGURE_ARGS+=	--with-extralibdir=${LOCALBASE}/lib \
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
		--disable-vm \
		--disable-tv-v4l
CONFIGURE_ENV+=	LANG=C
# insure CC,LD safeness
MAKE_ARGS+=	CC="${CC}" LD="${LD}"

CFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-fomit-frame-pointer

##
## Feature detection
##

# xine libdvdnav
.if exists(${LOCALBASE}/lib/libdvdnav.so)
WITH_DVD=yes
WITH_LIBDVDNAV=yes
.endif
.if exists(${LOCALBASE}/lib/libdvdplay.a)
# ogle's libdvdplay
WITH_DVD=yes
WITH_DVDPLAY=yes
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
.if ${HAVE_SDL:Msdl}!=""
WITH_SDL=yes
.endif
# sdl_image
.if ${HAVE_SDL:Mimage}!=""
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
.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif
# cdda support
.if defined(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
.else
CONFIGURE_ARGS+=	--disable-cdparanoia
.endif
# dvd support
.if defined(WITH_DVD)
LIB_DEPENDS+=	dvdread.5:${PORTSDIR}/multimedia/libdvdread

CONFIGURE_ARGS+=	--with-csslibdir=${LOCALBASE}/lib
PLIST_SUB+=	DVD=''
.else
PLIST_SUB+=	DVD='@comment '
.endif
# xine libdvdnav
.if defined(WITH_LIBDVDNAV) && !defined(WITHOUT_LIBDVDNAV)
LIB_DEPENDS+=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav

CONFIGURE_ARGS+=	--with-libdvdnav=${LOCALBASE}
.endif
# ogle's libdvdplay
.if defined(WITH_LIBDVDPLAY) && !defined(WITHOUT_LIBDVDPLAY)
LIB_DEPENDS+=	dvdplay.0:${PORTSDIR}/multimedia/libdvdplay

CONFIGURE_ARGS+=	--with-libdvdplay=${LOCALBASE}
.endif
# sdl
.if defined(WITH_SDL)
USE_SDL=	sdl
CONFIGURE_ARGS+=	--enable-sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif
# sdl_image
.if defined(WITH_SDL_IMAGE)
USE_SDL+=	image
CONFIGURE_ARGS+=	--enable-sdl-image
.else
CONFIGURE_ARGS+=	--disable-sdl-image
.endif
# xvid
.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid

CONFIGURE_ARGS+=	--enable-xvid \
			--with-xvidcore=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-xvid
.endif
# termcap key support
# mplayerxp does not clean up after itself yet
.if defined(WITH_TERMCAP)
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
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable additional compilation optimizations'
	@${ECHO_MSG} '		by defining WITH_OPTIMIZED_CFLAGS.'
.endif
.if !defined(WITH_CDPARANOIA)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable cdda support by defining WITH_CDPARANOIA.'
.endif
.if !defined(WITH_DVD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable DVD support by defining WITH_DVD.'
.endif
.if !defined(WITH_LIBDVDNAV)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable LIBDVDNAV support by defining WITH_LIBDVDNAV.'
.endif
.if !defined(WITH_LIBDVDNAV)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable LIBDVDPLAY support by defining WITH_LIBDVDPLAY.'
.endif
.if !defined(WITH_SDL)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable SDL support by defining WITH_SDL.'
.endif
.if !defined(WITH_SDL_IMAGE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable SDL_image support by defining WITH_SDL_IMAGE.'
.endif
.if !defined(WITH_TERMCAP)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable termcap key database support by defining WITH_TERMCAP.'
.endif
.if !defined(WITH_XVID)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable XVID support by defining WITH_XVID.'
.endif
.if !defined(WITHOUT_WIN32_CODECS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can disable support for Win32 codecs by defining WITHOUT_WIN32_CODECS'
.endif
	@${ECHO_MSG} '===>'

post-patch:
# win32 codec location
	@${REINPLACE_CMD} -E -e \
		's|WIN32_PATH|"${WIN32_CODEC_PREFIX}"|' \
		${WRKSRC}/loader/win32.c
# FreeBSD's install utility does not support -D flag
	@${FIND} ${WRKSRC} -name Makefile | \
		${XARGS} -x -n 10 ${REINPLACE_CMD} -E -e \
		's,(\$$\(INSTALL\)|install)(.*)-D,${INSTALL}\2,'
# PTHREAD_{CFLAGS,LIBS}
# stdint.h -> inttypes.h
	@${REINPLACE_CMD} -E -e  \
		's|-lpthread|${PTHREAD_LIBS}|; \
		s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|; \
		s|<stdint\.h>|<inttypes.h>|' \
		${WRKSRC}/mplayerxp/configure
# ffmpeg currently is not compatible with mplayerxp
#.for file in ad_ffmp3.c vd_ffmpeg.c
#	@${REINPLACE_CMD} -e 's|libavcodec.so|libNOTavcodec.so|' \
#		${WRKSRC}/mplayerxp/libmpcodecs/${file}
#.endfor
# native libdivxdecore is not compatible with mplayerxp
.for file in vd_divx4.c vd_xvid.c
	@${REINPLACE_CMD} -e 's|libdivxdecore|libNOTdivxdecore|' \
		${WRKSRC}/mplayerxp/libmpcodecs/${file}
.endfor

pre-install:
# create dirs before installation since the port uses a install
# utility option not available in FreeBSD
.for dir in etc/mplayerxp lib/mplayerxp/codecs lib/mplayerxp/wine
	@${MKDIR} ${PREFIX}/${dir}
.endfor

.include <bsd.port.post.mk>
