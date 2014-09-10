# $FreeBSD$

PORTNAME=	xf86-input-penmount
PORTVERSION=	${PEN_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org penmount input driver

XORG_CAT=	driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
PEN_VERSION=	1.5.0
PEN_REVISION=	1
.else
PEN_VERSION=	1.4.1
PEN_REVISION=	2
.endif

.include <bsd.port.mk>
