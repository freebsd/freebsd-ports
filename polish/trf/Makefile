# New ports collection makefile for:	trf
# Date created:		25 September 2003
# Whom:			Maciek Korzen <eaquer@ceti.pl>
#
# $FreeBSD$
#

PORTNAME=	trf
PORTVERSION=	0.4
CATEGORIES=	polish finance
MASTER_SITES=	http://www.ceti.pl/eaquer/trf/

MAINTAINER=	eaquer@ceti.pl
COMMENT=	Billing software for traffic counting working with most Polish ISPs

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
