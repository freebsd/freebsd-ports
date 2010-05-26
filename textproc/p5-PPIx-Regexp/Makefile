# New ports collection makefile for:	p5-PPIx-Regexp
# Date created:		2010-05-25
# Whom:			Ashish SHUKLA <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	PPIx-Regexp
PORTVERSION=	0.007
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/W/WY/WYANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	wahjava@gmail.com
COMMENT=	PPI regular expression parser

BUILD_DEPENDS=	p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-PPI>0:${PORTSDIR}/textproc/p5-PPI \
		p5-Params-Util>=0.250:${PORTSDIR}/devel/p5-Params-Util \
		p5-Readonly>0:${PORTSDIR}/devel/p5-Readonly \
		p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Task-Weaken>0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8+

MAN3=	PPIx::Regexp.3 \
	PPIx::Regexp::Constant.3 \
	PPIx::Regexp::Dumper.3 \
	PPIx::Regexp::Element.3 \
	PPIx::Regexp::Lexer.3 \
	PPIx::Regexp::Node.3 \
	PPIx::Regexp::Node::Range.3 \
	PPIx::Regexp::Structure.3 \
	PPIx::Regexp::Structure::Assertion.3 \
	PPIx::Regexp::Structure::BranchReset.3 \
	PPIx::Regexp::Structure::Capture.3 \
	PPIx::Regexp::Structure::CharClass.3 \
	PPIx::Regexp::Structure::Code.3 \
	PPIx::Regexp::Structure::Main.3 \
	PPIx::Regexp::Structure::Modifier.3 \
	PPIx::Regexp::Structure::NamedCapture.3 \
	PPIx::Regexp::Structure::Quantifier.3 \
	PPIx::Regexp::Structure::Regexp.3 \
	PPIx::Regexp::Structure::Replacement.3 \
	PPIx::Regexp::Structure::Subexpression.3 \
	PPIx::Regexp::Structure::Switch.3 \
	PPIx::Regexp::Structure::Unknown.3 \
	PPIx::Regexp::Support.3 \
	PPIx::Regexp::Token.3 \
	PPIx::Regexp::Token::Assertion.3 \
	PPIx::Regexp::Token::Backreference.3 \
	PPIx::Regexp::Token::Backtrack.3 \
	PPIx::Regexp::Token::CharClass.3 \
	PPIx::Regexp::Token::CharClass::POSIX.3 \
	PPIx::Regexp::Token::CharClass::Simple.3 \
	PPIx::Regexp::Token::Code.3 \
	PPIx::Regexp::Token::Comment.3 \
	PPIx::Regexp::Token::Condition.3 \
	PPIx::Regexp::Token::Control.3 \
	PPIx::Regexp::Token::Delimiter.3 \
	PPIx::Regexp::Token::Greediness.3 \
	PPIx::Regexp::Token::GroupType.3 \
	PPIx::Regexp::Token::GroupType::Assertion.3 \
	PPIx::Regexp::Token::GroupType::BranchReset.3 \
	PPIx::Regexp::Token::GroupType::Code.3 \
	PPIx::Regexp::Token::GroupType::Modifier.3 \
	PPIx::Regexp::Token::GroupType::NamedCapture.3 \
	PPIx::Regexp::Token::GroupType::Subexpression.3 \
	PPIx::Regexp::Token::GroupType::Switch.3 \
	PPIx::Regexp::Token::Interpolation.3 \
	PPIx::Regexp::Token::Literal.3 \
	PPIx::Regexp::Token::Modifier.3 \
	PPIx::Regexp::Token::Operator.3 \
	PPIx::Regexp::Token::Quantifier.3 \
	PPIx::Regexp::Token::Recursion.3 \
	PPIx::Regexp::Token::Reference.3 \
	PPIx::Regexp::Token::Structure.3 \
	PPIx::Regexp::Token::Unknown.3 \
	PPIx::Regexp::Token::Unmatched.3 \
	PPIx::Regexp::Token::Whitespace.3 \
	PPIx::Regexp::Tokenizer.3

.include <bsd.port.mk>
