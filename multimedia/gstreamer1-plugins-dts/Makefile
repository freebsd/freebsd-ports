PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer dts audio decode plugin

LIB_DEPENDS=	libdca.so:multimedia/libdca

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	dts

.include "${MASTERDIR}/Makefile"
