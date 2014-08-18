# $FreeBSD$
#    $MCom: ports/trunk/net-im/libnice-gst010/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTREVISION=	1
PKGNAMESUFFIX=	-gst010

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GStreamer 0.10 plugin from libnice

LIB_DEPENDS=	libnice.so:${PORTSDIR}/net-im/libnice

MASTERDIR=	${.CURDIR}/../libnice
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/gst
INSTALL_WRKSRC=	${WRKSRC}/gst

LIBNICE_SLAVE=	gstreamer010

.include "${MASTERDIR}/Makefile"
