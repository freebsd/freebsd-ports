# New ports collection makefile for:	sdf
# Date created:				12 December 2000
# Whom:					dannyman <dannyman@tellme.com>
#
# $FreeBSD$
#

PORTNAME=	sdf
PORTVERSION=	2.001
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	dannyman@toldme.com
COMMENT=	Simple Document Format - "author-friendly" mark-up system

MAN1=		pod2sdf.1

PERL_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc/ ${PREFIX}/share/doc/sdf
.endif

.include <bsd.port.mk>
