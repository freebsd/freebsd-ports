PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer mpeg decode plugin

LIB_DEPENDS=	libmpeg2.so:multimedia/libmpeg2

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		ugly
GST_PLUGIN=	mpeg2dec

.include "${MASTERDIR}/Makefile"
