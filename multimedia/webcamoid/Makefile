# $FreeBSD$

PORTNAME=	webcamoid
DISTVERSION=	8.1.0
PORTREVISION=	8
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

USES=		pkgconfig qmake qt:5
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
USE_GL=		gl
USE_QT=		concurrent core declarative gui multimedia network opengl svg widgets buildtools_build quickcontrols_run

MAKE_ENV=	NOOSS=1 # NOOSS is because the OSS module attempts to use kevent on OSS devices, which is broken in the base
QMAKE_ARGS=	INSTALLQMLDIR=${QT_QMLDIR} \
		MANDIR=${PREFIX}/man

# Workaround for the crash when built with clang that the upstream author says is a bug in clang
USE_GCC=	yes

# Workaround for Bug#224137: devel/qt5-qmake: Doesn't use the right compiler in case USE_GCC is selected
BINARY_ALIAS=	g++=${CXX}

.include <bsd.port.mk>
