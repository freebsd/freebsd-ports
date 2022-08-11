# this port is for future amdgpu kernel support testing.

PORTNAME=	xf86-video-amdgpu
PORTVERSION=	22.0.0
PORTREVISION=	1
CATEGORIES=	x11-drivers

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/driver/${PORTNAME}/-/commit/
PATCHFILES+=	77b13493.patch:-p1 # https://gitlab.freedesktop.org/xorg/driver/xf86-video-amdgpu/-/merge_requests/77

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org amdgpu display driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

# No amdgpu kernel driver on non-x86 and PC98.
ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	KMS is required and currently only available on x86/arm64/powerpc64le

LIB_DEPENDS=	libdrm_amdgpu.so:graphics/libdrm

EXTRACT_SUFX=	.tar.xz
USES=		gl xorg-cat:driver tar:xz
USE_GL=		gbm

CONFIGURE_ARGS+=--disable-udev

PLIST_FILES=	lib/xorg/modules/drivers/amdgpu_drv.so \
		man/man4/amdgpu.4x.gz \
		share/X11/xorg.conf.d/10-amdgpu.conf

.include <bsd.port.mk>
