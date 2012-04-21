# New ports collection makefile for:	xf86-input-elographics
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-elographics
PORTVERSION=	${ELO_VERSION}
PORTREVISION=	${ELO_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org elographics input driver

XORG_CAT=	driver
USE_XORG=	xextproto videoproto
MAN4=		elographics.4x

.if defined(WITH_NEW_XORG)
ELO_VERSION=	1.3.0
ELO_REVISION=	0
.else
ELO_VERSION=	1.2.4
ELO_REVISION=	0
.endif

.include <bsd.port.mk>
