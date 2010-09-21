# New ports collection makefile for:	p5-Apache-Compress
# Date created:				Sep 09 2003
# Whom:	      				Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Compress
PORTVERSION=	1.005
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Auto-compress web files with Gzip

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache.pm:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes

MAN3=		Apache::Compress.3
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
BUILD_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
