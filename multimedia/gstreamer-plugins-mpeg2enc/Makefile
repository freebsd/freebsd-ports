# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/gstreamer-plugins-mpeg2enc/Makefile,v 1.5 2008/03/19 14:05:37 ahze Exp $

PORTREVISION=	3
CATEGORIES=	multimedia

COMMENT=	Gstreamer mpeg encoder plugin

BROKEN_armv6=		fails to compile: 'format_codes.h' file not found
BROKEN_armv7=		fails to compile: 'format_codes.h' file not found

GST_PLUGIN=	mpeg2enc

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins

.include "${MASTERDIR}/Makefile"
