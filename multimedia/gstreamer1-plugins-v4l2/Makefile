PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer Video 4 Linux 2 source plugin

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
RUN_DEPENDS=	webcamd:multimedia/webcamd

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		good
GST_PLUGIN=	v4l2

.include "${MASTERDIR}/Makefile"
