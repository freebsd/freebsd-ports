# New ports collection makefile for:	p5-String-ToIdentifier-EN
# Date created:		2011-12-05
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	String-ToIdentifier-EN
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert Strings to English Program Identifiers

BUILD_DEPENDS=	p5-Lingua-EN-Inflect-Phrase>=0.07:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Phrase \
		p5-Text-Unidecode>=0.04:${PORTSDIR}/converters/p5-Text-Unidecode \
		p5-namespace-clean>=0.20:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS=	p5-Lingua-EN-Inflect-Phrase>=0.07:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Phrase \
		p5-Text-Unidecode>=0.04:${PORTSDIR}/converters/p5-Text-Unidecode \
		p5-namespace-clean>=0.20:${PORTSDIR}/devel/p5-namespace-clean

TEST_DEPENDS=	p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PERL_CONFIGURE=	yes

MAN3=		String::ToIdentifier::EN.3 \
		String::ToIdentifier::EN::Unicode.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.92:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
