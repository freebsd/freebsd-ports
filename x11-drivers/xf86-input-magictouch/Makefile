# $FreeBSD$

PORTNAME=	xf86-input-magictouch
PORTVERSION=	1.0.0.5
PORTREVISION=	8
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org magictouch input driver

BROKEN=		Does not compile

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
IGNORE=		needs xf86_ansic.h which doesn't exist with recent xserver
.endif

XORG_CAT=	driver
USE_AUTOTOOLS=	libtool

.include <bsd.port.mk>
