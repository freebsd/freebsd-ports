PORTREVISION=	0
CATEGORIES=	x11-toolkits

COMMENT=	GStreamer gtksink plugin

USES=		gnome
USE_GSTREAMER=	gl
USE_GNOME=	cairo gdkpixbuf gtk30

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=			good
GST_PLUGIN=		gtk3
GST_PLUGIN_SUFFIX=	-gtk

.include "${MASTERDIR}/Makefile"
