# New ports collection makefile for:	Lingua::EN::Sentence
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Lingua-EN-Sentence
PORTVERSION=		0.25
CATEGORIES=		textproc perl5
MASTER_SITES=		http://www.cpan.org/authors/id/S/SH/SHLOMOY/
PKGNAMEPREFIX=		p5-

MAINTAINER=		svenasse@polaris.ca

PERL_CONFIGURE=		yes

MAN3=			Lingua::EN::Sentence.3
MANPREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

post-extract:
	@${RM} -f ${WRKSRC}/lib/Lingua/EN/Sentence.pm~

.include <bsd.port.mk>
