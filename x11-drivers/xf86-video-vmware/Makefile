PORTNAME=	xf86-video-vmware
PORTVERSION=	13.4.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org vmware display driver
WWW=		https://www.x.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	vmware gfx protocol is only supported on x86-compatible architectures

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		tar:xz xorg-cat:driver

CONFIGURE_ARGS=	--without-libudev

.include <bsd.port.mk>
