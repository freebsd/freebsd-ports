PORTNAME=	gstreamer1-libav
PORTVERSION=	1.20.5
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-libav/
DISTNAME=	gst-libav-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in with many audio/video decoders/encoders
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	orc>=0.4.16:devel/orc
LIB_DEPENDS=	liborc-0.4.so:devel/orc

PORTSCOUT=	limitw:1,even

USES=		bison gettext-runtime gnome gstreamer libtool localbase \
		meson ninja pkgconfig python:3.8+,build tar:xz
USE_GNOME=	glib20

BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	FFMPEG
OPTIONS_DEFAULT=FFMPEG

FFMPEG_DESC?=	Use system ffmpeg instead of internal libav
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_BUILD_DEPENDS_OFF=	nasm:devel/nasm
FFMPEG_MAKE_ENV_OFF=	V=1
FFMPEG_VARS_OFF+=	NOPRECIOUSMAKEVARS=yes # ARCH

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MFFMPEG)
LDFLAGS_aarch64=	-Wl,-z,notext
.endif

.include <bsd.port.mk>
