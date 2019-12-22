# $FreeBSD$

PORTNAME=	subtitlecomposer
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	multimedia kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Subtitle editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++11-lang cmake desktop-file-utils gettext \
		kde:5 pkgconfig qt:5 shared-mime-info
USE_KDE=	auth codecs config configwidgets coreaddons ecm_build i18n \
		kio kross sonnet textwidgets widgetsaddons xmlgui
USE_QT=		buildtools_build qmake_build core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	maxrd2
GH_PROJECT=	SubtitleComposer

PORTSCOUT=	ignore:continuous

OPTIONS_GROUP=	VIDEO
VIDEO_DESC=	Video players
OPTIONS_GROUP_VIDEO=	GSTREAMER MPLAYER MPV PHONON XINE
OPTIONS_DEFAULT=	PHONON
OPTIONS_SUB=	yes

# Requires PocketSphinx-5prealpha
SPHINX_DESC=	Speech recognition via PocketSphinx
SPHINX_LIB_DEPENDS=	libpocketsphinx.so:audio/pocketsphinx
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_PocketSphinx=ON

GSTREAMER_USES=	gnome
GSTREAMER_USE=	GNOME=glib20 GSTREAMER1=yes
GSTREAMER_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_GStreamer=ON

MPLAYER_DESC=	Install MPlayer
MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer

MPV_DESC=	Multimedia support via MPV
MPV_LIB_DEPENDS=	libmpv.so:multimedia/mpv
MPV_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_MPV=ON

PHONON_USE=	QT=phonon4
PHONON_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Phonon4Qt5=ON

XINE_LIB_DEPENDS=	libxine.so:multimedia/libxine
XINE_USES=	xorg
XINE_USE=	XORG=x11,xcb
XINE_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Xine=ON

post-patch:
	${RM} ${WRKSRC}/cmake/FindICU.cmake
	${REINPLACE_CMD} '/include <locale>/s,locale,clocale,' \
		${WRKSRC}/src/videoplayerplugins/mpv/mpvbackend.cpp

.include <bsd.port.mk>
