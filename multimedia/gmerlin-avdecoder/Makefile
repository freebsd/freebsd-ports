# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmerlin-avdecoder
PORTVERSION=	1.2.0
PORTREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	SF/gmerlin/${PORTNAME}/${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	General purpose media decoding library

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/linux/dvb/frontend.h:multimedia/v4l_compat
LIB_DEPENDS=	libgavl.so:multimedia/gavl

OPTIONS_DEFINE=	A52 CDIO DCA DVDREAD FAAD FFMPEG FLAC GMERLIN MAD \
		MJPEGTOOLS MPEG2 MUSEPACK OPENJPEG OPTIMIZED_CFLAGS PNG \
		SAMBA SCHROEDINGER SPEEX THEORA TIFF VDPAU VORBIS DOCS
OPTIONS_DEFAULT=	A52 CDIO DCA DVDREAD FAAD FFMPEG FLAC GMERLIN MAD \
		MJPEGTOOLS MPEG2 MUSEPACK OPENJPEG OPTIMIZED_CFLAGS PNG \
		SAMBA SCHROEDINGER SPEEX THEORA TIFF VDPAU VORBIS
DVDREAD_DESC=	libdvdread support
GMERLIN_DESC=	gmerlin support
SAMBA_DESC=	Samba support using libsmbclient

USES=		gettext libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cpuflags=none --without-doxygen
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/ffmpeg0 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/ffmpeg0 -L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGMERLIN}
LIB_DEPENDS+=	libgmerlin.so:multimedia/gmerlin
PLIST_SUB+=	GMERLIN=""
.else
CONFIGURE_ARGS+=--disable-gmerlin
PLIST_SUB+=	GMERLIN="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec0.so:multimedia/ffmpeg0
.else
CONFIGURE_ARGS+=--disable-libavcodec --disable-libpostproc --disable-libswscale --disable-libavformat
.endif

.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=	libtheora.so:multimedia/libtheora
.else
CONFIGURE_ARGS+=--disable-theoradec
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	libspeex.so:audio/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if ${PORT_OPTIONS:MMJPEGTOOLS}
LIB_DEPENDS+=	liblavjpeg.so:multimedia/mjpegtools
.else
CONFIGURE_ARGS+=--disable-mjpegtools
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis
CONFIGURE_ARGS+=--with-vorbis=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${PORT_OPTIONS:MMPEG2}
LIB_DEPENDS+=	libmpeg2.so:multimedia/libmpeg2
.else
CONFIGURE_ARGS+=--disable-libmpeg2
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	libtiff.so:graphics/tiff
.else
CONFIGURE_ARGS+=--disable-libtiff
.endif

.if ${PORT_OPTIONS:MSAMBA}
LIB_DEPENDS+=	libsmbclient.so:net/samba-libsmbclient
.else
CONFIGURE_ARGS+=--disable-samba
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:graphics/png
.else
CONFIGURE_ARGS+=--disable-libpng
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	libfaad.so:audio/faad
.else
CONFIGURE_ARGS+=--disable-faad2
.endif

.if ${PORT_OPTIONS:MDVDREAD}
LIB_DEPENDS+=	libdvdread.so:multimedia/libdvdread
PLIST_SUB+=	DVDREAD=""
.else
CONFIGURE_ARGS+=--disable-dvdread
PLIST_SUB+=	DVDREAD="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	libFLAC.so:audio/flac
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
LIB_DEPENDS+=	libmpcdec.so:audio/musepack
.else
CONFIGURE_ARGS+=--disable-musepack
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	libmad.so:audio/libmad
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if ${PORT_OPTIONS:MA52}
LIB_DEPENDS+=	liba52.so:audio/liba52
.else
CONFIGURE_ARGS+=--disable-liba52
.endif

.if ${PORT_OPTIONS:MDCA}
LIB_DEPENDS+=	libdca.so:multimedia/libdca
.else
# error in configure
CONFIGURE_ARGS+=--disable-libcda --disable-libdca
.endif

.if ${PORT_OPTIONS:MCDIO}
LIB_DEPENDS+=	libcdio.so:sysutils/libcdio
PLIST_SUB+=	CDIO=""
.else
CONFIGURE_ARGS+=--disable-libcdio
PLIST_SUB+=	CDIO="@comment "
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	libopenjpeg.so:graphics/openjpeg15
.else
CONFIGURE_ARGS+=--disable-openjpeg
.endif

.if ${PORT_OPTIONS:MSCHROEDINGER}
LIB_DEPENDS+=	libschroedinger-1.0.so:multimedia/schroedinger
.else
CONFIGURE_ARGS+=--disable-schroedinger
.endif

.if ${PORT_OPTIONS:MVDPAU}
LIB_DEPENDS+=	libvdpau.so:multimedia/libvdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

# vendor ocflags from configure
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -funroll-all-loops -ffast-math
CXXFLAGS+=	-O3 -funroll-all-loops -ffast-math
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|-O3 -funroll-all-loops -ffast-math||g; \
		 /LIBS/ s|-ldl||g; \
		 s|^LDFLAGS="|&$${LDFLAGS} |' \
		 -e 's|^(.*PKG_CONFIG.*)libavcodec(.*)|\1libavcodec0\2|g' \
		 -e 's|^(.*PKG_CONFIG.*)libavformat(.*)|\1libavformat0\2|g' \
		 -e 's|^(.*PKG_CONFIG.*)libavutil(.*)|\1libavutil0\2|g' \
		 -e 's|^(.*PKG_CONFIG.*)libpostproc(.*)|\1libpostproc0\2|g' \
		 -e 's|^(.*PKG_CONFIG.*)libswscale(.*)|\1libswscale0\2|g' \
		 ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|#if DVDREAD_VERSION < 905|#if DVDREAD_VERSION < 904|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^LIBS = / s|$$| @LIBINTL@ -lz|' ${WRKSRC}/tests/Makefile.in
	@${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|' ${WRKSRC}/lib/in_smb.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
