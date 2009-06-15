# New ports collection makefile for:	mlt
# Date created:				7 October 2008
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	mlt
PORTVERSION=	0.4.2
CATEGORIES=	multimedia
MASTER_SITES=	SFE

MAINTAINER=	villa.alberto@gmail.com
COMMENT=	A multimedia framework and video playout server for TV broadcasting

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

PORTDOCS=	AUTHORS ChangeLog COPYING \
		NEWS README docs demo

OPTIONS=	AVFORMAT	"Avformat module" on \
		DV	"Quasar DV Codec module" on \
		FREI0R	"Frei0r module" on \
		GTK2	"GTK2 module" on \
		JACKRACK	"JACK Rack module" on \
		KINO	"Kino module" on \
		QIMAGE	"Qimage module" on \
		RESAMPLE	"Secret Rabbit Code module" on \
		SOX	"Sound eXchange module" on \
		VORBIS	"Vorbis module" on

.include <bsd.port.pre.mk>

.ifdef(WITH_AVFORMAT)
LIB_DEPENDS+=	avformat.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-avformat \
			--avformat-swscale
PLIST_SUB+=	AVFORMAT=""
.else
CONFIGURE_ARGS+=	--disable-avformat
PLIST_SUB+=	AVFORMAT="@comment "
.endif

.ifdef(WITH_DV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=	--enable-dv
PLIST_SUB+=	DV=""
.else
CONFIGURE_ARGS+=	--disable-dv
PLIST_SUB+=	DV="@comment "
.endif

.ifdef(WITH_FREI0R)
BUILD_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
CONFIGURE_ARGS+=	--enable-frei0r
PLIST_SUB+=	FREI0R=""
.else
CONFIGURE_ARGS+=	--disable-frei0r
PLIST_SUB+=	FREI0R="@comment "
.endif

.ifdef(WITH_GTK2)
CONFIGURE_ARGS+=	--enable-gtk2
USE_GNOME+=	gdkpixbuf gtk20 pango
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gtk2
PLIST_SUB+=	GTK2="@comment "
.endif

.ifdef(WITH_JACKRACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
CONFIGURE_ARGS+=	--enable-jackrack
PLIST_SUB+=	JACKRACK=""
.else
CONFIGURE_ARGS+=	--disable-jackrack
PLIST_SUB+=	JACKRACK="@comment "
.endif

.ifdef(WITH_KINO)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv \
		quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--enable-kino
PLIST_SUB+=	KINO=""
.else
CONFIGURE+ARGS+=	--disable-kino
PLIST_SUB+=	KINO="@comment "
.endif

.ifdef(WITH_QIMAGE)
CONFIGURE_ARGS+=	--enable-qimage \
			--qimage-includedir="${QT_INCDIR}" \
			--qimage-libdir="${QT_LIBDIR}"
QT_COMPONENTS+=	gui
PLIST_SUB+=	QIMAGE=""
.else
CONFIGURE_ARGS+=	--disable-qimage
PLIST_SUB+=	QIMAGE="@comment "
.endif

.ifdef(WITH_RESAMPLE)
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=	--enable-resample
PLIST_SUB+=	RESAMPLE=""
.else
CONFIGURE_ARGS+=	--disable-resample
PLIST_SUB+=	RESAMPLE="@comment "
.endif

.ifdef(WITH_SOX)
LIB_DEPENDS+=	sox.1:${PORTSDIR}/audio/sox
CONFIGURE_ARGS+=	--enable-sox
PLIST_SUB+=	SOX=""
.else
CONFIGURE_ARGS+=	--disable-sox
PLIST_SUB+=	SOX="@comment "
.endif

.ifdef(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-vorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/swig/*/build
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/src/framework/Makefile \
		${WRKSRC}/src/melt/Makefile \
		${WRKSRC}/src/modules/*/Makefile
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile

post-install:
.ifndef(NOPORTDOCS)
.for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
