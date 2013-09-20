# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$

PORTNAME=	transcode
PORTVERSION=	1.1.7
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	http://cdn.bitbucket.org/france/transcode-tcforge/downloads/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Text-console utility for video stream processing

LICENSE=	GPLv2

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

USE_BZIP2=	yes
FAKEDIR=	${WRKDIR}/fake
PLIST=		${WRKDIR}/plist
USE_LDCONFIG=	yes
USES=		gmake pkgconfig
WANT_SDL=	yes
WANT_GNOME=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-isystem ${LOCALBASE}/include
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-oss

MAN1=	avifix.1 aviindex.1 avimerge.1 avisplit.1 avisync.1 tccat.1 tcdemux.1 \
	tcprobe.1 tcscan.1 transcode.1 tcextract.1 tcdecode.1 tcmodinfo.1 \
	tcpvmexportd.1 tcxmlcheck.1 transcode_export.1 transcode_filter.1 \
	transcode_import.1 tcexport.1 tcmodchain.1

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=	OPTIMIZED_CFLAGS X11 MPEG2 BKTR POSTPROC FREETYPE LAME XVID \
		X264 OGG VORBIS THEORA DVDREAD DV QUICKTIME LZO LIBA52 \
		FAAC XML MJPEGTOOLS SDL IMAGEMAGICK JPEG ICONV V4L
OPTIONS_DEFAULT=	LAME DVDREAD JPEG ICONV
BKTR_DESC=	Bktr capture card support
POSTPROC_DESC=	Libpostproc support
DVDREAD_DESC=	Libdvdread support
LZO_DESC=	LZO compression support
LIBA52_DESC=	a52 support (as default decoder)
XML_DESC=	Libxml2 XML support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	xv xaw xpm
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if ${PORT_OPTIONS:MMPEG2}
LIB_DEPENDS+=	mpeg2:${PORTSDIR}/multimedia/libmpeg2
CONFIGURE_ARGS+=	--enable-libmpeg2 --enable-libmpeg2convert
.else
CONFIGURE_ARGS+=	--disable-libmpeg2
.endif

.if ${PORT_OPTIONS:MBKTR}
CONFIGURE_ARGS+=	--enable-bktr
.endif

.if ${PORT_OPTIONS:MPOSTPROC}
CONFIGURE_ARGS+=	--enable-libpostproc
.else
CONFIGURE_ARGS+=	--disable-libpostproc
.endif

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--enable-freetype2
.else
CONFIGURE_ARGS+=	--disable-freetype2
.endif

.if ${PORT_OPTIONS:MLAME}
LIB_DEPENDS+=	mp3lame:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--with-lame-prefix=${LOCALBASE} --enable-lame
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

.if ${PORT_OPTIONS:MXVID}
LIB_DEPENDS+=	xvidcore:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--with-xvid-prefix=${LOCALBASE} --enable-xvid
.else
CONFIGURE_ARGS+=	--disable-xvid
.endif

.if ${PORT_OPTIONS:MX264}
LIB_DEPENDS+=	x264:${PORTSDIR}/multimedia/x264
CONFIGURE_ARGS+=	--enable-x264
.else
CONFIGURE_ARGS+=	--disable-x264
.endif

.if ${PORT_OPTIONS:MOGG}
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=	--enable-ogg
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif

.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=	theora:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=	--enable-theora
.else
CONFIGURE_ARGS+=	--disable-theora
.endif

.if ${PORT_OPTIONS:MDVDREAD}
LIB_DEPENDS+=	dvdread:${PORTSDIR}/multimedia/libdvdread
CONFIGURE_ARGS+=	--with-libdvdread-prefix=${LOCALBASE} --enable-libdvdread
.else
CONFIGURE_ARGS+=	--disable-libdvdread
.endif

.if ${PORT_OPTIONS:MDV}
LIB_DEPENDS+=	dv:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=	--enable-libdv
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if ${PORT_OPTIONS:MQUICKTIME}
LIB_DEPENDS+=	quicktime:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--enable-libquicktime
.else
CONFIGURE_ARGS+=	--disable-libquicktime
.endif

.if ${PORT_OPTIONS:MLZO}
LIB_DEPENDS+=	lzo2:${PORTSDIR}/archivers/lzo2
CONFIGURE_ARGS+=	--with-lzo-prefix=${LOCALBASE} --with-lzo-includes=${LOCALBASE} \
			--enable-lzo
.else
CONFIGURE_ARGS+=	--disable-lzo
.endif

.if ${PORT_OPTIONS:MLIBA52}
LIB_DEPENDS+=	a52:${PORTSDIR}/audio/liba52
CONFIGURE_ARGS+=	--with-a52-prefix=${LOCALBASE} --enable-a52
.else
CONFIGURE_ARGS+=	--disable-a52
.endif

.if ${PORT_OPTIONS:MFAAC}
LIB_DEPENDS+=	faac:${PORTSDIR}/audio/faac
CONFIGURE_ARGS+=	--with-faac-prefix=${LOCALBASE} --enable-faac
.else
CONFIGURE_ARGS+=	--disable-faac
.endif

.if ${PORT_OPTIONS:MXML}
USE_GNOME+=	libxml2
CONFIGURE_ARGS+=	--enable-libxml2
.else
CONFIGURE_ARGS+=	--disable-libxml2
.endif

.if ${PORT_OPTIONS:MMJPEGTOOLS}
LIB_DEPENDS+=	lavjpeg-2.0:${PORTSDIR}/multimedia/mjpegtools
CONFIGURE_ARGS+=	--enable-mjpegtools
.else
CONFIGURE_ARGS+=	--disable-mjpegtools
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl
CONFIGURE_ARGS+=	--enable-sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
LIB_DEPENDS+=	MagickWand:${PORTSDIR}/graphics/ImageMagick
CONFIGURE_ARGS+=	--with-imagemagick-prefix=${LOCALBASE} --enable-imagemagick
.else
CONFIGURE_ARGS+=	--disable-imagemagick
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-libjpeg-prefix=${LOCALBASE} --enable-libjpeg
.else
CONFIGURE_ARGS+=	--disable-libjpeg
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
CONFIGURE_ARGS+=	--enable-iconv ${ICONV_CONFIGURE_ARG}
.else
CONFIGURE_ARGS+=	--disable-iconv
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
CONFIGURE_ARGS+=	--enable-v4l
.else
CONFIGURE_ARGS+=	--disable-v4l
.endif

post-extract:
	@${RM} ${WRKSRC}/import/v4l/videodev*

post-patch:
.if ${PORT_OPTIONS:MLZO}
	@${REINPLACE_CMD} -e 's|%%NUV%%|nuv|' ${WRKSRC}/import/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|%%NUV%%||' ${WRKSRC}/import/Makefile.in
.endif
.if !${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x ${REINPLACE_CMD} \
		-e 's|-O[236]|${CFLAGS}|'
.endif
	@${REINPLACE_CMD} -E -e 's|loff_t|uint64_t|' ${WRKSRC}/avilib/avidump.c
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
	@(cd ${WRKSRC} && ${GMAKE} install prefix=${FAKEDIR} mandir=${FAKEDIR}/man)
	${RM} -rf ${FAKEDIR}/man # let bsd.port.mk handle man files
.for dir in bin share/doc lib
	@(cd ${FAKEDIR}/${dir} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|${dir}/|' >> ${PLIST})
	@(cd ${FAKEDIR}/${dir} && ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${dir}/|' >> ${PLIST})
.endfor

.include <bsd.port.post.mk>
