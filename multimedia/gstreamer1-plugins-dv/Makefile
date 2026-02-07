PORTREVISION=	0
CATEGORIES=	multimedia
PKGNAMESUFFIX=	1-plugins-dv

COMMENT=	GStreamer dv demux and decoder plugin based on libdv

LIB_DEPENDS=	libdv.so:multimedia/libdv

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		good
GST_PLUGIN=	dv

.include "${MASTERDIR}/Makefile"
