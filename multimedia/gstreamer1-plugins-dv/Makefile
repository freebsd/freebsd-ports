PORTREVISION=	0
CATEGORIES=	multimedia
PKGNAMESUFFIX=	1-plugins-dv

COMMENT=	GStreamer dv demux and decoder plugin based on libdv

GST_PLUGIN=	dv
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=    libdv.so:multimedia/libdv

.include "${MASTERDIR}/Makefile"
