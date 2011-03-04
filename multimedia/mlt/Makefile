# New ports collection makefile for:	mlt
# Date created:				7 October 2008
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	mlt
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	A multimedia framework and video playout server for TV broadcasting

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2=	${WRKSRC}/GPL

USE_GNOME=	libxml2 gnomehack
USE_QT_VER=	4
USE_SDL=	image
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug \
		--enable-gpl
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/mlt

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64 (invokes i386 asm)

PORTDOCS=	AUTHORS ChangeLog NEWS README docs demo

OPTIONS=	AVFORMAT	"Avformat module" on \
		DV	"Quasar DV Codec module" on \
		FREI0R	"Frei0r module" on \
		GTK2	"GTK2 module" on \
		JACKRACK	"JACK Rack module" off \
		KINO	"Kino module" on \
		MMX	"MMX support (might cause problems on x86-64)" off \
		QIMAGE	"Qimage module" on \
		RESAMPLE	"Secret Rabbit Code module" on \
		SOX	"Sound eXchange module" on \
		SSE	"SSE support (requires MMX)" off \
		SSE2	"SSE2 support (requires SSE)" off \
		SWFDEC	"Swfdec module" on \
		VORBIS	"Vorbis module" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_AVFORMAT)
LIB_DEPENDS+=	avformat.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-avformat \
			--avformat-swscale
PLIST_SUB+=	AVFORMAT=""
.else
CONFIGURE_ARGS+=	--disable-avformat
PLIST_SUB+=	AVFORMAT="@comment "
.endif

.ifndef(WITHOUT_DV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=	--enable-dv
PLIST_SUB+=	DV=""
.else
CONFIGURE_ARGS+=	--disable-dv
PLIST_SUB+=	DV="@comment "
.endif

.ifndef(WITHOUT_FREI0R)
BUILD_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
CONFIGURE_ARGS+=	--enable-frei0r
PLIST_SUB+=	FREI0R=""
.else
CONFIGURE_ARGS+=	--disable-frei0r
PLIST_SUB+=	FREI0R="@comment "
.endif

.ifndef(WITHOUT_GTK2)
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
USE_GNOME+=	gdkpixbuf gtk20 pango
CONFIGURE_ARGS+=	--enable-gtk2
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gtk2
PLIST_SUB+=	GTK2="@comment "
.endif

.ifndef(WITHOUT_JACKRACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
CONFIGURE_ARGS+=	--enable-jackrack
PLIST_SUB+=	JACKRACK=""
.else
CONFIGURE_ARGS+=	--disable-jackrack
PLIST_SUB+=	JACKRACK="@comment "
.endif

.ifndef(WITHOUT_KINO)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv \
		quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--enable-kino
PLIST_SUB+=	KINO=""
.else
CONFIGURE_ARGS+=	--disable-kino
PLIST_SUB+=	KINO="@comment "
.endif

.ifdef(WITH_MMX)
CONFIGURE_ARGS+=	--enable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

.ifndef(WITHOUT_QIMAGE)
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
QT_COMPONENTS+=	gui svg xml
CONFIGURE_ARGS+=	--enable-qimage \
			--qimage-includedir="${QT_INCDIR}" \
			--qimage-libdir="${QT_LIBDIR}"
PLIST_SUB+=	QIMAGE=""
.else
CONFIGURE_ARGS+=	--disable-qimage
PLIST_SUB+=	QIMAGE="@comment "
.endif

.ifndef(WITHOUT_RESAMPLE)
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=	--enable-resample
PLIST_SUB+=	RESAMPLE=""
.else
CONFIGURE_ARGS+=	--disable-resample
PLIST_SUB+=	RESAMPLE="@comment "
.endif

.ifndef(WITHOUT_SOX)
LIB_DEPENDS+=	sox.1:${PORTSDIR}/audio/sox
CONFIGURE_ARGS+=	--enable-sox
PLIST_SUB+=	SOX=""
.else
CONFIGURE_ARGS+=	--disable-sox
PLIST_SUB+=	SOX="@comment "
.endif

.ifdef(WITH_SSE)
CONFIGURE_ARGS+=	--enable-sse
.else
CONFIGURE_ARGS+=	--disable-sse
.endif

.ifdef(WITH_SSE2)
CONFIGURE_ARGS+=	--enable-sse2
.else
CONFIGURE_ARGS+=	--disable-sse2
.endif

.ifndef(WITHOUT_SWFDEC)
LIB_DEPENDS+=	swfdec-0.8.0:${PORTSDIR}/graphics/swfdec
CONFIGURE_ARGS+=	--enable-swfdec
PLIST_SUB+=	SWFDEC=""
.else
CONFIGURE_ARGS+=	--disable-swfdec
PLIST_SUB+=	SWFDEC="@comment "
.endif

.ifndef(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-vorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/swig/*/build
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/src/framework/Makefile \
		${WRKSRC}/src/melt/Makefile \
		${WRKSRC}/src/modules/*/Makefile
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile

post-install:
.ifndef(NOPORTDOCS)
.for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
