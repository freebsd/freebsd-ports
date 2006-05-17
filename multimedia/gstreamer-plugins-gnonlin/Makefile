# New ports collection makefile for:	gstreamer-plugins-gnonlin
# Date created:		2006-04-25
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-gnonlin/Makefile,v 1.2 2006/04/25 20:54:56 ahze Exp $

PORTNAME=	gstreamer-plugins-gnonlin
PORTVERSION=	0.10.4
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gnonlin/
DISTNAME=	gnonlin-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gstreamer lib for writing non-linear audio and video

USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes

PLIST_FILES=	lib/gstreamer-0.10/libgnl.a lib/gstreamer-0.10/libgnl.la \
		lib/gstreamer-0.10/libgnl.so

.include <bsd.port.mk>
