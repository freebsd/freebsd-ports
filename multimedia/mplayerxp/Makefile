# New ports collection makefile for:	mplayerxp
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#

PORTNAME=	mplayerxp
PORTVERSION=	0.7.2
PORTREVISION=	4
CATEGORIES=	multimedia audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-threaded branch of the well known mplayer media player

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		vcdinfo.2:${PORTSDIR}/multimedia/vcdimager
RUN_DEPENDS=	${LOCALBASE}/share/mplayer/fonts:${PORTSDIR}/multimedia/mplayer-fonts

OPTIONS=	DVDNAV       	"Enable libdvdnav support"   	off \
		DVDPLAY      	"Enable libdvdplay support"    	off \
		CDPARANOIA   	"Enable CDDA support"         	off \
		OCFLAGS     	"Use optimized compiler flags"	off \
		SDL          	"Enable SDL video output"     	off \
		TERMCAP      	"Enable termcap key support"  	off \
		WIN32        	"Enable win32 codec set"      	on

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_XORG=	xinerama xv xxf86dga xxf86vm
USE_ICONV=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
WANT_SDL=	yes
USE_LDCONFIG=	yes

MAN1=	mplayerxp.1

WIN32_CODEC_PREFIX=	${LOCALBASE}/lib/win32

.include <bsd.port.pre.mk>

# add this after <bsd.port.pre.mk> so that we inherit /etc/make.conf
CONFIGURE_ARGS+=	--with-extralibdir=${LOCALBASE}/lib \
		--with-extraincdir=${LOCALBASE}/include \
		--cc=${CC} \
		--prefix=${PREFIX} \
		--confdir=${ETCDIR} \
		--datadir=${LOCALBASE}/share/mplayer \
		--libdir=${PREFIX}/lib \
		--disable-fbdev \
		--disable-lirc \
		--disable-rtc \
		--disable-tv-v4l
CONFIGURE_ENV+=	LANG=C
# insure CC,LD safeness
MAKE_ARGS+=	CC="${CC}" LD="${LD}" INSTALL="${INSTALL}"

CFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-fomit-frame-pointer

##
## Feature activation and Library Dependencies
##

# cdda support
.if defined(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia

CONFIGURE_ARGS+=	--enable-cdparanoia
.else
CONFIGURE_ARGS+=	--disable-cdparanoia
.endif
# dvd support
.if defined(WITH_DVDNAV) || defined(WITH_DVDPLAY)
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread

CONFIGURE_ARGS+=	--enable-libdvdread
.else
CONFIGURE_ARGS+=	--disable-libdvdread
.endif
# xine libdvdnav
.if defined(WITH_DVDNAV)
LIB_DEPENDS+=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav

CONFIGURE_ARGS+=	--enable-libdvdnav
.else
CONFIGURE_ARGS+=	--disable-libdvdnav
.endif
# ogle's libdvdplay
.if defined(WITH_DVDPLAY)
LIB_DEPENDS+=	dvdplay.0:${PORTSDIR}/multimedia/libdvdplay

CONFIGURE_ARGS+=	--enable-libdvdplay
.else
CONFIGURE_ARGS+=	--disable-libdvdplay
.endif
# compilation optimizations
.if defined(WITH_OCFLAGS)
CFLAGS+=	-O3 -ffast-math
.else
MAKE_ARGS+=	OPTFLAGS="${CFLAGS}" SHCFLAGS="${CFLAGS} -PIC"
.endif
# sdl
.if defined(WITH_SDL)
USE_SDL=	image sdl
CONFIGURE_ARGS+=	--enable-sdl --enable-sdl-image
.else
CONFIGURE_ARGS+=	--disable-sdl --disable-sdl-image
.endif
# termcap key support
# mplayerxp does not clean up after itself yet
.if defined(WITH_TERMCAP)
CONFIGURE_ARGS+=	--enable-termcap
.else
CONFIGURE_ARGS+=	--disable-termcap
.endif
# win32 binary dll codecs
.if !defined(WITHOUT_WIN32)
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.endif

post-patch:
# win32 codec location
	@${REINPLACE_CMD} -e \
		's|WIN32_PATH|"${WIN32_CODEC_PREFIX}"|' ${WRKSRC}/loader/win32.c
# FreeBSD's install utility does not support -D flag
	@${FIND} ${WRKSRC} -name "Makefile" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		'/INSTALL/s| -D | |g ; \
		 /install/s| -D | |g'
# PTHREAD_{CFLAGS,LIBS}
	@${REINPLACE_CMD} -e \
		'/pthread/s|_ld_i in .* ;|_ld_i in "${PTHREAD_LIBS}" ;|g ; \
		 s|pkg-config|true|g ; \
		 s|^MAKE=|#MAKE=|g' ${WRKSRC}/codecs/configure
	@${REINPLACE_CMD} -e \
		'/pthread/s|_ld_i in .* ;|_ld_i in "${PTHREAD_LIBS}" ;|g ; \
		 s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g' ${WRKSRC}/mplayerxp/configure
#
	@${REINPLACE_CMD} -e \
		's|-Wl,-rpath |-Wl,-rpath,|g' ${WRKSRC}/codecs/common.mak
	@${REINPLACE_CMD} -e \
		'/install -d/d' ${WRKSRC}/codecs/subdir.mak

post-configure:
	@cd ${WRKSRC}/codecs && ./configure --cc=${CC} \
		--prefix=${PREFIX} \
		--confdir=${ETCDIR} \
		--datadir=${LOCALBASE}/share/mplayer \
		--libdir=${PREFIX}/lib
.if !defined(WITH_OCFLAGS)
	@${FIND} ${WRKSRC} -name "config.h" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		'/CAN_COMPILE_/s|^#define|// #undef|g ; \
		 /_CLOBBERED/s|^#define|// #undef|g'
.endif

pre-install:
# create dirs before installation since the port uses a install
# utility option not available in FreeBSD
.for dir in etc/mplayerxp lib/mplayerxp/codecs lib/mplayerxp/wine
	@${MKDIR} ${PREFIX}/${dir}
.endfor

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/mplayerxp

.include <bsd.port.post.mk>
