# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Plucene
PORTVERSION=	1.25
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TMTM
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl port of the Java Lucene search engine

BUILD_DEPENDS=	p5-Tie-Array-Sorted>=0:${PORTSDIR}/devel/p5-Tie-Array-Sorted \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Class-Virtual>=0:${PORTSDIR}/devel/p5-Class-Virtual \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Time-Piece>=0:${PORTSDIR}/devel/p5-Time-Piece \
		p5-Lingua-Stem>=0:${PORTSDIR}/textproc/p5-Lingua-Stem \
		p5-Bit-Vector-Minimal>=0:${PORTSDIR}/math/p5-Bit-Vector-Minimal \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Plucene.3 \
	Plucene::Analysis::Analyzer.3 \
	Plucene::Analysis::CharTokenizer.3 \
	Plucene::Analysis::LetterTokenizer.3 \
	Plucene::Analysis::LowerCaseFilter.3 \
	Plucene::Analysis::LowerCaseTokenizer.3 \
	Plucene::Analysis::PorterStemFilter.3 \
	Plucene::Analysis::SimpleAnalyzer.3 \
	Plucene::Analysis::Standard::StandardAnalyzer.3 \
	Plucene::Analysis::Standard::StandardTokenizer.3 \
	Plucene::Analysis::StopAnalyzer.3 \
	Plucene::Analysis::StopFilter.3 \
	Plucene::Analysis::Token.3 \
	Plucene::Analysis::TokenFilter.3 \
	Plucene::Analysis::Tokenizer.3 \
	Plucene::Analysis::WhitespaceAnalyzer.3 \
	Plucene::Analysis::WhitespaceTokenizer.3 \
	Plucene::Bitvector.3 \
	Plucene::Document.3 \
	Plucene::Document::DateSerializer.3 \
	Plucene::Document::Field.3 \
	Plucene::Index::DocumentWriter.3 \
	Plucene::Index::FieldInfos.3 \
	Plucene::Index::FieldsReader.3 \
	Plucene::Index::FieldsWriter.3 \
	Plucene::Index::Reader.3 \
	Plucene::Index::SegmentInfo.3 \
	Plucene::Index::SegmentInfos.3 \
	Plucene::Index::SegmentMergeInfo.3 \
	Plucene::Index::SegmentMerger.3 \
	Plucene::Index::SegmentReader.3 \
	Plucene::Index::SegmentTermDocs.3 \
	Plucene::Index::SegmentTermEnum.3 \
	Plucene::Index::SegmentTermPositions.3 \
	Plucene::Index::SegmentsReader.3 \
	Plucene::Index::SegmentsTermEnum.3 \
	Plucene::Index::Term.3 \
	Plucene::Index::TermInfo.3 \
	Plucene::Index::TermInfosReader.3 \
	Plucene::Index::TermInfosWriter.3 \
	Plucene::Index::Writer.3 \
	Plucene::QueryParser.3 \
	Plucene::Search::BooleanClause.3 \
	Plucene::Search::BooleanQuery.3 \
	Plucene::Search::BooleanScorer.3 \
	Plucene::Search::DateFilter.3 \
	Plucene::Search::Filter.3 \
	Plucene::Search::HitCollector.3 \
	Plucene::Search::Hits.3 \
	Plucene::Search::IndexSearcher.3 \
	Plucene::Search::PhrasePositions.3 \
	Plucene::Search::PhraseQuery.3 \
	Plucene::Search::PhraseScorer.3 \
	Plucene::Search::PhraseScorer::Exact.3 \
	Plucene::Search::PhraseScorer::Sloppy.3 \
	Plucene::Search::PrefixQuery.3 \
	Plucene::Search::Query.3 \
	Plucene::Search::Scorer.3 \
	Plucene::Search::Searcher.3 \
	Plucene::Search::Similarity.3 \
	Plucene::Search::TermQuery.3 \
	Plucene::Search::TermScorer.3 \
	Plucene::Search::TopDocs.3 \
	Plucene::Store::InputStream.3 \
	Plucene::Store::OutputStream.3 \
	Plucene::TestCase.3 \
	Plucene::Utils.3

.include <bsd.port.mk>
