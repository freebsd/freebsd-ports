# $FreeBSD$

PORTNAME=	xf86-input-elographics
PORTVERSION=	${ELO_VERSION}
PORTREVISION=	${ELO_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org elographics input driver

XORG_CAT=	driver
MAN4=		elographics.4x

.if defined(WITH_NEW_XORG)
ELO_VERSION=	1.4.1
ELO_REVISION=	0
.else
ELO_VERSION=	1.2.4
ELO_REVISION=	0
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
