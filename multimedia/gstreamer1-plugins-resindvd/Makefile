PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer resindvd DVD playback plugin

BUILD_DEPENDS=	libdvdnav>=4.1.2:multimedia/libdvdnav
LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread
RUN_DEPENDS=	libdvdnav>=4.1.2:multimedia/libdvdnav

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	resindvd

.include "${MASTERDIR}/Makefile"
