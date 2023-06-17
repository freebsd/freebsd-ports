PORTNAME=	webcamoid
DISTVERSION=	9.1.1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Full featured webcam suite
WWW=		https://webcamoid.github.io

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libjack.so:audio/jack \
		libpipewire-0.3.so:multimedia/pipewire \
		libportaudio.so:audio/portaudio \
		libpulse.so:audio/pulseaudio \
		libuvc.so:multimedia/libuvc \
		libv4l2.so:multimedia/libv4l \
		libvlc.so:multimedia/vlc

USES=		cmake compiler:c++11-lang desktop-file-utils gl gnome gstreamer pkgconfig qt:5 sdl xorg
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_GL=		gl
USE_QT=		concurrent core dbus declarative gui multimedia network opengl quickcontrols2 svg widgets xml \
		buildtools:build qmake:build quickcontrols:run
USE_SDL=	sdl2
USE_LDCONFIG=	yes

MAKE_ENV=	NOOSS=1 # NOOSS is because the OSS module attempts to use kevent on OSS devices, which is broken in the base
QMAKE_ARGS=	INSTALLQMLDIR=${QT_QMLDIR} \
		LIBDIR=${PREFIX}/lib \
		MANDIR=${PREFIX}/man

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
# Workaround for Bug#224137: devel/qt5-qmake: Doesn't use the right compiler in case USE_GCC is selected
BINARY_ALIAS=	g++=${CXX}
.endif

.include <bsd.port.post.mk>
