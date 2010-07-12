# New ports collection makefile for:	textproc/p5-PPI
# Date created:				24 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PPI
PORTVERSION=	1.213
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Analyze and manipulate Perl code without using perl itself

BUILD_DEPENDS=	\
		p5-Clone>=0.30:${PORTSDIR}/devel/p5-Clone \
		p5-IO-String>=1.07:${PORTSDIR}/devel/p5-IO-String \
		p5-List-MoreUtils>=0.16:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Scalar-List-Utils>=1.20:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Params-Util>=1.00:${PORTSDIR}/devel/p5-Params-Util \
		p5-Task-Weaken>0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	PPI.3 \
	PPI::Cache.3 \
	PPI::Document.3 \
	PPI::Document::File.3 \
	PPI::Document::Fragment.3 \
	PPI::Document::Normalized.3 \
	PPI::Dumper.3 \
	PPI::Element.3 \
	PPI::Find.3 \
	PPI::Lexer.3 \
	PPI::Node.3 \
	PPI::Normal.3 \
	PPI::Normal::Standard.3 \
	PPI::Statement.3 \
	PPI::Statement::Break.3 \
	PPI::Statement::Compound.3 \
	PPI::Statement::Data.3 \
	PPI::Statement::End.3 \
	PPI::Statement::Expression.3 \
	PPI::Statement::Given.3 \
	PPI::Statement::Include.3 \
	PPI::Statement::Include::Perl6.3 \
	PPI::Statement::Null.3 \
	PPI::Statement::Package.3 \
	PPI::Statement::Scheduled.3 \
	PPI::Statement::Sub.3 \
	PPI::Statement::Unknown.3 \
	PPI::Statement::UnmatchedBrace.3 \
	PPI::Statement::Variable.3 \
	PPI::Statement::When.3 \
	PPI::Structure.3 \
	PPI::Structure::Block.3 \
	PPI::Structure::Condition.3 \
	PPI::Structure::Constructor.3 \
	PPI::Structure::For.3 \
	PPI::Structure::Given.3 \
	PPI::Structure::List.3 \
	PPI::Structure::Subscript.3 \
	PPI::Structure::Unknown.3 \
	PPI::Structure::When.3 \
	PPI::Token.3 \
	PPI::Token::ArrayIndex.3 \
	PPI::Token::Attribute.3 \
	PPI::Token::BOM.3 \
	PPI::Token::Cast.3 \
	PPI::Token::Comment.3 \
	PPI::Token::DashedWord.3 \
	PPI::Token::Data.3 \
	PPI::Token::End.3 \
	PPI::Token::HereDoc.3 \
	PPI::Token::Label.3 \
	PPI::Token::Magic.3 \
	PPI::Token::Number.3 \
	PPI::Token::Number::Binary.3 \
	PPI::Token::Number::Exp.3 \
	PPI::Token::Number::Float.3 \
	PPI::Token::Number::Hex.3 \
	PPI::Token::Number::Octal.3 \
	PPI::Token::Number::Version.3 \
	PPI::Token::Operator.3 \
	PPI::Token::Pod.3 \
	PPI::Token::Prototype.3 \
	PPI::Token::Quote.3 \
	PPI::Token::Quote::Double.3 \
	PPI::Token::Quote::Interpolate.3 \
	PPI::Token::Quote::Literal.3 \
	PPI::Token::Quote::Single.3 \
	PPI::Token::QuoteLike.3 \
	PPI::Token::QuoteLike::Backtick.3 \
	PPI::Token::QuoteLike::Command.3 \
	PPI::Token::QuoteLike::Readline.3 \
	PPI::Token::QuoteLike::Regexp.3 \
	PPI::Token::QuoteLike::Words.3 \
	PPI::Token::Regexp.3 \
	PPI::Token::Regexp::Match.3 \
	PPI::Token::Regexp::Substitute.3 \
	PPI::Token::Regexp::Transliterate.3 \
	PPI::Token::Separator.3 \
	PPI::Token::Structure.3 \
	PPI::Token::Symbol.3 \
	PPI::Token::Unknown.3 \
	PPI::Token::Whitespace.3 \
	PPI::Token::Word.3 \
	PPI::Token::_QuoteEngine.3 \
	PPI::Token::_QuoteEngine::Full.3 \
	PPI::Token::_QuoteEngine::Simple.3 \
	PPI::Tokenizer.3 \
	PPI::Transform.3 \
	PPI::Transform::UpdateCopyright.3

.include <bsd.port.mk>
