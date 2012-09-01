# $FreeBSD$

PORTNAME=	mlt
PORTVERSION=	0.8.2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Multimedia framework for TV broadcasting

LICENSE=	GPLv2 GPLv3 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/GPL
LICENSE_FILE_GPLv3=	${WRKSRC}/GPLv3
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

# They both install bin/melt.
CONFLICTS_INSTALL=	freeze-[0-9]*

USE_GNOME=	gnomehack libxml2
USE_PKGCONFIG=	build
USE_SDL=	image
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gpl --enable-gpl3 --linsys-with-jpeg
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include # Frei0r detection.
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.ifndef(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-debug
.else
CONFIGURE_ARGS+=	--enable-debug
.endif

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog NEWS README docs
PORTEXAMPLES=	demo

MAN1=		melt.1

OPTIONS_DEFINE=	DV FFMPEG FREI0R GTK2 JACK QT4 QUICKTIME \
		SAMPLERATE SOX SWFDEC VDPAU VORBIS
OPTIONS_DEFAULT=DV FFMPEG FREI0R GTK2 QT4 \
		SAMPLERATE SOX SWFDEC VORBIS

GTK2_DESC=	GTK+ 2 support (images, text rendering...)
QT4_DESC=	QImage support (Kdenlive titles, images...)
SOX_DESC=	SoX audio effects support

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not compile on sparc64 (invokes i386 asm)
.endif

.if ${PORT_OPTIONS:MDV}
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=	--enable-dv
PLIST_SUB+=	DV=""
.else
CONFIGURE_ARGS+=	--disable-dv
PLIST_SUB+=	DV="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG} || ${PORT_OPTIONS:MVDPAU}
LIB_DEPENDS+=	avformat:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-avformat \
			--avformat-swscale
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=	--disable-avformat
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MFREI0R}
BUILD_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
CONFIGURE_ARGS+=	--enable-frei0r
PLIST_SUB+=	FREI0R=""
.else
CONFIGURE_ARGS+=	--disable-frei0r
PLIST_SUB+=	FREI0R="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
USE_GNOME+=	gdkpixbuf2 gtk20 pango
CONFIGURE_ARGS+=	--enable-gtk2
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gtk2
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
CONFIGURE_ARGS+=	--enable-jackrack
PLIST_SUB+=	JACK=""
.else
CONFIGURE_ARGS+=	--disable-jackrack
PLIST_SUB+=	JACK="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
USE_QT4+=	gui svg xml
CONFIGURE_ARGS+=	--enable-qimage \
			--qimage-includedir="${QT_INCDIR}" \
			--qimage-libdir="${QT_LIBDIR}"
PLIST_SUB+=	QT4=""
.else
CONFIGURE_ARGS+=	--disable-qimage
PLIST_SUB+=	QT4="@comment "
.endif

.if ${PORT_OPTIONS:MQUICKTIME}
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv \
		quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--enable-kino
PLIST_SUB+=	KINO=""
.else
CONFIGURE_ARGS+=	--disable-kino
PLIST_SUB+=	KINO="@comment "
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=	--enable-resample
PLIST_SUB+=	SAMPLERATE=""
.else
CONFIGURE_ARGS+=	--disable-resample
PLIST_SUB+=	SAMPLERATE="@comment "
.endif

.if ${PORT_OPTIONS:MSOX}
LIB_DEPENDS+=	sox.1:${PORTSDIR}/audio/sox
CONFIGURE_ARGS+=	--enable-sox
PLIST_SUB+=	SOX=""
.else
CONFIGURE_ARGS+=	--disable-sox
PLIST_SUB+=	SOX="@comment "
.endif

.if ${PORT_OPTIONS:MSWFDEC}
LIB_DEPENDS+=	swfdec-0.8.0:${PORTSDIR}/graphics/swfdec
CONFIGURE_ARGS+=	--enable-swfdec
PLIST_SUB+=	SWFDEC=""
.else
CONFIGURE_ARGS+=	--disable-swfdec
PLIST_SUB+=	SWFDEC="@comment "
.endif

.if ${PORT_OPTIONS:MVDPAU}
USE_XORG+=	x11
CONFIGURE_ARGS+=	--avformat-vdpau
.else
CONFIGURE_ARGS+=	--avformat--no-vdpau
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-vorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/src/modules/avformat/vdpau.c \
		${WRKSRC}/src/modules/frei0r/factory.c \
		${WRKSRC}/src/modules/jackrack/plugin_mgr.c \
		${WRKSRC}/src/modules/linsys/Makefile
	${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},g' \
		${WRKSRC}/src/framework/Makefile \
		${WRKSRC}/src/melt/Makefile \
		${WRKSRC}/src/modules/*/Makefile
	${REINPLACE_CMD} -e 's,$$(libdir)/pkgconfig,${PREFIX}/libdata/pkgconfig,g' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/melt.1 ${MANPREFIX}/man/man1/melt.1
	${RM} -f ${WRKSRC}/docs/melt.1
.if ${PORT_OPTIONS:MDOCS}
. for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${DOCSDIR}
. endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
. for f in ${PORTEXAMPLES}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${EXAMPLESDIR}
. endfor
.endif

.include <bsd.port.mk>
