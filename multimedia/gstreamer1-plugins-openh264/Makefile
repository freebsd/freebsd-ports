# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	multimedia

COMMENT=	GStreamer (openh264) plugin

# https://cgit.freedesktop.org/gstreamer/gst-plugins-bad/commit/?id=9f2dfaaa7a97
BROKEN=		gstopenh264enc.cpp:737:32: error: no member \
		named 'sSliceCfg' in 'SSpatialLayerConfig'

GST_PLUGIN=	openh264
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

.include "${MASTERDIR}/Makefile"
