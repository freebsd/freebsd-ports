# New ports collection makefile for:	xplore
# Date created:				13 August 2003
# Whom:					Albert Graef <ag@muwiinfa.geschichte.uni-mainz.de>
#
# $FreeBSD$
#

PORTNAME=	xplore
PORTVERSION=	1.2a
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/${PORTNAME}/

MAINTAINER=	ag@muwiinfa.geschichte.uni-mainz.de
COMMENT=	Yet another Motif file manager

USE_IMAKE=	yes
USE_MOTIF=	yes
USE_XPM=	yes

MAN1=		xplore.1 xploretype.1

post-patch:
	@${REINPLACE_CMD} -e 's| read| read dummy|g' ${WRKSRC}/system.xplorerc

.include <bsd.port.mk>
