# $FreeBSD$

PORTNAME=	xf86-input-fpit
PORTVERSION=	1.4.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org fpit input driver

XORG_CAT=	driver
USE_XORG=	xrandr

MAN4=		fpit.4x

.if !defined(WITH_NEW_XORG)
IGNORE=		does not build with X server 1.7.7
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
