# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WordNet-Similarity
PORTVERSION=	2.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules/CLI to determine semantic relatedness using the WordNet

BUILD_DEPENDS=	p5-WordNet-QueryData>=0:${PORTSDIR}/textproc/p5-WordNet-QueryData \
		p5-Text-Similarity>=0:${PORTSDIR}/textproc/p5-Text-Similarity \
		p5-Digest-SHA1>=2.10:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

WNHOME?=	${LOCALBASE}/share/WordNet

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	WNHOME=${WNHOME}

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
