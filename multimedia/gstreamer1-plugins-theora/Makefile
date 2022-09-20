PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer theora plugin

GST_PLUGIN=	theora
DIST=		base

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS+= libtheora.so:multimedia/libtheora \
	libogg.so:audio/libogg

.include "${MASTERDIR}/Makefile"
