PORTNAME=	gstreamer1-plugin-netint
DISTVERSION=	5.9.0
CATEGORIES=	multimedia
# 5.9.0 not in NETINT's public repo: from the Quadra SDK (ni-gstreamer-plugins/)
MASTER_SITES=	LOCAL/olivier
DISTNAME=	netint-gst-plugins-${DISTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	GStreamer plugin for NETINT Quadra video processing units
WWW=		https://github.com/NETINT-Technologies/netint_gst_plugins

LICENSE=	LGPL20+

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	NETINT supports Quadra cards only on these architectures
IGNORE_FreeBSD_14=	needs the Linux-compatible ioctls of nvme(4), added in FreeBSD 15.0

LIB_DEPENDS=	libxcoder.so:multimedia/libxcoder

USES=		gnome gstreamer meson pkgconfig
USE_GNOME=	glib20
USE_GSTREAMER=	bad

MESON_ARGS=	-Dexamples=disabled \
		-Dni-gst-framework-patch=false \
		-Dnilogan=disabled \
		-Dniquadra=enabled \
		-Dpackage-origin=${WWW}

PLIST_FILES=	lib/gstreamer-1.0/libgstniquadra.so \
		lib/gstreamer-1.0/pkgconfig/gstniquadra.pc

.include <bsd.port.mk>
