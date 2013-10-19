# $FreeBSD$

PORTNAME=	mlt
PORTVERSION=	0.9.0
PORTREVISION?=	1
CATEGORIES?=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER?=	avilla@FreeBSD.org
COMMENT?=	Multimedia framework for TV broadcasting

LICENSE?=	GPLv2 GPLv3 LGPL21
LICENSE_COMB?=	multi

SLAVE_PORT?=	no

.if ${SLAVE_PORT} == "no"

# They both install bin/melt.
CONFLICTS_INSTALL=	freeze-[0-9]*

USE_GNOME=	libxml2
USE_SDL=	image
USES=		gmake iconv pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gpl --enable-gpl3
USE_LDCONFIG=	yes

.ifndef(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-debug
.else
CONFIGURE_ARGS+=--enable-debug
.endif

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog NEWS README docs
PORTEXAMPLES=	demo

MAN1=		melt.1

OPTIONS_DEFINE=	DOCS DV EXAMPLES FFMPEG FREI0R GTK2 JACK KDE4 QT4 QUICKTIME \
		SAMPLERATE SOX SWFDEC VDPAU VORBIS
OPTIONS_DEFAULT=DV FFMPEG FREI0R GTK2 QT4 \
		SAMPLERATE SOX SWFDEC VORBIS

GTK2_DESC=	Images and text rendering via GTK+ 2
KDE4_DESC=	QImage extra formats support
QT4_DESC=	Kdenlive titles and images support via QImage
SOX_DESC=	SoX audio effects support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not compile on sparc64 (invokes i386 asm)
.endif

.if ${PORT_OPTIONS:MDV}
LIB_DEPENDS+=	dv:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=--enable-dv
PLIST_SUB+=	DV=""
.else
CONFIGURE_ARGS+=--disable-dv
PLIST_SUB+=	DV="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG} || ${PORT_OPTIONS:MVDPAU}
FFMPEG_SUFX=	1
LIB_DEPENDS+=	avformat${FFMPEG_SUFX}:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFX}
CONFIGURE_ARGS+=--enable-avformat --avformat-swscale \
		--avformat-suffix="${FFMPEG_SUFX}"
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=--disable-avformat
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MFREI0R}
BUILD_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
CONFIGURE_ARGS+=--enable-frei0r
PLIST_SUB+=	FREI0R=""
.else
CONFIGURE_ARGS+=--disable-frei0r
PLIST_SUB+=	FREI0R="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
LIB_DEPENDS+=	exif:${PORTSDIR}/graphics/libexif
USE_GNOME+=	gdkpixbuf2 gtk20 pango
CONFIGURE_ARGS+=--enable-gtk2
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=--disable-gtk2
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
CONFIGURE_ARGS+=--enable-jackrack
PLIST_SUB+=	JACK=""
.else
CONFIGURE_ARGS+=--disable-jackrack
PLIST_SUB+=	JACK="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	exif:${PORTSDIR}/graphics/libexif
USE_QT4+=	corelib gui opengl svg xml
CONFIGURE_ARGS+=--enable-qimage \
		--qimage-includedir="${QT_INCDIR}" \
		--qimage-libdir="${QT_LIBDIR}"
PLIST_SUB+=	QT4=""
. if ${PORT_OPTIONS:MKDE4}
USE_KDE4+=	kdelibs
CONFIGURE_ENV+=	PATH="${KDE4_PREFIX}/bin:$$PATH"
. else
CONFIGURE_ARGS+=--without-kde
. endif
.else
CONFIGURE_ARGS+=--disable-qimage
PLIST_SUB+=	QT4="@comment "
.endif

.if ${PORT_OPTIONS:MQUICKTIME}
LIB_DEPENDS+=	dv:${PORTSDIR}/multimedia/libdv \
		quicktime:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=--enable-kino
PLIST_SUB+=	QUICKTIME=""
.else
CONFIGURE_ARGS+=--disable-kino
PLIST_SUB+=	QUICKTIME="@comment "
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	samplerate:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-resample
PLIST_SUB+=	SAMPLERATE=""
.else
CONFIGURE_ARGS+=--disable-resample
PLIST_SUB+=	SAMPLERATE="@comment "
.endif

.if ${PORT_OPTIONS:MSOX}
LIB_DEPENDS+=	sox:${PORTSDIR}/audio/sox
CONFIGURE_ARGS+=--enable-sox
PLIST_SUB+=	SOX=""
.else
CONFIGURE_ARGS+=--disable-sox
PLIST_SUB+=	SOX="@comment "
.endif

.if ${PORT_OPTIONS:MSWFDEC}
LIB_DEPENDS+=	swfdec-0.8:${PORTSDIR}/graphics/swfdec
CONFIGURE_ARGS+=--enable-swfdec
PLIST_SUB+=	SWFDEC=""
.else
CONFIGURE_ARGS+=--disable-swfdec
PLIST_SUB+=	SWFDEC="@comment "
.endif

.if ${PORT_OPTIONS:MVDPAU}
USE_XORG+=	x11
CONFIGURE_ARGS+=--avformat-vdpau
.else
CONFIGURE_ARGS+=--avformat-no-vdpau
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=--disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/src/modules/avformat/vdpau.c \
		${WRKSRC}/src/modules/frei0r/factory.c \
		${WRKSRC}/src/modules/jackrack/plugin_mgr.c \
		${WRKSRC}/src/modules/linsys/Makefile
	@${REINPLACE_CMD} -e 's,-lpthread,-pthread,' \
			-e 's,-liconv,${ICONV_LIB},' \
		${WRKSRC}/src/framework/Makefile \
		${WRKSRC}/src/melt/Makefile \
		${WRKSRC}/src/modules/*/Makefile
	@${REINPLACE_CMD} -e 's,$$(libdir)/pkgconfig,${PREFIX}/libdata/pkgconfig,' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/melt.1 ${MANPREFIX}/man/man1/melt.1
	@${RM} -f ${WRKSRC}/docs/melt.1
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

.endif # ${SLAVE_PORT} == "no"

.include <bsd.port.mk>
