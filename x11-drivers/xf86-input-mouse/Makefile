# New ports collection makefile for:	xf86-input-mouse
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-mouse
PORTVERSION=	1.5.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org mouse input driver

XORG_CAT=	driver
MAN4=		mousedrv.4x

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
