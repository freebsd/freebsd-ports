PORTREVISION=	0
CATEGORIES=	sysutils

COMMENT=	GStreamer compact disc input and control library

GST_PLUGIN=	cdio
DIST=		ugly

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libcdio.so:sysutils/libcdio

.include "${MASTERDIR}/Makefile"

MESON_ARGS+= -Dgpl=enabled
