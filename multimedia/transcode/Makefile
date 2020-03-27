# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$

PORTNAME=	transcode
PORTVERSION=	1.1.7
PORTREVISION=	42
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/france/transcode-tcforge/downloads/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Text-console utility for video stream processing

LICENSE=	GPLv2

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USE_LDCONFIG=	yes
USES=		gmake libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-oss
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS OPTIMIZED_CFLAGS X11 MPEG2 BKTR POSTPROC FREETYPE LAME \
			XVID X264 OGG VORBIS THEORA DVDREAD DV QUICKTIME LZO A52 \
			FAAC LIBXML2 MJPEGTOOLS SDL IMAGEMAGICK JPEG ICONV V4L
OPTIONS_DEFAULT=	LAME DVDREAD JPEG ICONV
BKTR_DESC=		Bktr capture card support
POSTPROC_DESC=		Libpostproc support
DVDREAD_DESC=		Libdvdread support
LZO_DESC=		LZO compression support

X11_USES=			xorg
X11_USE=			xorg=xv,xaw,xpm
X11_CONFIGURE_WITH=		x

MPEG2_LIB_DEPENDS=		libmpeg2.so:multimedia/libmpeg2
MPEG2_CONFIGURE_ENABLE=		libmpeg2 libmpeg2convert

BKTR_CONFIGURE_ENABLE=		bktr

POSTPROC_CONFIGURE_ENABLE=	libpostproc

FREETYPE_LIB_DEPENDS=		libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype2

LAME_LIB_DEPENDS=		libmp3lame.so:audio/lame
LAME_CONFIGURE_ENABLE=		lame
LAME_CONFIGURE_ON=		--with-lame-prefix=${LOCALBASE}

XVID_LIB_DEPENDS=		libxvidcore.so:multimedia/xvid
XVID_CONFIGURE_ENABLE=		xvid
XVID_CONFIGURE_ON=		--with-xvid-prefix=${LOCALBASE}

X264_LIB_DEPENDS=		libx264.so:multimedia/libx264
X264_CONFIGURE_ENABLE=		x264

OGG_LIB_DEPENDS=		libogg.so:audio/libogg
OGG_CONFIGURE_ENABLE=		ogg

VORBIS_LIB_DEPENDS=		libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	vorbis

THEORA_LIB_DEPENDS=		libtheora.so:multimedia/libtheora
THEORA_CONFIGURE_ENABLE=	theora

DVDREAD_LIB_DEPENDS=		libdvdread.so:multimedia/libdvdread
DVDREAD_CONFIGURE_ENABLE=	libdvdread
DVDREAD_CONFIGURE_ON=		--with-libdvdread-prefix=${LOCALBASE}

DV_LIB_DEPENDS=			libdv.so:multimedia/libdv
DV_CONFIGURE_ENABLE=		libdv

QUICKTIME_LIB_DEPENDS=		libquicktime.so:multimedia/libquicktime
QUICKTIME_CONFIGURE_ENABLE=	libquicktime

LZO_LIB_DEPENDS=		liblzo2.so:archivers/lzo2
LZO_CONFIGURE_ENABLE=		lzo
LZO_CONFIGURE_ON=		--with-lzo-prefix=${LOCALBASE} --with-lzo-includes=${LOCALBASE}

A52_LIB_DEPENDS=		liba52.so:audio/liba52
A52_CONFIGURE_ENABLE=		a52
A52_CONFIGURE_ON=		--with-a52-prefix=${LOCALBASE}

FAAC_LIB_DEPENDS=		libfaac.so:audio/faac
FAAC_CONFIGURE_ENABLE=		faac
FAAC_CONFIGURE_ON=		--with-faac-prefix=${LOCALBASE}

LIBXML2_USES=			gnome
LIBXML2_USE=			GNOME=libxml2
LIBXML2_CONFIGURE_ENABLE=	libxml2

MJPEGTOOLS_LIB_DEPENDS=		liblavjpeg.so:multimedia/mjpegtools
MJPEGTOOLS_CONFIGURE_ENABLE=	mjpegtools

SDL_USES=			sdl
SDL_USE=			SDL=sdl
SDL_CONFIGURE_ENABLE=		sdl

IMAGEMAGICK_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick6
IMAGEMAGICK_CONFIGURE_ENABLE=	imagemagick
IMAGEMAGICK_CONFIGURE_ON=	--with-imagemagick-prefix=${LOCALBASE}

JPEG_USES=			jpeg
JPEG_CONFIGURE_ENABLE=		libjpeg
JPEG_CONFIGURE_ON=		--with-libjpeg-prefix=${LOCALBASE}

ICONV_USES=			iconv
ICONV_CONFIGURE_ENABLE=		iconv
ICONV_CONFIGURE_ON=		--with-iconv-prefix=${ICONV_PREFIX}

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_CONFIGURE_ENABLE=		v4l

.include <bsd.port.pre.mk>

LDFLAGS_i386+=	-Wl,-z,notext

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv_open=no \
		ac_cv_lib_iconv_libiconv_open=no
.endif

post-extract:
	@${RM} ${WRKSRC}/import/v4l/videodev*

post-patch:
	@${REINPLACE_CMD} -E -e 's|loff_t|uint64_t|' ${WRKSRC}/avilib/avidump.c
	@${REINPLACE_CMD} -E -e 's|<SDL/|<|' ${WRKSRC}/filter/preview/display.h
	@${REINPLACE_CMD} -e '/^static.*lrint/s|static ||' ${WRKSRC}/filter/filter_modfps.c

	@${REINPLACE_CMD} -E -e 's|(-la52)|\1 ${LIBA52_DEP_LIBS}|g ; \
		s|FFMPEG_VERSION|LIBAVCODEC_IDENT|g ; \
		s|-lMagick|-lMagickCore|g' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

	@${REINPLACE_CMD} -E -e 's|-ldl||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|WRKSRC|${WRKSRC}|g' ${WRKSRC}/export/Makefile.in
	@${REINPLACE_CMD} -E -e 's|<quicktime/|<lqt/|g' \
		${WRKSRC}/configure \
		${WRKSRC}/export/export_mov.c \
		${WRKSRC}/import/decode_mov.c \
		${WRKSRC}/import/import_mov.c \
		${WRKSRC}/import/probe_mov.c

post-patch-LZO-on:
	@${REINPLACE_CMD} -e 's|%%NUV%%|nuv|' ${WRKSRC}/import/Makefile.in

post-patch-LZO-off:
	@${REINPLACE_CMD} -e 's|%%NUV%%||' ${WRKSRC}/import/Makefile.in

post-patch-OPTIMIZED_CFLAGS-off:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x ${REINPLACE_CMD} \
		-e 's|-O[236]|${CFLAGS}|'

post-stage:
	@(cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s lib/transcode -type f -or -type l >> ${TMPPLIST})

.include <bsd.port.post.mk>
