PORTNAME=	xlibre-xf86-video-vmware
PORTVERSION=	25.0.0
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre vmware display driver
WWW=		https://github.com/X11Libre/xf86-video-vmware/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	vmware gfx protocol is only supported on x86-compatible architectures

USES=		xlibre-cat:driver

LIB_DEPENDS+=	libdrm.so:graphics/libdrm \
		libxatracker.so:graphics/mesa-gallium-xa

CONFIGURE_ARGS=	--without-libudev

.include <bsd.port.mk>
