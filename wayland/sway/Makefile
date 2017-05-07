# Created by Johannes Lundberg <yohanesu75@gmail.com>
# $FreeBSD$

PORTNAME=	sway
PORTVERSION=	0.9
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	i3-compatible Wayland compositor

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libwlc.so:wayland/wlc \
		libwayland-server.so:wayland/wayland \
		libepoll-shim.so:wayland/libepoll-shim \
		libpcre.so:devel/pcre \
		libjson-c.so:devel/json-c \
		libxkbcommon.so:x11/libxkbcommon \
		libinput.so:wayland/libinput

# For image capture
#		libMagickCore-6.so:graphics/ImageMagick
# For video capture
#		libavutil.so:multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	SirCmpwn

USES=		cmake:outsource gettext-runtime gnome pathfix pkgconfig
USE_GNOME=	cairo pango gdkpixbuf2
USE_GCC=	any

CMAKE_ARGS=	-DLIBEPOLL_INCLUDE_DIR=${LOCALBASE}/include/libepoll-shim \
		-DLIBEPOLL_LIBRARIES=-lepoll-shim -lrt

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SUID
OPTIONS_DEFAULT=SUID
SUID_DESC=	Install sway binary with setuid bit set

.include <bsd.port.mk>
