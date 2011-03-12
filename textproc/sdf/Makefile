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
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Document Format - "author-friendly" mark-up system

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN1=		pod2sdf.1

PERL_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc/ ${PREFIX}/share/doc/sdf
.endif

.include <bsd.port.mk>
