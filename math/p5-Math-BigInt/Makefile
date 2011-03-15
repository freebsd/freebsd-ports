# New ports collection makefile for:	math/p5-Math-BigInt
# Date created:				12 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Math-BigInt
PORTVERSION=	1.993
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PJACKLAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Math::BigInt - Arbitrary size integer math package

PERL_CONFIGURE=	yes

MAN3=		Math::BigFloat.3 \
		Math::BigInt.3 \
		Math::BigInt::Calc.3 \
		Math::BigInt::CalcEmu.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.42:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.include <bsd.port.post.mk>
