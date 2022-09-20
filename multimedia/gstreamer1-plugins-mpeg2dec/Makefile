PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer mpeg decode plugin

GST_PLUGIN=	mpeg2dec
DIST=		ugly

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libmpeg2.so:multimedia/libmpeg2

.include "${MASTERDIR}/Makefile"

MESON_ARGS+= -Dgpl=enabled
