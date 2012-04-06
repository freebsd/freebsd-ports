# New ports collection makefile for:	Text::Template
# Date created:		Thu Oct 28 01:58:13 EDT 1999
# Whom:			Bill "I hate Perl" Fumerola
#
# $FreeBSD$
#

PORTNAME=	Text-Template
PORTVERSION=	1.45
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://perl.plover.com/Template/ \
		CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Expand template text with embedded Perl

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

PERL_CONFIGURE=	YES

MAN3=		Text::Template.3 Text::Template::Preprocess.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
