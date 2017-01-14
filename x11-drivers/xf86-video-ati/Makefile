# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	7.8.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess \
		libdrm_radeon.so:graphics/libdrm

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto \
		xineramaproto \
		xf86miscproto \
		glproto \
		presentproto
INSTALL_TARGET=	install-strip
# No Radeon kernel driver on non-x86 and PC98.
ONLY_FOR_ARCHS=	i386 amd64

CONFIGURE_ARGS+=--disable-udev

.include <bsd.port.mk>
