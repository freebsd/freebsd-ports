PORTREVISION=	1
CATEGORIES=	multimedia

COMMENT=	GStreamer libx265 based H265 plugin

LIB_DEPENDS=	libx265.so:multimedia/x265

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	x265

.include "${MASTERDIR}/Makefile"
