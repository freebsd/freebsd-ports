# $FreeBSD$

PORTNAME=	xf86-input-magictouch
PORTVERSION=	1.0.0.5
PORTREVISION=	9
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org magictouch input driver

BROKEN=		Does not compile
DEPRECATED=	Does not compile
EXPIRATION_DATE=2014-05-01

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
IGNORE=		needs xf86_ansic.h which doesn't exist with recent xserver
.endif

XORG_CAT=	driver
USES=		libtool

.include <bsd.port.mk>
