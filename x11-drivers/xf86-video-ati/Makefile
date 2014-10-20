# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	7.2.0
PORTREVISION=	4
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto xineramaproto xf86miscproto glproto
INSTALL_TARGET=	install-strip
# No Radeon kernel driver on non-x86 and PC98.
ONLY_FOR_ARCHS=	i386 amd64

CONFIGURE_ARGS+=--disable-udev
CONFIGURE_ARGS+=--disable-glamor

.include <bsd.port.mk>
