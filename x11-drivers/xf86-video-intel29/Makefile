# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	xf86-video-intel29
PORTVERSION=	2.9.1
CATEGORIES=	x11-drivers
DISTNAME=	xf86-video-intel-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Driver for Intel integrated graphics chipsets

DEPRECATED=	Not supported
EXPIRATION_DATE=2013-02-15
IGNORE=		Not supported.
CONFLICTS=	xf86-video-intel-2.7.[0-9]* xf86-video-intel-2.15.[0-9]*

ONLY_FOR_ARCHS=	amd64 i386
USE_GL=		gl

XORG_CAT=	driver
USE_XORG=	xvmc xineramaproto xextproto x11 xf86driproto glproto
MAN4=		intel.4x

.include <bsd.port.mk>
