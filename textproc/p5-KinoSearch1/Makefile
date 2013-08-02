# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	KinoSearch1
PORTVERSION=	1.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CREAMYG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl search engine library

BUILD_DEPENDS=	p5-Lingua-StopWords>=0.02:${PORTSDIR}/textproc/p5-Lingua-StopWords \
		p5-Lingua-Stem-Snowball>=0.94:${PORTSDIR}/textproc/p5-Lingua-Stem-Snowball \
		p5-Clone>=0.18:${PORTSDIR}/devel/p5-Clone
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	KinoSearch1.3 \
	KinoSearch1::Analysis::Analyzer.3 \
	KinoSearch1::Analysis::LCNormalizer.3 \
	KinoSearch1::Analysis::PolyAnalyzer.3 \
	KinoSearch1::Analysis::Stemmer.3 \
	KinoSearch1::Analysis::Stopalizer.3 \
	KinoSearch1::Analysis::Token.3 \
	KinoSearch1::Analysis::TokenBatch.3 \
	KinoSearch1::Analysis::Tokenizer.3 \
	KinoSearch1::Docs::FileFormat.3 \
	KinoSearch1::Docs::Tutorial.3 \
	KinoSearch1::Document::Doc.3 \
	KinoSearch1::Document::Field.3 \
	KinoSearch1::Highlight::Encoder.3 \
	KinoSearch1::Highlight::Formatter.3 \
	KinoSearch1::Highlight::Highlighter.3 \
	KinoSearch1::Highlight::SimpleHTMLEncoder.3 \
	KinoSearch1::Highlight::SimpleHTMLFormatter.3 \
	KinoSearch1::Index::Term.3 \
	KinoSearch1::InvIndexer.3 \
	KinoSearch1::QueryParser::QueryParser.3 \
	KinoSearch1::Search::BooleanQuery.3 \
	KinoSearch1::Search::Hit.3 \
	KinoSearch1::Search::Hits.3 \
	KinoSearch1::Search::MultiSearcher.3 \
	KinoSearch1::Search::PhraseQuery.3 \
	KinoSearch1::Search::Query.3 \
	KinoSearch1::Search::QueryFilter.3 \
	KinoSearch1::Search::SearchClient.3 \
	KinoSearch1::Search::SearchServer.3 \
	KinoSearch1::Search::TermQuery.3 \
	KinoSearch1::Searcher.3 \
	KinoSearch1::Store::FSInvIndex.3 \
	KinoSearch1::Store::InvIndex.3 \
	KinoSearch1::Store::RAMInvIndex.3 \

.include <bsd.port.mk>
