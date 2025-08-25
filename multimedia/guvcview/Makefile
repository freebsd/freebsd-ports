PORTNAME=	guvcview
DISTVERSION=	2.2.1
CATEGORIES=	multimedia
MASTER_SITES=	SOURCEFORGE/guvcview/source
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	walker.thompson@urz.uni-heidelberg.de
COMMENT=	Simple v4l2 full-featured video grabber
WWW=		https://guvcview.sourceforge.net/

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:multimedia/v4l_compat \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libgsl.so:math/gsl \
		libpng.so:graphics/png \
		libportaudio.so:audio/portaudio \
		libudev.so:devel/libudev-devd \
		libv4l2.so:multimedia/libv4l

USES=		cmake gl gettext-runtime gettext-tools localbase:ldflags ninja \
		pkgconfig qt:6 sdl tar:bz2
USE_GL=		opengl
USE_QT=		base
USE_SDL=	sdl2

CMAKE_ON=	USE_QT6 USE_SDL2
CMAKE_OFF=	USE_GTK3 USE_SFML

CFLAGS+=	-DNAME_MAX=MAXNAMLEN
LDFLAGS+=	-lintl

OPTIONS_DEFINE=		PULSEAUDIO
PULSEAUDIO_BROKEN=	Doesn't show up as an audio backend at runtime
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

.include <bsd.port.mk>
