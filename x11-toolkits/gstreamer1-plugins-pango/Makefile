PORTREVISION=	0
CATEGORIES=	x11-toolkits

COMMENT=	GStreamer pango textoverlay plugin

USES=		xorg
USE_GNOME=	cairo pango
USE_XORG=	x11 xext

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		base
GST_PLUGIN=	pango

.include "${MASTERDIR}/Makefile"
