PORTNAME=	xf86-video-siliconmotion
PORTVERSION=	1.7.9
PORTREVISION=	6
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org siliconmotion display driver
WWW=		https://www.x.org/

USES=		xorg-cat:driver

BROKEN_aarch64=		error: implicit declaration of function outb is invalid in C99
BROKEN_armv6=		error: implicit declaration of function outb is invalid in C99
BROKEN_armv7=		error: implicit declaration of function outb is invalid in C99

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
