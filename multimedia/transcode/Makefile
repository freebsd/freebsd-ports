# New ports collection makefile for:   transcode
# Date created: 	17 December 2001
# Whom: 		Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	transcode
PORTVERSION=	0.6.0.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.theorie.physik.uni-goettingen.de/~ostreich/transcode/pre/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.5$//g}pre5
EXTRACT_SUFX=	.tgz

MAINTAINER=	hendrik@scholz.net

LIB_DEPENDS=	dvdread.2:${PORTSDIR}/graphics/libdvdread \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_XLIB=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lgnugetopt" \
		SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"

MAN1=	transcode.1 tccat.1 avisplit.1 avimerge.1 avifix.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libMagick.so)
WITH_IMAGEMAGICK=	yes
.endif

.if exists(${LOCALBASE}/bin/nasm)
WITH_NASM=	yes
.endif

.if exists(${LOCALBASE}/lib/libaviplay-0.7.so)
WITH_AVIFILE=	yes
.endif

.if exists(${LOCALBASE}/lib/libSDL-1.1.so)
WITH_SDL=	yes
.endif

.if exists(${LOCALBASE}/lib/libxml2.so)
WITH_LIBXML2=	yes
.endif

.if exists(${LOCALBASE}/bin/ffmpeg)
WITH_FFMPEG=	yes
.endif

.if exists(${LOCALBASE}/lib/libdv.so)
WITH_LIBDV=	yes
.endif

.if exists(${LOCALBASE}/lib/libopenquicktime.so)
WITH_OPENQUICKTIME=	yes
.endif

.if exists(${LOCALBASE}/lib/libmpeg2.so)
WITH_LIBMPEG2=	yes
.endif

.if exists(${LOCALBASE}/lib/libfame.so)
WITH_LIBFAME=	yes
.endif

.if exists(${LOCALBASE}/lib/libxvidcore.so)
WITH_XVID=	yes
.endif

.if exists(${LOCALBASE}/lib/liba52.so)
.if exists(${LOCALBASE}/lib/liba52.la)
LIBA52_DEP_LIBS!=	${GREP} dependency_libs ${LOCALBASE}/lib/liba52.la | ${CUT} -d \' -f 2
.else
LIBA52_DEP_LIBS=
.endif
WITH_LIBA52=	yes
.endif

.if exists(${LOCALBASE}/lib/libmp3lame.so)
WITH_LAME=	yes
.endif

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	Magick.5:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
.else
CONFIGURE_ARGS+=	--with-magick-mods=no
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
.endif

.if defined(WITH_NASM)
BUILD_DEPENDS+=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm
ONLY_FOR_ARCHS=	i386
.endif

.if defined(WITH_AVIFILE)
LIB_DEPENDS+=	aviplay-0.7.0:${PORTSDIR}/graphics/avifile
PLIST_SUB+=	WITH_AVIFILE=""
.else
CONFIGURE_ARGS+=	--with-avifile-mods=no \
			--enable-avifile6=no
PLIST_SUB+=	WITH_AVIFILE="@comment "
WITHOUT_FFMPEG=	YES
.endif

.if defined(WITH_SDL)
LIB_DEPENDS+=	SDL-1.1.4:${PORTSDIR}/devel/sdl12
WITH_LIBDV=	yes
PLIST_SUB+=	WITH_SDL=""
.else
PLIST_SUB+=	WITH_SDL="@comment "
.endif

.if defined(WITH_LIBXML2)
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
PLIST_SUB+=	WITH_LIBXML2=""
.else
PLIST_SUB+=	WITH_LIBXML2="@comment "
.endif

.if defined(WITH_FFMPEG)
BUILD_DEPENDS+=	${LOCALBASE}/bin/ffmpeg:${PORTSDIR}/graphics/ffmpeg
PLIST_SUB+=	WITH_FFMPEG=""
.else
PLIST_SUB+=	WITH_FFMPEG="@comment "
.endif

.if defined(WITH_LIBDV)
LIB_DEPENDS+=	dv.2:${PORTSDIR}/graphics/libdv
PLIST_SUB+=	WITH_LIBDV=""
.else
CONFIGURE_ARGS+=	--with-dv=no
PLIST_SUB+=	WITH_LIBDV="@comment "
.endif

.if defined(WITH_OPENQUICKTIME)
LIB_DEPENDS+=	openquicktime.0:${PORTSDIR}/graphics/openquicktime
.else
CONFIGURE_ARGS+=	--with-openqt=no
.endif

.if defined(WITH_LIBMPEG2)
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/graphics/libmpeg2
.endif
.if defined(WITH_FAME)
LIB_DEPENDS+=	fame.10:${PORTSDIR}/graphics/libfame
PLIST_SUB+=	WITH_FAME=""
.else
PLIST_SUB+=	WITH_FAME="@comment "
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.0:${PORTSDIR}/graphics/xvid
PLIST_SUB+=	WITH_XVID=""
WITH_NASM=	YES
.else
PLIST_SUB+=	WITH_XVID="@comment "
.endif

.if defined(WITH_LIBA52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
CONFIGURE_ARGS+=	--enable-liba52=yes
PLIST_SUB+=	WITH_LIBA52=""
.else
CONFIGURE_ARGS+=	--with-a52=no \
			--enable-liba52=no
PLIST_SUB+=	WITH_LIBA52="@comment "
.endif

.if defined(WITH_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
PLIST_SUB+=	WITH_LAME=""
.else
CONFIGURE_ARGS+=	--with-lame=no
PLIST_SUB+=	WITH_LAME="@comment "
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable extra optimizations by defining"
	@${ECHO_MSG} "WITH_OPTIMIZED_CFLAGS."
.endif
.if !defined(WITH_IMAGEMAGICK)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable ImageMagick-dependent modules by defining"
	@${ECHO_MSG} "WITH_IMAGEMAGICK."
.endif
.if !defined(WITH_SDL)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable realtime-previewing by defining WITH_SDL."
	@${ECHO_MSG} "This implies WITH_LIBDV."
.endif
.if !defined(WITH_LIBXML2)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libxml2-dependent modules by defining WITH_LIBXML2."
.endif
.if !defined(WITH_FFMPEG)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable ffmpeg-dependent modules by defining WITH_FFMPEG."
.endif
.if !defined(WITH_LAME)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable lame-dependent modules by defining WITH_LAME."
	@${ECHO_MSG} "You will probably want to enable this, if you plan to"
	@${ECHO_MSG} "rip DVDs or dub videos."
.endif
.if !defined(WITH_LIBDV)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libdv-support by defining WITH_LIBDV."
	@${ECHO_MSG} "You will probably want to enable this, if you plan to"
	@${ECHO_MSG} "transcode DV data from a digital videocamera."
.endif
.if !defined(WITH_LIBA52)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable liba52-support by defining WITH_LIBA52."
	@${ECHO_MSG} "You will probably want to enable this, if you plan to"
	@${ECHO_MSG} "rip DVDs."
.endif
.if !defined(WITH_AVIFILE)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable avifile-dependent modules by defining WITH_AVIFILE."
.endif(WITH_AVIFILE)
.if !defined(WITH_NASM)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable nasm dependent modules by defining WITH_NASM."
	@${ECHO_MSG} "This turns this into an i386-only port."
.endif(WITH_NASM)
.if !defined(WITH_OPENQUICKTIME)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable openquicktime-dependent modules by defining WITH_OPENQUICKTIME."
.endif
.if !defined(WITH_FAME)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libfame-support by defining WITH_LIBFAME."
.endif
.if !defined(WITH_LIBMPEG2)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libmpeg2-dependent modules by defining WITH_LIBMPEG2."
	@${ECHO_MSG} "You will probably want to enable this, if you plan to"
	@${ECHO_MSG} "rip DVDs."
.endif
.if !defined(WITH_XVID)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable xvid support by defining WITH_XVID."
	@${ECHO_MSG} "This implies WITH_NASM and turns this into an i386-only port."
	@${ECHO_MSG} "You will probably want to enable this, if you plan to"
	@${ECHO_MSG} "rip DVDs."
.endif

post-patch:
.if ${OSVERSION} <= 500027
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x ${PERL} -pi \
		-e 's|<stdint.h>|<inttypes.h>|'
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x ${PERL} -pi \
		-e 's|-O[236]|${CFLAGS}|'
.endif
	@${PERL} -pi -e 's|(seek)64|\1|' ${WRKSRC}/avilib/avidump.c
	@${PERL} -pi -e 's|<SDL/|<|' ${WRKSRC}/filter/preview/display.h

	@${PERL} -pi -e 's|(-la52)|\1 ${LIBA52_DEP_LIBS}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|-ldl||g' ${WRKSRC}/configure

post-install:
.if defined(WITH_XVID)
	@${LN} -sf ${LOCALBASE}/lib/libxvidcore.so \
		${PREFIX}/lib/transcode/libxvidcore.so
.endif

# Remove .la-files.

	@${RM} ${PREFIX}/lib/transcode/*.la

.include <bsd.port.post.mk>
