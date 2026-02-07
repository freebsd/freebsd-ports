PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer DVD access plugin with libdvdread

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		ugly
GST_PLUGIN=	dvdread

.include "${MASTERDIR}/Makefile"
