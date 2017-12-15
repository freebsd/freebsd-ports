# $FreeBSD$

PORTNAME=	webcamoid
DISTVERSION=	8.1.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Full featured webcam suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libjack.so:audio/jack \
		libpulse.so:audio/pulseaudio \
		libv4l2.so:multimedia/libv4l

USES=		pkgconfig qmake
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
USE_GL=		gl
USE_QT5=	concurrent core gui multimedia network opengl qml quick svg widgets buildtools_build

MAKE_ENV=	NOOSS=1 # NOOSS is because the OSS module attempts to use kevent on OSS devices, which is broken in the base
QMAKE_ARGS=	INSTALLQMLDIR=${QT_QMLDIR} \
		MANDIR=${PREFIX}/man

.include <bsd.port.mk>
