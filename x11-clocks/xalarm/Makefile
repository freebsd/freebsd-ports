# New ports collection makefile for:	xalarm
# Date created:		4 December 1996
# Whom:			desmo@bandwidth.org
#
# $FreeBSD$
#

PORTNAME=	xalarm
PORTVERSION=	3.06
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	desmo@bandwidth.org

USE_IMAKE=	yes
IS_INTERACTIVE=	yes

MAN1=		xalarm.1 xmemo.1 xfortune.1 xyow.1

pre-install:
	(cd ${WRKSRC} ; ${CP} XAlarm.ad XAlarm-color.ad)

.include <bsd.port.mk>
