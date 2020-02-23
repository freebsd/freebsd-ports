# $FreeBSD$

PORTNAME=	xf86-video-tseng
PORTVERSION=	1.2.5
PORTREVISION=	11
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org tseng display driver

BROKEN=			does not build with xorg-server 1.20.7
DEPRECATED=		broken
EXPIRATION_DATE=	2020-05-01
BROKEN_aarch64=		error: implicit declaration of function outb is invalid in C99
BROKEN_armv6=		error: implicit declaration of function outb is invalid in C99
BROKEN_armv7=		error: implicit declaration of function outb is invalid in C99

USES=		xorg-cat:driver

.include <bsd.port.mk>
