# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer mplex plugin

BROKEN_armv6=		fails to build: ./gstmplex.hh:27:10: 'multiplexor.hpp' file not found
BROKEN_armv7=		fails to build: ./gstmplex.hh:27:10: 'multiplexor.hpp' file not found

GST_PLUGIN=	mplex
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

.include "${MASTERDIR}/Makefile"
