PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer theora plugin

LIB_DEPENDS+=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		base
GST_PLUGIN=	theora

.include "${MASTERDIR}/Makefile"
