# New ports collection makefile for:	FAQ::OMatic
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	FAQ-OMatic
PORTVERSION=	2.719
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl API to manipulate FAQ-O-Matics

USES=		perl5
USE_PERL5=	configure

MAN3=		FAQ::OMatic::API.3

post-install:
	@${CAT} ${WRKSRC}/install.notes

.include <bsd.port.mk>
