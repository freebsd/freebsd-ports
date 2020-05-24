# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	19.1.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/driver/${PORTNAME}/-/commit/
PATCHFILES+=	f223035f4ffcff2a9296d1e907a5193f8e8845a3.diff:-p1
PATCHFILES+=	4d84cf438e7f1bebf0053035ef0292e9fed257d1.diff:-p1
PATCHFILES+=	c0eb5dbd9c1db6b6d5b1574bcd8c584170d7ab54.diff:-p1
PATCHFILES+=	3845392426e9798c1fb2a6fc5e97bf5dfd5c443d.diff:-p1

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

# No Radeon kernel driver on non-x86.
ONLY_FOR_ARCHS=		amd64 i386 powerpc64
ONLY_FOR_ARCHS_REASON=	KMS is required and currently only available on x86

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess \
		libdrm_radeon.so:graphics/libdrm

CONFLICTS_INSTALL=	xf86-video-ati-legacy

USES=		gl xorg xorg-cat:driver
USE_GL=		gl
USE_XORG=	pciaccess

CONFIGURE_ARGS+=--disable-udev

.include <bsd.port.mk>
