# New ports collection makefile for:   transcode
# Date created: 	17 December 2001
# Whom: 		Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	transcode
PORTVERSION=	1.1.5
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_BERLIOS} \
		http://fromani.exit1.org/
MASTER_SITE_SUBDIR=	tcforge

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	A text-console utility for video stream processing

LIB_DEPENDS=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2 \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg

USE_BZIP2=	yes
FAKEDIR=	${WRKDIR}/fake
PLIST=		${WRKDIR}/plist
USE_GMAKE=	yes
USE_LDCONFIG=	yes
WANT_SDL=	yes
WANT_GNOME=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-isystem /usr/include -isystem ${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ARGS+=	--with-libmpeg2-prefix=${LOCALBASE} \
			--with-libavcodec-prefix=${LOCALBASE} \
			--enable-oss

MAN1=	avifix.1 aviindex.1 avimerge.1 avisplit.1 avisync.1 tccat.1 tcdemux.1 \
	tcprobe.1 tcscan.1 transcode.1 tcextract.1 tcdecode.1 tcmodinfo.1 \
	tcpvmexportd.1 tcxmlcheck.1 transcode_export.1 transcode_filter.1 \
	transcode_import.1 tcexport.1 tcmodchain.1

OPTIONS=	OPTIMIZED_CFLAGS "Build with optimizations" off \
		X11 "Build with X11 support" off \
		MPEG2 "Enable libmpeg2 support" off \
		BKTR "Enable bktr support" off \
		POSTPROC "Enable libpostproc support" off \
		FREETYPE "Enable FreeType2 support" off \
		LAME "Enable lame support" on \
		XVID "Enable Xvid support" off \
		X264 "Enable x264 support" off \
		OGG "Enable ogg support" off \
		VORBIS "Enable vorbis support" off \
		THEORA "Enable theora support" off \
		DVDREAD "Enable libdvdread support" on \
		LIBDV "Enable libdv support" off \
		QUICKTIME "Enable libquicktime support" off \
		LZO "Enable LZO support" off \
		LIBA52 "Enable a52 support (as default decoder)" off \
		FAAC "Enable faac support" off \
		XML "Enable libxml2 support" off \
		MJPEG "Enable mjpegtools support" off \
		SDL "Enable SDL support" off \
		IMAGEMAGICK "Enable ImageMagick support" off \
		JPEG "Enable libjpeg support" on \
		ICONV "Enable libiconv support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
CONFIGURE_ENV+=	LIBAVCODEC_EXTRA_LIBS="-pthread"
.endif

.if !defined(WITHOUT_X11)
USE_XORG=	xv xaw xpm
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if defined(WITH_MPEG2)
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
CONFIGURE_ARGS+=	--with-libmpeg2-prefix=${LOCALBASE} --enable-libmpeg2 --enable-libmpeg2convert
.else
CONFIGURE_ARGS+=	--disable-libmpeg2
.endif

.if defined(WITH_BKTR)
CONFIGURE_ARGS+=	--enable-bktr
.endif

.if !defined(WITHOUT_POSTPROC)
CONFIGURE_ARGS+=	--with-libpostproc-prefix=${LOCALBASE} --enable-libpostproc
.else
CONFIGURE_ARGS+=	--disable-libpostproc
.endif

.if defined(WITH_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-freetype2-prefix=${LOCALBASE} --enable-freetype2
.else
CONFIGURE_ARGS+=	--disable-freetype2
.endif

.if !defined(WITHOUT_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--with-lame-prefix=${LOCALBASE} --enable-lame
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
RUN_DEPENDS+=	xvid4conf:${PORTSDIR}/multimedia/xvid4conf
CONFIGURE_ARGS+=	--with-xvid-prefix=${LOCALBASE} --enable-xvid
.else
CONFIGURE_ARGS+=	--disable-xvid
.endif

.if defined(WITH_X264)
LIB_DEPENDS+=	x264.85:${PORTSDIR}/multimedia/x264
CONFIGURE_ARGS+=	--with-x264-prefix=${LOCALBASE} --enable-x264
.else
CONFIGURE_ARGS+=	--disable-x264
.endif

.if defined(WITH_OGG)
LIB_DEPENDS+=	ogg.7:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=	--with-ogg-prefix=${LOCALBASE} --enable-ogg
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-vorbis-prefix=${LOCALBASE} --enable-vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif

.if defined(WITH_THEORA)
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=	--with-theora-prefix=${LOCALBASE} --enable-theora
.else
CONFIGURE_ARGS+=	--disable-theora
.endif

.if !defined(WITHOUT_DVDREAD)
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
CONFIGURE_ARGS+=	--with-libdvdread-prefix=${LOCALBASE} --enable-libdvdread
.else
CONFIGURE_ARGS+=	--disable-libdvdread
.endif

.if defined(WITH_LIBDV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=	--with-pal-yuv=YV12 --with-libdv-prefix=${LOCALBASE} --enable-libdv
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if defined(WITH_QUICKTIME)
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--with-libquicktime-prefix=${LOCALBASE} --enable-libquicktime
.else
CONFIGURE_ARGS+=	--disable-libquicktime
.endif

.if defined(WITH_LZO)
LIB_DEPENDS+=	lzo2.2:${PORTSDIR}/archivers/lzo2
CONFIGURE_ARGS+=	--with-lzo-prefix=${LOCALBASE} --with-lzo-includes=${LOCALBASE} \
			--enable-lzo
.else
CONFIGURE_ARGS+=	--disable-lzo
.endif

.if defined(WITH_LIBA52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
CONFIGURE_ARGS+=	--with-a52-prefix=${LOCALBASE} --enable-a52
.else
CONFIGURE_ARGS+=	--disable-a52
.endif

.if defined(WITH_FAAC)
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
CONFIGURE_ARGS+=	--with-faac-prefix=${LOCALBASE} --enable-faac
.else
CONFIGURE_ARGS+=	--disable-faac
.endif

.if !defined(WITHOUT_XML) && (defined(WITH_XML) || ${HAVE_GNOME:Mlibxml2}!="")
USE_GNOME+=	libxml2
CONFIGURE_ARGS+=	--with-libxml2-prefix=${LOCALBASE} --enable-libxml2
.else
CONFIGURE_ARGS+=	--disable-libxml2
.endif

.if defined(WITH_MJPEG)
LIB_DEPENDS+=	lavjpeg-1.9.0:${PORTSDIR}/multimedia/mjpegtools
CONFIGURE_ARGS+=	--with-mjpegtools-prefix=${LOCALBASE} --enable-mjpegtools
.else
CONFIGURE_ARGS+=	--disable-mjpegtools
.endif

.if !defined(WITHOUT_SDL) && (defined(WITH_SDL) || ${HAVE_SDL:Msdl}!="")
USE_SDL+=	sdl
CONFIGURE_ARGS+=	--with-sdl-prefix=${LOCALBASE} --enable-sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	MagickWand.3:${PORTSDIR}/graphics/ImageMagick
CONFIGURE_ARGS+=	--with-imagemagick-prefix=${LOCALBASE} --enable-imagemagick
.else
CONFIGURE_ARGS+=	--disable-imagemagick
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-libjpeg-prefix=${LOCALBASE} --enable-libjpeg
.else
CONFIGURE_ARGS+=	--disable-libjpeg
.endif

.if !defined(WITHOUT_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=	--with-iconv-prefix=${LOCALBASE} --enable-iconv
.else
CONFIGURE_ARGS+=	--disable-iconv
.endif

post-patch:
.if defined(WITH_LZO) && !defined(WITHOUT_LZO)
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
		s|-lMagick|-lMagickCore|g' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	@${REINPLACE_CMD} -E -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|-ldl||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure
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
