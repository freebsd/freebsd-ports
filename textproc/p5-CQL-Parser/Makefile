# New ports collection makefile for:	CQL-Parser
# Date created:				19 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CQL-Parser
PORTVERSION=	0.98
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/E/ES/ESUMMERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Compiles CQL strings into parse trees of Node subtypes

BUILD_DEPENDS=	${SITE_PERL}/String/Tokenizer.pm:${PORTSDIR}/textproc/p5-String-Tokenizer \
		${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

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
	CQL::ProxNode.3 \
	CQL::Relation.3 \
	CQL::TermNode.3 \
	CQL::Token.3 \
	CQL::Visitor.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl5.6
.endif

.include <bsd.port.post.mk>
