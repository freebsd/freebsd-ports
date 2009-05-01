# New ports collection makefile for:	p5-Algorithm-FloodControl
# Date created:		2008-11-18
# Whom:			Andrey <gugu@zoo.rambler.ru>
#
# $FreeBSD$
#

PORTNAME=	Math-BigInt-Pari
PORTVERSION=	1.13
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Use Math::Pari for Math::BigInt routines

RUN_DEPENDS=	p5-Math-BigInt>=1.87:${PORTSDIR}/math/p5-Math-BigInt \
		p5-Math-Pari>=2.010709:${PORTSDIR}/math/p5-Math-Pari

PERL_CONFIGURE=	yes

MAN3=	Math::BigInt::Pari.3

.include <bsd.port.mk>
