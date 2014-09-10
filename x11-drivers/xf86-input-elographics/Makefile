# $FreeBSD$

PORTNAME=	xf86-input-elographics
PORTVERSION=	${ELO_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org elographics input driver

XORG_CAT=	driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
ELO_VERSION=	1.4.1
ELO_REVISION=	1
.else
ELO_VERSION=	1.2.4
ELO_REVISION=	1
.endif

.include <bsd.port.mk>
