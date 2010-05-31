# New ports collection makefile for:	gmerlin
# Date created:		07 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmerlin
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Multimedia framework

LIB_DEPENDS=	gavl.1:${PORTSDIR}/multimedia/gavl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-doxygen --without-texinfo --disable-alsa \
		--disable-v4l --disable-alsamixer --disable-camelot \
		--without-cpuflags --disable-v4l2 --disable-v4lconvert
USE_GNOME=	gtk20 gnomehack libxml2
USE_GL=		gl
USE_XORG=	x11 xv xinerama ice
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include/libvisual-0.4 -I${LOCALBASE}/include"

PORTDOCS=	README

INFO=		gmerlin
MAN1=		gmerlin_play.1

OPTIONS=	PULSEAUDIO "Enable PulseAudio support" on \
		QUICKTIME "Enable QuickTime support" on \
		LIBVISUAL "Enable libvisual support" on \
		LIBCDIO	"Enable libcdio support" on \
		MUSICBRAINZ "Enable MusicBrainz support" on \
		CDDB	"Enable CDDB support" on \
		ESOUND	"Enable ESounD support" off \
		JACK	"Enable Jack support" on \
		JPEG	"Enable JPEG support" on \
		PNG	"Enable PNG support" on \
		TIFF	"Enable TIFF support" on \
		MJPEGTOOLS "Enable mjpegtools support" on \
		PLUGINCFG "Build plugin configurator" on \
		PLAYER	"Build player" on \
		KBD	"Build keyboard daemon" on \
		TRANSCODER "Build transcoder" on \
		VISUALIZER "Build visualizer" on \
		THUMBNAILER "Build thumbnailer" on \
		OPTIMIZED_CFLAGS "Additional optimizations" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSEAUDIO=""
.else
CONFIGURE_ARGS+=--disable-pulseaudio
PLIST_SUB+=	PULSEAUDIO="@comment "
.endif

.if !defined(WITHOUT_QUICKTIME)
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
PLIST_SUB+=	QUICKTIME=""
.else
CONFIGURE_ARGS+=--disable-lqt
PLIST_SUB+=	QUICKTIME="@comment "
.endif

.if !defined(WITHOUT_LIBVISUAL)
LIB_DEPENDS+=	visual-0.4:${PORTSDIR}/graphics/libvisual04
.else
CONFIGURE_ARGS+=--disable-libvisual
.endif

.if !defined(WITHOUT_LIBCDIO)
LIB_DEPENDS+=	cdio.12:${PORTSDIR}/sysutils/libcdio
PLIST_SUB+=	CDIO=""
.else
CONFIGURE_ARGS+=--disable-libcdio
PLIST_SUB+=	CDIO="@comment "
.endif

.if !defined(WITHOUT_MUSICBRAINZ)
LIB_DEPENDS+=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz
.else
CONFIGURE_ARGS+=--disable-musicbrainz
.endif

.if !defined(WITHOUT_CDDB)
LIB_DEPENDS+=	cddb.4:${PORTSDIR}/audio/libcddb
.else
CONFIGURE_ARGS+=--disable-cddb
.endif

.if defined(WITH_ESOUND)
LIB_DEPENDS+=	esd.2:${PORTSDIR}/audio/esound
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=--disable-esd
PLIST_SUB+=	ESOUND="@comment "
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.else
CONFIGURE_ARGS+=--disable-jack
PLIST_SUB+=	JACK="@comment "
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--disable-libjpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=--disable-libpng
PLIST_SUB+=	PNG="@comment "
.endif

.if !defined(WITHOUT_TIFF)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=--disable-libtiff
PLIST_SUB+=	TIFF="@comment "
.endif

.if !defined(WITHOUT_MJPEGTOOLS)
LIB_DEPENDS+=	lavjpeg-1.9.0:${PORTSDIR}/multimedia/mjpegtools
.else
CONFIGURE_ARGS+=--disable-mjpegtools
.endif

# applications
.if !defined(WITHOUT_PLUGINCFG)
PLIST_SUB+=	PLUGINCFG=""
.else
CONFIGURE_ARGS+=--disable-plugincfg
PLIST_SUB+=	PLUGINCFG="@comment "
.endif

.if !defined(WITHOUT_PLAYER)
MAN1+=		gmerlin.1 gmerlin_remote.1
PLIST_SUB+=	PLAYER=""
.else
CONFIGURE_ARGS+=--disable-player
PLIST_SUB+=	PLAYER="@comment "
.endif

.if !defined(WITHOUT_KBD)
PLIST_SUB+=	KBD=""
.else
CONFIGURE_ARGS+=--disable-kbd
PLIST_SUB+=	KBD="@comment "
.endif

.if !defined(WITHOUT_TRANSCODER)
MAN1+=		gmerlin_transcoder.1 gmerlin_transcoder_remote.1
PLIST_SUB+=	TRANSCODER=""
.else
CONFIGURE_ARGS+=--disable-transcoder
PLIST_SUB+=	TRANSCODER="@comment "
.endif

.if !defined(WITHOUT_VISUALIZER)
PLIST_SUB+=	VISUALIZER=""
.else
CONFIGURE_ARGS+=--disable-visualizer
PLIST_SUB+=	VISUALIZER="@comment "
.endif

.if !defined(WITHOUT_THUMBNAILER)
PLIST_SUB+=	THUMBNAILER=""
.else
CONFIGURE_ARGS+=--disable-thumbnailer
PLIST_SUB+=	THUMBNAILER="@comment "
.endif

# vendor ocflags from configure
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -funroll-all-loops -fomit-frame-pointer -ffast-math
CXXFLAGS+=	-O3 -funroll-all-loops -fomit-frame-pointer -ffast-math
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3.*-ffast-math||g; \
		s|-DGTK_DISABLE_DEPRECATED||; \
		/LIBS/ s|-ldl||g; s|^LDFLAGS="|&$${LDFLAGS} |' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||; s|-lpthread|${PTHREAD_LIBS}|; \
		/^LIBS = / s|$$| @LIBINTL@ ${PTHREAD_LIBS}|' \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/tests/Makefile.in \
		${WRKSRC}/apps/cmdlineplayer/Makefile.in \
		${WRKSRC}/apps/kbd/Makefile.in \
		${WRKSRC}/apps/player/Makefile.in \
		${WRKSRC}/apps/transcoder/Makefile.in \
		${WRKSRC}/apps/thumbnailer/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
