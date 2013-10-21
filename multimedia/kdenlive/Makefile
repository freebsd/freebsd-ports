# $FreeBSD$

PORTNAME=	kdenlive
PORTVERSION=	0.9.6
PORTREVISION=	2
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE professional quality non-linear video editing suite

LICENSE=	GPLv2

LIB_DEPENDS=	mlt:${PORTSDIR}/multimedia/mlt \
		qjson:${PORTSDIR}/devel/qjson
RUN_DEPENDS=	ffmpeg${FFMPEG_SUFX}:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFX}

USE_KDE4=	kdehier kdelibs kdeprefix automoc4 sharedmime
USE_QT4=	dbus gui opengl script svg xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11
USES=		cmake pkgconfig
USE_BZIP2=	yes
CMAKE_ARGS=	-DFFMPEG_SUFFIX:STRING="${FFMPEG_SUFX}"

# Keep in sync with multimedia/mlt, possibly.
FFMPEG_SUFX=

MAN1=		kdenlive.1 kdenlive_render.1

OPTIONS_DEFINE=	DVDWIZARD FREI0R LADSPA NLS SCREENCAST XINE
OPTIONS_DEFAULT=DVDWIZARD FREI0R LADSPA SCREENCAST XINE

DVDWIZARD_DESC=	DVD authoring via DVDAuthor and cdrtools
SCREENCAST_DESC=Screen capture support via recordMyDesktop
#V4L_DESC=	Webcam support via Video 4 Linux
XINE_DESC=	DVD preview support via xine

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVDWIZARD}
RUN_DEPENDS+=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		cdrecord:${PORTSDIR}/sysutils/cdrtools
.endif

.if ${PORT_OPTIONS:MFREI0R}
RUN_DEPENDS+=	frei0r-plugins>=0:${PORTSDIR}/graphics/frei0r-plugins
.endif

.if ${PORT_OPTIONS:MLADSPA}
RUN_DEPENDS+=	swhplugins>=0:${PORTSDIR}/audio/swhplugins
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DBUILD_po:BOOL=FALSE
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSCREENCAST}
RUN_DEPENDS+=	recordmydesktop:${PORTSDIR}/multimedia/recordmydesktop
.endif

#.if ${PORT_OPTIONS:MV4L}
#LIB_DEPENDS+=	v4l2:${PORTSDIR}/multimedia/libv4l
#BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
#.else
CMAKE_ARGS+=	-DWITH_V4L:BOOL=FALSE
#.endif

.if ${PORT_OPTIONS:MXINE}
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
.endif

post-patch:
	@${REINPLACE_CMD} -E -e '/${PORTNAME}.(menu|xpm)/ d' \
		${PATCH_WRKSRC}/data/CMakeLists.txt
	@${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/src/mimetypes/CMakeLists.txt

.include <bsd.port.mk>
