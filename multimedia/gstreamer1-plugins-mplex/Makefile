PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer mplex plugin

LIB_DEPENDS=	libmplex2.so:multimedia/mjpegtools

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	mplex

.include "${MASTERDIR}/Makefile"
