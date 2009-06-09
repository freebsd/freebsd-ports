# New ports collection makefile for:    2d-rewriter
# Date created:                         8 December 2007
# Whom:                                 Igor Serikov <bt@turtle.freedns.us>
#
# $FreeBSD$
#

PORTNAME=	2d-rewriter
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.crowdeduniverse.org/distfiles/

MAINTAINER=	bt@turtle.freedns.us
COMMENT=	Cellular automata simulator

MAN1=		2d-rewriter.1
MANCOMPRESSED=	yes
USE_IMAKE=	yes
USE_XORG=	x11 xext

.if !defined(NOPORTEXAMPLES)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
