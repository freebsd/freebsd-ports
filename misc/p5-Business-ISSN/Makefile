# New ports collection makefile for:	Business::ISSN
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Business-ISSN
PORTVERSION=		0.91
CATEGORIES=		misc perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Perl extension for International Standard Serial Numbers

PERL_CONFIGURE=		yes

MAN3=			Business::ISSN.3

post-patch:
	${REINPLACE_CMD} -e 's,Business-ISSN,Business::ISSN,' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
