# New ports collection makefile for:   transcode
# Date created: 	17 December 2001
# Whom: 		Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	transcode
PORTVERSION=	1.0.6
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://transcode.kabewm.com/ \
		http://fromani.exit1.org/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A text-console utility for video stream processing

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2 \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg
BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
FAKEDIR=	${WRKDIR}/fake
PLIST=		${WRKDIR}/plist
USE_GMAKE=	yes
USE_LDCONFIG=	yes
WANT_SDL=	yes
USE_GNOME=	gnometarget
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-isystem /usr/include -isystem ${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ARGS+=	--with-libavcodec-includes=${LOCALBASE}/include/ffmpeg \
			--with-libavcodec-libs=${LOCALBASE}/lib \
			--with-libdvdread-prefix=${LOCALBASE} \
			--with-libiconv-prefix=${LOCALBASE} \
			--enable-oss \
			--enable-gtk=no

MAN1=	avifix.1 aviindex.1 avimerge.1 avisplit.1 avisync.1 tccat.1 tcdemux.1 \
	tcprobe.1 tcscan.1 transcode.1 tcextract.1 tcdecode.1 tcmodinfo.1 \
	tcpvmexportd.1 tcxmlcheck.1

.include <bsd.port.pre.mk>

.if	${OSVERSION} < 700000
CONFIGURE_ENV+=	LIBAVCODEC_EXTRA_LIBS="-pthread"
.endif

.if (defined(WITH_FREETYPE) || exists(${LOCALBASE}/lib/libfreetype.so)) && !defined(WITHOUT_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-ft-prefix=${LOCALBASE} --enable-freetype2
.else
CONFIGURE_ARGS+=	--disable-fttest --enable-freetype=no
.endif

.if (defined(WITH_OGG) || exists(${LOCALBASE}/lib/libogg.so)) && !defined(WITHOUT_OGG)
LIB_DEPENDS+=	ogg.6:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=	--with-ogg-prefix=${LOCALBASE} --enable-ogg
.else
CONFIGURE_ARGS+=	--enable-ogg=no
.endif

.if defined(WITH_BKTR)
CONFIGURE_ARGS+=	--enable-bktr
.endif

.if (defined(WITH_VORBIS) || exists(${LOCALBASE}/lib/libvorbis.so)) && !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-vorbis-prefix=${LOCALBASE} --enable-vorbis
.else
CONFIGURE_ARGS+=	--enable-vorbis=no
.endif

.if (defined(WITH_THEORA) || exists(${LOCALBASE}/lib/libtheora.so)) && !defined(WITHOUT_THEORA)
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=	--with-theora-prefix=${LOCALBASE} --enable-theora
.else
CONFIGURE_ARGS+=	--enable-theora=no
.endif

.if (defined(WITH_IMAGEMAGICK) || exists(${LOCALBASE}/lib/libMagickWand.so)) && !defined(WITHOUT_IMAGEMAGICK)
LIB_DEPENDS+=	MagickWand.2:${PORTSDIR}/graphics/ImageMagick
CONFIGURE_ARGS+=	--enable-imagemagick --with-imagemagick-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-imagemagick=no
.endif

.if (defined(WITH_MJPEG) || exists(${LOCALBASE}/lib/liblavjpeg.so)) && !defined(WITHOUT_MJPEG)
LIB_DEPENDS+=	lavjpeg-1.9.1:${PORTSDIR}/multimedia/mjpegtools
CONFIGURE_ARGS+=	--enable-mjpegtools
.else
CONFIGURE_ARGS+=	--enable-mjpegtools=no
.endif

.if (defined(WITH_AVIFILE) || exists(${LOCALBASE}/lib/libaviplay.so)) && !defined(WITHOUT_AVIFILE) && ${OSVERSION} < 700000
LIB_DEPENDS+=	aviplay:${PORTSDIR}/multimedia/avifile
CONFIGURE_ARGS+=	--with-avifile-prefix=${LOCALBASE} --enable-avifile
.else
CONFIGURE_ARGS+=	--enable-avifile=no
.endif

.if defined(WITH_SDL) || ${HAVE_SDL:Msdl}!=""
USE_SDL+=	sdl
WITH_LIBDV=	yes
CONFIGURE_ARGS+=	--enable-sdl --with-sdl-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-sdl=no
.endif

.if !defined(WITHOUT_XML) || ${HAVE_GNOME:Mlibxml2}!=""
USE_GNOME+=	libxml2
CONFIGURE_ARGS+=	--enable-libxml2 --with-libxml2-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-libxml2=no
.endif

.if (defined(WITH_LIBDV) || exists(${LOCALBASE}/lib/libdv.so)) && !defined(WITHOUT_LIBDV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=	--with-pal-yuv=YV12 --enable-libdv
.else
CONFIGURE_ARGS+=	--enable-libdv=no
.endif

.if (defined(WITH_QUICKTIME) || exists(${LOCALBASE}/lib/libquicktime.so)) && !defined(WITHOUT_QUICKTIME)
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--enable-libquicktime \
					--with-libquicktime-prefix=${LOCALBASE} \
					--with-libquicktime-includes=${LOCALBASE}/include/lqt
.else
CONFIGURE_ARGS+=	--enable-libquicktime=no
.endif

.if defined(WITH_FAME) # Disable.. meh # || (exists(${LOCALBASE}/lib/libfame.so) && !defined(WITHOUT_FAME))
LIB_DEPENDS+=	fame-0.9:${PORTSDIR}/multimedia/libfame
CONFIGURE_ARGS+=	--with-libfame-prefix=${LOCALBASE} --enable-libfame
.endif

.if defined(WITH_XVID) || (exists(${LOCALBASE}/lib/libxvidcore.so) && !defined(WITHOUT_XVID))
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
RUN_DEPENDS+=	xvid4conf:${PORTSDIR}/multimedia/xvid4conf
.endif

.if defined(WITH_LIBA52_DEFAULT) || (exists(${LOCALBASE}/lib/liba52.so) && !defined(WITHOUT_LIBA52))
WITH_LIBA52=	yes
CONFIGURE_ARGS+=	--enable-a52-default-decoder
.endif

.if defined(WITH_LIBA52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
CONFIGURE_ARGS+=	--enable-a52
.else
CONFIGURE_ARGS+=	--with-a52=no
.endif

.if defined(WITH_LAME) || (exists(${LOCALBASE}/lib/libmp3lame.so) && !defined(WITHOUT_LAME))
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--with-lame-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

.if defined(WITH_LZO) || (exists(${LOCALBASE}/lib/liblzo2.so) && !defined(WITHOUT_LZO))
LIB_DEPENDS+=	lzo2:${PORTSDIR}/archivers/lzo2
CONFIGURE_ARGS+=	--enable-lzo --with-lzo-prefix=${LOCALBASE} \
					--with-lzo-includes=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-lzo=no
.endif

.if (defined(WITH_DIVX5) && ${ARCH}=="i386") || (exists(${LINUXBASE}/usr/lib/libdivxdecore.so) && !defined(WITHOUT_DIVX5))
BUILD_DEPENDS+=	${LINUXBASE}/usr/lib/libdivxdecore.so:${PORTSDIR}/multimedia/linux-divx4linux
CFLAGS+=	-I${LINUXBASE}/usr/include/divx
.else
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
.if !defined(WITH_LIBA52_DEFAULT)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use liba52 as default audio encoder by defining WITH_LIBA52_DEFAULT."
	@${ECHO_MSG} "This implies WITH_LIBA52."
.endif
.if !defined(WITH_AVIFILE)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable avifile-dependent modules by defining WITH_AVIFILE."
.endif #WITH_AVIFILE
.if !defined(WITH_QUICKTIME)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable quicktime-dependent modules by defining WITH_QUICKTIME."
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
.if !defined(WITH_DIVX5) && ${ARCH}=="i386"
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable experimental DivX 5 support by defining WITH_DIVX5."
.endif
.if !defined(WITH_BKTR)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable support for bktr(4) devices by defining WITH_BKTR."
.endif

post-patch:
.if defined(WITH_LZO) || (exists(${LOCALBASE}/lib/liblzo2.so) && !defined(WITHOUT_LZO))
	@${REINPLACE_CMD} -e 's|%%NUV%%|nuv|' ${WRKSRC}/import/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|%%NUV%%||' ${WRKSRC}/import/Makefile.in
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x ${REINPLACE_CMD} \
		-e 's|-O[236]|${CFLAGS}|'
.endif
	@${REINPLACE_CMD} -E -e 's|(seek)64|\1|' ${WRKSRC}/avilib/avidump.c
	@${REINPLACE_CMD} -E -e 's|<SDL/|<|' ${WRKSRC}/filter/preview/display.h
	@${REINPLACE_CMD} -e '/^static.*lrint/s|static ||' ${WRKSRC}/filter/filter_modfps.c

	@${REINPLACE_CMD} -E -e 's|(-la52)|\1 ${LIBA52_DEP_LIBS}|g ; \
		s|FFMPEG_VERSION|LIBAVCODEC_IDENT|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|-lMagick|-lMagickCore|g' \
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

pre-install:
	${RM} -rf ${PLIST} ${FAKEDIR}
	${MKDIR} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
	@(cd ${WRKSRC} && ${GMAKE} install prefix=${FAKEDIR})
	${RM} -rf ${FAKEDIR}/man # let bsd.port.mk handle man files
.for dir in bin share/doc lib
	@(cd ${FAKEDIR}/${dir} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|${dir}/|' >> ${PLIST})
	@(cd ${FAKEDIR}/${dir} && ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${dir}/|' >> ${PLIST})
.endfor

.include <bsd.port.post.mk>
