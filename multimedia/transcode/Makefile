# New ports collection makefile for:   transcode
# Date created: 	17 December 2001
# Whom: 		Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	transcode
DISTVERSION=	1.0.0rc1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://dl.fkb.wormulon.net/transcode/ \
		http://dl.kel.wormulon.net/transcode/ \
		http://rebels.plukwa.net/linux-video/transcode/ \
		http://www.jakemsr.com/transcode/

MAINTAINER=	hendrik@scholz.net
COMMENT=	A text-console utility for video stream processing

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread \
				jpeg.9:${PORTSDIR}/graphics/jpeg \
				mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
BUILD_DEPENDS=	${LOCALBASE}/bin/ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
				iconv:${PORTSDIR}/converters/libiconv

USE_GETOPT_LONG=yes
USE_XLIB=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CPPFLAGS=	-I${X11BASE}/include -I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-ffmpeg_libs-prefix=${LOCALBASE} \
					--with-libdvdread-prefix=${LOCALBASE} \
					--with-libiconv-prefix=${LOCALBASE}
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
WANT_SDL=	yes

MAN1=	avifix.1 aviindex.1 avimerge.1 avisplit.1 avisync.1 tccat.1 tcdemux.1 \
	tcprobe.1 tcscan.1 transcode.1 tcextract.1 tcdecode.1 tcmodinfo.1 \
	tcpvmexportd.1 tcxmlcheck.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libfreetype.so)
WITH_FREETYPE=	yes
.endif

.if exists(${LOCALBASE}/lib/libogg.so)
WITH_OGG=	yes
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so)
WITH_VORBIS=	yes
.endif

.if exists(${LOCALBASE}/lib/libtheora.so)
WITH_THEORA=		yes
.endif

.if exists(${LOCALBASE}/lib/libMagick.so)
WITH_IMAGEMAGICK=	yes
.endif

.if exists(${LOCALBASE}/lib/libaviplay.so)
WITH_AVIFILE=	yes
.endif

.if ${HAVE_SDL:Msdl}!=""
WITH_SDL=	yes
.endif

.if exists(${LOCALBASE}/lib/libxml2.so)
WITH_XML=	yes
.endif

.if exists(${LOCALBASE}/lib/libdv.so)
WITH_LIBDV=	yes
.endif

.if exists(${LOCALBASE}/lib/libquicktime.so)
WITH_QUICKTIME=	yes
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

.if exists(${LOCALBASE}/lib/liblzo.so)
WITH_LZO=	yes
.endif

.if exists(${LINUXBASE}/usr/lib/libdivxdecore.so)
WITH_DIVX5=	yes
.endif

.if exists(${LOCALBASE}/lib/libjpeg-mmx.so)
WITH_JPEGMMX=	yes
.endif

.if exists(${LOCALBASE}/lib/liblavjpeg.so)
WITH_MJPEG=	yes
.endif

.if defined(WITH_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-ft-prefix=${LOCALBASE} --enable-freetype2
PLIST_SUB+=	WITH_FREETYPE=""
.else
CONFIGURE_ARGS+=	--disable-fttest --enable-freetype=no
PLIST_SUB+=	WITH_FREETYPE="@comment "
.endif

.if defined(WITH_OGG)
LIB_DEPENDS+=	ogg.5:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=	--with-ogg-prefix=${LOCALBASE} --enable-ogg
PLIST_SUB+=	WITH_OGG=""
.else
PLIST_SUB+=	WITH_OGG="@comment "
CONFIGURE_ARGS+=	--enable-ogg=no
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-vorbis-prefix=${LOCALBASE} --enable-vorbis
PLIST_SUB+=	WITH_VORBIS=""
.else
PLIST_SUB+=	WITH_VORBIS="@comment "
CONFIGURE_ARGS+=	--enable-vorbis=no
.endif

.if defined(WITH_THEORA)
LIB_DEPENDS+=	theora.1:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=	--with-theora-prefix=${LOCALBASE} --enable-theora
.else
CONFIGURE_ARGS+=	--enable-theora=no
.endif

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	Magick.8:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
CONFIGURE_ARGS+=	--enable-imagemagick --with-imagemagick-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-imagemagick=no
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
.endif

.if defined(WITH_JPEGMMX)
LIB_DEPENDS+=	jpeg-mmx.62:${PORTSDIR}/graphics/jpeg-mmx
CONFIGURE_ARGS+=	--enable-libjpegmmx
PLIST_SUB+=	WITH_JPEGMMX=""
.else
CONFIGURE_ARGS+=	--enable-libjpegmmx=no
PLIST_SUB+=	WITH_JPEGMMX="@comment "
.endif

.if defined(WITH_MJPEG)
LIB_DEPENDS+=	lavjpeg-1.6.3:${PORTSDIR}/multimedia/mjpegtools
CONFIGURE_ARGS+=	--enable-mjpegtools
PLIST_SUB+=	WITH_MJPEG=""
.else
CONFIGURE_ARGS+=	--enable-mjpegtools=no
PLIST_SUB+=	WITH_MJPEG="@comment "
.endif

.if defined(WITH_AVIFILE)
LIB_DEPENDS+=	aviplay:${PORTSDIR}/multimedia/avifile
PLIST_SUB+=	WITH_AVIFILE=""
CONFIGURE_ARGS+=	--with-avifile-prefix=${LOCALBASE} --enable-avifile
.else
CONFIGURE_ARGS+=	--enable-avifile=no
PLIST_SUB+=	WITH_AVIFILE="@comment "
.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
WITH_LIBDV=	yes
CONFIGURE_ARGS+=	--enable-sdl --with-sdl-prefix=${LOCALBASE}
PLIST_SUB+=	WITH_SDL=""
.else
CONFIGURE_ARGS+=	--enable-sdl=no
PLIST_SUB+=	WITH_SDL="@comment "
.endif

.if defined(WITH_XML)
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--enable-libxml2 --with-libxml2-prefix=${LOCALBASE}
PLIST_SUB+=	WITH_XML=""
.else
CONFIGURE_ARGS+=	--enable-libxml2=no
PLIST_SUB+=	WITH_XML="@comment "
.endif

.if defined(WITH_LIBDV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
PLIST_SUB+=	WITH_LIBDV=""
CONFIGURE_ARGS+=	--with-pal-yuv=YV12 --enable-libdv
.else
CONFIGURE_ARGS+=	--enable-libdv=no
PLIST_SUB+=	WITH_LIBDV="@comment "
.endif

.if defined(WITH_QUICKTIME)
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--enable-libquicktime \
					--with-libquicktime-prefix=${LOCALBASE} \
					--with-libquicktime-includes=${LOCALBASE}
PLIST_SUB+=	WITH_QUICKTIME=""
.else
CONFIGURE_ARGS+=	--enable-libquicktime=no
PLIST_SUB+=	WITH_QUICKTIME="@comment "
.endif

.if defined(WITH_FAME)
LIB_DEPENDS+=	fame-0.9:${PORTSDIR}/multimedia/libfame
CONFIGURE_ARGS+=	--with-libfame-prefix=${LOCALBASE} --enable-libfame
PLIST_SUB+=	WITH_FAME=""
.else
PLIST_SUB+=	WITH_FAME="@comment "
CONFIGURE_ARGS+=	--enable-libfame=no
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
RUN_DEPENDS+=	xvid4conf:${PORTSDIR}/multimedia/xvid4conf
PLIST_SUB+=	WITH_XVID=""
.else
PLIST_SUB+=	WITH_XVID="@comment "
.endif

.if defined(WITH_LIBA52_DEFAULT)
WITH_LIBA52=	yes
CONFIGURE_ARGS+=	--enable-a52-default-decoder
.endif

.if defined(WITH_LIBA52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
CONFIGURE_ARGS+=	--enable-a52
PLIST_SUB+=	WITH_LIBA52=""
.else
CONFIGURE_ARGS+=	--with-a52=no
PLIST_SUB+=	WITH_LIBA52="@comment "
.endif

.if defined(WITH_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--with-lame-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

.if defined(WITH_LZO)
LIB_DEPENDS+=	lzo.1:${PORTSDIR}/archivers/lzo
CONFIGURE_ARGS+=	--enable-lzo --with-lzo-prefix=${LOCALBASE} \
					--with-lzo-includes=${LOCALBASE}
PLIST_SUB+=	WITH_LZO=""
.else
CONFIGURE_ARGS+=	--enable-lzo=no
PLIST_SUB+=	WITH_LZO="@comment "
.endif

.if defined(WITH_DIVX5)
BUILD_DEPENDS+=	${LINUXBASE}/usr/lib/libdivxdecore.so:${PORTSDIR}/multimedia/linux-divx4linux
CFLAGS+=	-I${LINUXBASE}/usr/include/divx
CPPFLAGS+=	-I${LINUXBASE}/usr/include/divx
.else
.endif

.if defined(WITH_GTK)
CONFIGURE_ARGS+=	--enable-gtk
PLIST_SUB+=	WITH_GTK=""
.else
CONFIGURE_ARGS+=	--enable-gtk=no
PLIST_SUB+=	WITH_GTK="@comment "
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS."
.endif
.if !defined(WITH_FREETYPE)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable text/subtitler modules by defining WITH_FREETYPE."
.endif
.if !defined(WITH_OGG)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libogg support by defining WITH_OGG."
.endif
.if !defined(WITH_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libvorbis support by defining WITH_VORBIS."
.endif
.if !defined(WITH_THEORA)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libtheora support by defining WITH_THEORA."
.endif
.if !defined(WITH_JPEGMMX)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable JPEG with MMX by defining WITH_JPEGMMX."
.endif
.if !defined(WITH_MJPEG)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable MJPEG portions by defining WITH_JPEGMMX."
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
.if !defined(WITH_XML)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libxml2-dependent modules by defining WITH_XML."
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
.if !defined(WIH_LIBA52_DEFAULT)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use liba52 as default audio encoder by defining WITH_LIBA52_DEFAULT."
	@${ECHO_MSG} "This implies WITH_LIBA52."
	@${ECHO_MSG}
.endif
.if !defined(WITH_AVIFILE)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable avifile-dependent modules by defining WITH_AVIFILE."
.endif #WITH_AVIFILE
.if !defined(WITH_QUICKTIME)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable openquicktime-dependent modules by defining WITH_QUICKTIME."
.endif
.if !defined(WITH_FAME)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libfame-support by defining WITH_FAME."
.endif
.if !defined(WITH_XVID)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable xvid support by defining WITH_XVID."
	@${ECHO_MSG} "You will probably want to enable this, if you plan to"
	@${ECHO_MSG} "rip DVDs."
.endif
.if !defined(WITH_LZO)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable liblzo support by defining WITH_LZO."
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
	@${REINPLACE_CMD} -E -e 's|sdl-config|sdl11-config|g' ${WRKSRC}/configure

	@${REINPLACE_CMD} -E -e 's|(-la52)|\1 ${LIBA52_DEP_LIBS}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	@${REINPLACE_CMD} -E -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|-ldl||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|WRKSRC|${WRKSRC}|g' ${WRKSRC}/export/Makefile.in
	@${REINPLACE_CMD} -E -e 's|<quicktime/|<lqt/|g' \
		${WRKSRC}/configure \
		${WRKSRC}/export/export_mov.c \
		${WRKSRC}/import/decode_mov.c \
		${WRKSRC}/import/import_mov.c \
		${WRKSRC}/import/probe_mov.c
	
post-install:
.if defined(WITH_XVID)
	@${LN} -sf ${LOCALBASE}/lib/libxvidcore.so \
		${PREFIX}/lib/transcode/libxvidcore.so
	@${LN} -sf ${LOCALBASE}/lib/libxvidcore.so.4 \
		${PREFIX}/lib/transcode/libxvidcore.so.4
.endif

	@${RM} ${PREFIX}/lib/transcode/*.la

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${OSVERSION} > 500000 && ${ARCH}=="i386"
PLIST_SUB+=	GCC2=""
.else
PLIST_SUB+=	GCC2="@comment "
.endif

.include <bsd.port.post.mk>
