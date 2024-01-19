PORTNAME=	tg_owt
PORTVERSION=	0.0.20231221
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webrtc library used by telegram-desktop
WWW=		https://github.com/desktop-app/tg_owt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libjpeg.so:graphics/jpeg-turbo \
		libopus.so:audio/opus \
		libpipewire-0.3.so:multimedia/pipewire

USES=		cmake gl pkgconfig xorg
USE_XORG=	x11 xcomposite xdamage xrender xrandr xtst
USE_GL=		gbm
USE_GITHUB=	yes
GH_ACCOUNT=	desktop-app
GH_TAGNAME=	afd9d5d

# libyuv cloned from https://chromium.googlesource.com/libyuv/libyuv
# when updating port check if hash tag in the submodule was updated
GH_TUPLE=	abseil:abseil-cpp:8c0b94e:abseilcpp/src/third_party/abseil-cpp \
		cisco:libsrtp:a566a9:libsrtp/src/third_party/libsrtp \
		google:crc32c:21fc8ef:crc32c/src/third_party/crc32c/src \
		klemensn:libyuv:3aae5c7:libyuv/src/third_party/libyuv

.include <bsd.port.mk>
