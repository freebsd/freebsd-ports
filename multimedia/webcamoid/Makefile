PORTNAME=	webcamoid
DISTVERSION=	9.3.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Full featured webcam suite
WWW=		https://webcamoid.github.io \
		https://github.com/webcamoid/webcamoid

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libSvtAv1Enc.so:multimedia/svt-av1 \
		libaom.so:multimedia/aom \
		libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libjack.so:audio/jack \
		libopus.so:audio/opus \
		libpipewire-0.3.so:multimedia/pipewire \
		libportaudio.so:audio/portaudio \
		libpulse.so:audio/pulseaudio \
		libuvc.so:multimedia/libuvc \
		libv4l2.so:multimedia/libv4l \
		libvlc.so:multimedia/vlc \
		libvorbisenc.so:audio/libvorbis \
		libvpx.so:multimedia/libvpx \
		libx264.so:multimedia/libx264

USES=		cmake compiler:c++11-lang desktop-file-utils gl gnome gstreamer pkgconfig qt:6 sdl xorg
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_GL=		gl
USE_QT=		base declarative multimedia svg
USE_SDL=	sdl2
USE_X11=	x11 xext xfixes xrandr
USE_LDCONFIG=	yes

QMAKE_ARGS=	INSTALLQMLDIR=${QT_QMLDIR} \
		LIBDIR=${PREFIX}/lib \
		MANDIR=${PREFIX}/man

.include <bsd.port.mk>
