# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	7.9.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess \
		libdrm_radeon.so:graphics/libdrm

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	pciaccess

# No Radeon kernel driver on non-x86 and PC98.
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	KMS is required and currently only available on x86

CONFIGURE_ARGS+=--disable-udev

.include <bsd.port.mk>
