# New ports collection makefile for:	CSS-SAC
# Date created:	   07 July 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	CSS-SAC
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	textproc perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SAC CSS (Simple API for CSS) parser

RUN_DEPENDS=	p5-Class-ArrayObjects>=0.04:${PORTSDIR}/devel/p5-Class-ArrayObjects
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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

# Bareword "_out_" not allowed while "strict subs"
post-patch:
	@${REINPLACE_CMD} -e "s,_out_,'_out_',g" ${WRKSRC}/lib/CSS/SAC/TestWriter.pm
	@${FIND} ${WRKSRC} -name "*.bak" -delete

.include <bsd.port.mk>
