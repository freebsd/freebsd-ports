PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer dts audio decode plugin

GST_PLUGIN=	dts
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libdca.so:multimedia/libdca

.include "${MASTERDIR}/Makefile"

MESON_ARGS+= -Dgpl=enabled
