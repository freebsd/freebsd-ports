# New ports collection makefile for:	Lingua::EN::Sentence
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Lingua-EN-Sentence
PORTVERSION=		0.25
CATEGORIES=		textproc perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	CPAN:SHLOMOY
PKGNAMEPREFIX=		p5-

MAINTAINER=		perl@FreeBSD.org
COMMENT=		Module for splitting text into sentences

PERL_CONFIGURE=		yes

MAN3=			Lingua::EN::Sentence.3

post-extract:
	@${RM} -f ${WRKSRC}/lib/Lingua/EN/Sentence.pm~

.include <bsd.port.mk>
