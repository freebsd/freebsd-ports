PORTNAME=	xf86-video-vmware
PORTVERSION=	13.3.0
PORTREVISION=	9
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org vmware display driver
WWW=		https://www.x.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	vmware gfx protocol is only supported on x86-compatible architectures

USES=		xorg-cat:driver

LIB_DEPENDS+=	libdrm.so:graphics/libdrm \
		libxatracker.so:graphics/mesa-gallium-xa

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--without-libudev

.include <bsd.port.mk>
