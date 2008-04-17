# New ports collection makefile for:	p5-Text-Decorator
# Date created:				05 Jun 06
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Decorator
PORTVERSION=	1.65
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Apply a chain of filters to text

BUILD_DEPENDS=	${SITE_PERL}/URI/Find.pm:${PORTSDIR}/textproc/p5-URI-Find \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Text::Decorator.3 \
	Text::Decorator::Filter.3 \
	Text::Decorator::Filter::Quoted.3 \
	Text::Decorator::Filter::TTBridge.3 \
	Text::Decorator::Filter::Test.3 \
	Text::Decorator::Filter::URIFind.3 \
	Text::Decorator::Group.3 \
	Text::Decorator::Node.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
