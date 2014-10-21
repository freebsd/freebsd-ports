# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer1-plugins-gnonlin
PORTVERSION=	1.2.1
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gnonlin/
DISTNAME=	gnonlin-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Gstreamer lib for writing non-linear audio and video

CFLAGS:=	${CFLAGS} -O2 -Wno-format
USES=		libtool pkgconfig python:build tar:xz
GNU_CONFIGURE=	yes
USE_GSTREAMER1=	good
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/gstreamer-1.0/libgnl.so

.include <bsd.port.mk>
