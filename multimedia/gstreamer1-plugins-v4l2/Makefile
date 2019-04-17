# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	multimedia
PKGNAMESUFFIX=	1-plugins-v4l2

COMMENT=	GStreamer Video 4 Linux 2 source plugin

GST_PLUGIN=	gst_v4l2
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

EXTRA_PATCHDIR= ${.CURDIR}/files
EXTRA_PATCHES=  ${EXTRA_PATCHDIR}/patch-sys_v4l2_gstv4l2allocator.h

.include "${MASTERDIR}/Makefile"
