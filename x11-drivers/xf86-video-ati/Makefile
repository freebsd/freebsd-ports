PORTNAME=	xf86-video-ati
DISTVERSION=	22.0.0
PORTEPOCH=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	ATI/AMD Radeon video driver for the Xorg X server
WWW=		https://gitlab.freedesktop.org/xorg/driver/xf86-video-ati

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

# No Radeon kernel driver on non-x86.
ONLY_FOR_ARCHS=		aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	KMS is required and currently only available on x86/arm64/powerpc64

LIB_DEPENDS=	libdrm_radeon.so:graphics/libdrm

USES=		gl tar:xz xorg xorg-cat:driver
USE_GL=		gbm
USE_XORG=	pciaccess

CONFIGURE_ARGS+=--disable-udev

.include <bsd.port.mk>
