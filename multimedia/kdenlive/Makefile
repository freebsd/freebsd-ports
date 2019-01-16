# $FreeBSD$

PORTNAME=	kdenlive
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE professional quality non-linear video editing suite

LICENSE=	GPLv2

LIB_DEPENDS=	libmlt.so:multimedia/mlt
BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
RUN_DEPENDS=	ffmpeg${FFMPEG_SUFX}:multimedia/ffmpeg${FFMPEG_SUFX} \
		${LOCALBASE}/lib/mlt/libmltqt.so:multimedia/mlt-qt5

USES=		cmake desktop-file-utils gettext-tools pkgconfig \
		qt:5 shared-mime-info kde:5 tar:xz
USE_GL=		gl glu
USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons ecm filemetadata \
		guiaddons i18n iconthemes kio itemviews jobwidgets newstuff \
		notifications notifyconfig service solid sonnet textwidgets \
		widgetsaddons xmlgui \
		init_run
USE_QT=		concurrent core dbus declarative gui network xml \
		buildtools_build qmake_build \
		quickcontrols_run script svg webkit widgets
USE_XORG=	x11
CFLAGS+=	-I${LOCALBASE}/include # linux/input.h
CMAKE_ARGS=	-DFFMPEG_SUFFIX:STRING="${FFMPEG_SUFX}"

# Keep in sync with multimedia/mlt, possibly.
FFMPEG_SUFX=	# Currently empty.

OPTIONS_DEFINE=	DVDWIZARD FREI0R LADSPA SCREENCAST V4L XINE DOCS
OPTIONS_DEFAULT=DVDWIZARD FREI0R LADSPA SCREENCAST V4L XINE
OPTIONS_SUB=	yes

DVDWIZARD_DESC=	DVD authoring via DVDAuthor and cdrtools
SCREENCAST_DESC=Screen capture support via recordMyDesktop
V4L_DESC=	Webcam support via Video4Linux
XINE_DESC=	DVD preview support via xine

DVDWIZARD_RUN_DEPENDS=	dvdauthor:multimedia/dvdauthor \
			cdrecord:sysutils/cdrtools

FREI0R_RUN_DEPENDS=	frei0r-plugins>=0:graphics/frei0r-plugins

LADSPA_RUN_DEPENDS=	swhplugins>=0:audio/swhplugins

SCREENCAST_RUN_DEPENDS=	recordmydesktop:multimedia/recordmydesktop

V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CMAKE_OFF=		-DWITH_LibV4L2:BOOL=FALSE

XINE_RUN_DEPENDS=	xine:multimedia/xine

post-patch:
	@${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		-e '/SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/data/CMakeLists.txt

.include <bsd.port.mk>
