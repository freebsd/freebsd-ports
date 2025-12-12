PORTNAME=	xlibre-xf86-video-amdgpu
PORTVERSION=	23.0.0.5
CATEGORIES=	x11-drivers

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/driver/${PORTNAME:C/xlibre-//}/-/commit/
PATCHFILES+=	77b13493.patch:-p1 # https://gitlab.freedesktop.org/xorg/driver/xf86-video-amdgpu/-/merge_requests/77

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre amdgpu display driver
WWW=		https://github.com/X11Libre/xf86-video-amdgpu/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	xf86-video-amdgpu

# No amdgpu kernel driver on non-x86 and PC98.
ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	KMS is required and currently only available on x86/arm64/powerpc64le

LIB_DEPENDS=	libdrm_amdgpu.so:graphics/libdrm

USES=		gl tar:xz xlibre-cat:driver
USE_GL=		gbm

CONFIGURE_ARGS+=--disable-udev

PLIST_FILES=	lib/xorg/modules/xlibre-25.0/drivers/amdgpu_drv.so \
		share/man/man4/amdgpu.4x.gz \
		share/X11/xorg.conf.d/10-amdgpu.conf

.include <bsd.port.mk>
