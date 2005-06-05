# New ports collection makefile for:	xalarm
# Date created:		4 December 1996
# Whom:			desmo@bandwidth.org
#
# $FreeBSD$
#

PORTNAME=	xalarm
PORTVERSION=	3.06
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X based alarm clock

USE_IMAKE=	yes
IS_INTERACTIVE=	yes

.include <bsd.port.pre.mk>

MAN1=		xalarm.1 xmemo.1 xfortune.1 xyow.1

pre-install:
	(cd ${WRKSRC} ; ${CP} XAlarm.ad XAlarm-color.ad)

.include <bsd.port.post.mk>
