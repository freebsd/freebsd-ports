# New ports collection makefile for:	CSS-SAC
# Date created:	   07 July 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	CSS-SAC
PORTVERSION=	0.06
CATEGORIES=	textproc perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CSS
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	SAC CSS (Simple API for CSS) parser

BUILD_DEPENDS=	${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
		${SITE_PERL}/Class/ArrayObjects.pm:${PORTSDIR}/devel/p5-Class-ArrayObjects
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CSS::SAC.3 CSS::SAC::Condition.3 \
		CSS::SAC::Condition::Attribute.3 \
		CSS::SAC::Condition::Combinator.3 \
		CSS::SAC::Condition::Content.3 CSS::SAC::Condition::Lang.3 \
		CSS::SAC::Condition::Negative.3 \
		CSS::SAC::Condition::Positional.3 CSS::SAC::ConditionFactory.3 \
		CSS::SAC::LexicalUnit.3 CSS::SAC::Selector.3 \
		CSS::SAC::Selector::CharacterData.3 \
		CSS::SAC::Selector::Conditional.3 \
		CSS::SAC::Selector::Descendant.3 CSS::SAC::Selector::Element.3 \
		CSS::SAC::Selector::Negative.3 \
		CSS::SAC::Selector::ProcessingInstruction.3 \
		CSS::SAC::Selector::Sibling.3 CSS::SAC::Selector::Simple.3 \
		CSS::SAC::SelectorFactory.3 CSS::SAC::SelectorList.3 \
		CSS::SAC::TestWriter.3 CSS::SAC::Writer.3

.include <bsd.port.mk>
