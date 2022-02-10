# Created by: Henry Hu <henry.hu.sh@gmail.com>

PORTNAME=	tg_owt
PORTVERSION=	0.0.20220209
CATEGORIES=	net-im

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Webrtc library used by telegram-desktop

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libepoxy.so:graphics/libepoxy \
		libevent.so:devel/libevent \
		libjpeg.so:graphics/jpeg-turbo \
		libopus.so:audio/opus \
		libpipewire-0.3.so:multimedia/pipewire \
		libusrsctp.so:net/libusrsctp

USES=		cmake gl pkgconfig xorg
USE_XORG=	x11 xcomposite xdamage xrender xrandr xtst
USE_GL=		gbm
USE_GITHUB=	yes
GH_ACCOUNT=	desktop-app
GH_TAGNAME=	4cba1ac

# libyuv cloned from https://chromium.googlesource.com/libyuv/libyuv
# when updating port check if hash tag in the submodule was updated
GH_TUPLE=	HenryHu:libyuv:ad89006:libyuv/src/third_party/libyuv

# Disable DCHECKs, otherwise video calls will crash.
CXXFLAGS+=	-DNDEBUG

.include <bsd.port.mk>
