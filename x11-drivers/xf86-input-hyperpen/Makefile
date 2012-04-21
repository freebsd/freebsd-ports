# New ports collection makefile for:	xf86-input-hyperpen
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-hyperpen
PORTVERSION=	${HYPERVER}
PORTREVISION=	${HYPERREVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org hyperpen input driver

XORG_CAT=	driver
USE_XORG=	xextproto videoproto

.if defined(WITH_NEW_XORG)
HYPERVER=	1.4.1
HYPERREVISION=	0
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_xf86HyperPen.c

.else
HYPERVER=	1.3.0
HYPERREVISION=	6
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_xf86HyperPen.c
.endif

.include <bsd.port.mk>
