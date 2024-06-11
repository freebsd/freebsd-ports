PORTNAME=	tg_owt
PORTVERSION=	0.0.20231221
PORTREVISION=	5
CATEGORIES=	net-im

PATCH_SITES=	https://github.com/desktop-app/tg_owt/commit/
PATCHFILES=	a264c3311dec000dbe2ad8e3c819364f409d7897.patch:-p1 \
		62672f3756ecf218252098211d78c13369ab6d28.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webrtc library used by telegram-desktop
WWW=		https://github.com/desktop-app/tg_owt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libavformat.so:multimedia/ffmpeg \
		libcrc32c.so:devel/crc32c \
		libjpeg.so:graphics/jpeg-turbo \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpipewire-0.3.so:multimedia/pipewire \
		libprotobuf.so:devel/protobuf \
		libsrtp2.so:net/libsrtp2 \
		libvpx.so:multimedia/libvpx

USES=		cmake gl pkgconfig xorg
USE_XORG=	x11 xcomposite xdamage xrender xrandr xtst
USE_GL=		gbm gl
USE_GITHUB=	yes
GH_ACCOUNT=	desktop-app
GH_TAGNAME=	afd9d5d

# libyuv cloned from https://chromium.googlesource.com/libyuv/libyuv
# when updating port check if hash tag in the submodule was updated
GH_TUPLE=	osokin:libyuv:04821d1:libyuv/src/third_party/libyuv

post-extract:
		${RM} -rf \
		${WRKSRC}/src/sdk/android \
		${WRKSRC}/src/sdk/objc \
		${WRKSRC}/src/third_party/abseil-cpp \
		${WRKSRC}/src/third_party/crc32c \
		${WRKSRC}/src/third_party/libsrtp \
		${WRKSRC}/src/third_party/libsrtp_config \
		${WRKSRC}/src/third_party/libvpx \
		${WRKSRC}/src/third_party/openh264 \
		${WRKSRC}/src/third_party/yasm

.include <bsd.port.mk>
