PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer libx264 based H264 plugin

LIB_DEPENDS=	libx264.so:multimedia/libx264

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		ugly
GST_PLUGIN=	x264

.include "${MASTERDIR}/Makefile"
