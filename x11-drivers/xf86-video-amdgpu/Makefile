# $FreeBSD$

# this port is for future amdgpu kernel support testing.

PORTNAME=	xf86-video-amdgpu
PORTVERSION=	19.1.0
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org amdgpu display driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm_amdgpu.so:graphics/libdrm

USES=		gl xorg-cat:driver
USE_GL=		gbm
# No amdgpu kernel driver on non-x86 and PC98.
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	KMS is required and currently only available on x86

CONFIGURE_ARGS+=--disable-udev

PLIST_FILES=	lib/xorg/modules/drivers/amdgpu_drv.so \
		man/man4/amdgpu.4x.gz \
		share/X11/xorg.conf.d/10-amdgpu.conf

.include <bsd.port.mk>
