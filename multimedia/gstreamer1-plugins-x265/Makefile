PORTREVISION=	1
CATEGORIES=	multimedia

COMMENT=	GStreamer libx265 based H265 plugin

GST_PLUGIN=	x265
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libx265.so:multimedia/x265

.include "${MASTERDIR}/Makefile"

MESON_ARGS+= -Dgpl=enabled
