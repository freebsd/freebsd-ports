# $FreeBSD$

PORTNAME=	xf86-input-mutouch
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org mutouch input driver

XORG_CAT=	driver

.include <bsd.port.options.mk>

.if !defined(WITH_NEW_XORG)
IGNORE=		does not build with xorg-server 1.7.7
.endif

.include <bsd.port.mk>
