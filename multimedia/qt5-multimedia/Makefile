# $FreeBSD$

PORTNAME=	multimedia
DISTVERSION=	${QT5_VERSION}
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

OPTIONS_DEFINE=			AUDIOPLUGIN GSTREAMER OPENAL
OPTIONS_DEFAULT=		GSTREAMER
OPTIONS_RADIO=			AUDIOPLUGIN
OPTIONS_RADIO_AUDIOPLUGIN=	ALSA PULSEAUDIO
OPTIONS_SUB=			yes
AUDIOPLUGIN_DESC=		Audio plugins to build

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
GSTREAMER_BUILD_DEPENDS=${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
GSTREAMER_USE=		GSTREAMER=yes,bad
OPENAL_USES=		openal
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
.else
TBR_DEPENDS+=	gstreamer
QT_DEFINES+=	-GSTREAMER
QT_CONFIG+=	-gstreamer
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
		${WRKSRC}/src/plugins/v4l/radio/v4lradiocontrol.h

.include <bsd.port.mk>
