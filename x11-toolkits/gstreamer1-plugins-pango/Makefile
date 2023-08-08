PORTREVISION=	0
CATEGORIES=	x11-toolkits

COMMENT=	GStreamer pango textoverlay plugin

GST_PLUGIN=	pango
DIST=		base

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

USE_GNOME=  cairo pango
USES=	xorg
USE_XORG=	x11 xext

.include "${MASTERDIR}/Makefile"
