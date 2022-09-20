PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer resindvd DVD playback plugin

GST_PLUGIN=	resindvd
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

BUILD_DEPENDS+= libdvdnav>=4.1.2:multimedia/libdvdnav
LIB_DEPENDS+= libdvdread.so:multimedia/libdvdread
RUN_DEPENDS+= libdvdnav>=4.1.2:multimedia/libdvdnav

.include "${MASTERDIR}/Makefile"

MESON_ARGS+= -Dgpl=enabled
