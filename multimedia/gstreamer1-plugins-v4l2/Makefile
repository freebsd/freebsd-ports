PORTREVISION=	0
CATEGORIES=	multimedia
PKGNAMESUFFIX=	1-plugins-v4l2

COMMENT=	GStreamer Video 4 Linux 2 source plugin

GST_PLUGIN=	v4l2
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

BUILD_DEPENDS= v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS= libv4l2.so:multimedia/libv4l
RUN_DEPENDS= webcamd:multimedia/webcamd

.include "${MASTERDIR}/Makefile"
