# New ports collection makefile for:	sdf
# Date created:				12 December 2000
# Whom:					dannyman <dannyman@tellme.com>
#
# $FreeBSD$
#

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

MAN1=		pod2sdf.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
