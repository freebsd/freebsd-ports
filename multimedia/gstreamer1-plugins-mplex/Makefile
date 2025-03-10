PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer mplex plugin

BROKEN_armv6=	fails to build: ./gstmplex.hh:27:10: 'multiplexor.hpp' file not found
BROKEN_armv7=	fails to build: ./gstmplex.hh:27:10: 'multiplexor.hpp' file not found

LIB_DEPENDS=	libmplex2.so:multimedia/mjpegtools

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	mplex

.include "${MASTERDIR}/Makefile"
