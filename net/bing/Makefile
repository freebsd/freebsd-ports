# New ports collection makefile for:	bing
# Date created:		28 December 1996
# Whom:			jseger@scds.com
#
# $FreeBSD$
#

PORTNAME=	bing
PORTVERSION=	1.0.5
CATEGORIES=	net
MASTER_SITES=	http://www.freenix.org/reseau/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A point-to-point bandwith measurement tool

MAN8=		bing.8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
