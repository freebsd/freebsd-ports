# Created by: dannyman <dannyman@tellme.com>
# $FreeBSD$

PORTNAME=	sdf
PORTVERSION=	2.001
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:IANC
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Document Format - "author-friendly" mark-up system

USES=		perl5
USE_PERL5=	configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
