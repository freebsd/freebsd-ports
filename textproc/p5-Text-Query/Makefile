# New ports collection makefile for:	textproc/p5-Text-Query
# Date created:				31 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Query
PORTVERSION=	0.07
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Query processing framework

PERL_CONFIGURE=	yes

MAN3=		Text::Query.3 Text::Query::Build.3 \
		Text::Query::BuildAdvancedString.3 \
		Text::Query::BuildSimpleString.3 Text::Query::Optimize.3 \
		Text::Query::Parse.3 Text::Query::ParseAdvanced.3 \
		Text::Query::ParseSimple.3 Text::Query::Solve.3 \
		Text::Query::SolveAdvancedString.3 \
		Text::Query::SolveSimpleString.3

pre-patch:
	@${PERL} -pi -e 's/factor\(\$$self\)/\&factor(\$$self)/' \
		${WRKSRC}/lib/Text/Query/ParseAdvanced.pm

.include <bsd.port.mk>
