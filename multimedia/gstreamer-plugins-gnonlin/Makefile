# New ports collection makefile for:	gstreamer-plugins-gnonlin
# Date created:		2006-04-25
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-gnonlin/Makefile,v 1.7 2006/07/21 16:39:31 ahze Exp $
#

PORTNAME=	gstreamer-plugins-gnonlin
PORTVERSION=	0.10.11
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gnonlin/
DISTNAME=	gnonlin-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Gstreamer lib for writing non-linear audio and video

CFLAGS:=	${CFLAGS} -O2
USE_BZIP2=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes

PLIST_FILES=	lib/gstreamer-0.10/libgnl.la \
		lib/gstreamer-0.10/libgnl.so

.include <bsd.port.mk>
