# $FreeBSD$

PORTNAME=	multimedia
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	multimedia
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt audio, video, radio and camera support module

USE_QT5=	core gui network opengl qml quick widgets \
		buildtools_build
QT_DIST=	${PORTNAME}
USE_XORG=	x11 xext xv
USES=		pkgconfig qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

QT_DEFINES=	XVIDEO
QT_CONFIG=	xlib

OPTIONS_DEFINE=	ALSA GSTREAMER OPENAL PULSEAUDIO
OPTIONS_DEFAULT=GSTREAMER
OPTIONS_SUB=	yes

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib

GSTREAMER_BUILD_DEPENDS=${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
GSTREAMER_USE=	GSTREAMER=yes,bad

OPENAL_USE=	OPENAL=yes

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
QT_DEFINES+=	ALSA
QT_CONFIG+=	alsa
.else
TBR_DEPENDS+=	alsa
QT_DEFINES+=	-ALSA
QT_CONFIG+=	-alsa
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
QT_DEFINES+=	GSTREAMER
QT_CONFIG+=	gstreamer
PLIST_SUB+=	NOGSTREAMER="@comment "
.else
TBR_DEPENDS+=	gstreamer
QT_DEFINES+=	-GSTREAMER
QT_CONFIG+=	-gstreamer
PLIST_SUB+=	NOGSTREAMER=""
.endif

.if ! ${PORT_OPTIONS:MOPENAL}
TBR_DEPENDS+=	openal
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
QT_DEFINES+=	PULSEAUDIO
QT_CONFIG+=	pulseaudio
.else
TBR_DEPENDS+=	pulseaudio
QT_DEFINES+=	-PULSEAUDIO
QT_CONFIG+=	-pulseaudio
.endif

post-patch:
.for d in ${TBR_DEPENDS}
	@${REINPLACE_CMD} -e '/${d}/ d' \
		${WRKSRC}/qtmultimedia.pro
.endfor
	@${REINPLACE_CMD} -e 's|<linux/types.h>|<sys/types.h>|' \
		${WRKSRC}/src/gsttools/qgstreamervideoinputdevicecontrol.cpp \
		${WRKSRC}/src/plugins/gstreamer/audiodecoder/qgstreameraudiodecoderserviceplugin.cpp \
		${WRKSRC}/src/plugins/gstreamer/camerabin/camerabincontrol.cpp \
		${WRKSRC}/src/plugins/gstreamer/camerabin/camerabinserviceplugin.cpp \
		${WRKSRC}/src/plugins/gstreamer/mediacapture/qgstreamercaptureserviceplugin.cpp \
		${WRKSRC}/src/plugins/gstreamer/mediacapture/qgstreamerv4l2input.cpp \
		${WRKSRC}/src/plugins/gstreamer/mediaplayer/qgstreamerplayerserviceplugin.cpp \
		${WRKSRC}/src/plugins/v4l/radio/v4lradiocontrol.h

.include <bsd.port.mk>
