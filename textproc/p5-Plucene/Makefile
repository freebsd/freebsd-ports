# New ports collection makefile for:	textproc/p5-Plucene
# Date created:				29 July 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plucene
PORTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/T/TM/TMTM
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl port of the Java Lucene search engine

BUILD_DEPENDS=	${SITE_PERL}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize \
		${SITE_PERL}/Tie/Array/Sorted.pm:${PORTSDIR}/devel/p5-Tie-Array-Sorted \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/Encode/compat.pm:${PORTSDIR}/devel/p5-Encode-compat \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/Class/Virtual.pm:${PORTSDIR}/devel/p5-Class-Virtual \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece \
		${SITE_PERL}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Lingua/Stem/En.pm:${PORTSDIR}/textproc/p5-Lingua-Stem \
		${SITE_PERL}/Bit/Vector/Minimal.pm:${PORTSDIR}/math/p5-Bit-Vector-Minimal \
		${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
		${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

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
	Plucene::Index::FieldInfo.3 \
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	This port requires perl 5.6 or above.
.endif

.include <bsd.port.post.mk>
