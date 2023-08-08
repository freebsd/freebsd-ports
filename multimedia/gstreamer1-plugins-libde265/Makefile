PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer HEVC/H.265 decoder (libde265) plugin

GST_PLUGIN=	libde265
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libde265.so:multimedia/libde265

.include "${MASTERDIR}/Makefile"
