# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WordNet-Similarity
PORTVERSION=	2.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules/CLI to determine semantic relatedness using the WordNet

RUN_DEPENDS=	p5-WordNet-QueryData>=0:${PORTSDIR}/textproc/p5-WordNet-QueryData \
		p5-Text-Similarity>=0:${PORTSDIR}/textproc/p5-Text-Similarity \
		p5-Digest-SHA1>=2.10:${PORTSDIR}/security/p5-Digest-SHA1
BUILD_DEPENDS:=	${RUN_DEPENDS}

WNHOME?=	${LOCALBASE}/share/WordNet

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	WNHOME=${WNHOME}

MAN1=		rawtextFreq.pl.1 \
		BNCFreq.pl.1 \
		similarity.pl.1 \
		wordVectors.pl.1 \
		compounds.pl.1 \
		brownFreq.pl.1 \
		treebankFreq.pl.1 \
		wnDepths.pl.1 \
		semCorRawFreq.pl.1 \
		semCorFreq.pl.1 \
		similarity_server.pl.1
MAN3=		WordNet::Similarity.3 WordNet::Similarity::jcn.3 \
		WordNet::Similarity::hso.3 WordNet::Similarity::vector.3 \
		WordNet::Similarity::random.3 WordNet::Similarity::res.3 \
		WordNet::Similarity::lesk.3 \
		WordNet::Similarity::vector_pairs.3 \
		WordNet::Similarity::lin.3 WordNet::Similarity::lch.3 \
		WordNet::Similarity::wup.3 WordNet::Similarity::path.3 \
		WordNet::Similarity::DepthFinder.3 \
		WordNet::Similarity::FrequencyCounter.3 \
		WordNet::Similarity::GlossFinder.3 \
		WordNet::Similarity::ICFinder.3 \
		WordNet::Similarity::PathFinder.3 \
		WordNet::Tools.3 \
		WordNet::get_wn_info.3 WordNet::stem.3 \
		WordNet::vectorFile.3

post-patch:
	@${FIND} ${WRKSRC}/build -type f| ${XARGS} ${REINPLACE_CMD} -e \
		 "/wndictpath/s|'dict'|''|"
	@${FIND} ${WRKSRC}/utils -type f| ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local/bin/perl|${PERL}|; \
		 /wnUnixPath/s|/usr/local/WordNet-3.0|${WNHOME}|; \
		 /wnUnixPath/s|/dict||'

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not build on sparc64
.endif

.include <bsd.port.post.mk>
