PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer DVD access plugin with libdvdread

GST_PLUGIN=	dvdread
DIST=		ugly

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=libdvdread.so:multimedia/libdvdread

.include "${MASTERDIR}/Makefile"

MESON_ARGS+= -Dgpl=enabled
