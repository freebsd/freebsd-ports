PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer mpeg encoder plugin

LIB_DEPENDS=	libmjpegutils.so:multimedia/mjpegtools

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	mpeg2enc

.include "${MASTERDIR}/Makefile"
