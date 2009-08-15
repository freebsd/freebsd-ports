# New ports collection makefile for:	xplore
# Date created:				13 August 2003
# Whom:					Albert Graef <ag@muwiinfa.geschichte.uni-mainz.de>
#
# $FreeBSD$
#

PORTNAME=	xplore
PORTVERSION=	1.2a
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another Motif file manager

USE_IMAKE=	yes
USE_MOTIF=	yes
USE_XORG=	xpm
MAKE_JOBS_UNSAFE=yes

MAN1=		xplore.1 xploretype.1

post-patch:
	@${REINPLACE_CMD} -e 's| read| read dummy|g' ${WRKSRC}/system.xplorerc

.include <bsd.port.mk>
