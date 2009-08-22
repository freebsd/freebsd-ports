# New ports collection makefile for:	gmerlin-avdecoder
# Date created:		07 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmerlin-avdecoder
PORTVERSION=	1.0.1
CATEGORIES=	multimedia
MASTER_SITES=	SF/gmerlin/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	General purpose media decoding library

LIB_DEPENDS=	gavl.1:${PORTSDIR}/multimedia/gavl

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--without-cpuflags --without-doxygen
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	README

OPTIONS=	GMERLIN	"Enable gmerlin support" on \
		FFMPEG	"Enable ffmpeg support" on \
		THEORA	"Enable theora support" on \
		SPEEX	"Enable speex support" on \
		MJPEGTOOLS "Enable mjpegtools support" on \
		VORBIS	"Enable vorbis support" on \
		MPEG2	"Enable MPEG2 support" on \
		TIFF	"Enable TIFF support" on \
		SAMBA	"Enable samba support" on \
		PNG	"Enable libpng support" on \
		FAAD	"Enabled FAAD2 support" on \
		DVDREAD "Enable libdvdread support" on \
		FLAC	"Enable FLAC support" on \
		MUSEPACK "Enable musepack (mpc) support" on \
		MAD	"Enable mp3 support" on \
		A52	"Enable A52 support" on \
		DCA	"Enable DTS Coherent Acoustics decoder" on \
		LIBCDIO	"Enable libcdio support" on \
		OPENJPEG "Enable JPEG2000 support" on \
		SCHROEDINGER "Enable dirac support" on \
		OPTIMIZED_CFLAGS "Additional optimizations" on

.include <bsd.port.pre.mk>

# Hack for 6.x to properly detect ffmpeg
.if ${OSVERSION} < 700000
CONFIGURE_ENV+=	AVCODEC_LIBS="`pkg-config --libs libavcodec` ${PTHREAD_LIBS}"
.endif

.if !defined(WITHOUT_GMERLIN)
LIB_DEPENDS+=	gmerlin.0:${PORTSDIR}/multimedia/gmerlin
PLIST_SUB+=	GMERLIN=""
.else
CONFIGURE_ARGS+=--disable-gmerlin
PLIST_SUB+=	GMERLIN="@comment "
.endif

.if !defined(WITHOUT_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=--disable-libavcodec --disable-libpostproc --disable-libswscale --disable-libavformat
.endif

.if !defined(WITHOUT_THEORA)
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
.else
CONFIGURE_ARGS+=--disable-theora
.endif

.if !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if !defined(WITHOUT_MJPEGTOOLS)
LIB_DEPENDS+=	lavjpeg-1.9.1:${PORTSDIR}/multimedia/mjpegtools
.else
CONFIGURE_ARGS+=--disable-mjpegtools
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-vorbis=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if !defined(WITHOUT_MPEG2)
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
.else
CONFIGURE_ARGS+=--disable-libmpeg2
.endif

.if !defined(WITHOUT_TIFF)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.else
CONFIGURE_ARGS+=--disable-libtiff
.endif

.if !defined(WITHOUT_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
.else
CONFIGURE_ARGS+=--disable-samba
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=--disable-libpng
.endif

.if !defined(WITHOUT_FAAD)
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=--disable-faad2
.endif

.if !defined(WITHOUT_DVDREAD)
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
PLIST_SUB+=	DVDREAD=""
.else
CONFIGURE_ARGS+=--disable-dvdread
PLIST_SUB+=	DVDREAD="@comment "
.endif

.if !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if !defined(WITHOUT_MUSEPACK)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
.else
CONFIGURE_ARGS+=--disable-musepack
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if !defined(WITHOUT_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
.else
CONFIGURE_ARGS+=--disable-liba52
.endif

.if !defined(WITHOUT_DCA)
LIB_DEPENDS+=	dca.0:${PORTSDIR}/multimedia/libdca
.else
# error in configure
CONFIGURE_ARGS+=--disable-libcda --disable-libdca
.endif

.if !defined(WITHOUT_LIBCDIO)
LIB_DEPENDS+=	cdio.8:${PORTSDIR}/sysutils/libcdio
PLIST_SUB+=	LIBCDIO=""
.else
CONFIGURE_ARGS+=--disable-libcdio
PLIST_SUB+=	LIBCDIO="@comment "
.endif

.if !defined(WITHOUT_OPENJPEG)
LIB_DEPENDS+=	openjpeg.2:${PORTSDIR}/graphics/openjpeg
.else
CONFIGURE_ARGS+=--disable-openjpeg
.endif

.if !defined(WITHOUT_SCHROEDINGER)
LIB_DEPENDS+=	schroedinger-1.0.2:${PORTSDIR}/multimedia/schroedinger
.else
CONFIGURE_ARGS+=--disable-schroedinger
.endif

# vendor ocflags from configure
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -funroll-all-loops -ffast-math
CXXFLAGS+=	-O3 -funroll-all-loops -ffast-math
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -funroll-all-loops -ffast-math||g; \
		/LIBS/ s|-ldl||g; s|^LDFLAGS="|&$${LDFLAGS} |' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#if DVDREAD_VERSION < 905|#if DVDREAD_VERSION < 904|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^LIBS = / s|$$| @LIBINTL@ -lz|' \
		${WRKSRC}/tests/Makefile.in
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/lib/in_smb.c

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
