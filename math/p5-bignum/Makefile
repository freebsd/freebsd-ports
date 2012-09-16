# New ports collection makefile for:	math/p5-bignum
# Date created:				25 May 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bignum
PORTVERSION=	0.30
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Transparent BigNumber/BigRational support for Perl

PERL_CONFIGURE=	yes

MAN3=		bigint.3 \
		bignum.3 \
		bigrat.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Math-BigInt>=1.880:${PORTSDIR}/math/p5-Math-BigInt \
		p5-Math-BigRat>=0.21:${PORTSDIR}/math/p5-Math-BigRat
RUN_DEPENDS+=	p5-Math-BigInt>=1.880:${PORTSDIR}/math/p5-Math-BigInt \
		p5-Math-BigRat>=0.21:${PORTSDIR}/math/p5-Math-BigRat
.endif

.include <bsd.port.post.mk>
