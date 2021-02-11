# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	tg_owt
PORTVERSION=	0.0.20210207
CATEGORIES=	net-im

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Webrtc library used by telegram-desktop

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib \
		pulseaudio>0:audio/pulseaudio \
		v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libjpeg.so:graphics/jpeg-turbo \
		libusrsctp.so:net/libusrsctp \
		libopus.so:audio/opus

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	desktop-app
GH_PROJECT=	tg_owt
GH_TAGNAME=	a198773
# libyuv cloned from https://chromium.googlesource.com/libyuv/libyuv
GH_TUPLE=	webmproject:libvpx:5b63f0f:libvpx/src/third_party/libvpx/source/libvpx \
		HenryHu:libyuv:ad89006:libyuv/src/third_party/libyuv

# Disable DCHECKs, otherwise video calls will crash.
CXXFLAGS+=	-DNDEBUG

CMAKE_OFF=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
