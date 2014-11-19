# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/libnice-gst1/Makefile 19801 2014-08-13 09:46:10Z gusi $

PORTREVISION=	1
PKGNAMESUFFIX=	-gst1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GStreamer 1 plugin from libnice

LIB_DEPENDS=	libnice.so:${PORTSDIR}/net-im/libnice

MASTERDIR=	${.CURDIR}/../libnice
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/gst
INSTALL_WRKSRC=	${WRKSRC}/gst

LIBNICE_SLAVE=	gstreamer1

.include "${MASTERDIR}/Makefile"
