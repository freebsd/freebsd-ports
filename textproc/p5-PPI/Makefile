# New ports collection makefile for:	textproc/p5-PPI
# Date created:				24 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PPI
PORTVERSION=	1.112
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Analyze and manipulate Perl code without using perl itself

BUILD_DEPENDS=	\
		p5-Clone>=0.17:${PORTSDIR}/devel/p5-Clone \
		p5-Scalar-List-Utils>=0.17:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-List-MoreUtils>=0.13:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Params-Util>=0.10:${PORTSDIR}/devel/p5-Params-Util \
		p5-IO-stringy>=2.105:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Digest-MD5>=2.27:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Storable>=2.14:${PORTSDIR}/devel/p5-Storable \
		p5-Test-Simple>=0.47:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-ClassAPI>=1.02:${PORTSDIR}/devel/p5-Test-ClassAPI \
		p5-Test-SubCalls>=0.01:${PORTSDIR}/devel/p5-Test-SubCalls \
		p5-PathTools>=0.84:${PORTSDIR}/devel/p5-PathTools \
		p5-File-Remove>=0.22:${PORTSDIR}/devel/p5-File-Remove
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	PPI.3 \
	PPI::Cache.3 \
	PPI::Document.3 \
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
	PPI::Statement::Include.3 \
	PPI::Statement::Null.3 \
	PPI::Statement::Package.3 \
	PPI::Statement::Scheduled.3 \
	PPI::Statement::Sub.3 \
	PPI::Statement::Unknown.3 \
	PPI::Statement::UnmatchedBrace.3 \
	PPI::Statement::Variable.3 \
	PPI::Structure::Block.3 \
	PPI::Structure::Condition.3 \
	PPI::Structure::Constructor.3 \
	PPI::Structure::ForLoop.3 \
	PPI::Structure::List.3 \
	PPI::Structure::Subscript.3 \
	PPI::Structure::Unknown.3 \
	PPI::Token.3 \
	PPI::Token::ArrayIndex.3 \
	PPI::Token::Attribute.3 \
	PPI::Token::Cast.3 \
	PPI::Token::Comment.3 \
	PPI::Token::DashedWord.3 \
	PPI::Token::Data.3 \
	PPI::Token::End.3 \
	PPI::Token::HereDoc.3 \
	PPI::Token::Label.3 \
	PPI::Token::Magic.3 \
	PPI::Token::Number.3 \
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
	PPI::Transform.3

post-patch:
	@${RM} ${WRKSRC}/inc/Module/Install/AutoInstall.pm
	@${PERL} -pi -e '$$_="" if m/AutoInstall/' ${WRKSRC}/MANIFEST
	@${PERL} -pi -e '$$_="" if m/Test::More|auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	requires Perl 5.6.1 or newer. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
