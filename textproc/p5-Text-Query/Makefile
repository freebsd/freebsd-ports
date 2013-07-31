# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Text-Query
PORTVERSION=	0.07
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Query processing framework

USES=		perl5
USE_PERL5=	configure patch

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
