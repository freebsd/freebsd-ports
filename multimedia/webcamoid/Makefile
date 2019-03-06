# $FreeBSD$

PORTNAME=	webcamoid
DISTVERSION=	8.5.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Full featured webcam suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libjack.so:audio/jack \
		libpulse.so:audio/pulseaudio \
		libv4l2.so:multimedia/libv4l

USES=		gl gnome pkgconfig qmake qt:5
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
USE_GL=		gl
USE_QT=		concurrent core declarative gui multimedia network opengl quickcontrols2 svg widgets xml buildtools_build

MAKE_ENV=	NOOSS=1 # NOOSS is because the OSS module attempts to use kevent on OSS devices, which is broken in the base
QMAKE_ARGS=	INSTALLQMLDIR=${QT_QMLDIR} \
		MANDIR=${PREFIX}/man

# Workaround for Bug#224137: devel/qt5-qmake: Doesn't use the right compiler in case USE_GCC is selected
BINARY_ALIAS=	g++=${CXX}

.include <bsd.port.mk>
