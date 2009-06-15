# New ports collection makefile for:	wdiag
# Date created:				3 September 2006
# Whom:					Josh Carroll <josh.carroll@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	wdiag
PORTVERSION=	0.10
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	Utility to collect DSL line stats from Westell DSL modems

WRKSRC=		${WRKDIR}/${PORTNAME}/src

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 800000)
IGNORE=	broken on -CURRENT
.endif

.include <bsd.port.post.mk>
