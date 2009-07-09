# New ports collection makefile for:	p5-KinoSearch
# Date created:				Thu Apr 20 15:08:34 EDT 2006
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	KinoSearch
PORTVERSION=	0.165
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/C/CR/CREAMYG
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	A Perl search engine library

MODULE_DEPENDS=	p5-Lingua-StopWords>=0.02:${PORTSDIR}/textproc/p5-Lingua-StopWords \
		p5-Lingua-Stem-Snowball>=0.94:${PORTSDIR}/textproc/p5-Lingua-Stem-Snowball \
		p5-Clone>=0.18:${PORTSDIR}/devel/p5-Clone \
		p5-Compress-Zlib>=2.008:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS+=	${MODULE_DEPENDS}
BUILD_DEPENDS+=	${MODULE_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=	KinoSearch.3 \
	KinoSearch::Analysis::Analyzer.3 \
	KinoSearch::Analysis::LCNormalizer.3 \
	KinoSearch::Analysis::PolyAnalyzer.3 \
	KinoSearch::Analysis::Stemmer.3 \
	KinoSearch::Analysis::Stopalizer.3 \
	KinoSearch::Analysis::Token.3 \
	KinoSearch::Analysis::TokenBatch.3 \
	KinoSearch::Analysis::Tokenizer.3 \
	KinoSearch::Docs::DevGuide.3 \
	KinoSearch::Docs::FileFormat.3 \
	KinoSearch::Docs::Tutorial.3 \
	KinoSearch::Document::Doc.3 \
	KinoSearch::Document::Field.3 \
	KinoSearch::Highlight::Encoder.3 \
	KinoSearch::Highlight::Formatter.3 \
	KinoSearch::Highlight::Highlighter.3 \
	KinoSearch::Highlight::SimpleHTMLEncoder.3 \
	KinoSearch::Highlight::SimpleHTMLFormatter.3 \
	KinoSearch::Index::CompoundFileReader.3 \
	KinoSearch::Index::CompoundFileWriter.3 \
	KinoSearch::Index::DelDocs.3 \
	KinoSearch::Index::FieldInfos.3 \
	KinoSearch::Index::FieldsReader.3 \
	KinoSearch::Index::FieldsWriter.3 \
	KinoSearch::Index::IndexFileNames.3 \
	KinoSearch::Index::IndexReader.3 \
	KinoSearch::Index::MultiReader.3 \
	KinoSearch::Index::MultiTermDocs.3 \
	KinoSearch::Index::NormsReader.3 \
	KinoSearch::Index::PostingsWriter.3 \
	KinoSearch::Index::SegInfos.3 \
	KinoSearch::Index::SegReader.3 \
	KinoSearch::Index::SegTermDocs.3 \
	KinoSearch::Index::SegTermEnum.3 \
	KinoSearch::Index::SegWriter.3 \
	KinoSearch::Index::Term.3 \
	KinoSearch::Index::TermBuffer.3 \
	KinoSearch::Index::TermDocs.3 \
	KinoSearch::Index::TermEnum.3 \
	KinoSearch::Index::TermInfo.3 \
	KinoSearch::Index::TermInfosReader.3 \
	KinoSearch::Index::TermInfosWriter.3 \
	KinoSearch::Index::TermVector.3 \
	KinoSearch::InvIndexer.3 \
	KinoSearch::QueryParser::QueryParser.3 \
	KinoSearch::Search::BooleanClause.3 \
	KinoSearch::Search::BooleanQuery.3 \
	KinoSearch::Search::BooleanScorer.3 \
	KinoSearch::Search::Hit.3 \
	KinoSearch::Search::HitCollector.3 \
	KinoSearch::Search::HitQueue.3 \
	KinoSearch::Search::Hits.3 \
	KinoSearch::Search::MultiSearcher.3 \
	KinoSearch::Search::PhraseQuery.3 \
	KinoSearch::Search::PhraseScorer.3 \
	KinoSearch::Search::Query.3 \
	KinoSearch::Search::QueryFilter.3 \
	KinoSearch::Search::Scorer.3 \
	KinoSearch::Search::Searchable.3 \
	KinoSearch::Search::SearchServer.3 \
	KinoSearch::Search::SearchClient.3 \
	KinoSearch::Search::Similarity.3 \
	KinoSearch::Search::TermQuery.3 \
	KinoSearch::Search::TermScorer.3 \
	KinoSearch::Search::Weight.3 \
	KinoSearch::Searcher.3 \
	KinoSearch::Store::FSInvIndex.3 \
	KinoSearch::Store::FSLock.3 \
	KinoSearch::Store::InStream.3 \
	KinoSearch::Store::InvIndex.3 \
	KinoSearch::Store::Lock.3 \
	KinoSearch::Store::OutStream.3 \
	KinoSearch::Store::RAMInvIndex.3 \
	KinoSearch::Store::RAMLock.3 \
	KinoSearch::Util::BitVector.3 \
	KinoSearch::Util::ByteBuf.3 \
	KinoSearch::Util::CClass.3 \
	KinoSearch::Util::Carp.3 \
	KinoSearch::Util::Class.3 \
	KinoSearch::Util::IntMap.3 \
	KinoSearch::Util::MathUtils.3 \
	KinoSearch::Util::MemManager.3 \
	KinoSearch::Util::PriorityQueue.3 \
	KinoSearch::Util::SortExternal.3 \
	KinoSearch::Util::StringHelper.3 \
	KinoSearch::Util::ToStringUtils.3 \
	KinoSearch::Util::ToolSet.3 \
	KinoSearch::Util::VerifyArgs.3

.include <bsd.port.mk>
