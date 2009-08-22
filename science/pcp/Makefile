# New ports collection makefile for:	pcp
# Date created:		2006-07-25
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pcp
PORTVERSION=	2.2
CATEGORIES=	science math
MASTER_SITES=	SF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Machine learning program for pattern classification

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
