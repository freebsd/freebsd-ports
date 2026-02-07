PORTNAME=	xlibre-xf86-video-amdgpu
PORTVERSION=	25.0.1
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre amdgpu display driver
WWW=		https://github.com/X11Libre/xf86-video-amdgpu/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

# No amdgpu kernel driver on non-x86 and PC98.
ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	KMS is required and currently only available on x86/arm64/powerpc64le

LIB_DEPENDS=	libdrm_amdgpu.so:graphics/libdrm

USES=		gl tar:xz xlibre-cat:driver
USE_GL=		gbm

CONFIGURE_ARGS+=--disable-udev

PLIST_FILES=	${MODULEDIR}/drivers/amdgpu_drv.so \
		share/man/man4/amdgpu.4x.gz \
		share/X11/xorg.conf.d/10-amdgpu.conf

.include <bsd.port.mk>
