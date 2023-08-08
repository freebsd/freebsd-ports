PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer libx264 based H264 plugin

GST_PLUGIN=	x264
DIST=		ugly

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libx264.so:multimedia/libx264

.include "${MASTERDIR}/Makefile"

MESON_ARGS+= -Dgpl=enabled
