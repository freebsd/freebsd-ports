PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer mplex plugin

BROKEN_armv6=		fails to build: ./gstmplex.hh:27:10: 'multiplexor.hpp' file not found
BROKEN_armv7=		fails to build: ./gstmplex.hh:27:10: 'multiplexor.hpp' file not found

GST_PLUGIN=	mplex
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libmplex2.so:multimedia/mjpegtools

.include "${MASTERDIR}/Makefile"

MESON_ARGS+= -Dgpl=enabled
