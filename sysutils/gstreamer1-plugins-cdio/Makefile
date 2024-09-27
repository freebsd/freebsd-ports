PORTREVISION=	0
CATEGORIES=	sysutils

COMMENT=	GStreamer compact disc input and control library

LIB_DEPENDS=	libcdio.so:sysutils/libcdio

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		ugly
GST_PLUGIN=	cdio

.include "${MASTERDIR}/Makefile"
