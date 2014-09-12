# $FreeBSD$

PORTNAME=	xf86-input-void
PORTVERSION=	${VOID_VERSION}
PORTREVISION=	${VOID_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org void input driver

XORG_CAT=	driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
VOID_VERSION=	1.4.0
VOID_REVISION=	2
.else
VOID_VERSION=	1.3.1
VOID_REVISION=	2
.endif

.include <bsd.port.mk>
