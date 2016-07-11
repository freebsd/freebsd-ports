# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	multimedia

COMMENT=	GStreamer (openh264) plugin

BROKEN=		gstopenh264enc.cpp:737:32: error: no member \
		named 'sSliceCfg' in 'SSpatialLayerConfig'

GST_PLUGIN=	openh264
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

.include "${MASTERDIR}/Makefile"
