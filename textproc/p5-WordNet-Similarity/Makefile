# New ports collection makefile for:	p5-WordNet-Similarity
# Date created:				07 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WordNet-Similarity
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WordNet
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	Modules/CLI to determine semantic relatedness using the WordNet

BUILD_DEPENDS=	${SITE_PERL}/WordNet/QueryData.pm:${PORTSDIR}/textproc/p5-WordNet-QueryData \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB
RUN_DEPENDS=	${BUILD_DEPENDS}

WNHOME?=	${LOCALBASE}/share/WordNet-1.7.1

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	WNHOME=${WNHOME}
USE_REINPLACE=	yes

MAN3=		WordNet::Similarity.3 WordNet::Similarity::jcn.3 \
		WordNet::Similarity::hso.3 WordNet::Similarity::vector.3 \
		WordNet::Similarity::random.3 WordNet::Similarity::res.3 \
		WordNet::Similarity::lesk.3 WordNet::Similarity::edge.3 \
		WordNet::Similarity::lin.3 WordNet::Similarity::lch.3 \
		WordNet::Similarity::wup.3

post-patch:
	@${REINPLACE_CMD} -e  \
		'/wnUnixPath/s|/usr/local/WordNet-1.7.1|${WNHOME}|; \
		 /wnUnixPath/s|."/dict"||' ${WRKSRC}/Makefile.PL
	@${FIND} ${WRKSRC}/utils -type f| ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local/bin/perl|${PERL}|'

.include <bsd.port.mk>
