PORTREVISION=		1
CATEGORIES=	x11-toolkits
GST_PLUGIN_SUFFIX=	-gtk

COMMENT=	GStreamer gtksink plugin

GST_PLUGIN=	gtk3
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

USES=    gnome
USE_GSTREAMER= gl
USE_GNOME= cairo gdkpixbuf2 gtk30

.include "${MASTERDIR}/Makefile"
