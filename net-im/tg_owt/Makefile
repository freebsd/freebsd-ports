# Created by: Henry Hu <henry.hu.sh@gmail.com>

PORTNAME=	tg_owt
PORTVERSION=	0.0.20211021
CATEGORIES=	net-im

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Webrtc library used by telegram-desktop

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib \
		pulseaudio>0:audio/pulseaudio \
		v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libevent.so:devel/libevent \
		libjpeg.so:graphics/jpeg-turbo \
		libopus.so:audio/opus \
		libpipewire-0.3.so:multimedia/pipewire \
		libusrsctp.so:net/libusrsctp \
		libvpx.so:multimedia/libvpx

USES=		cmake pkgconfig xorg
USE_XORG=	x11 xcomposite xdamage xrender xrandr
USE_GITHUB=	yes
GH_ACCOUNT=	desktop-app
GH_TAGNAME=	d578c76
# libyuv cloned from https://chromium.googlesource.com/libyuv/libyuv
GH_TUPLE=	webmproject:libvpx:5b63f0f:libvpx/src/third_party/libvpx/source/libvpx \
		HenryHu:libyuv:ad89006:libyuv/src/third_party/libyuv

CMAKE_OFF=	BUILD_SHARED_LIBS TG_OWT_BUILD_AUDIO_BACKENDS

# Disable DCHECKs, otherwise video calls will crash.
CXXFLAGS+=	-DNDEBUG

.include <bsd.port.mk>
