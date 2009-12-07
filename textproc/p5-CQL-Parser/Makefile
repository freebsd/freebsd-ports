# New ports collection makefile for:	CQL-Parser
# Date created:				19 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CQL-Parser
PORTVERSION=	1.10
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRICAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiles CQL strings into parse trees of Node subtypes

RUN_DEPENDS=    p5-Class-Accessor>=0.1:${PORTSDIR}/devel/p5-Class-Accessor \
                p5-Clone>=0.15:${PORTSDIR}/devel/p5-Clone \
                p5-String-Tokenizer>=0.05:${PORTSDIR}/textproc/p5-String-Tokenizer
BUILD_DEPENDS=  ${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:${PORTSDIR}/devel/p5-Test-Exception

MAN3=	CQL::AndNode.3 \
	CQL::BooleanNode.3 \
	CQL::Lexer.3 \
	CQL::ModifierSet.3 \
	CQL::Node.3 \
	CQL::NotNode.3 \
	CQL::OrNode.3 \
	CQL::Parser.3 \
	CQL::Prefix.3 \
	CQL::PrefixNode.3 \
	CQL::ProxModifierSet.3 \
	CQL::ProxNode.3 \
	CQL::Relation.3 \
	CQL::TermNode.3 \
	CQL::Token.3 \
	CQL::Visitor.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
