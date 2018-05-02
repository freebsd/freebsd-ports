# $FreeBSD$

PORTNAME=	kdenlive
PORTVERSION=	0.9.10
PORTREVISION=	8
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src/
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE professional quality non-linear video editing suite

LICENSE=	GPLv2

LIB_DEPENDS=	libmlt.so:multimedia/mlt \
		libqjson.so:devel/qjson@qt4
RUN_DEPENDS=	ffmpeg${FFMPEG_SUFX}:multimedia/ffmpeg${FFMPEG_SUFX} \
		${LOCALBASE}/lib/mlt/libmltqt.so:multimedia/mlt-qt4

USES=		cmake kde:4 pkgconfig shared-mime-info tar:bzip2
USE_KDE=	automoc4 kdelibs nepomuk-core
USE_QT4=	corelib dbus gui opengl script svg xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11
CMAKE_ARGS=	-DFFMPEG_SUFFIX:STRING="${FFMPEG_SUFX}"

# Keep in sync with multimedia/mlt, possibly.
FFMPEG_SUFX=	# Currently empty.

OPTIONS_DEFINE=	DOCS DVDWIZARD FREI0R LADSPA NLS SCREENCAST V4L XINE
OPTIONS_DEFAULT=DVDWIZARD FREI0R LADSPA SCREENCAST V4L XINE
OPTIONS_SUB=	yes

DVDWIZARD_DESC=	DVD authoring via DVDAuthor and cdrtools
SCREENCAST_DESC=Screen capture support via recordMyDesktop
V4L_DESC=	Webcam support via Video4Linux
XINE_DESC=	DVD preview support via xine

DOCS_CMAKE_OFF=		-DBUILD_doc:BOOL=FALSE

DVDWIZARD_RUN_DEPENDS=	dvdauthor:multimedia/dvdauthor \
			cdrecord:sysutils/cdrtools

FREI0R_RUN_DEPENDS=	frei0r-plugins>=0:graphics/frei0r-plugins

LADSPA_RUN_DEPENDS=	swhplugins>=0:audio/swhplugins

NLS_USES=		gettext
NLS_CMAKE_OFF=		-DBUILD_po:BOOL=FALSE

SCREENCAST_RUN_DEPENDS=	recordmydesktop:multimedia/recordmydesktop

V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_CMAKE_OFF=		-DWITH_LibV4L2:BOOL=FALSE

XINE_RUN_DEPENDS=	xine:multimedia/xine

post-patch:
	@${REINPLACE_CMD} -E -e '/${PORTNAME}.(menu|xpm)/ d' \
		-e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/data/CMakeLists.txt

.include <bsd.port.mk>
