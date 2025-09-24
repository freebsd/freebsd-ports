PORTNAME=	tg_owt
PORTVERSION=	0.0.20250914
CATEGORIES=	net-im

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

USES=		cmake gl gnome pkgconfig xorg
USE_XORG=	x11 xcomposite xdamage xrender xrandr xtst
USE_GL=		gbm gl
USE_GITHUB=	yes
USE_GNOME=	glib20
GH_ACCOUNT=	desktop-app
GH_TAGNAME=	5c5c712

CMAME_ON=	TG_OWT_PACKAGED_BUILD

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

# remove more sources not needed to build telegram-desktop, they are however
# required at tg_owt configure-time even though they are not built, see
# nice_target_sources()/remove_target_sources() calls in CMakeLists.txt
post-configure:
	${RM} -rf \
		${WRKSRC}/src/modules/audio_device/android \
		${WRKSRC}/src/modules/audio_device/mac \
		${WRKSRC}/src/modules/audio_device/win \
		${WRKSRC}/src/modules/desktop_capture/mac \
		${WRKSRC}/src/modules/desktop_capture/wayland \
		${WRKSRC}/src/modules/desktop_capture/win \
		${WRKSRC}/src/modules/video_capture/windows \
		${WRKSRC}/src/rtc_base/win \
		${WRKSRC}/src/rtc_base/win32*.h

.include <bsd.port.mk>
