# $FreeBSD$

PORTNAME=	xf86-input-void
PORTVERSION=	${VOID_VERSION}
PORTREVISION=	${VOID_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org void input driver

XORG_CAT=	driver
MAN4=		void.4x

.if defined(WITH_NEW_XORG)
VOID_VERSION=	1.4.0
VOID_REVISION=	0
.else
VOID_VERSION=	1.3.1
VOID_REVISION=	0
.endif


NO_STAGE=	yes
.include <bsd.port.mk>
