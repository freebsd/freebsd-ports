# New ports collection makefile for:	xf86-input-elographics
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-elographics
PORTVERSION=	1.2.3
PORTREVISION=	3
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org elographics input driver

BROKEN=		does not compile

XORG_CAT=	driver
MAN4=		elographics.4x

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
