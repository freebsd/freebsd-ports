# $FreeBSD$

PORTNAME=	mlt
PORTVERSION=	6.2.0
PORTREVISION?=	3
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
USE_XORG=	x11
USES=		alias gmake iconv pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gpl --enable-gpl3 --target-os=FreeBSD
USE_LDCONFIG=	yes

.ifndef(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-debug
.else
CONFIGURE_ARGS+=--enable-debug
.endif

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog NEWS README docs
PORTEXAMPLES=	demo

OPTIONS_DEFINE=	DOCS EXAMPLES FFMPEG FREI0R GTK2 JACK KDE4 \
		SAMPLERATE SOX SWFDEC VDPAU VIDSTAB
OPTIONS_RADIO=  	QT
OPTIONS_RADIO_QT=	QT4 QT5
OPTIONS_DEFAULT=FFMPEG FREI0R GTK2 QT4 SAMPLERATE SOX SWFDEC VIDSTAB
OPTIONS_SUB=	yes

GTK2_DESC=	Images and text rendering via GTK+ 2
KDE4_DESC=	Qt extra image formats support
QT4_DESC=	Kdenlive titles and images support via Qt 4
SOX_DESC=	SoX audio effects support
VIDSTAB_DESC=	Video stabilization support via Vid.Stab

FFMPEG_SUFX=		# Currently empty.
FFMPEG_LIB_DEPENDS=	libavformat${FFMPEG_SUFX}.so:multimedia/ffmpeg${FFMPEG_SUFX}
FFMPEG_CONFIGURE_ENABLE=avformat
FFMPEG_CONFIGURE_ON=	--avformat-suffix="${FFMPEG_SUFX}"

FREI0R_BUILD_DEPENDS=	${LOCALBASE}/include/frei0r.h:graphics/frei0r
FREI0R_CONFIGURE_ENABLE=frei0r

GTK2_LIB_DEPENDS=	libexif.so:graphics/libexif
GTK2_USE=		GNOME=gdkpixbuf2,gtk20,pango
GTK2_CONFIGURE_ENABLE=	gtk2

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
JACK_CONFIGURE_ENABLE=	jackrack
JACK_USE=		GNOME=glib20

KDE4_CONFIGURE_ENV=	PATH="${KDE_PREFIX}/bin:$$PATH"
KDE4_CONFIGURE_WITH=	kde
KDE4_USES=		kde:4
KDE4_USE=		KDE=kdelibs
KDE4_IMPLIES=		QT4

QT4_USE=		QT4=corelib,gui,opengl,svg,xml
QT5_USE=                QT5=core,gui,opengl,svg,xml

SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=resample

SOX_LIB_DEPENDS=	libsox.so:audio/sox
SOX_CONFIGURE_ENABLE=	sox

SWFDEC_LIB_DEPENDS=	libswfdec-0.8.so:graphics/swfdec
SWFDEC_CONFIGURE_ENABLE=swfdec
SWFDEC_USE=		GNOME=glib20,cairo

VDPAU_CONFIGURE_ON=	--avformat-vdpau
VDPAU_CONFIGURE_OFF=	--avformat-no-vdpau
# vdpau.c:239:21: error: no member named 'get_buffer' in 'struct AVCodecContext'
VDPAU_BROKEN=		https://sourceforge.net/p/mlt/bugs/240/

VIDSTAB_LIB_DEPENDS=	libvidstab.so:multimedia/vid.stab
VIDSTAB_CONFIGURE_ENABLE=vid.stab

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not compile on sparc64 (invokes i386 asm)
.endif

.if ${PORT_OPTIONS:MQT[45]}
LIB_DEPENDS+=		libexif.so:graphics/libexif
CONFIGURE_ARGS+=	--enable-qt \
			--qt-libdir="${QT_LIBDIR}" \
			--qt-includedir="${QT_INCDIR}"
PLIST_SUB+=             QT=""
.else
CONFIGURE_ARGS+=        --disable-qt
PLIST_SUB+=             QT="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/src/modules/avformat/vdpau.c \
		${WRKSRC}/src/modules/frei0r/factory.c \
		${WRKSRC}/src/modules/jackrack/plugin_mgr.c
	@${REINPLACE_CMD} -e 's,-lpthread,-pthread,' \
			-e 's,-liconv,${ICONV_LIB},' \
		${WRKSRC}/src/framework/Makefile \
		${WRKSRC}/src/melt/Makefile \
		${WRKSRC}/src/modules/*/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/melt.1 ${STAGEDIR}${MANPREFIX}/man/man1/melt.1
	@${RM} ${WRKSRC}/docs/melt.1
.if ${PORT_OPTIONS:MDOCS}
. for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DOCSDIR}
. endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
. for f in ${PORTEXAMPLES}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${EXAMPLESDIR}
. endfor
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/melt
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmlt.so.${PORTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmlt++.so.${PORTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mlt/*

.endif # ${SLAVE_PORT} == "no"

.include <bsd.port.mk>
