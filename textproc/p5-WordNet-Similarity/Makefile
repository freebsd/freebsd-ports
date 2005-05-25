# New ports collection makefile for:	p5-WordNet-Similarity
# Date created:				07 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WordNet-Similarity
PORTVERSION=	0.13
PORTREVISION=	0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WordNet
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Modules/CLI to determine semantic relatedness using the WordNet

BUILD_DEPENDS=	${SITE_PERL}/WordNet/QueryData.pm:${PORTSDIR}/textproc/p5-WordNet-QueryData \
		${SITE_PERL}/Text/OverlapFinder.pm:${PORTSDIR}/textproc/p5-Text-Similarity
RUN_DEPENDS=	${BUILD_DEPENDS}

WNHOME?=	${LOCALBASE}/share/WordNet-2.0

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	WNHOME=${WNHOME}
CONFIGURE_ARGS=	</dev/null
USE_REINPLACE=	yes

MAN1=		rawtextFreq.pl.1 \
		BNCFreq.pl.1 \
		similarity.pl.1 \
		wordVectors.pl.1 \
		compounds.pl.1 \
		brownFreq.pl.1 \
		treebankFreq.pl.1 \
		wnDepths.pl.1 \
		semCorRawFreq.pl.1 \
		semCorFreq.pl.1
MAN3=		WordNet::Similarity.3 WordNet::Similarity::jcn.3 \
		WordNet::Similarity::hso.3 WordNet::Similarity::vector.3 \
		WordNet::Similarity::random.3 WordNet::Similarity::res.3 \
		WordNet::Similarity::lesk.3 \
		WordNet::Similarity::vector_pairs.3 \
		WordNet::Similarity::lin.3 WordNet::Similarity::lch.3 \
		WordNet::Similarity::wup.3 WordNet::Similarity::path.3 \
		WordNet::Similarity::DepthFinder.3 \
		WordNet::Similarity::GlossFinder.3 \
		WordNet::Similarity::ICFinder.3 \
		WordNet::Similarity::PathFinder.3

post-patch:
	@${REINPLACE_CMD} -e  \
		'/wnUnixPath/s|/usr/local/WordNet-2.0|${WNHOME}|; \
		 /wnUnixPath/s|."/dict"||' ${WRKSRC}/Makefile.PL
	@${FIND} ${WRKSRC}/utils -type f| ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local/bin/perl|${PERL}|; \
		 /wnUnixPath/s|/dict||'

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
