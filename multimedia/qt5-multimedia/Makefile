# $FreeBSD$

PORTNAME=	multimedia
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt audio, video, radio and camera support module

# LICENSE set via USES_QT5 (bsd.qt.mk)

USES=		pkgconfig qmake:norecursive
USE_GL=		gl
USE_GNOME=	glib20
USE_QT5=	core gui network opengl qml quick widgets \
		buildtools_build
QT_DIST=	${PORTNAME}
USE_XORG=	x11 xext xv
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

QT_CONFIG=	xlib

OPTIONS_DEFINE=			GSTREAMER OPENAL
OPTIONS_DEFAULT=		ALSA GSTREAMER
OPTIONS_RADIO=			AUDIOPLUGIN
OPTIONS_RADIO_AUDIOPLUGIN=	ALSA PULSEAUDIO
OPTIONS_SUB=			yes

AUDIOPLUGIN_DESC=	Audio plugins to build
OPENAL_DESC=		3D positional spatialized sound support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_VARS=		QT_CONFIG+=alsa
ALSA_VARS_OFF=		QT_CONFIG+=-alsa \
			QMAKE_CONFIGURE_ARGS+=-no-alsa
GSTREAMER_BUILD_DEPENDS=${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
GSTREAMER_USE=		GSTREAMER1=bad
GSTREAMER_VARS=		QT_CONFIG+=gstreamer-1.0 \
			QMAKE_CONFIGURE_ARGS+=-gstreamer 1.0
GSTREAMER_VARS_OFF=	QT_CONFIG+=-gstreamer-1.0 \
			QMAKE_CONFIGURE_ARGS+=-no-gstreamer
OPENAL_USES=		openal
OPENAL_VARS_OFF=	QMAKE_CONFIGURE_ARGS+=-no-openal
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	QT_CONFIG+=pulseaudio
PULSEAUDIO_VARS_OFF=	QT_CONFIG+=-pulseaudio \
			QMAKE_CONFIGURE_ARGS+=-no-pulseaudio

.include <bsd.port.mk>
