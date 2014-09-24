# $FreeBSD$

PORTNAME=	kdenlive
PORTVERSION=	0.9.8
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE professional quality non-linear video editing suite

LICENSE=	GPLv2

LIB_DEPENDS=	libmlt.so:${PORTSDIR}/multimedia/mlt \
		libqjson.so:${PORTSDIR}/devel/qjson
RUN_DEPENDS=	ffmpeg${FFMPEG_SUFX}:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFX}

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	dbus gui opengl script svg xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11
USES=		cmake pkgconfig shared-mime-info tar:bzip2
CMAKE_ARGS=	-DFFMPEG_SUFFIX:STRING="${FFMPEG_SUFX}"

# Keep in sync with multimedia/mlt, possibly.
FFMPEG_SUFX=	# Currently empty.

OPTIONS_DEFINE=	DVDWIZARD FREI0R LADSPA NLS SCREENCAST V4L XINE
OPTIONS_DEFAULT=DVDWIZARD FREI0R LADSPA SCREENCAST V4L XINE
OPTIONS_SUB=	yes

DVDWIZARD_DESC=	DVD authoring via DVDAuthor and cdrtools
SCREENCAST_DESC=Screen capture support via recordMyDesktop
V4L_DESC=	Webcam support via Video 4 Linux
XINE_DESC=	DVD preview support via xine

DVDWIZARD_RUN_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
			cdrecord:${PORTSDIR}/sysutils/cdrtools

FREI0R_RUN_DEPENDS=	frei0r-plugins>=0:${PORTSDIR}/graphics/frei0r-plugins

LADSPA_RUN_DEPENDS=	swhplugins>=0:${PORTSDIR}/audio/swhplugins

NLS_USES=		gettext
NLS_CMAKE_OFF=		-DBUILD_po:BOOL=FALSE

SCREENCAST_RUN_DEPENDS=	recordmydesktop:${PORTSDIR}/multimedia/recordmydesktop

V4L_LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
V4L_CMAKE_OFF=		-DWITH_LibV4L2:BOOL=FALSE

XINE_RUN_DEPENDS=	xine:${PORTSDIR}/multimedia/xine

post-patch:
	@${REINPLACE_CMD} -E -e '/${PORTNAME}.(menu|xpm)/ d' \
		${PATCH_WRKSRC}/data/CMakeLists.txt
	@${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/src/mimetypes/CMakeLists.txt
.for lang in bs ca ca@valencia cs da de el es et fi fr ga gl he hr hu it ja lt mr nb nds nl pl pt pt_BR ro ru sk sl sv tr ug uk zh_CN zh_TW
	@${REINPLACE_CMD} -e 's,fr ALL,${lang} ALL,' \
		${PATCH_WRKSRC}/po/${lang}/CMakeLists.txt
.endfor

.include <bsd.port.mk>
