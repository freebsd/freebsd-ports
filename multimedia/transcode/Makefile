# New ports collection makefile for:   transcode
# Date created: 	17 December 2001
# Whom: 		Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	transcode
PORTVERSION=	0.6.10
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.zebra.fh-weingarten.de/~transcode/pre/

MAINTAINER=	hendrik@scholz.net
COMMENT=	A text-console utility for video stream processing

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GETOPT_LONG=yes
USE_XLIB=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CPPFLAGS=	-I${X11BASE}/include -I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"
CONFIGURE_ARGS=	--program-transform-name=""
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes

MAN1=	avifix.1 aviindex.1 avimerge.1 avisplit.1 avisync.1 tccat.1 tcdemux.1 \
	tcprobe.1 tcscan.1 transcode.1 tcextract.1 tcdecode.1 tcmodinfo.1 \
	tcpvmexportd.1 tcxmlcheck.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libMagick.so)
WITH_IMAGEMAGICK=	yes
.endif

.if exists(${LOCALBASE}/bin/nasm)
WITH_NASM=	yes
.endif

.if exists(${LOCALBASE}/lib/libaviplay.so)
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

.if exists(${LOCALBASE}/lib/libfame.so)
WITH_FAME=	yes
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

.if exists(${LOCALBASE}/lib/libogg.so)
WITH_OGG=	yes
.endif

.if exists(${LOCALBASE}/include/mjpegtools/yuv4mpeg.h)
WITH_MJPEG=	yes
.endif

.if exists(${LOCALBASE}/lib/liblzo.so)
WITH_LZO=	yes
.endif

.if exists(${LINUXBASE}/usr/lib/libdivxdecore.so)
WITH_DIVX5=	yes
.endif

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	Magick.6:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
.else
CONFIGURE_ARGS+=	--with-magick-mods=no
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
.endif

.if defined(WITH_NASM)
BUILD_DEPENDS+=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm
ONLY_FOR_ARCHS=	i386
PLIST_SUB+=	WITH_NASM=""
.else
PLIST_SUB+=	WITH_NASM="@comment "
.endif

.if defined(WITH_AVIFILE)
LIB_DEPENDS+=	aviplay:${PORTSDIR}/multimedia/avifile
PLIST_SUB+=	WITH_AVIFILE=""
.else
CONFIGURE_ARGS+=	--with-avifile-mods=no \
			--enable-avifile6=no
PLIST_SUB+=	WITH_AVIFILE="@comment "
WITHOUT_FFMPEG=	YES
.endif

.if defined(WITH_SDL)
LIB_DEPENDS+=	SDL-1.1.5:${PORTSDIR}/devel/sdl12
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

.if defined(WITH_FFMPEG) && !defined(WITHOUT_FFMPEG)
BUILD_DEPENDS+=	${LOCALBASE}/bin/ffmpeg:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	WITH_FFMPEG=""
.else
PLIST_SUB+=	WITH_FFMPEG="@comment "
.endif

.if defined(WITH_LIBDV)
LIB_DEPENDS+=	dv.3:${PORTSDIR}/multimedia/libdv
PLIST_SUB+=	WITH_LIBDV=""
CONFIGURE_ARGS+=	--with-pal-yuv=YV12
.else
CONFIGURE_ARGS+=	--with-dv=no
PLIST_SUB+=	WITH_LIBDV="@comment "
.endif

.if defined(WITH_OPENQUICKTIME)
LIB_DEPENDS+=	openquicktime.0:${PORTSDIR}/multimedia/openquicktime
.else
CONFIGURE_ARGS+=	--with-openqt=no
.endif

.if defined(WITH_FAME)
LIB_DEPENDS+=	fame-0.9:${PORTSDIR}/multimedia/libfame
PLIST_SUB+=	WITH_FAME=""
.else
PLIST_SUB+=	WITH_FAME="@comment "
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.2:${PORTSDIR}/multimedia/xvid
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
CONFIGURE_ARGS+=	--with-lame-libs=${LOCALBASE}/lib
PLIST_SUB+=	WITH_LAME=""
.else
CONFIGURE_ARGS+=	--with-lame=no
PLIST_SUB+=	WITH_LAME="@comment "
.endif

.if defined(WITH_OGG)
LIB_DEPENDS+=	ogg.5:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=	--with-ogg=yes
PLIST_SUB+=	WITH_OGG=""
.else
PLIST_SUB+=	WITH_OGG="@comment "
.endif

.if defined(WITH_MJPEG)
LIB_DEPENDS+=	lavplay-1.6.1:${PORTSDIR}/multimedia/mjpegtools
PLIST_SUB+=	WITH_MJPEG=""
.else
PLIST_SUB+=	WITH_MJPEG="@comment "
.endif

.if defined(WITH_LZO)
LIB_DEPENDS+=	lzo.1:${PORTSDIR}/archivers/lzo
PLIST_SUB+=	WITH_LZO=""
.else
PLIST_SUB+=	WITH_LZO="@comment "
.endif

.if defined(WITH_SUBRIP)
PLIST_SUB+=	WITH_SUBRIP=""
.else
PLIST_SUB+=	WITH_SUBRIP="@comment "
.endif

.if defined(WITH_DIVX5)
BUILD_DEPENDS+=	${LINUXBASE}/usr/lib/libdivxdecore.so:${PORTSDIR}/multimedia/linux-divx4linux
CONFIGURE_ENV+=	CFLAGS="-I${LINUXBASE}/usr/include/divx" CPPFLAGS="-I${LINUXBASE}/usr/include/divx"
.else
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS."
.endif
.if !defined(WITH_IMAGEMAGICK)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable ImageMagick-dependent modules by defining WITH_IMAGEMAGICK."
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
.if !defined(WITH_FFMPEG) || defined(WITHOUT_FFMEG)
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
	@${ECHO_MSG} "You can enable libfame-support by defining WITH_FAME."
.endif
.if !defined(WITH_XVID)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable xvid support by defining WITH_XVID."
	@${ECHO_MSG} "This implies WITH_NASM and turns this into an i386-only port."
	@${ECHO_MSG} "You will probably want to enable this, if you plan to"
	@${ECHO_MSG} "rip DVDs."
.endif
.if !defined(WITH_OGG)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libogg support by defining WITH_OGG."
.endif
.if !defined(WITH_LZO)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable liblzo support by defining WITH_LZO."
.endif
.if !defined(WITH_MJPEG)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable support for the MJPEG toolkit by defining WITH_MJPEG."
.endif
.if !defined(WITH_SUBRIP)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable compilation of subtitleripper by defining WITH_SUBRIP."
.endif
.if !defined(WITH_DIVX5)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable experimental DivX 5 support by defining WITH_DIVX5."
.endif

post-patch:
.if ${OSVERSION} <= 500027
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x ${REINPLACE_CMD} \
		-e 's|<stdint.h>|<inttypes.h>|'
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x ${REINPLACE_CMD} \
		-e 's|-O[236]|${CFLAGS}|'
.endif
	@${REINPLACE_CMD} -E -e 's|(seek)64|\1|' ${WRKSRC}/avilib/avidump.c
	@${REINPLACE_CMD} -E -e 's|<SDL/|<|' ${WRKSRC}/filter/preview/display.h

	@${REINPLACE_CMD} -E -e 's|(-la52)|\1 ${LIBA52_DEP_LIBS}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	@${REINPLACE_CMD} -E -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|-ldl||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|WRKSRC|${WRKSRC}|g' ${WRKSRC}/export/Makefile.in

pre-build:
.if defined(WITH_SUBRIP)
	@cd ${WRKSRC}/contrib/subrip; ${GMAKE} clean all
.endif

post-install:
.if defined(WITH_XVID)
	@${LN} -sf ${LOCALBASE}/lib/libxvidcore.so \
		${PREFIX}/lib/transcode/libxvidcore.so
	@${LN} -sf ${LOCALBASE}/lib/libxvidcore.so.2 \
		${PREFIX}/lib/transcode/libxvidcore.so.2
.endif

.if defined(WITH_SUBRIP)
	@cd ${WRKSRC}/contrib/subrip; \
		${INSTALL_PROGRAM} srttool subtitle2pgm subtitle2vobsub ${PREFIX}/bin
.endif

	@${RM} ${PREFIX}/lib/transcode/*.la

.include <bsd.port.post.mk>
