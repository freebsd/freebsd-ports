# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WordNet-Similarity
PORTVERSION=	2.07
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules/CLI to determine semantic relatedness using the WordNet

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Text-Similarity>=0.10:textproc/p5-Text-Similarity \
		p5-WordNet-QueryData>=1.49:textproc/p5-WordNet-QueryData
RUN_DEPENDS:=	${BUILD_DEPENDS}

WNHOME?=	${LOCALBASE}/share/WordNet

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	WNHOME=${WNHOME}

BROKEN_sparc64=	Does not build on sparc64

post-patch:
	@${FIND} ${WRKSRC}/build -type f| ${XARGS} ${REINPLACE_CMD} -e \
		 "/wndictpath/s|'dict'|''|"
	@${FIND} ${WRKSRC}/utils -type f| ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local/bin/perl|${PERL}|; \
		 /wnUnixPath/s|/usr/local/WordNet-3.0|${WNHOME}|; \
		 /wnUnixPath/s|/cntlist|&.rev|; \
		 /wnUnixPath/s|/dict||'

.include <bsd.port.mk>
