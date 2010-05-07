# New ports collection makefile for:	xf86-video-siliconmotion
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-video-siliconmotion
PORTVERSION=	1.7.3
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org siliconmotion display driver

XORG_CAT=	driver
USE_XORG=	videoproto xextproto
MAN4=		siliconmotion.4x

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
